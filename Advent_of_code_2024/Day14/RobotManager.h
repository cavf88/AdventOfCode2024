#include "Tuple.h"
#include <vector>
#include "Robot.h"

class RobotManager
{
public:
    RobotManager() = default;
    ~RobotManager() = default;

    void addRobot(const Tuple& initialPosition, const Tuple& speed);
    void update();
    std::vector<Robot> generateRobots();
    // void draw();

private:
    std::vector<Robot> m_robots;
};