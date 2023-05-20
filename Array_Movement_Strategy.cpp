// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Movement_Strategy.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Array_Movement_Strategy.h"
#include "Game_Over_Visitor.h"
#include "Chess_Piece.h"
#include "Pawn.h"
//#include "Rook.h"
//#include "Bishop.h"
//#include "Queen.h"
//#include "King.h"
//#include "Knight.h"


/*
  Constructors & Destructors
*/
//
// Array_Movement_Strategy ()
//
Array_Movement_Strategy::Array_Movement_Strategy(void)
  :Movement_Validation_Strategy()
{}


//
// ~Array_Movement_Strategy ()
//
Array_Movement_Strategy::~Array_Movement_Strategy(void)
{}



/*
  Movement Methods
*/
//
// check_pawn_movement (size_t, size_t, Chess_Piece &, Chess_Board & board)
//
const bool Array_Movement_Strategy::check_pawn_movement(size_t x, size_t y, Chess_Piece & piece, Chess_Board & board)
{
  // Take advantage of C++ return behavior by first checking for 
  // border collision.
  if (x > 7 || y > 7)
  {
    return false;
  }

  // A pawn that does not eat other pieces can only move forward.
  // White pawns' 'forward movement' result in decrementing y-coordinates,
  // while black pawns' 'forward movement' result in incrementing 
  // y-coordinates.
  if (piece.is_white() == true && y == piece.get_y() - 1 && x == piece.get_x())   // White
  {
    return true;
  }

  if (piece.is_white() == false && y == piece.get_y() + 1 && x == piece.get_x())  // Black
  {
    return true;
  }

  // A pawn that eats other pieces can move forward diagonally.
  if (piece.is_white() == true && y == piece.get_y() - 1)   // White
  {
    if (x == piece.get_x() - 1 || x == piece.get_x() + 1)
    {
      if (this->is_collide(x, y, piece, board) == true)
      {
        return true;
      }
    }
  }

  if (piece.is_white() == false && y == piece.get_y()  + 1)  // Black
  {
    if (x == piece.get_x() || x == piece.get_x() + 1)
    {
      if (this->is_collide(x, y, piece, board) == true)
      {
        return true;
      }
    }
  }

  // If any of the above is not true, then this move must be invalid.
  return false;
}