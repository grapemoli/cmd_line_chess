// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Movement_Strategy.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Array_Movement_Strategy.h"
#include "Array_Chess_Board.h"
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
// Array_Movement_Strategy (Chess_Board &)
//
Array_Movement_Strategy::Array_Movement_Strategy(Chess_Board & board)
  :Movement_Validation_Strategy(board)
{}


//
// ~Array_Movement_Strategy ()
//
Array_Movement_Strategy::~Array_Movement_Strategy()
{}



/*
  Movement Methods
*/
//
// check_pawn_movement (size_t, size_t, Chess_Piece &)
//
Array_Movement_Strategy::check_pawn_movement(size_t x, size_t y, Chess_Piece& piece)
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
  if (this->is_white_ == true && y == this->y_ - 1)
  {
    return true;
  }

  if (this->is_white_ == false && y == this->y_ + 1)
  {
    return true;
  }

  // A pawn that eats other pieces can move forward diagonally.
  if (this->is_white_ == true && y == this->y_ - 1)
  {
    if (x == this->x_ - 1 || x == this->x_ + 1)
    {
      if (this->is_collide(x, y, board) == true)
      {
        return true;
      }
    }
  }

  if (this->is_white_ == false && y == this->y_ + 1)
  {
    if (x == this->x_ - 1 || x == this->x_ + 1)
    {
      if (this->is_collide(x, y, board) == true)
      {
        return true;
      }
    }
  }

  // If any of the above is not true, then this move must be invalid.
  return false;
}