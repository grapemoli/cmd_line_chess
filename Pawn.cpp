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
#include "Queen.h"


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
{}



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
      // Set the pawn position on the board -and- the property.
      board.set_chess_piece(x, y, *this);
      this->x_ = x;
      this->y_ = y;

      // Check if the pawn can transform.
      this->transform(board);
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


//
// transform (Chess_Board &)
//
void Pawn::transform (Chess_Board & board)
{
  // A white pawn can transform if it reaches the end of the board (y = 0).
  // A black pawn can transform if it reaches the end of the board (y = 7).
  bool can_transform = false;
  if (this->is_white_ == true && this->y_ == 0)
  {
    can_transform = true;
  }
  else if (this->is_white_ == false && this->y_ == 7)
  {
    can_transform = true;
  }

  // If appropiate, prompt the user for what they would like to change
  // the Pawn into.
  if (can_transform == true)
  {
    std::string user_input;
    std::shared_ptr<Transform_Chess_Piece> new_piece = nullptr;

    while (user_input != "QUIT")
    {
      user_input.clear();
      std::cout << "\nPawn to...\n1. Queen\n2. Rook\n3. Bishop\n4. Knight\nYour choice ('QUIT' to keep the same): ";
      std::cin >> user_input;

      // Build the appropiate piece based on the user input.
      // Build the user's request.
      if (user_input == "1")
      {
        // Make a queen.
        new_piece = std::make_shared<Queen>(*this);
        break;
      }
      else if (user_input == "2")
      {
        // Make a rook.
        //new_piece = std::make_shared<Rook>(*this);
        break;
      }
      else if (user_input == "3")
      {
        // Make a bishop.
        //new_piece = std::make_shared<Bishop>(*this);
        break;
      }
      else if (user_input == "4")
      {
        // Make a knight.
        //new_piece = std::make_shared<Knight>(*this);
        break;
      }
      else if (user_input != "QUIT") 
      {
        std::cout << "\nInvalid input, try again.";
      }
    }

    // Set the piece on the chess board.
    if (new_piece != nullptr)
    {
      board.transform(new_piece);
    }
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
  list_valid_moves (Chess_Board &)
*/
void Pawn::list_valid_moves(Chess_Board & board)
{
  // White y_ decrements, while black y_ increments for "forward" movement.
  // Take advantage of true <=> 1 conversion to "calculate" the direction that this
  // piece needs to move in (white moves -y, black moves +y).
  const int y_movement = 1 - (2 * this->is_white_);

  // These one-liners look complex, but they are simple in nature: *only* print a
  // coordinate if it is a valid coordindate.
  // Typical Movement: (x, y -/+ 1)
  this->movement_strategy_.check_pawn_movement(this->x_, this->y_ + y_movement, *this, board) ? std::cout << "\n" << "- " << this->alpha_[this->x_] << this->y_ + y_movement : std::cout << "";

  // Pawn Eating Movement, pt. 1: (x + 1, y -/+ 1)
  this->movement_strategy_.check_pawn_movement(this->x_ + 1, this->y_ + y_movement, *this, board) ? std::cout << "\n" << "- " << this->alpha_[this->x_ + 1] << this->y_ + y_movement : std::cout << "";

  // Pawn Eating Movement, pt. 2: (x - 1, y -/+ 1)
  this->movement_strategy_.check_pawn_movement(this->x_ - 1, this->y_ + y_movement, *this, board) ? std::cout << "\n" << "- " << this->alpha_[this->x_ - 1] << this->y_ + y_movement : std::cout << "";
}
