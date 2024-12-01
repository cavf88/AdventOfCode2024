#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string inputLine;
    fstream inputFile("input.txt");
    while(getline(inputFile, inputLine))
    {
        // Format of line is a string of numbers followed by 3 spaces and then the second number
        size_t pos = inputLine.find("   ");
        const string firstNumberStr = inputLine.substr(0, pos);
        // assume there is always 3 spaces between the string of numbers to be able to get the second number
        const string secondNumberStr = inputLine.substr(pos + 3, inputLine.length());

        // convert string of numebers to int
        const int n1 = atoi(firstNumberStr.c_str());
        const int n2 = atoi(secondNumberStr.c_str());
        cout << firstNumberStr << "+" << secondNumberStr << endl;
    }
    inputFile.close();
    
    return 0;
}