#include "RRT.h"
#include "../utils/geometry_utils.h"

RRT::Node::Node(double x, double y) : x(x), y(y), parent(NULL), cost(0) {}

RRT::RRT(const vector<vector<double>> &obstacleList,
         const vector<double> &randArea, const vector<double> &playArea, double robotRadius, double expandDis,
         double goalSampleRate, int maxIter) :obstacle_list(obstacleList), rand_area(randArea), play_area(playArea), robot_radius(robotRadius),
         extend_dis(expandDis), goal_sample_rate(goalSampleRate), max_iter(maxIter){}


/*
  计算两个节点间的距离和方位角
    @param from_node
    @param to_node
    @return
*/

vector<double> RRT::calDisttanceAngle(RRT::Node * from_node, RRT::Node* to_node) {
  double dx = to_node->x - from_node->x;
  double dy = to_node->y - from_node->y;
  double d = sqrt(pow(dx, 2) + pow(dy, 2));
  double theta = atan2(dy, dx);
  return {d, theta};
}

/*
  判断是否有障碍物， 使用线段与圆形的相交性方法来实现
  @param node
  @return
*/
bool RRT::obstacleFree(Node* node) {
  auto isSegmentIntersectingObstacle = [this](const Point& p1, const Point& p2) {
    for(const auto& obs: obstacle_list) {
      Point obstacleCenter = {obs[0], obs[1]};
      double distance = distanceBetweenPoints(p1, p2);
      const Point closestPointOnLine = closestPointOnSegment(p1, p2, obstacleCenter);
      double dis_to_center = distanceBetweenPoints(obstacleCenter, closestPointOnLine);
      if(dis_to_center <= obs[2] + robot_radius && dis_to_center >= 0 && dist_to_center <= distance) {
        return true;
      }
    }
    return false;
  };
  for(int i = 0; i < node->path_x.size() - 1; i++) {
    Point point1 = {node->path_x[i], node->path_y[i]};
    Point point2 = {node->path_x[i + 1], node->path_y[i + 1]};
    if(isSegmentIntersectingObstacle(point1, point2)) {
      return fasle;
    }
  }
  return true;
}
/*
  判断是否在可行区域内
  @param node 
  @return
*/

bool RRT::isInsidePlayArea(RRT::Node* node) {
  if(node->x < play_area[0] || node->x > play_area[1] || node->y < play_area[2] || node->y > play_area[3]) {
    return false;
  }
  return true;
}

/*
计算最近节点
@param node_list 节点列表
@param rnd_node  随机采样的节点
@return 最近的节点索引
*/
int RRT::getNearestNodeIndex(vector<Node*> node_list, RRT::Node* rnd_node) {
  int min_index = -1;
  double d = numeric_limits<double>::max();
  for(int i = 0; i < node_list.size(); i++) {
    Node* node = node_list[i];
    doubld dis = pow(node->x - rnd_node->x, 2) + pow(node->y - rnd_node->y, 2);
    if(d > dist) {
      d = dist;
      min_index = i;
    }
  }
  return min_index;
}

void RRT::setBegin(RRT::Node* begin) {
         RRT::begin = begin;
}

void RRT::setAnEnd(RRT::Node* anEnd) {
         RRT::end = anEnd;
}

/*
计算(x,y)距离目标点的距离
@param x
@param y
@return
*/
double RRT::calDistToGoal(double x, double y) {
         double dx = x - end->x;
         double dy = y - end->y;
         return sqrt(pow(dx, 2) + pow(dy, 2));
}
