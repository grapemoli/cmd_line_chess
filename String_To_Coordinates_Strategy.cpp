// -*- C++ -*-
//==============================================================================
/**
 * File: String_To_Coordinates_Strategy.cpp
 * By: Grace Nguyen
 */
 //==============================================================================


#include "String_To_Coordinates_Strategy.h"


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
// clean_string (string)
//
std::string String_To_Coordinates_Strategy::clean_string(std::string string)
{
  // Remove parenthesis and spaces. Make the delimiter between the first and
  // second coordinate a comma delimiter.
  std::string clean_string;

  std::istringstream ss;
  ss.clear();
  ss.str("");
  ss.str(string);

  std::string token;

  while (ss >> token)
  {
    // Check that the token is entirely alphanumeric before parsing it.
    // This will remove parenthesis, etc.
    bool valid = true;
    for (int i = 0; i < token.length(); i++)
    {
      if (isalnum(token[i]) == 0)
      {
        valid == false;
      }

      // Only concatenate the token to the string *if* the token is entirely
      // alphanumeric.
      if (valid == true)
      {
        if (clean_string.length() != 0)
        {
          clean_string += ",";
          clean_string += token;
        }
        else
        {
          clean_string += token;
        }
      }
    }
  }

  // Check for if the string is formatted as, ex., A4. In which case, format the string as
  // A,4.
  if (string.length() == 2 && isalpha(string[0]) != 0 && isdigit(string[1]) != 0)
  {
    clean_string = clean_string[0] + "," + clean_string[1];
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

  // Parse the string and return the coordinates appropiately.
  if (this->is_valid(string) == false)
  {
    throw invalid_operation();
  }
  else
  {
    std::istringstream ss;
    ss.clear();
    ss.str("");

    ss >> string;
    std::string token;
    int i = 0;

    try
    {
      // clean_string() uses a comma delimiter.
      while (std::getline(ss, token, ',')) 
      {
        coordinates[i] = this->to_size_t(token);
        i++;
      }
    }
    catch (...)
    {
      throw invalid_operation();
    }
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