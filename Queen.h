// -*- C++ -*-
//==============================================================================
/**
 * File: Queen.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _QUEEN_CHESS_PIECE_H_
#define _QUEEN_CHESS_PIECE_H_

#include "Transform_Chess_Piece.h"

// Forward Declarations.
class Chess_Board;
class Chess_Piece_Visitor;
class Movement_Validation_Strategy;
class Pawn;


/**
 * @class Queen
 * 
 * A full implementation of the Transform_Chess_Piece, allowing 
 * for Pawns to transform into a Queen if applicable.
 */
class Queen: public Transform_Chess_Piece
{
public:
   /**
    * Overloaded constructor.
    * 
    * @param[in]          is_white      Boolean to determine color
    * @param[in]          str           String representation of the Chess Piece
    * @param[in]          strategy      Movement_Validation_Strategy reference
    */
   Queen (bool is_white, Movement_Validation_Strategy & strategy);

  /**
   * Copy Constructor for pieces that Pawns can turn into will take a 
   * Pawn reference and copy over the nessecary information. Deep copy.
   * 
   * @param[in]         piece         Pawn reference
   */
  Queen (Pawn & piece);

  /// Destructor.
  ~Queen (void);

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
  void execute (size_t x, size_t y, Chess_Board & board);

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   * 
   * @param[in]         board         Reference to a Chess_Board instance
   */
  void list_valid_moves (Chess_Board & board);

  /**
   * Enable double dispatching. Used for collision detection.
   * 
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  void accept (Chess_Piece_Visitor & v);
};


#endif   // !defined _QUEEN_CHESS_PIECE_H_