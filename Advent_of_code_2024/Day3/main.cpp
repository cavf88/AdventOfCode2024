#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int getMulValuesFromGroup(string& group)
{
    smatch searchMatch;
    const regex expression("mul[(][0-9]*,[0-9]*[)]");
    int sum = 0;

    while(regex_search(group, searchMatch, expression))
    {
        for(auto match : searchMatch)
        {
            int n1 = 0;
            int n2 = 0;
            sscanf(match.str().c_str() ,"mul(%d,%d)", &n1, &n2);
            sum += n1 * n2;
            cout << match << endl;
        }
        group = searchMatch.suffix().str();
    }
    return sum;
}

void part2()
{
    fstream inputFile("input.txt");
    int sum = 0;

    string inputLine;
    getline(inputFile, inputLine);

    bool isMulAllowed = true;
    
    int dontPos = 0;
    int doPos = 0;
    do
    {
        do
        {
            // If we can multiply, then we need to find first "don't" and get the value fro all mul before the "don't"
            if(isMulAllowed)
            {   
                // in a while as multiple occurences of do can appear.
                do    
                {
                    dontPos = inputLine.find("don't", doPos);
                    if(dontPos == string::npos)
                        sum += getMulValuesFromGroup(inputLine.substr(doPos));
                    else
                        sum += getMulValuesFromGroup(inputLine.substr(doPos, dontPos - doPos));
                    // case in which a do() was in a previous inputLine and the newLine continues the do() instructions
                    if(dontPos == string::npos)
                    {
                        doPos = 0;
                        break;
                    }
                    isMulAllowed = false;
                }while(isMulAllowed);
            }
            else
            {
                do
                {
                    dontPos = inputLine.find("do", dontPos + 2); // +2 because find finds the position before don't
                    if(dontPos == string::npos)
                        break;
                    // we only care for don't not do. Since  line dontPos = inputLine.find("do", dontPos + 2) works for both do and don't
                    if(inputLine.at(dontPos + 2) == 'n')
                        continue;
                    isMulAllowed = true;
                } while (!isMulAllowed);
                doPos = dontPos;
            }
        }
        while(dontPos != string::npos);

    } while (getline(inputFile, inputLine)  || dontPos != string::npos);

    cout << "Sum: " << sum << endl;

    inputFile.close();
}


void part1()
{
    string inputLine;
    fstream inputFile("input.txt");
    int sum = 0;

    while(getline(inputFile, inputLine))
    {
        sum += getMulValuesFromGroup(inputLine);   
    }
    cout << "Sum: " << sum << endl;
    inputFile.close();

}

int main()
{
    part1();
    part2();
}