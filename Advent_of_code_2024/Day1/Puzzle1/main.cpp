#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

void part1(const vector<int>& n1, const vector<int> n2)
{
    int sum = 0;
    for(int i = 0; i < n1.size(); i++)
    {
        sum += abs(n1[i] - n2[i]);
    }

    cout << sum << endl;
}

void part2(const vector<int>& n1, const vector<int> n2)
{
    map<int, int> resultMap;
    for(int i = 0; i < n1.size(); i++)
    {
        resultMap[n1[i]] = 0;
    }

    for(int i = 0; i < n1.size(); i++)
    { 
        if(resultMap.find(n2[i]) != resultMap.end())
        {
            resultMap[n2[i]] += 1;
        }
    }

    int sum = 0;
    for(int i = 0; i < n1.size(); i++)
    { 
        sum += resultMap[n1[i]] * n1[i];
    }

    cout << sum << endl;
}

int main()
{
    string inputLine;
    fstream inputFile("input.txt");

    vector<int> n1, n2;

    while(getline(inputFile, inputLine))
    {
        // Format of line is a string of numbers followed by 3 spaces and then the second number
        size_t pos = inputLine.find(" ");
        const string firstNumberStr = inputLine.substr(0, pos);
        // assume there is always 3 spaces between the string of numbers to be able to get the second number
        const string secondNumberStr = inputLine.substr(pos + 3, inputLine.length());

        n1.push_back(atoi(firstNumberStr.c_str()));
        n2.push_back(atoi(secondNumberStr.c_str()));
    }

    inputFile.close();

    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());

    part1(n1, n2);
    part2(n1, n2);

    return 0;
}