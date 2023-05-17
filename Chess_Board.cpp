// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Board.h
 * By: Grace Nguyen
 */
 //==============================================================================

#define SIZE 8

#include "Chess_Piece.h"
#include "Movement_Validation_Strategy.h"
//#include "Transform_Chess_Piece.h"
#include "Pawn.h"
#include "Chess_Board.h"


/*
  Constructors & Destructors
*/
//
// Chess_Board (Movement_Validation_Strategy &)
//
Chess_Board::Chess_Board(Movement_Validation_Strategy & strategy)
  :moves_(),
  size_(SIZE),
  movement_strategy_(strategy)
{}


//
// Chess_Board (Chess_Board & )
//
Chess_Board::Chess_Board (Chess_Board & board)
  :moves_(board.moves_),
  size_(SIZE),
  movement_strategy_(board.movement_strategy_)
{}


//
// ~Chess_Board ()
//
Chess_Board::~Chess_Board(void)
{}



/*
  Helper Methods
*/
//
// to_size_t (std::string)
//
size_t Chess_Board::to_size_t(std::string input)
{
  size_t size_t_str;

  std::stringstream converter;
  converter.clear();
  converter.str("");

  converter << input;
  converter >> size_t_str;

  return size_t_str;
}