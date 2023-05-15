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
Chess_Piece::Chess_Piece(bool is_white, size_t x, size_t y)
  :is_white_(is_white),
  x_(x),
  y_(y),
  actions_()
{}


//
// ~Chess_Piece ()
//
Chess_Piece::~Chess_Piece() 
{}



/*
  Movement Methods
*/
//
// is_collide (size_t, size_t, Chess_Board)
//
bool Chess_Piece::is_collide(size_t x, size_t y)
{
  /*
  if there is a thing on the chess_board at that place:
  1. accept()
  2. if king, game over! return game_over
  3. else, eat the piece.
  */
  return true;
}


//
// undo ()
//
void Chess_Piece::undo(void)
{
  std::array<int, 2> prev_pos = this->actions_.top();
  this->actions_.pop();
  this->x_ = prev_pos[0];
  this->y_ = prev_pos[1];
}