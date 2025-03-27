#include <math.h>
#include <vector>
#include <algorithm>

#include "practica6_pkg/msg/way_point_path.hpp"

class WayPointPathTools
{
    public:
    practica6_pkg::msg::WayPointPath path;
    double L;

    WayPointPathTools(practica6_pkg::msg::WayPointPath, double);
    
    geometry_msgs::msg::Point findClosestPointOnPath(double *dClosest, double x_rob, double y_rob);
    geometry_msgs::msg::Point p2sLookAheadDistance(const geometry_msgs::msg::Point& p1, const geometry_msgs::msg::Point& p2, const geometry_msgs::msg::Point& pi, double *d);
    std::vector<double> calculateRoots(const double &a0,const double &a1,const double &a2,const double &a3);
};
