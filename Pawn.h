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


// Forward Declarations.
class Chess_Piece;


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
   */
  Pawn (bool is_white, size_t x);

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
  void execute (size_t x, size_t y);                                   /// TODO: add in BOARD

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   */
  void list_valid_moves (void);

  /**
   * Check if the movement is valid. Unique to each specific
   * piece.
   * 
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  const bool is_valid (size_t x, size_t y);

  /**
   * Enable double dispatching. Used for collision detection.
   *
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  void accept (void);
};


#endif   // !defined _PAWN_H_