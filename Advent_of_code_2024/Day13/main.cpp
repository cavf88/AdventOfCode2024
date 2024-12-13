#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    string inputLine = "";
    fstream inputFile("input.txt");

    long ax = 0;
    long ay = 0;
    long bx = 0;
    long by = 0;
    long r1 = 0;
    long r2 = 0;
    bool isFirstLine = true;
    long count = 1;
    long sum = 0;
    do
    {
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Prize: X=%d, Y=%d", &r1, &r2);

        for(long i = 0; i < 100; ++i)
        {
            //ax*X+bx*Y = r1
            //ay*X+by*Y = r2
            //int X = (bx*i)/ax;
            long X = (r1 - bx*i)/ax;
            if(ay*X+by*i == r2)
            {
                cout << "Equation" << count << " result: " << X << ", " << i << endl;
                long tokenSum = 3*X + i*1;
                sum += tokenSum;
                break;
            }
                
        }
        count++;
    }while(getline(inputFile, inputLine));
    inputFile.close();

    cout << "sum: " << sum << endl;
    return 0;
}