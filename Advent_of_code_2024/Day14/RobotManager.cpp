#include "RobotManager.h"
#include "../_utils/Utils.h"
#include "Grid.h"

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
        Utils::printToCoordinates(t.x, t.y, "X");
    }
}

std::map<int, int> RobotManager::getRobotsPerQuadrant()
{
    std::map<int, int> result;

    const int halfH = (GRID_H / 2) + 1;
    const int halfW = (GRID_W / 2) + 1;

    for (auto& r : m_robots)
    {
        Tuple pos = r.getPosition();
        // 1st quadrant
        if (pos.x < halfW && pos.y < halfH)
        {
            result[0] += 1;
            continue;
        }

        // second quadrant
        if(pos.x > halfW && pos.y < halfH)
        {
            result[1] += 1;
            continue;
        }

        // third quadrant
        if (pos.x < halfW && pos.y > halfH)
        {
            result[2] += 1;
            continue;
        }

        // fourth quadrant
        if (pos.x > halfW && pos.y > halfH)
        {
            result[3] += 1;
            continue;
        }
    }

    return result;
}