// -*- C++ -*-
//==============================================================================
/**
 * File: Game_Over_Visitor.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Game_Over.h"
#include "Pawn.h"
//#include "Rook.h"
//#include "King.h"
//#include "Queen.h"
//#include "Rook.h"
//#include "Bishop.h"
//#include "Knight.h"


/*
  Constructors & Destructors
*/
//
// Game_Over ()
//
Game_Over::Game_Over(void)
  :visited_king_(false)
{}


//
// ~Game_Over ()
//
Game_Over::~Game_Over(void)
{}



/*
  Double Dispatching methods
*/
//
// visit (Pawn &)
//
Game_Over::visit(Pawn & piece)
{
  this->visited_king_ = false;
}


//
// visit (King &)
//
/*
Game_Over::visit(King & piece)
{
  this->visited_king_ = true;
}
*/


//
// visit (Queen &)
//
/*
Game_Over::visit(Queen & piece)
{
  this->visited_king_ = false;
}
*/


//
// visit (Bishop &)
//
/*
Game_Over::visit(Bishop & piece)
{
  this->visited_king_ = false;
}
*/


//
// visit (Rook &)
//
/*
Game_Over::visit(Rook & piece)
{
  this->visited_king_ = false;
}
*/


//
// visit (Knight &)
//
/*
Game_Over::visit(Knight & piece)
{
  this->visited_king_ = false;
}
*/



/*
  get_result ()
*/
bool get_result(void)
{
  bool result = this->visited_king_;
  this->visited_king_ = false;
  return result;
}