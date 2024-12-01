#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

const static int NUM_SIZE = 5;

int main()
{
    string inputLine;
    fstream inputFile("input.txt");
    int sum = 0;
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

    sort(n1.begin(), n1.end());
    sort(n2.begin(), n2.end());

    // Part 1
    for(int i = 0; i < n1.size(); i++)
    {
        sum += abs(n1[i] - n2[i]);
    }

    cout << sum << endl;

    // Part 2

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

    int sum2 = 0;
    for(int i = 0; i < n1.size(); i++)
    { 
        sum2 += resultMap[n1[i]] * n1[i];
    }

    cout << sum2 << endl;

    inputFile.close();

    return 0;
}