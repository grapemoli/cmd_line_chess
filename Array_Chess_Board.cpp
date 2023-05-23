// -*- C++ -*-
//==============================================================================
/**
 * File: Array_Chess_Board.cpp
 * By: Grace Nguyen
 */
 //==============================================================================


#include "Array_Chess_Board.h"
#include "Array_Movement_Strategy.h"
#include "Chess_Piece.h"
#include "Pawn.h"
#include "Queen.h"
#include "Transform_Chess_Piece.h"


/*
  Constructors & Destructor
*/
//
// Array_Chess_Board (Array_Movement_Strategy &)
//
Array_Chess_Board::Array_Chess_Board(Array_Movement_Strategy & strategy)
  :board_(),
  Chess_Board(strategy)
{
  // Note that the Array_Movement_Strategy is made for Array 
  // representations of the Chess_Board, therefore the client must 
  // use Array_Movement strategies/derived strategies.

  this->build_board();
}


//
// Array_Chess_Board (Array_Chess_Board &)
//
Array_Chess_Board::Array_Chess_Board(Array_Chess_Board & board)
  :board_(board.board_),
  Chess_Board(board)
{}


//
// ~Array_Chess_Board ()
//
Array_Chess_Board::~Array_Chess_Board(void)
{}



/*
  UI Methods
*/
//
// start ()
//
void Array_Chess_Board::start(void)
{
  // Start the game.
  bool keep_going = true;
  std::string user_input;
  bool player = false;   // First Player = false
  std::shared_ptr<Chess_Piece> current_piece = nullptr;
  size_t x_initial;
  size_t y_initial;

  while (keep_going == true)
  {
    std::cout << "\n\n\n***** CHESS *****\n('QUIT' to quit)\n\n";
    this->print();

    // Get coordinates.
    try
    {
      std::cout << "\nPlayer " << player + 1;

      // Get coordinates
      user_input.clear();
      std::cout << "\n";
      x_initial = this->get_coordinate("Choose a x coordinate: ");
      y_initial = this->get_coordinate("Choose a y coordinate: ");

      current_piece = this->board_[y_initial][x_initial];

      // Check that the user inputted an existing piece.
      if (current_piece != nullptr)
      {
        bool moved = this->move(*current_piece, player);

        // Switch players.
        if (moved == true)
        {
          player = !player;
        }
      }
      else
      {
        std::cout << "\nNo piece at this coordinate. Try again.";
      }
    }
    catch (Chess_Board::quit & e)
    {
      break;
    }
    catch (Chess_Piece::game_over & e)
    {
      keep_going = false;
      std::cout << "Game Over!\nCongratulations, Player " << player + 1;
    }
    catch (std::exception & e)
    {
      e.what();
    }
    catch (...)
    {
      std::cout << "\nSomething went wrong. Try again.";
    }
  }
}


//
// get_coordinate (string)
//
size_t Array_Chess_Board::get_coordinate (std::string prompt)
{
  bool keep_going = true;
  std::string user_input;

  while (keep_going == true)
  {
    user_input.clear();
    std::cout << prompt;
    std::cin >> user_input;

    if (user_input == "QUIT")
    {
      keep_going = false;
      throw quit();
    }
    else
    {
      try
      {
        size_t coordindate = this->to_size_t(user_input);
        return coordindate;
      }
      catch (...)
      {
        std::cout << "Invalid input. Try again.\n";
      }
    }
  }
}


/*
  Movement Methods
*/
//
// move (Chess_Piece & piece, bool)
//
bool Array_Chess_Board::move(Chess_Piece & piece, bool player)
{
  // Player 1 is false (0) = white (1). Player 2 is true (1) = black (0).
  // Check that the player is moving a piece of the correct color.
  std::cout << "\n\n--- " << piece.string() << "(" << piece.get_x() << ", " << piece.get_y() << ") ---";

  if (player == piece.is_white())
  {
    std::cout << "\nAttempted to move the opposite team's chess piece. Try again.";
  }
  else
  {
    bool keep_going = true;
    std::string user_input;
    size_t x_final;
    size_t y_final;

    while (keep_going == true)
    {
      user_input.clear();

      try
      {
        std::cout << "\n1.Move\n2. View valid moves\n00.Go back (or 'QUIT')\nChoose an option : ";
        std::cin >> user_input;

        // Check if the user wants to go back.
        if (user_input == "00" || user_input == "QUIT")
        {
          return false;
        }
        else if (user_input == "2")
        {
          std::cout << "\nValid Moves:";
          this->board_[piece.get_y()][piece.get_x()]->list_valid_moves(*this);
          std::cout << "\n";
        }
        else if (user_input == "1")
        { 
          // Get new coordinates.
          user_input.clear();
          std::cout << "\n";
          x_final = this->get_coordinate("New x Coordinate: ");
          y_final = this->get_coordinate("New y Coordinate: ");

          // Move.
          piece.execute(x_final,y_final, *this);
          keep_going = false;
          return true;
        }
      }
      catch (Chess_Board::quit & e)
      {
        return false;
      }
      catch (Chess_Piece::invalid_move & e)
      {
        std::cout << "\nInvalid move. Try again!\n";
      }
      catch (Chess_Piece::game_over & e)
      {
        throw;
      }
      catch (...)
      {
        std::cout << "\nInvalid input! Try again.\n";
      }
    }
  }
}



/*
  Access Methods
*/
//
// set_chess_piece (size_t, size_t, Chess_Piece &)
//
void Array_Chess_Board::set_chess_piece (size_t x, size_t y, Chess_Piece & piece)
{
  // Set the original location to nullptr, and set the new location
  // to contain the piece.
  std::shared_ptr<Chess_Piece> temp = this->board_[piece.get_y()][piece.get_x()];
  
  // Check that the stored piece and the passed piece are the same chess piece.
  if (temp.get() == &piece)
  {
    this->board_[piece.get_y()][piece.get_x()] = nullptr;
    this->board_[y][x] = temp;
  }
  else
  {
    throw invalid_set();
  }
}


//
// transform (std::shared_ptr<Transform_Chess_Piece>)
//
void Array_Chess_Board::transform (std::shared_ptr<Transform_Chess_Piece> piece)
{
  if (piece.get() != nullptr)
  {
    this->board_[piece->get_y()][piece->get_x()] = piece;
  }
  else
  {
    throw invalid_set();
  }
}


//
// get_chess_piece (size_t, size_t)
//
std::shared_ptr<Chess_Piece> Array_Chess_Board::get_chess_piece(size_t x, size_t y)
{
  return this->board_[y][x];
}



/*
  Misc. Methods
*/
//
// print ()
//
void Array_Chess_Board::print(void)
{
  // Print the board.
  for (int i = 0; i < 8; i++)
  {
    std::cout << i << " ";
    for (int j = 0; j < 8; j++)
    {
      // Print differently based on if the space is occupied or not.
      if (this->board_[i][j] == nullptr)
      {
        std::cout << "|     |";
      }
      else
      {
        std::cout << "| " << this->board_[i][j]->string() << " |";
      }
    }
    
    // New row, new line.
    std::cout << "\n";
  }

  for (int i = 0; i < 8; i++)
  {
    std::cout << "      " << i;
  }
}


//
// build_board ()
//
void Array_Chess_Board::build_board(void)
{
  // Use a Builder to build the board correctly.
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      this->board_[i][j] = nullptr;
    }
  }

  std::shared_ptr<Pawn> p_w = std::make_shared<Pawn>(true, 0, this->movement_strategy_);
  this->board_[p_w->get_y()][p_w->get_x()] = p_w;
  std::shared_ptr<Pawn> p_b = std::make_shared<Pawn>(false, 1, this->movement_strategy_);
  this->board_[p_b->get_y()][p_b->get_x()] = p_b;
  
  std::shared_ptr<Queen> q_w = std::make_shared<Queen>(true, this->movement_strategy_);
  this->board_[q_w->get_y()][q_w->get_x()] = q_w;
  std::shared_ptr<Queen> q_b = std::make_shared<Queen>(false, this->movement_strategy_);
  this->board_[q_b->get_y()][q_b->get_x()] = q_b;
}