// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Chess_Board.h
 * By: Grace Nguyen
 */
 //==============================================================================


#pragma once
#ifndef _ARRAY_CHESS_BOARD_H_
#define _ARRAY_CHESS_BOARD_H_

#include <array>      // For array.
#include <iostream>   // For printing.
#include "Chess_Board.h"

// Forward Declarations.
class Chess_Piece;
class Array_Movement_Strategy;


/**
 * @class Array_Chess_Board
 *
 * Full implementation of Chess_Board, representing the board as a 
 * two-dimensional array.
 */
class Array_Chess_Board : public Chess_Board
{
public:
  /// Default constructor.
  Array_Chess_Board (Array_Movement_Strategy & strategy);

  /**
   * Copy constructor (deep copy).
   * 
   * @param[in]         board         Array_Chess_Board reference
   */
  Array_Chess_Board (Array_Chess_Board & board);

  /// Destructor.
  virtual ~Array_Chess_Board (void);

  /// Print the board.
  void print (void);

  /// Start the game, including UI for Chess.
  void start (void);

  /**
   * Ask for the user input needed to move the appropiate
   * chess piece.
   *
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          color         Boolean representing the color playing
   */
  void move (Chess_Piece & piece, bool color);

  /**
   * Get the chess piece at the passed parameters.
   *
   * @param[in]         x             The x coordinate to retrieve from
   * @param[in]         y             The y coordinate to retrieve from
   * @return            Chess_Piece pointer (pointer because can be null)
   */
  std::shared_ptr<Chess_Piece> get_chess_piece (size_t x, size_t y);

  /**
   * Transform the pawn by replacing the Pawn representation
   * with the new representation that the user chooses.
   *
   * @param[in]         piece           Transform_Chess_Piece reference
   */
  void transform (Chess_Piece & piece);

  /**
   * Set the chess piece to the inputted parameters.
   *
   * @param[in]         x               The new x-position
   * @param[in]         y               The new y-position
   * @param[in]         piece           Chess_Piece reference
   */
  void set_chess_piece(size_t x, size_t y, Chess_Piece & piece);

  /**
   * Build the chess board such that it represents the bnoard
   * at the beginning of the game.
   */
  void build_board(void);

protected:
  /*************
   * Attributes
   **************/
   /// Representation of the Chess_Board: two dimensional array.
  std::array<std::array<std::shared_ptr<Chess_Piece>, 8>, 8> board_;
};


#endif   // !defined _ARRAY_CHESS_BOARD_H_