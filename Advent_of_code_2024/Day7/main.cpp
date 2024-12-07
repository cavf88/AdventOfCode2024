#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;
typedef map<int, vector<int>> Equations;

Equations parseInput(const string& inputName)
{
    string inputLine;
    fstream inputFile(inputName);
    Equations equations;
    
    while(getline(inputFile, inputLine))
    {
        int pos = inputLine.find(':');
        const int result = atoi(inputLine.substr(0, pos).c_str());
        pos++; //to avoid the first empty space after ":"
        do
        {
            int newPos = inputLine.find(' ', pos+1);
            int operand = 0;
            if(newPos ==  string::npos)
                operand = atoi(inputLine.substr(pos).c_str());
            else
                operand = atoi(inputLine.substr(pos, newPos).c_str());

            if(operand > 0)
                equations[result].push_back(operand);
            pos = newPos;

        }while(pos != string::npos);
    }
    inputFile.close();

    return equations;
}

int main()
{
    const Equations equations = parseInput("input_test.txt");

    return 0;
}