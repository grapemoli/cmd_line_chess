// -*- C++ -*-
//==============================================================================
/**
 * File: Pawn.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Board.h"
#include "Game_Over_Visitor.h"
#include "Pawn.h"


/*
  Constructor & Destructor
*/
//
// Pawn (bool, size_t)
//
Pawn::Pawn(bool is_white, size_t x)
  :Chess_Piece(is_white, x, 1)
{
  // Pawns are initialized at y = 1 if the Pawn is black, and 
  // initialized at y = 6 if the Pawn is white.
  if (is_white == true)
  {
    this->y_ = 6;
  }
}


//
// ~Pawn ()
//
Pawn::~Pawn(void)
{
  // There is nothing to deallocate.
}



/*
  Movement Execution Methods
*/
// 
// execute (size_t x, size_t y, Chess_Board &)
//
void Pawn::execute(size_t x, size_t y, Chess_Board & board)
{
  std::cout << "x: " << x << "\ny: " << y << "\n";
}


//
// is_valid (size_t, size_t, Chess_Board &)
//
const bool Pawn::is_valid(size_t x, size_t y, Chess_Board & board)
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
  // x-coordinates.
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



/*
  accept (Chess_Piece_Visitor &)
*/
void Pawn::accept(Chess_Piece_Visitor & v)
{
  v.visit(*this);
}



/*
  Misc. Methods
*/
//
// list_moves ()
//
void Pawn::list_valid_moves(void)
{
  // For each possible move, check that the coordinate
  // is valid!
}