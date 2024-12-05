#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

typedef map<int, vector<int>> Rules;
typedef vector<vector<int>> Pages;

void parseLineInRules(const string& line, Rules& rules)
{
    int n1 = 0;
    int n2 = 0;
    sscanf(line.c_str() ,"%d|%d", &n1, &n2);
    rules[n1].push_back(n2);
}

void parseLine(const string& line, Pages& pages)
{
    int pos = 0;
    vector<int> pageNums;
    do
    {
        int foundIndex = line.find(',', pos);
        const int pageNum = atoi(line.substr(pos, foundIndex).c_str());
        pageNums.push_back(pageNum);
        pos = foundIndex + 1;
    }while(pos != 0);
    pages.push_back(pageNums);
}

int main()
{

    string inputLine;
    fstream inputFile("input_test.txt");
    
    Rules rules;
    Pages pages;
    while(getline(inputFile, inputLine))
    {
        if(!inputLine.empty())
        {
            if(inputLine.find('|') != string::npos)
            {
                parseLineInRules(inputLine, rules);
            }
            else
            {
                parseLine(inputLine, pages);
            }
        }
    }
)

    inputFile.close();


    return 0;
}