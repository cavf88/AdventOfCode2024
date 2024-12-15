#include "Robot.h"
#include "Grid.h"

Robot::Robot(Tuple initialPosition, Tuple speed)
: m_position(initialPosition)
, m_speed(speed)
{}

void Robot::move()
{
    Tuple tempPosition = m_position;
    tempPosition += m_speed;

    if(tempPosition.x < 0)
        tempPosition.x = GRID_W - (abs(m_speed.x) - m_position.x);

    if (tempPosition.x >= GRID_W)
        tempPosition.x = tempPosition.x % GRID_W;

    if(tempPosition.y < 0)
        tempPosition.y = GRID_H - (abs(m_speed.y) - m_position.y);

    if(tempPosition.y >= GRID_H)
        tempPosition.y = tempPosition.y % GRID_H;

    m_position = tempPosition;
}