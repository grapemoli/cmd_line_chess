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
class Transform_Chess_Piece;


/**
 * @class Array_Chess_Board
 *
 * Full implementation of Chess_Board, representing the board as a 
 * two-dimensional array. In this representation: x = arr[i].length, 
 * while y = arr.length. To access appropiately: arr[y][x].
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
  std::shared_ptr<Chess_Piece> get_chess_piece (size_t x, size_t y);

  /**
   * Transform the pawn by replacing the Pawn representation
   * with the new representation that the user chooses.
   *
   * @param[in]         piece           Transform_Chess_Piece pointer
   * @exception         invalid_set     The argument is null
   */
  void transform (std::shared_ptr<Transform_Chess_Piece> piece);

  /**
   * Set the chess piece to the inputted parameters.
   *
   * @param[in]         x               The new x-position
   * @param[in]         y               The new y-position
   * @param[in]         piece           Chess_Piece reference
   * @exception         invalid_set     The argument pointer differs from the pointer
   *                                    stored in the chess board
   */
  void set_chess_piece(size_t x, size_t y, Chess_Piece & piece);

  /**
   * Build the chess board such that it represents the bnoard
   * at the beginning of the game.
   */
  void build_board(void);

protected:
  /*************
   * Helper Methods
   **************/
  /**
   * Prompt the user for a coordinate until the input fits
   * requirements.
   *
   * @param[in]         prompt          What to prompt the user
   * @return            size_t of the user input
   * @exception         quit()          User inputs 'QUIT'
   */
  size_t get_coordinate (std::string prompt);

  /*************
   * Attributes
   **************/
   /// Representation of the Chess_Board: two dimensional array.
  std::array<std::array<std::shared_ptr<Chess_Piece>, 8>, 8> board_;

  /// Alphabet-to-Number conversion.
  std::string alpha_ = "ABDCEFGH";
};


#endif   // !defined _ARRAY_CHESS_BOARD_H_