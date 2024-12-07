#include "Equation.h"

Equation::Equation(int result)
: m_result(result)
{}

void Equation::pushBackOperand(const int operand)
{
    m_operands.push_back(operand);
}