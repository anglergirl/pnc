#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "../../matplotlibcpp.h"
namespace plt = matplotlibcpp;

using namespace std;
using namespace Eigen;

#define PI 3.1415926
class RRT{
  public:
    struct Node{
      double x, y; //节点坐标
      vector<double> path_x = {}, path_y = {};
      Node(double x, double y);
      Node* parent;
      double cost;
    }
}
