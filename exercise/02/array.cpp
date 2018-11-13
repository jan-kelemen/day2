#include "array.h"

#include <iterator>
#include <memory>
#include <stdexcept>

namespace
{
  auto const size_check = [](int const& size) 
  { 
    if (size < 0) throw std::invalid_argument("invalid array size");
    return size;
  };

  auto const bounds_check = [](int const& index, int const& upper_bound)
  {
    if(index < 0 || index >= upper_bound) throw std::out_of_range("invalid index");
  };
}

array::array(int size) 
  : p { new double[size_check(size)] }
  , n { size }
{
}

array::array(int size, double value) : array(size)
{
  std::fill(p, p + size, value);
}

array::array(array const& other) : array(other.n)
{
  std::copy(other.p, other.p + n, p);
}

array::array(array&& other) noexcept
  : p { other.p }
  , n { other.n }
{
  other.p = nullptr;
  other.n = 0;
}

int array::size() const noexcept
{
    return n;
}

double& array::at(int index)
{
  bounds_check(index, size());
  return p[index];
}

double const& array::at(int index) const
{
  bounds_check(index, size());
  return p[index];
}

array& array::operator=(array const& other)
{
  if(this == std::addressof(other)) return *this;

  auto tmp = other;
  *this = std::move(tmp);
  return *this;
}

array& array::operator=(array&& other) noexcept
{
  this->~array();
  std::swap(p, other.p);
  std::swap(n, other.n);
  return *this;
}

array::~array()
{
  delete[] p;
  p = nullptr;
  n = 0;
}
