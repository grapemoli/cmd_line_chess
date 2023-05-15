// -*- C++ -*-
//==============================================================================
/**
 * File: Pawn.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Piece.h"
#include "Chess_Board.h"
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
  return true;
}



/*
  accept (Chess_Piece_Visitor)
*/
void Pawn::accept(void)
{

}



/*
  Misc. Methods
*/
//
// list_moves ()
//
void Pawn::list_valid_moves(void)
{
  
}