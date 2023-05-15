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
  void print (void);

  /// Start the game.
  void start (void);

  /**
   * Check for game over (if a king is eaten).
   * 
   * @retvalue          True          Game Over
   * @retvalue          False         Game is not over
   */
  bool game_over (void);

  /**
   * Ask for the user input needed to move the appropiate
   * chess piece.
   * 
   * @param[in]          color         Boolean representing the color playing
   */
  void move (bool color);

private:
  /*************
   * Attributes
   **************/
  /// Allows for back-tracking of moves.
  std::stack<Chess_Piece> moves_;
};


#endif   // !defined _CHESS_BOARD_H_