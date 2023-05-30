// -*- C++ -*-
//==============================================================================
/**
 * File: Movement_Validation_Strategy.h
 * By: Grace Nguyen
 */
//==============================================================================


#pragma once
#ifndef _MOVEMENT_VALIDTION_STRATEGY_H_
#define _MOVEMENT_VALIDTION_STRATEGY_H_

#include <exception>      // For custom exception: invalid_move, game_over.
#include <memory>         // For shared_ptr.

// Forward Declarations.
class Chess_Piece;
class Chess_Board;
class Chess_Piece_Visitor;


/**
 * @class Movement_Validation_Strategy
 * 
 * An abstract class that outlines validation strategies. Note that
 * validation refers to (1) collision detection, (2) game over detection,
 * and (3) verifying the validity of movements. Collision detection is 
 * implemented in this abstract class.
 */
class Movement_Validation_Strategy
{
public:
  /*************
   * Custom Exceptions
   **************/
  /**
   * @class invalid_move
   *
   * Exception thrown to indicate invalid move.
   */
  class invalid_move: public std::exception
  {
  public:
    /// Default constructor.
    invalid_move (void)
      :std::exception () { }
      
    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    invalid_move (const char * msg)
      :std::exception (msg) { }

    /// Message to be returned when what() is called.
    const char* what () const throw ()
    {
      return "Invalid move.";
    }
  };


  /**
   * @class game_over
   *
   * Exception thrown to indicate game over (i.e.,
   * the King is eaten!).
   */
  class game_over : public std::exception
  {
  public:
    /// Default constructor.
    game_over (void)
      :std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg          Error message.
     */
    game_over (const char* msg)
      :std::exception (msg) { }

    /// Message to be returned when what() is called.
    const char* what () const throw ()
    {
      return "Game over!";
    }
  };



  /*************
   * Member Functions
   **************/
   /// Default constructor.
  Movement_Validation_Strategy ();

  /// Destructor.
  virtual ~Movement_Validation_Strategy (void);

  /**
   * Checks if the movement of the chess piece will cause
   * a collision with any other piece.
   * 
   * @param[in]          x             New x position
   * @param[in]          y             New y position
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          There is a collision
   * @retvalue           False         There is no collision
   * @exception          game_over     The opposing King is eaten
   */
  const bool is_collide (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board);

  /**
   * Check if the movement is valid for a pawn.
   * 
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  virtual const bool check_pawn_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

  /**
   * Check if the movement is valid for a rook.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //virtual const bool check_rook_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

  /**
   * Check if the movement is valid for a bishop.
   * piece.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //virtual const bool check_bishop_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

  /**
   * Check if the movement is valid for a knight.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  //virtual const bool check_knight_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

  /**
   * Check if the movement is valid for a queen.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  virtual const bool check_queen_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

  /**
   * Check if the movement is valid for a king.
   *
   * @param[in]          x             The to-be x placement
   * @param[in]          y             The to-be y placement
   * @param[in]          piece         Chess_Piece reference
   * @param[in]          board         Chess_Board reference
   * @retvalue           True          Valid
   * @retvalue           False         Not valid
   */
  virtual const bool check_king_movement (size_t x, size_t y, Chess_Piece & piece, Chess_Board & board) = 0;

protected:
  /*************
   * Attributes
   **************/
  /// Instace of the appropiate visitor for collision/game over detection.
  Chess_Piece_Visitor & collision_visitor_;
};


#endif   // !defined _MOVEMENT_VALIDTION_STRATEGY_H_