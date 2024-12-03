#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string inputLine;
    fstream inputFile("input.txt");
    int sum = 0;
    int count = 0;

    while(getline(inputFile, inputLine))
    {

        smatch searchMatch;
        const regex expression("mul[(][0-9]*,[0-9]*[)]");

        while(regex_search(inputLine, searchMatch, expression))
        {
            for(auto match : searchMatch)
            {
                int n1 = 0;
                int n2 = 0;
                sscanf(match.str().c_str() ,"mul(%d,%d)", &n1, &n2);
                sum += n1 * n2;
            }
            inputLine = searchMatch.suffix().str();
            count++;
        }
        
    }
    cout << "Sum: " << sum << endl;
    cout << "count: " << count << endl;

    inputFile.close();
    return 0;
}