#include "RobotManager.h"

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