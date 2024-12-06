#include <algorithm>
#include <iostream>
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
    int absSum = 0;

    do
    {
        // vertical lookup |^|
        for(int i = rowObstructed; i > INVALID_POS; --i)
        {
            if(rows[i].at(colObstructed) == '#')
            {
                rowObstructed = i + 1;
                break;
            }
        }

        absSum = abs(rowObstructed - row);
        cout << absSum << endl;
        sum += abs(rowObstructed - row);
        row = rowObstructed;

        // horizontal lookup |>|
        colObstructed = rows[rowObstructed].find('#', colObstructed) - 1;
        if(colObstructed + 1 == INVALID_POS)
            break;

        absSum = abs(colObstructed - col);
        cout << absSum << endl;
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

        absSum = abs(rowObstructed - row);
        cout << absSum << endl;
        sum += abs(rowObstructed - row);
        row = rowObstructed;

        // horizontal |<| reverse

        string reverseRow = rows[rowObstructed].substr(0, colObstructed);
        reverse(reverseRow.begin(), reverseRow.end());
        const int reverseCol = reverseRow.find('#');
        colObstructed = abs(colObstructed - reverseCol) + (reverseRow.size() - colObstructed);

        if(reverseCol  == INVALID_POS)
            break;

         absSum = abs(colObstructed - col);
        cout << absSum << endl;
        sum += abs(colObstructed - col);
        col = colObstructed;
        
    } while (rows[rowObstructed].at(colObstructed) == '.');

    sum -= rows.size() - colObstructed;
    cout << sum << endl;
}

int main()
{
    string inputLine;
    fstream inputFile("input.txt");

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