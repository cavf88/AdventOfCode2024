#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

typedef int64_t biglong;
typedef uint64_t bigbiglong;

const static int POSITION_DEVIATION = 10000000000000;
const static int MAX_ITERATIONS_PART1 = 100;

const static int MATRIZ_SIZE = 2;
const static double IDENTITY_VALUE = 1.0;


// solves by substitution
//ax*X+bx*Y = r1
//ay*X+by*Y = r2
//int X = (bx*i)/ax;
int solvePart1(const int ax, const int ay, const int bx, const int by, const int r1, const int r2, const int count)
{
    int sum = 0;
    for(int i = 0; i < MAX_ITERATIONS_PART1; ++i)
    {
        //ax*X+bx*Y = r1
        //ay*X+by*Y = r2
        //int X = (bx*i)/ax;
        int X = (r1 - bx*i)/ax;
        if(ay*X+by*i == r2 && ax*X+bx*i == r1)
        {
            cout << "Equation" << count << " result: " << X << ", " << i << endl;
            int tokenSum = 3*X + i*1;
            sum += tokenSum;
            break;
        }
            
    }

    return sum;
}

// works for test, but for real input it breaks due to floating point not being exact.
biglong solveWithMatrix(const double ax, const double ay, const double bx, const double by, const biglong r1, const biglong r2, const int count)
{
    biglong sum = 0;

    double matrixEq[MATRIZ_SIZE][MATRIZ_SIZE] = {  ax, bx, 
                                                ay, by};
    double det = ax * by - bx * ay;
    if(det == 0)
        return 0;
    //double detInv = 1/det;

    double matrixInv[MATRIZ_SIZE][MATRIZ_SIZE] = {
        by, (bx * -1),
        (ay * -1), ax};

    double matrixIdentity[MATRIZ_SIZE][MATRIZ_SIZE] = 
    {
        matrixEq[0][0] * (matrixInv[0][0]/det) + matrixEq[0][1] * (matrixInv[1][0]/det),
        matrixEq[0][0] * (matrixInv[1][0]/det) + matrixEq[0][1] * (matrixInv[1][1]/det),
        matrixEq[0][1] * (matrixInv[0][0]/det) + matrixEq[1][1] * (matrixInv[1][0]/det),
        matrixEq[0][1] * (matrixInv[1][0]/det) + matrixEq[1][1] * (matrixInv[1][1]/det)
    };

    // matrixIndentity is not right so the equation is not solvable
    double identityA = matrixIdentity[0][0];
    double identityB = matrixIdentity[1][1];
    if(identityA < IDENTITY_VALUE || identityB  < IDENTITY_VALUE)
        return 0;

    float X = (matrixInv[0][0]/det) * r1 + (matrixInv[0][1]/det) * r2;
    float Y = (matrixInv[1][0]/det) * r1 + (matrixInv[1][1]/det) * r2;

    return 3 * X + 1 * Y;
}


// Solves by addition
//ax*X+bx*Y = r1  => (by)(ax*X+bx*Y) = r1(by)
//ay*X+by*Y = r2  => (-bx)(ay*X+by*Y) = r2(-bx)
bigbiglong solvePart2(const biglong ax, const biglong ay, const biglong bx, const biglong by, const biglong r1, const biglong r2, const int count)
{
    bigbiglong sum = 0;

    biglong YCoeff = ax * by - ay * bx;
    biglong rhs =  r1 * by - r2 * bx;

    if(rhs % YCoeff == 0)
    {
        biglong Y = rhs / YCoeff;
        biglong X = (r1 - ax * Y) / bx;
        sum += Y * 3 + X * 1;
    }    

    return sum;
}

int main()
{
    const auto start{std::chrono::steady_clock::now()};
    string inputLine = "";
    fstream inputFile("input.txt");

    int ax = 0;
    int ay = 0;
    int bx = 0;
    int by = 0;
    int r1 = 0;
    int r2 = 0;
    bool isFirstLine = true;
    int count = 1;
    bigbiglong sumPart1 = 0;
    bigbiglong sumPart2 = 0;
    do
    {
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Button A: X+%d, Y+%d", &ax, &ay);
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Button B: X+%d, Y+%d", &bx, &by);
        getline(inputFile, inputLine);
        sscanf(inputLine.c_str(), "Prize: X=%d, Y=%d", &r1, &r2);

        //biglong result = solvePart2(ax, ay, bx, by, r1, r2, count);        
        bigbiglong result = solvePart2(
            ax,
            ay,
            bx,
            by,
            biglong(r1) + biglong(10000000000000),
            biglong(r2) + biglong(10000000000000),
            count);

        if(result != 0)
        {
            sumPart1 += result;
            cout << "Button A: " << ax << "," << ay << endl;
            cout << "Button B: " << bx << "," << by << endl;
        }            
        count++;
    }while(getline(inputFile, inputLine));
    inputFile.close();

    cout << "Sum Part1: " << sumPart1 << endl;
    cout << "Sum Part2: " << sumPart2 << endl;

     const auto end{std::chrono::steady_clock::now()};
    const std::chrono::duration<double> elapsed_seconds{end - start};

    cout << "Time:" << elapsed_seconds.count() << "s";
    return 0;
}