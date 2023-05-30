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
  Movement Methods
*/
//
// execute (size_t, size_t, Chess_Board &)
//
void King::execute(size_t x, size_t y, Chess_Board& board)
{
  const bool valid_move = this->movement_strategy_.check_king_movement(x, y, *this, board);
  try
  {
    if (valid_move == true)
    {
      // Set the king position on the board -and- the property.
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
  // Kings can move in the square around them.
  // Check all variations where x is incremented.
  try
  {
    this->movement_strategy_.check_king_movement(this->x_ + 1, this->y_, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_ : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_;
  }

  try
  {
    this->movement_strategy_.check_king_movement(this->x_ + 1, this->y_ + 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_ + 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_ + 1;
  }

  try
  {
      this->movement_strategy_.check_king_movement(this->x_ + 1, this->y_ - 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_ - 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ + 1] << this->y_ - 1;

  }

  // Check all remaining variations where y is incremented.
  try
  {
    this->movement_strategy_.check_king_movement(this->x_, this->y_ + 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_] << this->y_ + 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_] << this->y_ + 1;
  }

  try
  {
    this->movement_strategy_.check_king_movement(this->x_ - 1, this->y_ + 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_ + 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_ + 1;
  }

  // Check all remaining variations where x is decremented.
  try
  {
    this->movement_strategy_.check_king_movement(this->x_ - 1, this->y_, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_ : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_;
  }

  try
  {
    this->movement_strategy_.check_king_movement(this->x_ - 1, this->y_ - 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_ - 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_ - 1] << this->y_ - 1;
  }

  // Check the remaining variations where y is decremented.
  try
  {
    this->movement_strategy_.check_king_movement(this->x_, this->y_ - 1, *this, board) ? std::cout << "\n" << "-" << this->alpha_[this->x_] << this->y_ - 1 : std::cout << "";
  }
  catch (Movement_Validation_Strategy::game_over & e)
  {
    std::cout << "\n" << "-" << this->alpha_[this->x_] << this->y_ - 1;
  }
}



