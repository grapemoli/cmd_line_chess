﻿// -*- C++ -*-
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
#include "Queen.h"
#include <memory>
#include <iostream>


int main (void)
{
  Array_Movement_Strategy mv;
  Array_Chess_Board a = Array_Chess_Board (mv);
  a.start();
}