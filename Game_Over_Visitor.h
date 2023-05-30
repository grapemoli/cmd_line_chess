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
class King;
class Queen;
//class Rook;
//class Bishop;
//class Knight;


/**
 * @class Game_Over_Visitor
 * 
 * Full implementation of the Chess_Piece_Visitor, made with the
 * goal to 
 */
class Game_Over_Visitor : public Chess_Piece_Visitor
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
  void visit (const Pawn & piece);
   
  /**
   * Set visited_king_ to true.
   * 
   * @param[in]         piece         Reference to a King
   */
  void visit (const King & piece);

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Queen
   */
  void visit (const Queen & piece);

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Bishop
   */
  //virtual void visit (const Bishop & piece) = 0;

  /**
   * Set visited_king_ to false. 
   * 
   * @param[in]         piece         Reference to a Rook
   */
  //virtual void visit (const Rook & piece) = 0;

  /**
   * Set visited_king_ to false.
   * 
   * @param[in]         piece         Reference to a Knight
   */
  //virtual void visit (const Knight & piece) = 0;

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
   /// Keeps track of if the latest dispatch was to a King.
  bool visited_king_;
};


#endif   // !defined _GAME_OVER_VISITOR_H_