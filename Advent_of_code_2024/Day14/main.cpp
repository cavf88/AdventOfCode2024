#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>

#include "RobotManager.h"
#include "Tuple.h"
#include "Grid.h"

using namespace std;

#define TEST

#ifndef TEST
const static string s_fileName = "input.txt";
#else
const static string s_fileName = "D:\\cavf88\\Documents\\Google Drive\\Git\\Advent_of_code_2024\\Day14\\input_test.txt";
#endif


int main()
{
    const auto start{std::chrono::steady_clock::now()};
    string inputLine = "";
    ifstream inputFile(s_fileName.c_str());

    RobotManager robotManager;
    while(getline(inputFile, inputLine))
    {
        int x = 0;
        int y = 0;
        int vx = 0;
        int vy = 0;
        sscanf_s(inputLine.c_str(), "p=%d,%d v=%d,%d", &x, &y, &vx, &vy);
        robotManager.addRobot({x,y}, {vx, vy});
    }


    for(int i = 0; i < 5; i++)
    {
        Grid::drawGrid();
        robotManager.draw();
        robotManager.update();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));   
        system("cls");
    }

    string s;
    cin >> s;
    inputFile.close();
    return 0;
}