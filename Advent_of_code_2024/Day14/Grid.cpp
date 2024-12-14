#include "Grid.h"

namespace Grid
{
void Grid::drawGrid()
{
    for(int i = 0; i < GRID_W; i++)
    {
        for(int k = 0; k < GRID_H; k++)
        {
            Utils::printToCoordinates(i, k, ".");
        }
    }
}
}