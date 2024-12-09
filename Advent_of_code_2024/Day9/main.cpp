#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

#include "Disk.h"

using namespace std;


Disk parseInput(const string& inputName)
{
    string inputLine;
    fstream inputFile(inputName);

    Disk disk;
    
    int id = 0;
    int layoutPos = 0;
    int freeSpacePos = 1;
    getline(inputFile, inputLine);
    do
    {
        const int layOutSize = inputLine.at(layoutPos) - 48;
        const int freeSpace = inputLine.at(freeSpacePos) - 48;

        File file(id, layOutSize, freeSpace);
        disk.pushFile(file);
        layoutPos += 2;
        freeSpacePos +=  2;
        id++;

    }while(freeSpacePos < inputLine.size());

    // get the last value
    File file(id, inputLine.at(layoutPos) - 48, 0);
    disk.pushFile(file);

    inputFile.close();

    return disk;

}

int main()
{

    Disk disk = parseInput("input.txt");
    disk.compactDisk();
    disk.outPutDisk();
    return 0;
}