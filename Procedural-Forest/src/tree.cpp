#include "tree.hpp"
#include<iostream>

TreeData trees[5] =
{
     TreeData{TreeType::BIRCH , olc::Pixel(246,238,223)  , olc::Pixel(119, 177, 137)}
    ,TreeData{TreeType::MAPLE , olc::Pixel(150, 111, 87) , olc::Pixel(210, 122, 63)}
    ,TreeData{TreeType::OAK   , olc::Pixel(186, 164, 138), olc::Pixel(96, 143, 7)}
    ,TreeData{TreeType::PINE  , olc::Pixel(130, 112, 100), olc::Pixel(1, 121, 111)}
    ,TreeData{TreeType::WILLOW, olc::Pixel(158, 144, 103), olc::Pixel(170, 173, 156)}
    
};


Tree::Tree(olc::vu2d& pos
          ,olc::vf2d& offset)
: pos(pos)
{
    rng = Wyhash_RNG(pos.x + (uint32_t) offset.x, pos.y + (uint32_t) offset.y);
    exists = (rng.random_integer(0,4) == 1);

    if(!exists) 
        return;

    data = trees[rng.random_integer(0,5)];
}

auto Tree::highlight(olc::PixelGameEngine* pge) -> void
{
    pge->DrawRect(adj_pos.x-4, adj_pos.y-2, 10, 15, olc::WHITE);
}

auto Tree::draw_tree(olc::PixelGameEngine* pge) -> void
{
    adj_pos.x = pos.x * 16 + 8;
    adj_pos.y = pos.y * 16 + 8;
    pge->FillRect(adj_pos.x, adj_pos.y, 2, 2, this->data.leaf_color);
    pge->FillRect(adj_pos.x-1, adj_pos.y+2, 4, 2, this->data.leaf_color);
    pge->FillRect(adj_pos.x-2, adj_pos.y+4, 6, 2, this->data.leaf_color);
    pge->FillRect(adj_pos.x, adj_pos.y+6, 2, 4, this->data.trunk_color);
}

auto draw_birch(olc::PixelGameEngine* pge, int x, int y) -> void
{

}

auto draw_maple(olc::PixelGameEngine* pge, int x, int y) -> void
{

}

auto draw_oak(olc::PixelGameEngine* pge, int x, int y) -> void
{

}

auto draw_pine(olc::PixelGameEngine* pge, int x, int y) -> void
{

}

auto draw_willow(olc::PixelGameEngine* pge, int x, int y) -> void
{

}