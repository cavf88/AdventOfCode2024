#pragma once
#include "Tuple.h"
#include "../_utils/Utils.h"

//#define TEST

#ifndef TEST
const static int GRID_W = 101;
const static int GRID_H = 103;
#else

const static int GRID_W = 11;
const static int GRID_H = 7;
#endif

namespace Grid
{
    void drawGrid();
}