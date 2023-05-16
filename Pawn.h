// -*- C++ -*-
//==============================================================================
/**
 * File: Pawn.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _PAWN_H_
#define _PAWN_H_

#include "Chess_Piece.h"

// Forward Declarations.
class Chess_Board;
class Chess_Piece_Visitor;


/**
 * @class Pawn
 * 
 * A full implementation of the Chess_Piece class. All 
 * pawns will start in varying location along the second-to-last
 * row of Pawns.
 */
class Pawn : public Chess_Piece
{
public:
  /**
   * Default constructer.
   * 
   * @param[in]         is_white      Boolean representation of the color
   * @param[in]         x             The x position
   * @param[in]         strategy      Movement_Validation_Strategy reference
   */
  Pawn (bool is_white, size_t x, Movement_Validation_Strategy & strategy);

  /// Destructor.
  ~Pawn (void);

  /**
   * Check if the move is valid and if it collides with any other piece.
   * If both passes are true, then set the new position and push to the
   * actions stack.
   * 
   * @param[in]         x             New x position
   * @param[in]         y             New y position
   * @param[in]         board         The Chess_Board instance
   */
  void execute (size_t x, size_t y, Chess_Board & board);

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   */
  void list_valid_moves (void);

  /**
   * Enable double dispatching. Used for collision detection.
   *
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  void accept (Chess_Piece_Visitor & v);
};


#endif   // !defined _PAWN_H_