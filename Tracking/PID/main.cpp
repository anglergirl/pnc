#include<iostream>
#include "PID_controller.h"
#include "../utils/KinematicModel.h"
#include "../../matplotlibcpp.h"
namespace plt = matplotlibcpp;
#define PI 3.1415926

/**
 * 得到距离参考轨迹最近点的下标
 * @param robot_state 机器人状态（x,y）
 * @param refer_path  参考路径
 * @return 距离参考轨迹最近点的下标
 */
double calTargetIndex(vector<double> robot_state, vector<vector<double>> refer_Path) {
    vector<double> dists;
    for(vector<double>xy : refer_path) {
        double dist = sqrt(pow(xy[0] - robot_state[0], 2) + pow(xy[1] - robot_state[1], 2));
        dists.push_back(dis);
    }
    return min_element(dists.begin(), dists.end()) - dists.begin();
}

int main() {
    vector<vector<double>> refer_path(1000, vector<double>(2));  //1000个 (x, y)点
    vector<double> refer_x, refer_y;

    //生成参考轨迹
    for(int i = 0; i < 1000; i++) {
        refer_path[i][0] = 0.1 * i;
        refer_path[i][1] = 2 * sin(refer_path[i][0] / 3.0);
        refer_x.push_back(refer_path[i][0]);
        refer_y.push_back(refer_path[i][1]);
    }

    //运动学模型
    KinematicNodel ugv(0, -1, 0.5, 2, 2, 0.1);  // x y 偏航角 速度 轴距 采样时间

    //PID控制器
    PID_controller PID(2, 0.01, 30, 0., PI/6, -PI/6);  //ki kp kd target upper lower
    //保存机器人运动过程轨迹
    vector<double> x_, y_;
    //机器人状态
    vector<double> robot_state(2);

    //运行500个回合
    for(int = 0; i < 500; i++) {
        plt::clf();
        robot_state[0] = ugv.x;
        robot_state[1] = ugv.y;

        //参考博客中公式
        //机器人当前位置与参考线的最短距离
        double min_ind = calTargetIndex(robot_state, refer_path);
        double alpha = atan2(refer_path[min_ind][1] - robot_state[1], refer_path[min_ind][0] - robot_state[0]);
        double l_d = sqrt(pow(refer_path[min_ind][0] - robot_state[0], 2) + pow(refer_path[min_ind][1] - robot_state[1], 2));
        double theta_e = alpha - ugv.psi;
        double e_y = -l_d * sin(theta_e);
        double delta_f = PID.calOutput(e_y);

        //更新机器人状态
        ugv.updateState(0, delta_f);
        x_.push_back(ugv.x);
        y_.push_back(ugv.y);

        //画图
        plt::plot(refer_x, refer_y, "b--");
        plt::plot(x_, y_, "r");
        plt::grid(true);
        plt::ylim(-2.5, 2.5);
        plt::pause(0.01);
    }

    return 0;
}