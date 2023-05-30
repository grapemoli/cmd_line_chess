// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Movement_Strategy.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _ARRAY_MOVEMENT_STRATEGY_H_
#define _ARRAY_MOVEMENT_STRATEGY_H_

#include "Movement_Validation_Strategy.h"
#include "Game_Over_Visitor.h"
#include <cmath>        // For absolute value.

// Forward Declarations.
class Chess_Board;
class Pawn;
class Queen;


/**
 * @class Array_Movement_Strategy
 * 
 * Full implementation of Movement_Validation_Strategy, which implements
 * (1) game over detection and (2) verifying the validity of movements for
 * array representations of a Chess Board.
 */
class Array_Movement_Strategy: public Movement_Validation_Strategy
{
public:
   /**
    * Default constructor.
    */
  Array_Movement_Strategy (void);

  /// Destructor.
  virtual ~Array_Movement_Strategy (void);

  /**
   * Check if the movement is valid for a pawn.
   * 
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  const bool check_pawn_movement (size_t x, size_t y, Chess_Piece & piece,Chess_Board & board);

  /**
   * Check if the movement is valid for a rook.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //const bool check_rook_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check if the movement is valid for a bishop.
   * piece.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //const bool check_bishop_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check if the movement is valid for a knight.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //const bool check_knight_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check if the movement is valid for a queen.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  const bool check_queen_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check if the movement is valid for a king.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  const bool check_king_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

private:
  /**********
  * Helper Methods
  ***********/
  /**
   * Check if the game is over (this is defined as the victim of the x-y coordinate is a
   * King. Uses the Game_Over_Visitor class.
   * 
   * @param[in]         x             The to-be x placement
   * @param[in]         y             The to-be y placement
   * @param[in]         board         The Chess_Board reference
   * @exception         game_over
   */
  void check_game_over (size_t x, size_t y, Chess_Board & board);

  /**
   * Check if there are any pieces in between the path of movement.
   * 
   * @param[in]         x             The new x coordinate
   * @param[in]         y             The new y coordinate
   * @param[in]         piece         Chess_Piece reference
   * @param[in]         board         Chess_Board reference
   * @retvalue          True          A piece is jumped over
   * @retvalue          False         A piece is not jumped over
   */
  const bool jump_over (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check that the collision is valid. 
   *
   * @param[in]         x             The new x coordinate
   * @param[in]         y             The new y coordinate
   * @param[in]         piece         Chess_Piee reference
   * @param[in]         board         Chess_Board reference
   * @retvalue          True          Collision occurs and is valid (or does not occur at all)
   * @retvalue          False         Collision occurs and is not valid
   */
  const bool valid_collision (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

private:
  // Game over stragegy.
  Game_Over_Visitor game_over_;
};


#endif   // !defined _ARRAY_MOVEMENT_STRATEGY_H_