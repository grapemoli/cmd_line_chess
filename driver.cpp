// -*- C++ -*-
//==============================================================================
/**
 * File: driver.cpp
 * By: Grace Nguyen
 */
//==============================================================================

 
#include <iostream>
#include "Chess_Piece.h"
#include "Pawn.h"
#include "Game_Over_Visitor.h"
#include "Array_Movement_Strategy.h"
#include "Array_Chess_Board.h"
#include <memory>

Chess_Piece & test(Chess_Piece & piece);

int main (void)
{
  Array_Movement_Strategy mv;
  Array_Chess_Board a = Array_Chess_Board (mv);

  std::shared_ptr<Chess_Piece> g = std::make_shared<Pawn>(true, 1, mv);
  std::cout << g << std::endl;

  Chess_Piece & gt = test(*g);
  std::cout << &gt << std::endl;

  if (g.get() == &gt)
  {
    std::cout << "address: " g.get() << std::endl;
  }
}

Chess_Piece & test(Chess_Piece & piece)
{
  std::cout << &piece << std::endl;
  return piece;
}