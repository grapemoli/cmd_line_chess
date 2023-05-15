// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.cpp
 * By: Grace Nguyen
 */
//==============================================================================

 
#include "Chess_Piece.h"


/*
  Constructor & Destructor
*/
//
// Chess_Piece (bool, size_t, size_t)
//
Chess_Piece::Chess_Piece(bool color, size_t x, size_t y)
  :color_(color),
  x_(x),
  y_(y),
  actions_()
{}


//
// ~Chess_Piece ()
//
Chess_Piece::~Chess_Piece(void)
{
  // There is nothing to deallocate.
}


/*
  Movement Methods
*/
//
// is_collide (Chess_Board)
//
bool Chess_Piece::is_collide(void)
{
  return true;
}


//
// undo ()
//
void Chess_Piece::undo(void)
{
  std::array<int, 2> prev_pos = this->actions_.pop();
  this->x_ = prev_pos[0];
  this->y_ = prev_pos[1];
}