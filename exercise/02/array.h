// do not use standard container as member or base class

#pragma once

#include <type_traits>

class array
{
    double* p{ nullptr };
    int n{ 0 };
public:
    explicit array(int size = 0);
    array(int size, double value);
    array(array const& other);
    array(array&& other) noexcept;

    int size() const noexcept;
    double& at(int index);
    double const& at(int index) const;

    array& operator=(array const& other);
    array& operator=(array&& other) noexcept;

    ~array();
};

static_assert(std::is_default_constructible_v<array>);
static_assert(std::is_copy_constructible_v<array>);
static_assert(std::is_copy_assignable_v<array>);
static_assert(std::is_move_constructible_v<array>);
static_assert(std::is_move_assignable_v<array>);
