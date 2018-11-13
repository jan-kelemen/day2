#pragma once

#include <type_traits>

#include <windows.h>

class color
{
public:
  explicit color(double red = 0., double green = 0., double blue = 0.) noexcept;

  decltype(RGB(0, 0, 0)) get_color_ref() const noexcept;
  double get_luminance() const noexcept;

  double get_red() const noexcept;
  double get_green() const noexcept;
  double get_blue() const noexcept;

  void set_red(double v) noexcept;
  void set_green(double v) noexcept;
  void set_blue(double v) noexcept;

private:
  double r;
  double g;
  double b;

  friend bool operator==(color const&, color const&);
};

static_assert(std::is_default_constructible_v<color>);
static_assert(std::is_copy_constructible_v<color>);
static_assert(std::is_copy_assignable_v<color>);
static_assert(std::is_move_constructible_v<color>);
static_assert(std::is_move_assignable_v<color>);

bool operator==(color const& lhs, color const& rhs);
bool operator!=(color const& lhs, color const& rhs);
