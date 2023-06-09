// -*- C++ -*-
//==============================================================================
/**
 * File: Movement_Validation_Strategy.cpp
 * By: Grace Nguyen
 */
//==============================================================================

#include "Chess_Board.h"
#include "Chess_Piece.h"
#include "Chess_Piece_Visitor.h"
#include "Game_Over_Visitor.h"
#include "Movement_Validation_Strategy.h"


/*
  Constructors & Destructors
*/
//
// Movement_Validation_Strategy ()
//
Movement_Validation_Strategy::Movement_Validation_Strategy(void)
  :collision_visitor_(Game_Over_Visitor())
{}


//
// ~Movement_Validation_Strategy ()
//
Movement_Validation_Strategy::~Movement_Validation_Strategy(void)
{}



/*
  is_collide (size_t, size_t, Chess_Piece &, Chess_Board &)
*/
const bool Movement_Validation_Strategy::is_collide(size_t x, size_t y, Chess_Piece & piece, Chess_Board & board)
{
  std::shared_ptr<Chess_Piece> occupied_piece = board.get_chess_piece(x, y);

  // If there is no piece at the coordinates, there is no collision. Else, check
  // whether the taken piece is a king or not (i.e., check for game over).
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
      if (occupied_piece->is_white() != piece.is_white())
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