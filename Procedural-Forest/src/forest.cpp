#include "forest.hpp"
#include "tree.hpp"


auto Forest::generate_forest(olc::PixelGameEngine* pge) -> void
{
    int row_sectors = pge->ScreenWidth() / 16;
    int col_sectors = pge->ScreenHeight() / 16;
    olc::vu2d mouse({pge->GetMouseX()/16, pge->GetMouseY()/16});
    olc::vu2d sector({0,0});
    for(sector.x = 0; sector.x < row_sectors; sector.x++){
        for(sector.y = 0; sector.y < col_sectors; sector.y++){
            Tree tree(sector, offset);
            if(tree.exists)
            {
                tree.draw_tree(pge);
                if(mouse.x == sector.x && mouse.y == sector.y){
                    tree.highlight(pge);
                }
            }
        }  
    }
}

