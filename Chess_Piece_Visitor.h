// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece_Vistor.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _CHESS_PIECE_VISITOR_H_
#define _CHESS_PIECE_VISITOR_H_


// Forward Declarations.
class Pawn;
//class King;
class Queen;
//class Rook;
//class Bishop;
//class Knight;


/**
 * @class Chess_Piece_Visitor
 * 
 * An abstract class that enables double dispatching with
 * concretions of Chess_Piece.
 */
class Chess_Piece_Visitor
{
public:
  /// Default constructor.
  Chess_Piece_Visitor (void) {};

  /// Destructor.
  virtual ~Chess_Piece_Visitor (void) {};

  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a Pawn
   */
  virtual void visit (const Pawn & piece) = 0;
   
  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a King
   */
  //virtual void visit (const King & piece) = 0;

  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a Queen
   */
  virtual void visit (const Queen & piece) = 0;

  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a Bishop
   */
  //virtual void visit (const Bishop & piece) = 0;

  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a Rook
   */
  //virtual void visit (const Rook & piece) = 0;

  /**
   * Enable double dispatching. 
   * 
   * @param[in]         piece         Reference to a Knight
   */
  //virtual void visit (const Knight & piece) = 0;

  /**
   * Get the result.
   * 
   * @return            bool          Return the result
   */
  virtual bool get_result (void) = 0;
};


#endif   // !defined _CHESS_PIECE_VISITOR_H_