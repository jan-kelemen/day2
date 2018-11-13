#pragma once

#include <utility>
#include <type_traits>

class point
{
public:
    explicit point(int x = 0, int y = 0) noexcept;

private:
    std::pair<int, int> data;

    friend bool operator==(point const&, point const&);
    friend bool operator<(point const&, point const&);
};

bool operator==(point const& lhs, point const& rhs);
bool operator!=(point const& lhs, point const& rhs);
bool operator<(point const& lhs, point const& rhs);
bool operator>(point const& lhs, point const& rhs);
bool operator<=(point const& lhs, point const& rhs);
bool operator>=(point const& lhs, point const& rhs);

static_assert(std::is_default_constructible_v<point>);
static_assert(std::is_copy_constructible_v<point>);
static_assert(std::is_copy_assignable_v<point>);
static_assert(std::is_move_constructible_v<point>);
static_assert(std::is_move_assignable_v<point>);