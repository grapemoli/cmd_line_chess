// -*- C++ -*-
//==============================================================================
/**
 * File: Pawn.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Chess_Board.h"
#include "Movement_Validation_Strategy.h"
#include "Game_Over_Visitor.h"
#include "Pawn.h"


/*
  Constructor & Destructor
*/
//
// Pawn (bool, size_t, Movement_Validation_Strategy &)
//
Pawn::Pawn(bool is_white, size_t x, Movement_Validation_Strategy & strategy)
  :Chess_Piece(is_white, x, 1, "~P~", strategy)
{
  // Pawns are initialized at y = 1 if the Pawn is black, and 
  // initialized at y = 6 if the Pawn is white.
  if (is_white == true)
  {
    this->y_ = 6;
    this->string_representation_ = "-P-";
  }
}


//
// Pawn (Pawn &)
//
Pawn::Pawn(Pawn & piece)
  :Chess_Piece(piece)
{}


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
  // Use the strategy to verify the validity of the move. 
  // If the move is invalid, then throw the invalid_move exception.
  // If the game is over, then throw game_over exception.
  try 
  {
    const bool is_valid = this->movement_strategy_.check_pawn_movement(x, y, *this, board);

    if (is_valid == true)
    {
      // execute as needed.
      board.set_chess_piece(x, y, *this);
      this->x_ = y;
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
}



/*
  accept (Chess_Piece_Visitor &)
*/
void Pawn::accept(Chess_Piece_Visitor & v)
{
  v.visit(*this);
}



/*
  list_valid_moves ()
*/
void Pawn::list_valid_moves(void)
{
  // For each possible move, check that the coordinate
  // is valid!
}