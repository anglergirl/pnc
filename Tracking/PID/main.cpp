#include "PID_controller.h"
#include <algorithm>

#define PI 3.1415926

int main() {
    vector<vector<double>> refer_path(1000, vector<double>(2));
    vector<double> refer_x, refer_y;

    //生成参考轨迹
    for(int i = 0; i < 1000; i++) {
        refer_path[i][0] = 0.1 * i;
        refer_path[i][1] = 2 * sin(refer_path[i][0] / 3.0);
        refer_x.push_back(refer_path[i][0]);
        refer_y.push_back(refer_path[i][1]);
    }

    //运动学模型
    KinematicNodel ugv(0, -1, 0.5, 2, 2, 0.1);

    //PID控制器
    PID_controller PID(2, 0.01, 30, 0., PI/6, -PI/6);
    //保存机器人运动过程轨迹
    vector<double> x_, y_;
    //机器人状态
    vector<double> robot_state(2);

    //运行500个回合
    for(int = 0; i < 500; i++) {
        
    }
}