// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Movement_Strategy.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Array_Movement_Strategy.h"
#include "Game_Over_Visitor.h"
#include "Chess_Piece.h"
#include "Pawn.h"
#include "Chess_Board.h"
//#include "Rook.h"
//#include "Bishop.h"
#include "Queen.h"
//#include "King.h"
//#include "Knight.h"


/*
  Constructors & Destructors
*/
//
// Array_Movement_Strategy ()
//
Array_Movement_Strategy::Array_Movement_Strategy(void)
  :Movement_Validation_Strategy()
{}


//
// ~Array_Movement_Strategy ()
//
Array_Movement_Strategy::~Array_Movement_Strategy(void)
{}



/*
  Movement Methods
*/
//
// check_pawn_movement (size_t, size_t, Chess_Piece &, Chess_Board & board)
//
const bool Array_Movement_Strategy::check_pawn_movement(size_t x, size_t y, Chess_Piece & piece, Chess_Board & board)
{
  // Take advantage of C++ return behavior by first checking for 
  // border collision.
  if (x > 7 || y > 7)
  {
    return false;
  }

  // A pawn that does not eat other pieces can only move forward.
  // White pawns' 'forward movement' result in decrementing y-coordinates,
  // while black pawns' 'forward movement' result in incrementing 
  // y-coordinates.
  if (piece.is_white() == true && y == piece.get_y() - 1 && x == piece.get_x())   // White
  {
    return true;
  }

  if (piece.is_white() == false && y == piece.get_y() + 1 && x == piece.get_x())  // Black
  {
    return true;
  }

  // A pawn that eats other pieces can move forward diagonally.
  if (piece.is_white() == true && y == piece.get_y() - 1)   // White
  {
    if (x == piece.get_x() - 1 || x == piece.get_x() + 1)
    {
      if (this->is_collide(x, y, piece, board) == true)
      {
        return true;
      }
    }
  }

  if (piece.is_white() == false && y == piece.get_y()  + 1)  // Black
  {
    if (x == piece.get_x() || x == piece.get_x() + 1)
    {
      if (this->is_collide(x, y, piece, board) == true)
      {
        return true;
      }
    }
  }

  // If any of the above is not true, then this move must be invalid.
  return false;
}


//
// check_queen_movement (size_t, size_t, Chess_Piece &, Chess_Board &)
//
const bool Array_Movement_Strategy::check_queen_movement(size_t x, size_t y, Chess_Piece & piece, Chess_Board & board)
{
  const int x_displacement = piece.get_x() - x;
  const int y_displacement = piece.get_y() - y;

  // Check that the movement is not outside of the board's bounds.
  if (x > 7 || y > 7)
  {
    return false;
  }

  // Check that the movement is not the same placement currently.
  if (piece.get_x() == x && piece.get_y() == y)
  {
    return false;
  }

  // A queen can move in any direction forwards or backwards.
  if (piece.get_x() == x && piece.get_y() != y)
  {
    if (this->jump_over(x, y, piece, board) == false)
    {
      return true;
    }
  }

  if (piece.get_y() == y && piece.get_x() != x)
  {
    if (this->jump_over(x, y, piece, board) == false)
    {
      return true;
    }
  }

  // A queen can move in any direction diagonally. When moving diagonally, 
  // dx and dy will both be the same displacement as one another.
  if (std::abs(x_displacement) == std::abs(y_displacement))
  {
    if (this->jump_over(x, y, piece, board) == false)
    {
      return true;
    }
  }

  // If none of the above are true, then must be false.
  return false;
}



/*
  Helper Methods
*/
//
// jump_over (size_t, size_t, Chess_Piece &, Chess_Board &)
//
const bool Array_Movement_Strategy::jump_over(size_t x, size_t y, Chess_Piece & piece, Chess_Board & board)
{
  // Check that there are no pieces in between the path of movement and 
  // the final destination (does not include final destination, 
  // i.e., collisions).
  int dx = piece.get_x() - x;  
  int dy = piece.get_y() - y;  

  const int x_direction = (dx == 0 ? 0 : dx/std::abs(dx));
  const int y_direction = (dy == 0 ? 0 : dy/std::abs(dy));

  size_t x_index;
  size_t y_index;

  // If there is no change in movement, then the piece must have not jumped
  // over any piece.
  if (dx == 0 && dy == 0)
  {
    return false;
  }

  while (dx != 0 && dy != 0)
  {
    // Break if at the final position.
    if (dx == 0 && dy == 0)
    {
      // Do not check the final position.
      // If there is no nullptr up until this point, then the
      // piece must have not jumped over anything.
      return false;
      break;
    }

    // Calculate current index.
    x_index = piece.get_x() + dx;
    y_index = piece.get_y() + dy;

    // Check that the piece is a nullptr.
    std::shared_ptr<Chess_Piece> temp = board.get_chess_piece(x_index, y_index);

    // If the piece is not a nullptr, then the passed arguement must have 
    // jumped over a piece.
    if (temp.get() != nullptr)
    {
      return true;
      break;
    }

    // Increment the displacements.
    dx = (dx != 0 ? dx - x_direction : 0);
    dy = (dy != 0 ? dy - y_direction : 0);
  }

  // If the while loop runs successfully, then the piece must have not
  // jumped over any piece.
  return false;
}