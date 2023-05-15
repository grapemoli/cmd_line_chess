// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Piece.h"
#include "Chess_Board.h"


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
// is_collide (size_t, size_t, Chess_Board &)
//
const bool Chess_Piece::is_collide(size_t x, size_t y, Chess_Board & board)
{
  std::shared_ptr<Chess_Piece> occupied_piece = board.get_chess_piece(x, y);
  if (occupied_piece == nullptr)
  {
    return false;
  }
  else
  {
    // Check if king.
    // occupied_piece.accept(visitor);
    // if (visitor.get_result() == true) { throw game_over(); }
    // else { return true; }
    return true;
  }
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