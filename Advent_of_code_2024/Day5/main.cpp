#include <algorithm>>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

typedef map<int, vector<int>> Rules;
typedef vector<vector<int>> Pages;

//const static int HASH_NUM = 1;

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

bool validatePages(const vector<int> pages, const Rules& rules)
{
    for(int i = 0; i < pages.size() - 1; ++i)
    {
        const int pageNum = pages[i];
        if(rules.find(pageNum) != rules.end())
        {
            const vector<int> pageRules = rules.at(pageNum);
            for(int k = i + 1; k < pages.size() - 1; ++k)
            {
                if(find(pageRules.begin(), pageRules.end(), pages[k]) == pageRules.end())
                {
                    return false;
                }

            }
        }   
        else
        {
            return false;
        }
    }
    return true;
}

int calculateMiddlePagesSum(const Pages& pages, const vector<int>& indexes)
{
    int sum = 0;
    for(int i = 0; i < indexes.size(); ++i)
    {
        const int index = indexes[i];
        const auto pageVec = pages.at(index);
        const int numOfPages = pageVec.size();
        sum += pageVec.at(numOfPages / 2);
    }

    return sum;
}

int main()
{

    string inputLine;
    fstream inputFile("input.txt");
    
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
    inputFile.close();

    vector<int> validPagesIndexes;
    for(int i = 0; i < pages.size(); ++i)
    {
        if(validatePages(pages[i], rules))
        {
            validPagesIndexes.push_back(i);
        }
    }

    cout << calculateMiddlePagesSum(pages, validPagesIndexes) << endl;

    return 0;
}