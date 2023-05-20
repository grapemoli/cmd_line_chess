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

  //this->start_board();
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
    std::cout << "\n\n***** CHESS ***** ('QUIT' to quit)\n";
    this->print();

    // Get coordinates.
    try
    {
      std::cout << "\nPlayer " << player + 1 << "\n";
      std::cout << "\nChoose an x coordinate: ";
      std::cin >> user_input;

      if (user_input == "QUIT")
      {
        break;
      }
      else
      {
        x_initial = this->to_size_t(user_input);
      }
      std::cout << "\nChoose a y coordinate: ";
      std::cin >> user_input;
      if (user_input == "QUIT")
      {
        break;
      }
      else
      {
        y_initial = this->to_size_t(user_input);
      }

      current_piece = this->board_[y_initial][x_initial]; 

      // Check that the user inputted an existing piece.
      if (current_piece != nullptr)
      {
        this->move(*current_piece, player);

        // Switch players.
        player = !player;
      }
      else
      {
        std::cout << "\nNo piece at this coordinate. Try again.";
      }
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



/*
  Movement Methods
*/
//
// move (Chess_Piece & piece, bool)
//
void Array_Chess_Board::move(Chess_Piece & piece, bool player)
{
  // Player 1 is false (0) = white (1). Player 2 is true (1) = black (0).
  // Check that the player is moving a piece of the correct color.
  if (player == piece.is_white())
  {
    std::cout << "\nAttempted to move the opposite team's chess piece.";
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
        std::cout << "\n1. View valid moves\n2. Move\nChoose an option ('QUIT' to go back): ";
        std::cin >> user_input;

        // Check if the user wants to go back.
        if (user_input == "QUIT")
        {
          break;
        }
        else
        {
          // Get new coordinates.
          std::cout << "\nNew X coordinate: ";
          std::cin >> user_input;
          if (user_input == "QUIT")
          {
            break;
          }
          else
          {

            x_final = this->to_size_t(user_input);
          }

          std::cout << "\nNew Y coordinate: ";
          std::cin >> user_input;
          if (user_input == "QUIT")
          {
            break;
          }
          else
          {
            x_final = this->to_size_t(user_input);
          }

          // Move.
          piece.execute(x_final, y_final, *this);
          keep_going = false;
        }
      }
      catch (Chess_Piece::invalid_move & e)
      {
        std::cout << "\nInvalid move. Try again!";
      }
      catch (Chess_Piece::game_over & e)
      {
        throw;
        keep_going = false;
      }
      catch (...)
      {
        std::cout << "\nInvalid input! Try again.";
      }
    }
  }
}



/*
  Misc. Methods
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
// transform (std::shared_ptr<Chess_Piece>)
//
void Array_Chess_Board::transform (std::shared_ptr<Chess_Piece> piece)
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


//
// print ()
//
void Array_Chess_Board::print(void)
{
  // Print the board.
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // Print differently based on if the space is occupied or not.
      if (this->board_[j][i] == nullptr)
      {
        std::cout << "|    |";
      }
      else
      {
        std::cout << "| " << this->board_[j][i]->string() << " |";
      }
    }
    
    // New row, new line.
    std::cout << "\n";
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
      this->board_[j][i] = nullptr;
    }
  }
}