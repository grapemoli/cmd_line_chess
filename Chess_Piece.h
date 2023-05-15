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
#include <exception>      // For custom exception: invalid_move.
#include <iostream>       // For printing.


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
   * Custom Exception: invalid_move
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
    const char* what() const throw()
    {
      return "Invalid move.";
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
   */
  Chess_Piece (bool is_white, size_t x, size_t y);

  /// Destructor.
  virtual ~Chess_Piece (void);

  /// Return the x_ data member.
  size_t get_x (void);

  /// Return the y_ data member.
  size_t get_y (void);

  /// Return the is_white_ data member.
  bool is_white (void);

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
   virtual void execute (size_t x, size_t y) = 0;                                 /// TODO: add in BOARD

   /**
    * Checks if the movement of the chess piece will cause
    * a collision with any other piece.
    * 
    * @param[in]          x             New x position
    * @param[in]          y             New y position
    * @param[in]          board         The Chess_Board instance
    * @retvalue           True          There is a collision
    * @retvalue           False         There is no collision
    */
    bool is_collide (size_t x, size_t y);                                         /// TODO: add in BOARD

   /**
    * List the possible moves that can be made, taking into
    * account edge collision. Unique to each specific piece.
    */
    virtual void list_valid_moves (void) = 0;

   /**
    * Check if the movement is valid. Unique to each specific
    * piece.
    * 
    * @param[in]          x             The to-be x placement
    * @param[in]          y             The to-be y placement
    * @retvalue           True          Valid
    * @retvalue           False         Not valid
    */
    virtual bool is_valid (size_t x, size_t y) = 0;

   /**
    * Support the undo() operation by regressing to the top
    * position on the stack.
    */

    void undo (void);

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
};


// Include the inline file.
#include "Chess_Piece.inl"


#endif   // !defined _CHESS_PIECE_H