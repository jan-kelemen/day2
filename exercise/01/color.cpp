#include "stdafx.h"

#include "color.h"

#include <algorithm>
#include <limits>

namespace
{
  auto const clamp_color = [](double const& value) { return std::clamp(value, 0., 1.); };
}

color::color(double red, double green, double blue) noexcept
  : r{ clamp_color(red) }
  , g{ clamp_color(green) }
  , b{ clamp_color(blue) }
{
  ;
}

decltype(RGB(0, 0, 0)) color::get_color_ref() const noexcept
{
  auto const conv = [](double c) { return c * 255; };
  return RGB(conv(r), conv(g), conv(b));
}

double color::get_luminance() const noexcept
{
  return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

double color::get_red() const noexcept
{
  return r;
}

double color::get_green() const noexcept
{
  return g;
}

double color::get_blue() const noexcept
{
  return b;
}

void color::set_red(double v) noexcept
{
  r = clamp_color(v);
}

void color::set_green(double v) noexcept
{
  g = clamp_color(v);
}

void color::set_blue(double v) noexcept
{
  b = clamp_color(v);
}

bool operator==(color const& lhs, color const& rhs)
{
  auto const compare = [](double const& lhs, double const& rhs) { return std::abs(lhs - rhs) < std::numeric_limits<double>::epsilon(); };
  return compare(lhs.r, rhs.r) && compare(lhs.g, rhs.g) && compare(lhs.b, lhs.b);
}

bool operator!=(color const& lhs, color const& rhs)
{
  return !(lhs == rhs);
}
