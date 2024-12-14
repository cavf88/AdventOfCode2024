#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <thread>

#include "RobotManager.h"
#include "Tuple.h"
//#include "../_utils/Utils.h"

using namespace std;

int main()
{
    const auto start{std::chrono::steady_clock::now()};
    string inputLine = "";
    fstream inputFile("input_test.txt");

    RobotManager robotManager;
    while(getline(inputFile, inputLine))
    {
        int x = 0;
        int y = 0;
        int vx = 0;
        int vy = 0;
        sscanf(inputLine.c_str(), "p=%d,%d v=%d,%d", &x, &y, &vx, &vy);
        robotManager.addRobot({x,y}, {vx, vy});
    }


    for(int i = 0; i < 5; i++)
    {
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