#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

const static int MAX_DIFF = 3;

vector<int> parseLine(const string& line, const char* delimiter = " ")
{
    vector<int> parsedLine;

    size_t pos = 0;
    while(1)
    {
        auto newPos = line.find(delimiter, pos);
        const string tempStr = line.substr(pos, newPos-pos);
        parsedLine.push_back(atoi(tempStr.c_str()));
        pos = newPos+1;

        if(newPos == string::npos)
        {
            break;
        }
    }

    return parsedLine;
}

bool isVectorValidPart1(const vector<int>& values)
{
    int n1 = values[0];
    int n2 = values[1];
    int diff = n1 - n2;
    if(abs(diff)> MAX_DIFF)
        return false;

    if(diff == 0)
        return false;

    for(int i = 1; i < values.size()-1; i++)
    {
        n1 = values[i];
        n2 = values[i+1];
        int newDiff = n1-n2;
        if(diff > 0 && newDiff < 0 || diff < 0 && newDiff > 0 || newDiff == 0 || abs(newDiff)> MAX_DIFF)
            return false;

        diff = newDiff;
    }

    return true;
}

int main()
{

    string inputLine;
    fstream inputFile("input.txt");
    int part1Sum = 0;

    while(getline(inputFile, inputLine))
    {
        vector<int> values = parseLine(inputLine);
        if(isVectorValidPart1(values))
        {
            part1Sum++;
        }
    }

    cout << "Part1: " << part1Sum << endl;
    inputFile.close();

    return 0;
}