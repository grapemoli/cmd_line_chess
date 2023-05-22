// -*- C++ -*-
//==============================================================================
/**
 * File: Transform_Chess_Piece.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Transform_Chess_Piece.h"
#include "Chess_Board.h"
#include "Movement_Validation_Strategy.h"
#include "Pawn.h"


/*
  Constructor & Destructor
*/
//
// Transform_Chess_Piece (bool, size_t, string, Movement_Validation_Strategy &)
//
Transform_Chess_Piece::Transform_Chess_Piece(bool is_white, size_t x, std::string str, Movement_Validation_Strategy & strategy)
  :Chess_Piece(is_white, x, 1, "~P~", strategy)
{
  // Pieces are initialized at y = 1 if the Piece is black, and 
  // initialized at y = 7 if the Piece is white.
  if (is_white == true)
  {
    this->y_ = 7;
    this->string_representation_ = "-P-";
  }
}


//
// Transform_Chess_Piece (Pawn &)
//
Transform_Chess_Piece::Transform_Chess_Piece(Pawn & piece)
  :Chess_Piece(piece)
{}