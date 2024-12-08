#include <vector>
#include <string>
#include <iostream>

class Equation
{
    public:
        Equation() = default;
        Equation(const int64_t result);
        Equation(const Equation& e);
        ~Equation() = default;

        friend std::ostream& operator<<(std::ostream& os, const Equation& e);

        void pushBackOperand(const int operand);
        bool isEquationValid();
        int64_t getConcatenatedValue();
        int64_t getResult() {return m_result;};

    private:
        std::vector<int> m_operands;
        std::vector<std::string> m_operators;
        int64_t m_result = 0;

        void generateOperators();
        
};