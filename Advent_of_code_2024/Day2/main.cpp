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

bool isVectorValid(vector<int>& values, const int levelOfTolerance = 0)
{

    int localLevelOfTolerance = 0;
    int pos1 = 0;
    int pos2 = 1;
    do
    {
        int n1 = values[pos1];
        int n2 = values[pos2];
        int diff = n1 - n2;
        n1 = values[pos1+1], n2 = values[pos2+1];
        int newDiff = n1-n2;

        if(diff > 0 && newDiff < 0 || diff < 0 && newDiff > 0 || newDiff == 0 || abs(newDiff)> MAX_DIFF || abs(diff) > MAX_DIFF || diff == 0)
        {
            if(localLevelOfTolerance == levelOfTolerance)
            {
                return false;
            }
            else
            {
                // incomplete for part 2... missing values. The answwer is 528
                values.erase(values.begin() + pos2 + 1);
                pos1 = 0;
                pos2 = 1;
                localLevelOfTolerance++;
                continue;
            }
        }
        
        diff = newDiff;
        pos1++;
        pos2++;
        
    } while (pos1 < values.size()-2);

    return true;
}

int main()
{

    string inputLine;
    fstream inputFile("input.txt");
    int part1Sum = 0;
    int part2Sum = 0;

    while(getline(inputFile, inputLine))
    {
        vector<int> values = parseLine(inputLine);
        // part1
        if(isVectorValid(values))
        {
            part1Sum++;
        }
        
        //par2
        if(isVectorValid(values, 1))
        {
            part2Sum++;
        }
        else
        {
            cout << inputLine << endl;
        }
        
    }

    cout << "Part1: " << part1Sum << endl;
    cout << "Part2: " << part2Sum << endl;
    inputFile.close();

    return 0;
}