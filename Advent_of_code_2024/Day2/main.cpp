#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

vector<int> parseLine(const string& line, const char* delimiter = " ")
{
    vector<int> parsedLine;

    size_t pos = 0;
    while(1)
    {
        auto newPos = line.find(delimiter, pos);
        const string tempStr = line.substr(pos, 2);
        parsedLine.push_back(atoi(tempStr.c_str()));
        pos = newPos+1;

        if(newPos == string::npos)
        {
            break;
        }
    }

    return parsedLine;
}

int main()
{

    string inputLine;
    fstream inputFile("input.txt");

    while(getline(inputFile, inputLine))
    {
        vector<int> values = parseLine(inputLine);
    }

    inputFile.close();

    return 0;
}