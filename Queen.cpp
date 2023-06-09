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
Queen::Queen(bool is_white, Movement_Validation_Strategy & strategy)
  :Transform_Chess_Piece(is_white, 3, "~Q~", strategy)
{
  // All Queens are set on x = 3.
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
{
  // Currently, the string representation is the Pawn's, 
  // so change the string representation to be the Queen's.
  if (this->is_white_ == true)
  {
    this->string_representation_ = "-Q-";
  }
  else
  {
    this->string_representation_ = "~Q~";
  }
}


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
  catch (Movement_Validation_Strategy::invalid_move & e)
  {
    throw invalid_move();
  }
}


//
// list_valid_moves (Chess_Board &)
//
void Queen::list_valid_moves(Chess_Board& board)
{
  // Print all valid horizontal moves.
  for (int x = 0; x < this->x_; x++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, this->y_, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << this->y_ : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << this->y_;
    }
  }

  for (int x = this->x_; x < 8; x++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, this->y_, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << this->y_ : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << this->y_;
    }
  }

  // Print all valid vertical moves.
  for (int y = 0; y < this->y_; y++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(this->x_, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[this->x_] << y;
    }
  }

  for (int y = this->y_; y < 8; y++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(this->x_, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
       std::cout << "\n" << "!! " << this->alpha_[this->x_] << y;
    }
  }

  // Print all valid diagonal moves.
  // Increasing x and y.
  for (int x = this->x_, y = this->y_; x < 8, y < 8; x++, y++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << y;
    }
  }

  // Increasing x, decreasing y.
  for (int x = this->x_, y = this->y_; x < 8, y > 0; x++, y--)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << y;
    }
  }

  // Decreasing x, increasing y.
  for (int x = this->x_, y = this->y_; x > 0, y < 8; x--, y++)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << y;
    }
  }

  // Decreasing x, decreasing y.
  for (int x = this->x_, y = this->y_; x > 0, y > 0; x--, y--)
  {
    try
    {
      this->movement_strategy_.check_queen_movement(x, y, *this, board) ? std::cout << "\n" << "-" << this->alpha_[x] << y : std::cout << "";
    }
    catch (Movement_Validation_Strategy::game_over & e)
    {
      std::cout << "\n" << "!! " << this->alpha_[x] << y;
    }
  }
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