#include <vector>
#include <string>
#include <iostream>

class Equation
{
    public:
        Equation() = default;
        Equation(const int result);
        Equation(const Equation& e);
        ~Equation() = default;

        friend std::ostream& operator<<(std::ostream& os, const Equation& e);

        void pushBackOperand(const int operand);
        bool isEquationValid();
        int getResult() {return m_result;};

    private:
        std::vector<int> m_operands;
        std::vector<std::string> m_operators;
        int m_result = 0;

        void generateOperators();
        
};