// -*- C++ -*-
//==============================================================================
/**
 * File: Chess_Piece.inl
 * By: Grace Nguyen
 */
//==============================================================================



//
// string()
//
inline
const std::string Chess_Piece::string(void)
{
  return this->string_representation_;
}


//
// get_x ()
//
inline
const size_t Chess_Piece::get_x(void) const
{
  return this->x_;
}


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
const size_t Chess_Piece::get_y(void) const
{
  return this->y_;
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
const bool Chess_Piece::is_white(void) const
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