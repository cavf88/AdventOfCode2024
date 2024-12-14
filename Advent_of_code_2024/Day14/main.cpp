#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "RobotManager.h"

using namespace std;

int main()
{
    const auto start{std::chrono::steady_clock::now()};
    string inputLine = "";
    fstream inputFile("input_test.txt");

    while(getline(inputFile, inputLine))
    {
    }

    inputFile.close();
    return 0;
}