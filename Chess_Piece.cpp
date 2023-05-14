// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.cpp
 * By: Grace Nguyen
 */
//==============================================================================

 
#include "Chess_Piece.h"


/*
  Constructor & Destructor
*/
//
// Chess_Piece (bool, size_t, size_t)
//
Chess_Piece::Chess_Piece(bool color, size_t x, size_t y)
  :color_(color),
  x_(x),
  y_(y),
  actions_()
{}


//
// ~Chess_Piece ()
//
Chess_Piece::~Chess_Piece(void)
{
  // There is nothing to deallocate.
}