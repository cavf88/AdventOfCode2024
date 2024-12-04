#include <iostream>
#include <string>
#include <map>
#include <fstream>

const static int MATRIX_SIZE = 141;
const static int PADDING_SIZE = 6;
const static int PADDING_VAL = 0;


using namespace std;

void initializeMatrix(int matrix[][MATRIX_SIZE + PADDING_SIZE])
{
    for(int i = 0; i < MATRIX_SIZE + PADDING_SIZE; i++)
    {
        for(int k = 0; k < MATRIX_SIZE + PADDING_SIZE; k++)
        {
            matrix[i][k] = PADDING_VAL;
        }
    }
}

int main()
{
    string inputLine;
    fstream inputFile("input.txt");


    int matrix[MATRIX_SIZE + PADDING_SIZE][MATRIX_SIZE + PADDING_SIZE];
    initializeMatrix(matrix);
    
    int rowNum = 0;
    while(getline(inputFile, inputLine))
    {
        for(int i = 0; i < inputLine.length() ; i++)
        {
            matrix[rowNum + PADDING_SIZE][i + PADDING_SIZE] = inputLine.at(i);
        }
        rowNum++;
    }




    inputFile.close();

    return 0;
}