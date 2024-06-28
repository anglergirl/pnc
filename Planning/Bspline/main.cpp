#include "BSpline.h"


int main() {
  vector<double> x_ref, y_ref;
  for(int i = 0; i < Ps.size(); i++) {
    x_ref.push_back(Ps[i][0]);
    y_ref.push_back(Ps[i][1]);
  }

  vector<double> x_, y_;

  int n = Ps.size() - 1;   //控制点个数- 1
  int k = 3;    //k阶  k-1次B样条
  Vector2d p_u(0，0);
  vector<double> bik_u(n + 1);

  int flag;
  
}
