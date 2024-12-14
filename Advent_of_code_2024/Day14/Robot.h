#include "Tuple.h"

class Robot
{
public:
    Robot(const Tuple initialPos, const Tuple speed);
    ~Robot() = default;
    void move();
    void teleport();
private:
    Tuple m_position;
    Tuple m_speed;
};