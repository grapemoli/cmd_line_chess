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
  
  // If there is no collision, return false. Else, check for if the taken piece
  // if a king (i.e., checking for game over).
  if (occupied_piece == nullptr)
  {
    return false;
  }
  else
  {
    Game_Over_Visitor visitor;
    occupied_piece->accept(visitor);
    
    // Check if the taken piece is a king.
    if (visitor.get_result() == false)
    {
      // There is a collision, but the victim piece is not a king.
      return true;
    }
    else 
    { 
      // If the king being taken is of the opposing side, the game is over.
      if (occupied_piece->is_white() != this->is_white())
      {
        throw game_over();
      }
      else
      {
        // There is a king collision of the same color.
        return true;
      }
    }
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