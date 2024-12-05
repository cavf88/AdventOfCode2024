#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

typedef map<int, vector<int>> Rules;
typedef vector<vector<int>> Pages;

// Parse the rules which are formatted n|m
void parseLineInRules(const string& line, Rules& rules)
{
    int n1 = 0;
    int n2 = 0;
    sscanf(line.c_str() ,"%d|%d", &n1, &n2);
    rules[n1].push_back(n2);
}

// Parse pages which are in a , separated format.
void parsePages(const string& line, Pages& pages)
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

// Validate the Pages. 
// To validate iterate through pages.
// If the pages after the i page exist in the Rules for the page, then the pages are valid.
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

// Get the middle value and sum it.
int calculateMiddlePagesSumPart1(const Pages& pages, const vector<int>& indexes)
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

// Iterate through the incorrect vector and sort it by swapping values until validate is achieved.
int calculateMiddlePageSumPart2(const Rules& rules, Pages& pages,const vector<int>& indexes)
{
    int sum = 0;
    for(int i = 0; i < indexes.size(); ++i)
    {
        const int index = indexes[i];
        auto pageVec = pages.at(index);
        const int numOfPages = pageVec.size();
        do
        {
            // go in the incorrect pages and swap values.
            for(int j = 0; j < pageVec.size(); j++)
            {
                const auto pageRule = rules.at(pageVec[j]);
                for(int k = j + 1; k < pageVec.size(); k++)
                {
                    if(find(pageRule.begin(), pageRule.end(), pageVec[k]) == pageRule.end())
                    {
                        const int temp = pageVec[j];
                        pageVec[j] = pageVec[k];
                        pageVec[k] = temp;
                    }
                }
            }
        } while (!validatePages(pageVec, rules));

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
                parsePages(inputLine, pages);
            }
        }
    }
    inputFile.close();

    vector<int> validPagesIndexes;
    vector<int> invaludPagesIndexes;
    for(int i = 0; i < pages.size(); ++i)
    {
        if(validatePages(pages[i], rules))
        {
            validPagesIndexes.push_back(i);
        }
        else
        {
            invaludPagesIndexes.push_back(i);
        }
    }

    cout << calculateMiddlePagesSumPart1(pages, validPagesIndexes) << endl;
    cout << calculateMiddlePageSumPart2(rules, pages, invaludPagesIndexes) << endl;

    return 0;
}