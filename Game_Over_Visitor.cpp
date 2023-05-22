// -*- C++ -*-
//==============================================================================
/**
 * File: Game_Over_Visitor.cpp
 * By: Grace Nguyen
 */
//==============================================================================


#include "Game_Over_Visitor.h"
#include "Pawn.h"
//#include "Rook.h"
//#include "King.h"
#include "Queen.h"
//#include "Rook.h"
//#include "Bishop.h"
//#include "Knight.h"


/*
  Constructors & Destructors
*/
//
// Game_Over_Visitor ()
//
Game_Over_Visitor::Game_Over_Visitor(void)
  :visited_king_(false)
{}


//
// ~Game_Over_Visitor ()
//
Game_Over_Visitor::~Game_Over_Visitor(void)
{}



/*
  Double Dispatching methods
*/
//
// visit (Pawn &)
//
void Game_Over_Visitor::visit(const Pawn & piece)
{
  this->visited_king_ = false;
}


//
// visit (King &)
//
/*
void Game_Over_Visitor::visit(const King & piece)
{
  this->visited_king_ = true;
}
*/


//
// visit (Queen &)
//
void Game_Over_Visitor::visit(const Queen & piece)
{
  this->visited_king_ = false;
}



//
// visit (Bishop &)
//
/*
void Game_Over_Visitor::visit(const Bishop & piece)
{
  this->visited_king_ = false;
}
*/


//
// visit (Rook &)
//
/*
void Game_Over_Visitor::visit(const Rook & piece)
{
  this->visited_king_ = false;
}
*/


//
// visit (Knight &)
//
/*
void Game_Over_Visitor::visit(const Knight & piece)
{
  this->visited_king_ = false;
}
*/



/*
  get_result ()
*/
bool Game_Over_Visitor::get_result(void)
{
  bool result = this->visited_king_;
  this->visited_king_ = false;
  return result;
}