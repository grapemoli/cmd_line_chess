// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Piece.h"
#include "Chess_Board.h"
#include "Game_Over_Visitor.h"
#include "Movement_Validation_Strategy.h"


/*
  Constructor & Destructor
*/
//
// Chess_Piece (bool, size_t, size_t, Movement_Validation_Strategy &)
//
Chess_Piece::Chess_Piece(bool is_white, size_t x, size_t y, Movement_Validation_Strategy & strategy)
  :is_white_(is_white),
  x_(x),
  y_(y),
  actions_(),
  movement_strategy_(strategy)
{}


//
// ~Chess_Piece ()
//
Chess_Piece::~Chess_Piece() 
{}



/*
  undo ()
*/
void Chess_Piece::undo(void)
{
  std::array<int, 2> prev_pos = this->actions_.top();
  this->actions_.pop();
  this->x_ = prev_pos[0];
  this->y_ = prev_pos[1];
}



/*
  Setter Methods
*/
//
// set_x (size_t)
//
void Chess_Piece::set_x(size_t x)
{
  this->x_ = x;
}


//
// set_y (size_t)
//
void Chess_Piece::set_y(size_t y)
{
  this->y_ = y;
}