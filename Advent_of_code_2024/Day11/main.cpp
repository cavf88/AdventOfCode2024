#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib> 
#include <chrono>


using namespace std;

typedef uint64_t biglong;
static map<biglong, biglong> s_finalCount;
const int MAX_BLINKS = 25;

string stringifyValue(const biglong value)
{
    stringstream ss;
    ss << value;
    if(ss.str().size()%2 == 0)
        return ss.str();

return string();
}

int main()
{
    const auto start{std::chrono::steady_clock::now()};
    string inputLine;
    fstream inputFile("input.txt");

    getline(inputFile, inputLine);
    inputFile.close();

    int pos = 0;
    do
    {
        int newPos = inputLine.find(" ", pos);
        long value = atol(inputLine.substr(pos, newPos).c_str());
        s_finalCount[value] = 1;
        pos = newPos + 1;
    }while(pos != string::npos + 1);

    for(int i = 0; i < MAX_BLINKS; i++)
    {
        map<biglong, biglong> tempMap;
        for(map<biglong, biglong>::iterator it = s_finalCount.begin(); it != s_finalCount.end(); ++it)
        {
            if(it->first == 0)
            {
                // convert to 1
                tempMap[1] += it->second;
                s_finalCount.erase(it);
            }
            else
            {
                string valueStr =  stringifyValue(it->first);
                if(!valueStr.empty())
                {
                    // split                                                                                                        
                    const int halfPos = valueStr.size() / 2;
                    const long count = it->second;

                    // first part of the string
                    string halfString = valueStr.substr(0, halfPos);
                    biglong halfIndex = strtoull(halfString.c_str(), NULL, 10);
                    tempMap[halfIndex] += count;

                    //second part
                    halfString = valueStr.substr(halfPos);
                    halfIndex = strtoull(halfString.c_str(), NULL, 10);
                    tempMap[halfIndex] += count;
                    s_finalCount.erase(it);
                }
                else
                {
                    // case in which you multiply by 2024
                    tempMap[it->first * 2024] += it->second;
                    s_finalCount.erase(it);
                }
            }
        }
        s_finalCount.clear();
        s_finalCount = tempMap;
    }

    long sum = 0;
    for(const auto& it: s_finalCount)
    {
        sum += it.second;
    }
    cout << sum << endl;

    const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};

    cout << "Time(ms):" << elapsed_seconds.count() * 1000 << "s";

    return 0;
}