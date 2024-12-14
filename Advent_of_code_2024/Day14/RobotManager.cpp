#include "RobotManager.h"
#include "../_utils/Utils.h"

void RobotManager::addRobot(const Tuple& initialPosition, const Tuple& speed)
{
    m_robots.push_back(Robot(initialPosition, speed));
}

void RobotManager::update()
{
    for(auto& it : m_robots)
    {
        it.move();
    }
}

void RobotManager::draw()
{
    for(auto& it : m_robots)
    {
        const Tuple t = it.getPosition();
        printToCoordinates(t.x, t.y, "X");
    }
}