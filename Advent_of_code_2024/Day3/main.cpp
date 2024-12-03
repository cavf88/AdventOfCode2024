#include <fstream>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

//void part2()
//{
//    string inputLine;
//    fstream inputFile("input.txt");
//    int sum = 0;
//    int count = 0;
//    const regex expression("mul[(][0-9]*,[0-9]*[)]");
//
//    int doPos = 0;
//    int endDoPos = 0;
//    bool findDo = true;
//    string instructionToFind = "do";
//
//    while(getline(inputFile, inputLine))
//    {
//        while(findDo)
//        {
//            // found the end of a Do
//            endDoPos = inputLine.find(instructionToFind + "n't", endDoPos);
//        }
//
//        string newInput = inputLine.substr(doPos, endDoPos);
//
//        // now the end of a Do becomes the beginning
//        doPos = endDoPos;
//
//        smatch searchMatch;
//        while(regex_search(newInput, searchMatch, expression))
//        {
//            for(auto match : searchMatch)
//            {
//                int n1 = 0;
//                int n2 = 0;
//                sscanf(match.str().c_str() ,"mul(%d,%d)", &n1, &n2);
//                sum += n1 * n2;
//            }
//            newInput = searchMatch.suffix().str();
//            count++;
//        }
//
//        int instructionPos = 0;
//        bool isMulAllowed = true;
//        string instructionToFind = "don't";
//        while(instructionPos != string::npos)
//        {
//            string newInput;
//            //string instructionToFind;
//            //if(isMulAllowed)
//            //{
//            //    instructionToFind = "don't";
//            //}
//            //else
//            //{
//            //    instructionToFind = "do";
//            //}
//
//            int instructionPosTemp = inputLine.find(instructionToFind, instructionPos);
//            if(instructionPosTemp == string::npos) 
//                break;
//            if(instructionToFind == "do") //dont
//            {
//                if(inputLine.at(instructionPosTemp + 2) == 'n')
//                {
//                    instructionPos = instructionPosTemp + 2;
//                    continue;
//                }
//                instructionToFind = "don't";
//            }
//            newInput = inputLine.substr(instructionPos, instructionPos + instructionPosTemp);
//            if(instructionPosTemp != string::npos)
//                instructionPos = instructionPosTemp + instructionToFind.size();
//            else
//                instructionPos = string::npos;
//
//            //if(instructionToFind == "do")
//            //{
//                smatch searchMatch;
//
//                while(regex_search(newInput, searchMatch, expression))
//                {
//                    for(auto match : searchMatch)
//                    {
//                        int n1 = 0;
//                        int n2 = 0;
//                        sscanf(match.str().c_str() ,"mul(%d,%d)", &n1, &n2);
//                        sum += n1 * n2;
//                    }
//                    newInput = searchMatch.suffix().str();
//                    count++;
//                }
//                instructionToFind = "do";
//            //}
//        }
//        
//    }
//    cout << "Sum: " << sum << endl;
//    cout << "count: " << count << endl;
//
//    inputFile.close();
//
//}


void part1()
{
    string inputLine;
    fstream inputFile("input.txt");
    int sum = 0;
    int count = 0;
    const regex expression("mul[(][0-9]*,[0-9]*[)]");

    while(getline(inputFile, inputLine))
    {

        smatch searchMatch;

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

}

int main()
{
    part1();
    //part2();
}