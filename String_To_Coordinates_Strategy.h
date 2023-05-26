// -*- C++ -*-
//==============================================================================
/**
 * File: String_To_Coordinates_Strategy.h
 * By: Grace Nguyen
 */
 //==============================================================================


#pragma once
#ifndef _STRING_TO_COORDINATES_BOARD_H_
#define _STRING_TO_COORDINATES_BOARD_H_

#include <array>      // For array.
#include <string>     // For string methods.
#include <exception>  // For custom exception: invalid_exception
#include <sstream>    // For stringstream.
#include <ctype.h>    // For islanum.


/**
 * @class String_To_Coordinates_Strategy
 *
 * A class that groups together algorithms that deal with string-to-number
 * conversions (in particular, the numbers are size_t coordinates). This class
 * can be extended if wanted, hence methods are given the virtual tag.
 */
class String_To_Coordinates_Strategy 
{
public:
  /*************
  * Custom Exceptions
  **************/
  /**
   * @class invalid_string
   *
   * Exception thrown to indicate an invalid operation or
   * conversion was done to the string.
   */
  class invalid_operation : public std::exception
  {
  public:
    /// Default constructor.
    invalid_operation (void)
      :std::exception() { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    invalid_operation (const char* msg)
      :std::exception(msg) { }

    /// Message to be returned when what() is called.
    const char* what() const throw ()
    {
      return "Invalid string conversion or operation.";
    }
  };



  /*************
  * Member Functions
  **************/
  /// Default constructor.
  String_To_Coordinates_Strategy (void);

  /// Destructor.
  virtual ~String_To_Coordinates_Strategy (void);

  /**
   * Extract coordinates from the string.
   * 
   * @param[in]         string          The string input
   * @return            An array of two size_t coordinates
   * @exception         invalid_operation
   */
  virtual std::array<size_t, 2> get_coordinates (std::string string);

  /**
   * Convert the passed string into a size_t.
   * 
   * @param[in]          string          The string input
   * @return             A size_t version of the string
   * @exception          invalid_operation
   */
  virtual size_t to_size_t (std::string string);

  /**
   * Clean the string such all parenthesis and spaces are removed
   * from the string. Note that between the first and second coordinate
   * is a comma delimiter.
   *
   * @param[in]           string          The string input
   * @return              The cleaned string input.
   */
  virtual std::string clean_string(std::string string);

  /**
   * Check that the passed string is valid for coordinates extraction.
   *
   * @param[in]          string          The string input
   * @retvalue           True            The string input is valid
   * @retvalue           False           The string input is invalid
   */
  virtual bool is_valid(std::string string);

protected:
  /*************
   * Attributes
   **************/
  /// Alphabet-to-Number conversion.
  std::string alpha_ = "ABDCEFGH";
};


#endif   // !defined _STRING_TO_COORDINATES_BOARD_H_
