#include "point.h"

point::point(int x, int y) noexcept
  : data{x, y}
{
}

bool operator==(point const& lhs, point const& rhs)
{
  return lhs.data == rhs.data;
}

bool operator!=(point const& lhs, point const& rhs)
{
  return !(lhs == rhs);
}

bool operator<(point const& lhs, point const& rhs)
{
  return lhs.data < rhs.data;
}

bool operator>(point const& lhs, point const& rhs)
{
  return rhs < lhs;
}

bool operator<=(point const& lhs, point const& rhs)
{
  return !(rhs < lhs);
}

bool operator>=(point const& lhs, point const& rhs)
{
  return !(lhs < rhs);
}
