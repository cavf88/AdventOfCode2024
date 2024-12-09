#include "Equation.h"
#include <algorithm>
#include <bitset>
#include <iostream>
#include <math.h>
#include <sstream>

const static int BIT_SIZE = 16;


Equation::Equation(int64_t result)
: m_result(result)
{}

Equation::Equation(const Equation& e)
{
    m_operands = e.m_operands;
    m_result = e.m_result;
    generateOperators();
}

std::ostream& operator<<(std::ostream& os, const Equation& e)
{
    os << e.m_result << ":";
    for(const auto& i : e.m_operands)
    {
        os << " " << i;
    }
    os << std::endl;
    os << "number of permutiations for operators: " << e.m_operators.size();

    return os;
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
    }
}

void Equation::generateConcatenationOperators()
{
    for(int i = 0; i < m_operands.size(); i++)
    {
        for(int k = 1; k < m_operands.size() - 1; k++)
        {

        }
    }
}

bool Equation::isEquationValid(bool concatenate)
{
    if(m_operands.size() == 0)
        return false;

    if(m_operands.size() == 1 && m_operands[0] ==  m_result)
        return true;

    if(concatenate)
        

    for(const auto& op : m_operators)
    {
        std::string operandsStr = op;
        int64_t result = m_operands[0];
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

// icomplete contation as I am giving precedence to the || operator instead of treating it from left to right.
int64_t Equation::getConcatenatedValue()
{
    int i = 0;
    int k = i + 1;
    std::vector<Equation> concatenatedEquation;
    do
    {
        Equation e(m_result);
        std::string operandStr = std::to_string(m_operands[i]) + std::to_string(m_operands[k]);
        for(int j = 0; j < m_operands.size(); ++j)
        {
            if(j == i)
                continue;
            else if(j == k)
                e.pushBackOperand(atoi(operandStr.c_str()));
            else
                e.pushBackOperand(m_operands[j]);
        }
        i++;
        k++;
        concatenatedEquation.push_back(e);
    } while (k < m_operands.size());

    for(auto& e : concatenatedEquation)
    {
        if(e.isEquationValid())
            return e.getResult();
    }

    return 0;
}