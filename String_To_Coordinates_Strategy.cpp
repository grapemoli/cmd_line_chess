// -*- C++ -*-
//==============================================================================
/**
 * File: String_To_Coordinates_Strategy.cpp
 * By: Grace Nguyen
 */
 //==============================================================================


#include "String_To_Coordinates_Strategy.h"
#include <iostream>


/*
  Constructors & Destructors
*/
//
// String_To_Coordinates ()
//
String_To_Coordinates_Strategy::String_To_Coordinates_Strategy(void)
  :alpha_("ABCDEFGH")
{}


//
// ~String_To_Coordindates ()
//
String_To_Coordinates_Strategy::~String_To_Coordinates_Strategy(void)
{}



/*
  String-to-Coordinates Methods
*/
//
// clean_string (std::string)
//
std::string String_To_Coordinates_Strategy::clean_string(std::string string)
{
  // Remove parenthesis and spaces. Make the delimiter between the first and
  // second coordinate a comma delimiter.
  std::string clean_string;

  std::stringstream ss;
  ss.clear();
  ss.str("");
  ss.str(string);

  std::string token;
  std::string temp;
  bool valid = true;

  while (ss >> token)
  {
    valid = true;
    temp.clear();

    // Search through the token to make sure one of the characters is not a comma or parenthesis.
    for (int i = 0; i < token.length(); i++)
    {
      if (isalnum(token[i]) == 0)
      {
        // "Valid" inputs are: commas, parenthesis.
        if (token[i] != ',' && token[i] != '(' && token[i] != ')')
        {
          // Invalid input.
          valid = false;
          break;
        }
      }
      else
      {
        temp += token.substr(i, 1);
      }
    }

    // ONLY parse the -validified- token if the valid flag is true.
    if (valid == true)
    {
      if (clean_string.length() != 0)
      {
        clean_string = clean_string +  "," + temp;
      }
      else
      {
        clean_string = temp;
      }
    }
  }

  // Check for inputs such as A4, where you need to split the token to become A,4.
  if (clean_string.length() == 2 && isalpha(clean_string[0]) != 0 && isdigit(clean_string[1]) != 0)
  {
    clean_string = clean_string.substr(0, 1) + "," + clean_string.substr(1);
  }

  return clean_string;
}


//
// is_valid (string)
//
bool String_To_Coordinates_Strategy::is_valid(std::string string)
{
  // Check that the length is 3 and the string is formatted properly.
  if (string.find(",") != std::string::npos && string.length() == 3 && isalpha(string[0]) != 0 && isdigit(string[2]) != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}


//
// get_coordinates (string)
//
std::array<size_t, 2> String_To_Coordinates_Strategy::get_coordinates(std::string string)
{ 
  std::array<size_t, 2> coordinates;

  // Get the coordinates.
  if (this->is_valid(string) == false)
  {
    throw invalid_operation();
  }
  else
  {
    coordinates[0] = this->to_size_t(string.substr(0, 1));
    coordinates[1] = this->to_size_t(string.substr(2));
  }
  
  return coordinates;
}


//
// to_size_t (string)
//
size_t String_To_Coordinates_Strategy::to_size_t(std::string string)
{
  // Check if the input contains all digits.
  bool is_integer = (string.find_first_not_of("0123456789") == std::string::npos);

  if (is_integer == true)
  {
    size_t size_t_str;

    std::stringstream converter;
    converter.clear();
    converter.str("");

    converter << string;
    converter >> size_t_str;

    converter.clear();
    return size_t_str;
  }
  else
  {
    // Check that the string is a character.
    if (string.length() == 1 && isalpha(string[0]) != 0)
    {
      // Conversion of string to number using the alpha_ member.
      return this->alpha_.find(std::toupper(string[0]));
    }
    else
    {
      throw invalid_operation();
    }
  }
}