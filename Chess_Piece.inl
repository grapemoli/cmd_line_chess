// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.inl
 * By: Grace Nguyen
 */
//==============================================================================

//
// get_x ()
//
size_t Chess_Piece::get_x(void)
{
  return this->x_;
}

//
// get_y ()
//
size_t Chess_Piece::get_y(void)
{
  return this->y_;
}

//
// get_color ()
//
bool Chess_Piece::get_color(void)
{
  return this->color_;
}

//
// get_actions ()
//
std::stack<std::array<int, 2>> & Chess_Piece::get_actions(void)
{
  return this->actions_;
}