#pragma once
#include "Tuple.h"
#include <vector>
#include <map>
#include "Robot.h"

class RobotManager
{
public:
    RobotManager() = default;
    ~RobotManager() = default;

    void addRobot(const Tuple& initialPosition, const Tuple& speed);
    void update();
    std::vector<Robot> generateRobots();
    void draw();

    std::map<int, int> getRobotsPerQuadrant();

private:
    std::vector<Robot> m_robots;
};