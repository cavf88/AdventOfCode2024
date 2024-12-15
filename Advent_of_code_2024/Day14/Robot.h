#pragma once
#include "Tuple.h"

class Robot
{
public:
    Robot(const Tuple initialPos, const Tuple speed);
    ~Robot() = default;

    const Tuple getPosition(){return m_position;};

    void move();
private:
    Tuple m_position;
    Tuple m_speed;
};