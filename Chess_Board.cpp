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
  movement_strategy_(strategy),
  conversion_strategy_(nullptr)
{
  conversion_strategy_ = std::make_shared<String_To_Coordinates_Strategy>();
}


//
// Chess_Board (Chess_Board & )
//
Chess_Board::Chess_Board (Chess_Board & board)
  :moves_(board.moves_),
  size_(SIZE),
  movement_strategy_(board.movement_strategy_),
  conversion_strategy_(board.conversion_strategy_)
{}


//
// ~Chess_Board ()
//
Chess_Board::~Chess_Board(void)
{}