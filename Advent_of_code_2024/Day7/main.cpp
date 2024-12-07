#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

#include "Equation.h"

using namespace std;
typedef vector<Equation> Equations;

Equations parseInput(const string& inputName)
{
    string inputLine;
    fstream inputFile(inputName);
    
    Equations equations;
    while(getline(inputFile, inputLine))
    {
        int pos = inputLine.find(':');
        const int result = atoi(inputLine.substr(0, pos).c_str());
        Equation equation(result);
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
                equation.pushBackOperand(operand);
            pos = newPos;

        }while(pos != string::npos);
        
        //equation.generateOperators();
        equations.push_back(equation);
    }
    inputFile.close();

    return equations;
}

int main()
{
    const Equations equations = parseInput("input.txt");
    int sum = 0;
    for(auto e :  equations)
    {
        if(e.isEquationValid())
            sum += e.getResult();
    }

    cout << sum << endl;

    return 0;
}