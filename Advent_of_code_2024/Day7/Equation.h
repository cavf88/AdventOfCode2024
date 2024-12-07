#include <vector>
#include <string>
#include <iostream>

class Equation
{
    public:
        Equation() = default;
        Equation(const std::int64_t result);
        Equation(const Equation& e);
        ~Equation() = default;

        friend std::ostream& operator<<(std::ostream& os, const Equation& e);

        void pushBackOperand(const int operand);
        bool isEquationValid();
        std::int64_t getResult() {return m_result;};

    private:
        std::vector<int> m_operands;
        std::vector<std::string> m_operators;
        std::int64_t m_result = 0;

        void generateOperators();
        
};