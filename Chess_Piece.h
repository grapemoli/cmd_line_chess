// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _CHESS_PIECE_H_
#define _CHESS_PIECE_H_

#include <stack>          // For stack.
#include <array>          // For array.
#include <exception>      // For custom exception: invalid_move, game_over.
#include <iostream>       // For printing.
#include <memory>         // For shared_ptr.

// Forward Declarations.
class Chess_Board;
class Chess_Piece_Visitor;
class Movement_Validation_Strategy;


/**
 * @class Chess_Piece
 * 
 * An abstract class that outlines common behavior between
 * between all chess pieces.
 */
class Chess_Piece 
{
public:
  /*************
   * Custom Exceptions
   **************/
  /**
    * @class invalid_move
    *
    * Exception thrown to indicate invalid move.
    */
  class invalid_move: public std::exception
  {
  public:
    /// Default constructor.
    invalid_move (void)
      :std::exception () { }
      
    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    invalid_move (const char * msg)
      :std::exception (msg) { }

    /// Message to be returned when what() is called.
    const char* what () const throw ()
    {
      return "Invalid move.";
    }
  };


  /**
    * @class game_over
    *
    * Exception thrown to indicate game over (i.e.,
    * the King is eaten!).
    */
  class game_over : public std::exception
  {
  public:
    /// Default constructor.
    game_over (void)
      :std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    game_over (const char* msg)
      :std::exception (msg) { }

    /// Message to be returned when what() is called.
    const char* what () const throw ()
    {
      return "Game over!";
    }
  };



  /*************
   * Member Functions
   **************/
  /**
   * Default constructer.
   * 
   * @param[in]         is_white      Boolean to determine color
   * @param[in]         x             The x coordinate
   * @param[in]         y             The y coordinate
   * @param[in]         str           The string representation of this class
   * @param[in]         strategy      Movement_Validation_Strategy reference
   */
  Chess_Piece (bool is_white, size_t x, size_t y, std::string str, Movement_Validation_Strategy & strategy);

  /// Destructor.
  virtual ~Chess_Piece (void);

  /// Return the x_ data member, which can not change this.
  const size_t get_x (void) const;

  /// Return the x_ data member, which can change this.
  size_t get_x (void);

  /// Return the y_ data member, which can not change this.
  const size_t get_y (void) const;

  /// Return the y_ data member, which can change this.
  size_t get_y (void);

  /// Return the string_representation_ data member.
  const std::string string (void);

  /// Return the is_white_ data member.
  const bool is_white (void) const;

  /// Return the stack of actions.
  std::stack<std::array<int, 2>> & get_actions (void);

  /**
   * A pure method that will check the placement validity,
   * and then move the chess piece. Lastly, the "previous" 
   * position is pushed into the actions stack.
   * 
   * @param[in]         x             New x position
   * @param[in]         y             New y position
   * @param[in]         board         Reference to a Chess_Board instance
   * @exception         invalid_move
   */
  virtual void execute (size_t x, size_t y, Chess_Board & board) = 0;

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   */
  virtual void list_valid_moves (void) = 0;

  /**
   * Support the undo() operation by regressing to the top
   * position on the stack.
   */
  void undo (void);

  /**
   * Enable double dispatching. Used for collision detection.
   * 
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  virtual void accept (Chess_Piece_Visitor & v) = 0;

protected:
  /*************
   * Attributes
   **************/
  /// True if the chess piece is white, false if black.
  bool is_white_;

  /// The x position of the chess piece.
  size_t x_;

  /// The y position of the chess piece.
  size_t y_;

  /// A stack of previous placements of the chess piece. 
  std::stack<std::array<int, 2>> actions_;

  /// The strategy to employ for movement, collision & game over detection.
  Movement_Validation_Strategy & movement_strategy_;

  /// The string representation of this class on the board.
  std::string string_representation_;
};


// Include the inline file.
#include "Chess_Piece.inl"


#endif   // !defined _CHESS_PIECE_H