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
   * @param[in]         color         Boolean representation of the color
   * @param[in]         x             The x position
   */
  Pawn (bool color, size_t x);

  /// Destructor.
  ~Pawn (void);

  /**
   * Check if the move is valid and if it collides with any other piece.
   * If both passes are true, then set the new position and push to the
   * actions stack.
   * 
   * @param[in]         board         The Chess_Board instance
   */
   void execute (void);                                   /// TODO: add in BOARD

   /**
    * Checks if the movement of the chess piece will cause
    * a collision with any other piece.
    * 
    * @param[in]          board         The Chess_Board instance
    * @retvalue           True          There is a collision
    * @retvalue           False         There is no collision
    */
    bool is_collide (void);                                         /// TODO: add in BOARD

   /**
    * List the possible moves that can be made, taking into
    * account edge collision. Unique to each specific piece.
    */
    virtual void list_moves (void) = 0;

   /**
    * Check if the movement is valid. Unique to each specific
    * piece.
    * 
    * @param[in]          x             The to-be x placement
    * @param[in]          y             The to-be y placement
    * @retvalue           True          Valid
    * @retvalue           False         Not valid
    */
    bool is_valid (size_t x, size_t y);
};


#endif   // !defined _PAWN_H_