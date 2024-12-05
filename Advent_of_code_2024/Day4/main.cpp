#include <iostream>
#include <string>
#include <map>
#include <fstream>

const static int MATRIX_SIZE_H = 140;
const static int MATRIX_SIZE_W = 141;
const static int PADDING_SIZE = 10;
const static int PADDING_VAL = 0;

using namespace std;

void part1(int matrix[][MATRIX_SIZE_W + PADDING_SIZE])
{
    int sum  = 0;
    for(int i = 0; i < MATRIX_SIZE_H; i++)
    {
        for(int k = 0; k < MATRIX_SIZE_W; k++)
        {
            const int position = ((PADDING_SIZE + i) * 10) + (PADDING_SIZE + k);
            //right
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i][PADDING_SIZE + k + 1] == 'M' &&
                matrix[PADDING_SIZE + i][PADDING_SIZE + k + 2] == 'A' && matrix[PADDING_SIZE + i][PADDING_SIZE + k + 3] == 'S')
            {
                sum++;
            }
            // left
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i][PADDING_SIZE + k - 1] == 'M' &&
                matrix[PADDING_SIZE + i][PADDING_SIZE + k - 2] == 'A' && matrix[PADDING_SIZE + i][PADDING_SIZE + k - 3] == 'S')
            {
                sum++;
            }
            // down
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k] == 'M' &&
                matrix[PADDING_SIZE + i + 2][PADDING_SIZE + k] == 'A' && matrix[PADDING_SIZE + i + 3][PADDING_SIZE + k] == 'S')
            {
                sum++;
            }

            // up
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k] == 'M' &&
                matrix[PADDING_SIZE + i - 2][PADDING_SIZE + k] == 'A' && matrix[PADDING_SIZE + i - 3][PADDING_SIZE + k] == 'S')
            {
                sum++;
            }

            // diagonal right up
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k + 1] == 'M' &&
                matrix[PADDING_SIZE + i - 2][PADDING_SIZE + k + 2] == 'A' && matrix[PADDING_SIZE + i - 3][PADDING_SIZE + k + 3] == 'S')
            {
                sum++;
            }

            // diagonal right down
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k + 1] == 'M' &&
                matrix[PADDING_SIZE + i + 2][PADDING_SIZE + k + 2] == 'A' && matrix[PADDING_SIZE + i + 3][PADDING_SIZE + k + 3] == 'S')
            {
                sum++;
            }

            // diagonal leftup
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k - 1] == 'M' &&
                matrix[PADDING_SIZE + i - 2][PADDING_SIZE + k - 2] == 'A' && matrix[PADDING_SIZE + i - 3][PADDING_SIZE + k - 3] == 'S')
            {
                sum++;
            }

            // diagonal left down
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'X' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k - 1] == 'M' &&
                matrix[PADDING_SIZE + i + 2][PADDING_SIZE + k - 2] == 'A' && matrix[PADDING_SIZE + i + 3][PADDING_SIZE + k - 3] == 'S')
            {
                sum++;
            }
        }
    }

    cout << sum << endl;
}

void part2(int matrix[][MATRIX_SIZE_W + PADDING_SIZE])
{
    int sum  = 0;
    for(int i = 0; i < MATRIX_SIZE_H; i++)
    {
        for(int k = 0; k < MATRIX_SIZE_W; k++)
        {
            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'A' && 
            matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k - 1] == 'M' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k + 1] == 'M' && 
            matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k - 1] == 'S' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k + 1] == 'S')
            {
                sum++;
            }

            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'A' && 
            matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k - 1] == 'S' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k + 1] == 'S' && 
            matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k - 1] == 'M' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k + 1] == 'M')
            {
                sum++;
            }

            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'A' && 
            matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k - 1] == 'M' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k + 1] == 'S' && 
            matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k - 1] == 'M' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k + 1] == 'S')
            {
                sum++;
            }

            if(matrix[PADDING_SIZE + i][PADDING_SIZE + k] == 'A' && 
            matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k - 1] == 'S' && matrix[PADDING_SIZE + i - 1][PADDING_SIZE + k + 1] == 'M' && 
            matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k - 1] == 'S' && matrix[PADDING_SIZE + i + 1][PADDING_SIZE + k + 1] == 'M')
            {
                sum++;
            }
        }
    }

    cout << sum;
}

void initializeMatrix(int matrix[][MATRIX_SIZE_W + PADDING_SIZE])
{
    for(int i = 0; i < MATRIX_SIZE_H + PADDING_SIZE; i++)
    {
        for(int k = 0; k < MATRIX_SIZE_W + PADDING_SIZE; k++)
        {
            matrix[i][k] = PADDING_VAL;
        }
    }
}

int main()
{
    string inputLine;
    fstream inputFile("input.txt");


    int matrix[MATRIX_SIZE_H + PADDING_SIZE][MATRIX_SIZE_W + PADDING_SIZE];
    initializeMatrix(matrix);
    
    int rowNum = 0;
    while(getline(inputFile, inputLine))
    {
        for(int i = 0; i < inputLine.length() ; i++)
        {
            matrix[PADDING_SIZE + rowNum][PADDING_SIZE + i] = inputLine.at(i);
        }
        rowNum++;
    }

    part1(matrix);
    part2(matrix);
    inputFile.close();

    return 0;
}