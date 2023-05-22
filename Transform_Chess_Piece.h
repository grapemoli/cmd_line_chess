// -*- C++ -*-
//==============================================================================
/**
 * File: Transform_Chess_Piece.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _TRANSFORM_CHESS_PIECE_H_
#define _TRANSFORM_CHESS_PIECE_H_

#include "Chess_Piece.h"

// Forward Declarations.
class Chess_Board;
class Chess_Piece_Visitor;
class Movement_Validation_Strategy;
class Pawn;


/**
 * @class Transform_Chess_Piece
 * 
 * An abstract class made by the template method, to ensure that 
 * all chess pieces that Pawns can transform into have the appropiate
 * methods to allow such behavior.
 */
class Transform_Chess_Piece: public Chess_Piece
{
public:
  /**
   * Default constructor.
   * 
   * @param[in]         is_white      Boolean to determine color
   * @param[in]         strategy      Movement_Validation_Strategy reference
   */
   Transform_Chess_Piece (bool is_white, Movement_Validation_Strategy & strategy);

   /**
    * Overloaded constructor.
    * 
    * @param[in]          is_white      Boolean to determine color
    * @param[in]          x             The x coordinate
    * @param[in]          strategy      Movement_Validation_Strategy reference
    */
   Transform_Chess_Piece (bool is_white, size_t x, Movement_Validation_Strategy & strategy);

  /**
   * Copy Constructor for pieces that Pawns can turn into will take a 
   * Pawn reference and copy over the nessecary information. Deep copy.
   * 
   * @param[in]         piece         Pawn reference
   */
  Transform_Chess_Piece (Pawn & piece);

  /// Destructor.
  virtual ~Transform_Chess_Piece (void);

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
  virtual void execute (size_t x, size_t y, Chess_Board & board) = 0;

  /**
   * List the possible moves that can be made, taking into
   * account edge collision. Unique to each specific piece.
   * 
   * @param[in]         board         Reference to a Chess_Board instance
   */
  virtual void list_valid_moves (Chess_Board & board) = 0;

  /**
   * Enable double dispatching. Used for collision detection.
   * 
   * @param[in]         v             Chess_Piece_Visitor instance
   */
  virtual void accept (Chess_Piece_Visitor & v) = 0;
};


#endif   // !defined _TRANSFORM_CHESS_PIECE_H_