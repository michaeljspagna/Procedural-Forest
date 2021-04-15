#ifndef FOREST_HPP
#define FOREST_HPP
#include "../include/olcPixelGameEngine.h"

struct Forest
{
public:
    olc::vf2d offset = {0,0};
    auto generate_forest(olc::PixelGameEngine*) -> void;
};

#endif