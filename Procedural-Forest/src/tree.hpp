#ifndef TREE_HPP
#define TREE_HPP
#include <string>
#include <cstdint>
#include <unordered_map>
#include "wyhash_rng.hpp"
#include "../include/olcPixelGameEngine.h"

enum TreeType
{
     BIRCH
    ,MAPLE
    ,OAK
    ,PINE
    ,WILLOW
};

struct TreeData
{
    TreeType type;
    olc::Pixel trunk_color;
    olc::Pixel leaf_color;
};


struct Tree
{
    Wyhash_RNG rng;
    TreeData data;
    olc::vu2d pos;
    olc::vu2d adj_pos;
    bool exists = false;

    Tree(olc::vu2d&
        ,olc::vf2d&);

    auto highlight(olc::PixelGameEngine*) -> void;
    auto draw_tree(olc::PixelGameEngine*) -> void;

    auto draw_birch(olc::PixelGameEngine*,  int, int) -> void;
    auto draw_maple(olc::PixelGameEngine*,  int, int) -> void;
    auto draw_oak(olc::PixelGameEngine*,    int, int) -> void;
    auto draw_pine(olc::PixelGameEngine*,   int, int) -> void;
    auto draw_willow(olc::PixelGameEngine*, int, int) -> void;
};

#endif