#include "Equation.h"
#include <algorithm>
#include <bitset>
#include <iostream>
#include <math.h>
#include <sstream>

const static int BIT_SIZE = 16;


Equation::Equation(int result)
: m_result(result)
{}

Equation::Equation(const Equation& e)
{
    m_operands = e.m_operands;
    m_result = e.m_result;
    generateOperators();
}

void Equation::pushBackOperand(const int operand)
{
    m_operands.push_back(operand);
}

void Equation::generateOperators()
{
    if(m_operands.size() == 2)
    {
        m_operators.push_back("1");
        m_operators.push_back("0");
    }
    else
    {
        // permutate between the table of values for operators
        const int numbersOfOperands = pow(2, m_operands.size() - 1);
        for(int i = 0; i < numbersOfOperands; ++i)
        {
            // Safe size 16
            std::bitset<BIT_SIZE> b(i);
            std::string operatorStr = b.to_string();
            // Trim the trailing 0s
            operatorStr = operatorStr.substr(operatorStr.size() - m_operands.size() + 1);
            m_operators.push_back(operatorStr);
        }

        //const int numbersOfOperands = pow(2, m_operands.size() - 1);
        //std::vector<bool> permutations(numbersOfOperands);
        //permutations[numbersOfOperands - 1] = true;
        //do
        //{  
        //    std::stringstream operandsSS;
        //    for (const auto& p : permutations) 
        //    {
        //        operandsSS << p;
        //    }
        //    m_operators.push_back(operandsSS.str());
        //} while (std::next_permutation(permutations.begin(), permutations.end()));
    //
        //std::cout << std::endl;
    }
}

bool Equation::isEquationValid()
{
    for(const auto& op : m_operators)
    {
        std::string operandsStr = op;
        int result = m_operands[0];
        for(int i = 1; i < m_operands.size(); ++i)
        {
            if(operandsStr[i-1] == '1')
            {
                result += m_operands[i];
            }
            else
            {
                result *= m_operands[i];
            }

            if(result == m_result)
            {
                return m_result;
            }
        }
         
    }
    return false;
}