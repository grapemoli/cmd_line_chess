// -*- C++ -*-
//==============================================================================
/**
 * File: Pawn.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Piece.h"
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
// execute (size_t x, size_t y, Chess_Board)
//
void Pawn::execute(size_t x, size_t y)
{
  
}


//
// is_valid (size_t, size_t)
//
bool Pawn::is_valid(size_t x, size_t y)
{
  return true;
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