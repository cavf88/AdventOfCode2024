#include "Equation.h"
#include <algorithm>
#include <bitset>
#include <iostream>
#include <math.h>
#include <sstream>




Equation::Equation(int result)
: m_result(result)
{}

Equation::Equation(const Equation& e)
{
    m_operands = e.m_operands;
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
        const int numbersOfOperands = pow(2, m_operands.size() - 1);
        std::vector<bool> permutations(numbersOfOperands);
        permutations[numbersOfOperands - 1] = true;
        do
        {  
            std::stringstream operandsSS;
            for (const auto& p : permutations) 
            {
                operandsSS << p;
            }
            m_operators.push_back(operandsSS.str());
        } while (std::next_permutation(permutations.begin(), permutations.end()));
    
        std::cout << std::endl;
    }
}