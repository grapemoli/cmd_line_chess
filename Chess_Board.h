// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Board.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _CHESS_BOARD_H_
#define _CHESS_BOARD_H_

#include <stack>          // For stack.
#include <memory>         // For shared_ptr.
#include <sstream>        // For string conversion.
#include <memory>         // For custom exception: invalid_set.

// Forward Declarations.
class Chess_Piece;
class Movement_Validation_Strategy;
class Transform_Chess_Piece;


/**
 * @class Chess_Board
 * 
 * A class that allows for representations of the Chess_Board 
 * to vary without burdening the client.
 */
class Chess_Board
{
public:
  /*************
  * Custom Exceptions
  **************/
  /**
   * @class invalid_set
   *
   * Exception thrown to indicate invalid setting of Chess Pieces.
   */
  class invalid_set : public std::exception
  {
  public:
    /// Default constructor.
    invalid_set(void)
      :std::exception() { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    invalid_set(const char* msg)
      :std::exception(msg) { }

    /// Message to be returned when what() is called.
    const char* what() const throw ()
    {
      return "Invalid attempt to set a Chess Piece.";
    }
  };


  /**
   * @class invalid_input
   *
   * Exception thrown to indicate invalid input.
   */
  class invalid_input : public std::exception
  {
  public:
    /// Default constructor.
    invalid_input (void)
      :std::exception() { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    invalid_input (const char* msg)
      :std::exception(msg) { }

    /// Message to be returned when what() is called.
    const char* what() const throw ()
    {
      return "Invalid input.";
    }
  };


  /**
   * @class quit
   *
   * Exception thrown to indicate user wants to quit.
   */
  class quit : public std::exception
  {
  public:
    /// Default constructor.
    quit (void)
      :std::exception() { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    quit (const char* msg)
      :std::exception(msg) { }

    /// Message to be returned when what() is called.
    const char* what() const throw ()
    {
      return "User inputted 'QUIT' or equivalent.";
    }
  };



  /*************
  * Member Functions
  **************/
  /**
   * Default constructor.
   * 
   * @param[in]         strategy      Strategy reference for movement
   */
  Chess_Board (Movement_Validation_Strategy & strategy);

  /**
   * Deep copy constructor.
   * 
   * @param[in]         board         Chess board reference
   */
  Chess_Board (Chess_Board & board);

  /// Destructor.
  virtual ~Chess_Board (void);

  /// Print the board.
  virtual void print (void) = 0;

  /// Start the game.
  virtual void start (void) = 0;

  /**
   * Ask for the user input needed to move the appropiate
   * chess piece.
   *
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          color         Boolean representing the color playing
   * @retvalue           True          Player completed their move
   * @retvalue           False         Player did not complete their move ('QUIT')
   */
  bool move (Chess_Piece & piece, bool color);

  /**
   * Get the chess piece at the passed parameters.
   * 
   * @param[in]         x             The x coordinate to retrieve from
   * @param[in]         y             The y coordinate to retrieve from
   * @return            Chess_Piece pointer (pointer because can be null)
   */
  virtual std::shared_ptr<Chess_Piece> get_chess_piece (size_t x, size_t y) = 0;

  /**
   * Transform the pawn by replacing the Pawn representation
   * with the new representation that the user chooses.
   * 
   * @param[in]         piece           Transform_Chess_Piece pointer
   */
  virtual void transform (std::shared_ptr<Transform_Chess_Piece> piece) = 0;

  /// Return size_.
  size_t get_size (void) const;

  /**
   * Set the chess piece to the inputted parameters.
   * 
   * @param[in]         x               The new x-position
   * @param[in]         y               The new y-position
   * @param[in]         piece           Chess_Piece reference
   */
  virtual void set_chess_piece (size_t x, size_t y, Chess_Piece & piece) = 0;

  /**
   * Build the chess board such that it represents the board at the
   * beginning of the game.
   */
  virtual void build_board (void) = 0;

protected:
  /**************
   * Helper Methods
   **************/
  /**
   * Turn the inputted string to a size_t.
   * 
   * @param[in]         input         String input
   * @return            size_t of the input
   * @exception         invalid_input Input is invalid
   */
  size_t to_size_t (std::string input);
  

  /*************
   * Attributes
   **************/
  /// Allows for back-tracking of moves.
  std::stack<std::shared_ptr<Chess_Piece>> moves_;

  /// A Chess_Board is 8x8.
  size_t size_;

  /// Strategy for movement.
  Movement_Validation_Strategy & movement_strategy_;
};


// Include inline.
#include "Chess_Board.inl"


#endif   // !defined _CHESS_BOARD_H_