#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

const static int INVALID_POS = string::npos;

void part1(const vector<string>& rows, int labRow, int labCol)
{
    int sum = 1;
    int row = labRow;
    int col = labCol;

    int rowObstructed = labRow;
    int colObstructed = labCol;

    do
    {
        int i;
        // vertical lookup |^|
        for(i = rowObstructed; i > INVALID_POS; --i)
        {
            if(rows[i].at(colObstructed) == '#')
            {
                rowObstructed = i + 1;
                break;
            }
        }
        if(rowObstructed - i < 0)
            break;

        sum += abs(rowObstructed - row);
        row = rowObstructed;

        // horizontal lookup |>|
        colObstructed = rows[rowObstructed].find_first_of('#', colObstructed) - 1;
        if(colObstructed + 1 == INVALID_POS)
            break;

        sum += abs(colObstructed - col);
        col = colObstructed;

        // vertical |v|
        for(i = rowObstructed; i < rows.size(); ++i)
        {

            if(rows[i].at(colObstructed) == '#')
            {
                rowObstructed = i - 1;
                break;
            }
        }

        if(i + rowObstructed == rows.size())
            break;

        sum += abs(rowObstructed - row);
        row = rowObstructed;

        // horizontal |<| reverse
        string reverseRow = rows[rowObstructed].substr(0, colObstructed);
        reverse(reverseRow.begin(), reverseRow.end());
        const int reverseCol = reverseRow.find_first_of('#');
        colObstructed = abs(colObstructed - reverseCol) + (reverseRow.size() - colObstructed);

        if(reverseCol  == INVALID_POS)
            break;

        sum += abs(colObstructed - col);
        col = colObstructed;
        
    } while (rows[rowObstructed].at(colObstructed) == '.');

    sum -= rows.size() - colObstructed;
    cout << sum << endl;
}

int main()
{
    string inputLine;
    fstream inputFile("input_test.txt");

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