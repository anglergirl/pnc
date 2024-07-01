#include "PurePursuit.h"
#include "../utils/KinematicModel.h"
#include "../../matplotlibcpp.h"
namespace plt = matplotlibcpp;

#define PI 3.1415926

int main() {
    double x0 = 0.0, y0 = -1.0, psi = 0.5, v = 2, L = 2, dt = 0.1;
    double lam = 0.1;  //前视距离系数
    double c = 2; //前视距离

    vector<vector<double>> refer_path (1000, vector<double>(2));
    vector<double> refer_x, refer_y;

    for(int i = 0; i < 1000; i++) {
        refer_path[i][0] = i * 0.1;
        refer_path[i][1] = 2 * sin(refer_path[i][0] / 3.0) + 2.5 * cos(refer_path[i][0] / 2.0);
        refer_x.push_back(refer_path[i][0]);
        refer_y.push_back(refer_path[i][1]);
    }

    //运动学模型
    KinematicModel ugv(x0, y0, pai, v, L, dt);

    //保存机器人运行轨迹
    vector<double> x_, y_;

    //机器人状态
    vector<double> robot_state;
    PurePursuit pp;
    for(int i = 0; i < 600; i++) {
        robot_state[0] = ugv.x;
        robot_state[1] = ugv.y;

        double l_d = lam * ugv.v + c;
        double min_ind = PurePursuit::calTargetIndex(robot_state, refer_path, l_d);
        double delta = PurePursuit::purePursuitControl(robot_state, refer_path[min_ind], l_d, ugv.psi, L);
        ugv.updateState(0, delta);

        x_.push_back(ugv.x);
        y_.push_back(ugv.y);
    }   

    return 0;
}