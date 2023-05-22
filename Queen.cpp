// -*- C++ -*-
//==============================================================================
/**
 * File: Queen.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Queen.h"
#include "Chess_Piece_Visitor.h"
#include "Pawn.h"
#include "Movement_Validation_Strategy.h"
#include "Chess_Board.h"


/*
  Constructors & Destructors
*/
//
// Queen (bool, Movement_Validation_Strategy &)
//
Queen::Queen (bool is_white, Movement_Validation_Strategy & strategy)
  :Transform_Chess_Piece(is_white, 4, "~Q~", strategy)
{
  // All Queens are set on x = 4.
  if (this->is_white_ == true)
  {
    this->string_representation_ = "-Q-";
  }
}


//
// Queen (Pawn &)
//
Queen::Queen(Pawn & piece)
  :Transform_Chess_Piece(piece)
{}


//
// ~Queen ()
//
Queen::~Queen(void)
{}



/*
  Movement Methods
*/
//
// execute (size_t, size_t, Chess_Board &)
//
void Queen::execute(size_t x, size_t y, Chess_Board & board)
{
  const bool valid_move = this->movement_strategy_.check_queen_movement(x, y, *this, board);
  try
  {
    if (valid_move == true)
    {
      const bool is_collide = this->movement_strategy_.is_collide(x, y, *this, board);

      // Check that collisions are valid (eating the other team).
      // Set the queen position on the board -and- the property.
      board.set_chess_piece(x, y, *this);
      this->x_ = x;
      this->y_ = y;
    }
    else
    {
      throw invalid_move();
    }
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    throw game_over();
  }
  catch (Movement_Validation_Strategy::invalid_move& e)
  {
    throw invalid_move();
  }
}


//
// list_valid_moves (Chess_Board &)
//
void Queen::list_valid_moves(Chess_Board& board)
{
  // Print all valid moves.
}



/*
  accept (Chess_Piece_Visitor &)
*/
//
// accept (Chess_Piece_Visitor &)
//
void Queen::accept(Chess_Piece_Visitor & v)
{
  v.visit(*this);
}