// -*- C++ -*-
//==============================================================================
/**
 * File: King.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "King.h"
#include "Chess_Board.h"
#include "Movement_Validation_Strategy.h"
#include "Chess_Piece_Visitor.h"
#include "Game_Over_Visitor.h"


/*
  Constructor & Destructor
*/
//
// King (bool, Movement_Validation_Strategy &)
//
King::King(bool is_white, Movement_Validation_Strategy & strategy)
  :Chess_Piece(is_white, 4, 0, "~K~", strategy)
{
  // All Kings are set on x = 4.
  if (this->is_white_ == true)
  {
    this->string_representation_ = "-K-";
    this->y_ = 7;
  }
}


//
// ~King ()
//
King::~King(void)
{}



/*
  Execution Methods
*/
//
// execute (size_t, size_t, Chess_Board &)
//
void King::execute(size_t x, size_t y, Chess_Board& board)
{
  // Go forward, as always.
}


//
// accept (Chess_Piece_Visitor & v)
//
void King::accept(Chess_Piece_Visitor & v)
{
  v.visit(*this);
}


//
// list_valid_moves (Chess_Board & board)
//
void King::list_valid_moves (Chess_Board & board)
{
  // List the valid moves.
}


