#ifndef WYHASH_RNG_HPP
#define WYHASH_RNG_HPP
#include <cstdint>

struct Wyhash_RNG
{
    uint32_t wyhash32_x;
    
    Wyhash_RNG();

    Wyhash_RNG(uint32_t, uint32_t);

    auto wyhash32() -> uint32_t;

    auto random_double(double, double) -> double;

    auto random_integer(int, int) -> int;
};

#endif 