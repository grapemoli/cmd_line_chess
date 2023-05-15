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

// Forward Declarations.
class Chess_Piece;


/**
 * @class Chess_Board
 * 
 * A class that allows for representations of the Chess_Board 
 * to vary without burdening the client.
 */
class Chess_Board
{
public:
  /// Default constructor.
  Chess_Board (void);

  /// Destructor.
  virtual ~Chess_Board (void);

  /// Print the board.
  virtual void print (void) = 0;

  /// Start the game.
  virtual void start (void) = 0;

  /**
   * Check for game over (if a king is eaten).
   * 
   * @retvalue          True          Game Over
   * @retvalue          False         Game is not over
   */
  virtual bool game_over (void) = 0;

  /**
   * Ask for the user input needed to move the appropiate
   * chess piece.
   * 
   * @param[in]          color         Boolean representing the color playing
   */
  virtual void move (bool color) = 0;

  /**
   * Get the chess piece at the passed parameters.
   * 
   * @param[in]         x             The x coordinate to retrieve from
   * @param[in]         y             The y coordinate to retrieve from
   * @return            Chess_Piece instance
   */
  virtual Chess_Piece get_chess_piece(size_t x, size_t y) = 0;

  /**
   * Transform the pawn by replacing the Pawn representation
   * with the new representation that the user chooses.
   * 
   * @param[in]         piece           Transform_Chess_Piece reference
   */
  virtual void transform (Chess_Piece & piece) = 0;

protected:
  /*************
   * Attributes
   **************/
  /// Allows for back-tracking of moves.
  std::stack<Chess_Piece> moves_;
};


#endif   // !defined _CHESS_BOARD_H_