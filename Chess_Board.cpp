// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Board.h
 * By: Grace Nguyen
 */
 //==============================================================================

#define SIZE 8

#include "Chess_Piece.h"
//#include "Transform_Chess_Piece.h"
#include "Pawn.h"
#include "Chess_Board.h"


/*
  Constructors & Destructors
*/
//
// Chess_Board ()
//
Chess_Board::Chess_Board(void)
  :moves_(),
  size_(SIZE)
{}


//
// ~Chess_Board ()
//
Chess_Board::~Chess_Board(void)
{}