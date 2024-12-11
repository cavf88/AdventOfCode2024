#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

struct Position{int row = -1; 
                int col = -1;};

typedef vector<Position> Positions;
typedef map<int, Positions> PositionsMap;
static PositionsMap s_positionsMap;
static PositionsMap s_trialMap;
static int trailheadNum = 0;
static int sum = 0;

bool isTrailHeadValid(const Positions& positions, const int trailNumber)
{
    if(trailNumber == 0)
    {
        sum++;
        return true;
    }

    //if(trailNumber == -1)
    //{
    //    return false;
    //}

    const int newTrailNumber = trailNumber - 1;
    Positions &newposition = s_positionsMap[newTrailNumber];
    for(const Position& op : positions)
    {
        for(const Position& np : newposition)
        {
            // << left
            if(op.col - np.col == 1)
            {
                if(isTrailHeadValid(newposition, newTrailNumber))
                {
                    trailheadNum++;
                    //s_trialMap[trailNumber].push_back(op);
                    return true;
                }
            }

            // ^^ up
            if(op.row - np.row == 1)
            {
                if(isTrailHeadValid(newposition, newTrailNumber))
                {
                    trailheadNum++;
                    //s_trialMap[trailNumber].push_back(np);
                    return true;
                }
            }

            // >> right
            if(op.col - np.col == -1)
            {
                if(isTrailHeadValid(newposition, newTrailNumber))
                {
                    trailheadNum++;
                    //s_trialMap[trailNumber].push_back(np);
                    return true;
                }
            }

            // vv down
            if(op.row - np.row == -1)
            {
                if(isTrailHeadValid(newposition, newTrailNumber))
                {
                    trailheadNum++;
                    //s_trialMap[trailNumber].push_back(np);
                    return true;
                }
            }

        }   
    }

    return false;
}

void parseInput()
{
    string inputLine;
    fstream inputFile("input_test.txt");
    
    int countRow = 0;
    while(getline(inputFile, inputLine))
    {
        for(int i = 0; i < inputLine.size(); ++i)
        {
            Position pos = {countRow, i};
            s_positionsMap[inputLine.at(i) - 48].push_back(pos);            
        }
        countRow++;
    }

    inputFile.close();
}

int main()
{
    parseInput();

    isTrailHeadValid(s_positionsMap[9], 9);
    cout << sum;

    //for(Positions& p: s_positionsMap.at(9))
    //{
    //    isTrailHeadValid()
    //}

    return 0;
}