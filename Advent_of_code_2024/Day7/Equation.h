#include <vector>

class Equation
{
    public:
        Equation() = default;
        Equation(const int result);
        ~Equation() = default;

        void pushBackOperand(const int operand);
    
    private:
        std::vector<int> m_operands;
        std::vector<char> m_operators;
        int m_result = 0;
};