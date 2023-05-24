// -*- C++ -*-
//==============================================================================
/**
 * File: King.h
 * By: Grace Nguyen
 */
 //==============================================================================


#pragma once
#ifndef _KING_H_
#define _KING_H_

#include "Chess_Piece.h"

// Forward Declarations.
class Chess_Board;
class Chess_Piece_Visitor;


/**
 * @class King
 *
 * A full implementation of the Chess_Piece class. All
 * kings have set positions based on their color.
 */
class King : public Chess_Piece
{
public:
  /**
   * Default constructer.
   *
   * @param[in]         is_white      Boolean representation of the color
   * @param[in]         x             The x position
   * @param[in]         strategy      Movement_Validation_Strategy reference
   */
  King (bool is_white, size_t x, Movement_Validation_Strategy& strategy);

  /// Destructor.
  ~King (void);

  /**
   * Check if the move is valid and if it collides with any other piece.
   * If both passes are true, then set the new position and push to the
   * actions stack.
   *
   * @param[in]         x             New x position
   * @param[in]         y             New y position
   * @param[in]         board         The Chess_Board instance
   */
  void execute(size_t x, size_t y, Chess_Board& board);

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   *
   * @param[in]         board         Chess_Board reference
   */
  void list_valid_moves(Chess_Board& board);

  /**
   * Enable double dispatching. Used for collision detection.
   *
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  void accept(Chess_Piece_Visitor& v);

private:
  /*************
   * Helper Methods
   **************/
   /**
    * Check if the Pawn can transform (i.e., reaches the end of the board),
    * and prompt the user for the piece they wish to transform the pawn
    * into. Then, transform the pawn with the new piece.
    *
    * @param[in]         board         Chess_Board reference
    */
  void transform(Chess_Board& board);
};


#endif   // !defined _KING_H_