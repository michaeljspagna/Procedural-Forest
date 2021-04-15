#include "wyhash_rng.hpp"

    Wyhash_RNG::Wyhash_RNG() {}

    Wyhash_RNG::Wyhash_RNG(uint32_t x, uint32_t y)
    {
        wyhash32_x = (x & 0xFFFF) << 16 | (y & 0xFFFF); 
    }

    auto Wyhash_RNG::wyhash32() -> uint32_t
    {
        wyhash32_x += 0x60bee2bee120fc15;
        __uint64_t tmp;
        tmp = (__uint64_t) wyhash32_x * 0xa3b195354a39b70d;
        uint32_t m1 = (tmp >> 32) ^ tmp;
        tmp = (__uint128_t)m1 * 0x1b03738712fad5c9;
        uint32_t m2 = (tmp >> 32) ^ tmp;
        return m2;
    }

    auto Wyhash_RNG::random_double(double min, double max) -> double
    {
        return ((double)wyhash32() / (double)(0x7FFFFFFF)) * (max - min) + min;
    }

    auto Wyhash_RNG::random_integer(int min, int max) -> int
    {
        return (wyhash32() % (max - min)) + min;
    }