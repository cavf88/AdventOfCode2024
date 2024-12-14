#include "Robot.h"

Robot::Robot(Tuple initialPosition, Tuple speed)
: m_position(initialPosition)
, m_speed(speed)
{}

void Robot::move()
{
    m_position += m_speed;
}
void Robot::teleport()
{
    // blink
}