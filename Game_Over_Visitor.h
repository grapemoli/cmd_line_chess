// -*- C++ -*-
//==============================================================================
/**
 * File: Game_Over_Visitor.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _GAME_OVER_VISITOR_H_
#define _GAME_OVER_VISITOR_H_

#include "Chess_Piece_Visitor.h"

// Forward Declarations.
class Pawn;
//class King;
//class Queen;
//class Rook;
//class Bishop;
//class Knight;


/**
 * @class Game_Over_Visitor
 * 
 * Full implementation of the Chess_Piece_Visitor, made with the
 * goal to 
 */
class Game_Over_Visitor
{
public:
  /// Default constructor.
  Game_Over_Visitor (void);

  /// Destructor.
  ~Game_Over_Visitor (void);

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Pawn
   */
  void visit (Pawn & piece);
   
  /**
   * Set visited_king_ to true.
   * 
   * @param[in]         piece         Reference to a King
   */
  //virtual void visit (King & piece) = 0;

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Queen
   */
  //virtual void visit (Queen & piece) = 0;

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Bishop
   */
  //virtual void visit (Bishop & piece) = 0;

  /**
   * Set visited_king_ to false. 
   * 
   * @param[in]         piece         Reference to a Rook
   */
  //virtual void visit (Rook & piece) = 0;

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Knight
   */
  //virtual void visit (Knight & piece) = 0;

  /**
   * Return visited_king_, and then set visited_king_ to false.
   *
   * @return            bool          Return the result
   */
  bool get_result (void);

private: 
  /*************
   * Attributes
   **************/
   /// True if the chess piece is white, false if black.
  bool is_white_;
};


#endif   // !defined _GAME_OVER_VISITOR_H_