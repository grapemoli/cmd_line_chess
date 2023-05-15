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
inline
size_t Chess_Piece::get_x(void)
{
  return this->x_;
}

//
// get_y ()
//
inline
size_t Chess_Piece::get_y(void)
{
  return this->y_;
}

//
// is_white ()
//
inline
bool Chess_Piece::is_white(void)
{
  return this->is_white_;
}

//
// get_actions ()
//
inline
std::stack<std::array<int, 2>> & Chess_Piece::get_actions(void)
{
  return this->actions_;
}