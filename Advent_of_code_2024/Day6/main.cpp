#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const static int INVALID_POS = string::npos;

void part1(const vector<string>& rows, int labRow, int labCol)
{
    int sum = 0;
    int row = labRow;
    int col = labCol;

    int rowObstructed = INVALID_POS;
    int colObstructed = labCol;

    do
    {
        // vertical lookup |^|
        for(int i = 0; i < rows.size(); ++i)
        {
            if(rows[i].at(colObstructed) == '#')
            {
                rowObstructed = i + 1;
                break;
            }
        }

        sum += abs(rowObstructed - row);
        col = rowObstructed;

        // horizontal lookup |>|
        colObstructed = rows[rowObstructed].find('#', colObstructed) - 1;
        if(colObstructed + 1 == INVALID_POS)
            break;

        sum += abs(colObstructed - col);
        col = colObstructed;

        // vertical |v|
        for(int i = rowObstructed; i < rows.size(); ++i)
        {

            if(rows[i].at(colObstructed) == '#')
            {
                rowObstructed = i - 1;
                break;
            }
        }

        sum += abs(rowObstructed - row);
        row = rowObstructed;

        colObstructed = rows[rowObstructed].find('#') + 1;
        if(colObstructed - 1 == INVALID_POS)
            break;

        sum += abs(colObstructed - col);
        col = colObstructed;

        sum++;
    } while (rows[rowObstructed].at(colObstructed) == '.');
    
    cout << sum << endl;
}

int main()
{
    string inputLine;
    fstream inputFile("test_input.txt");

    vector<string> rows;

    // IMBORTANT ~BLANS~ POSITIONS!
    int labRow = INVALID_POS;
    int labCol = INVALID_POS;
    
    int countRow = 0;
    while(getline(inputFile, inputLine))
    {
        rows.push_back(inputLine);
        const auto foundPos = inputLine.find('^');
        if(foundPos != INVALID_POS)
        {
            labRow = countRow;
            labCol = foundPos;
        }
        countRow++;
    }


    part1(rows, labRow, labCol);

    inputFile.close();
    
    return 0;
}