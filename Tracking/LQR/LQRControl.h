#include <iostream>
#define EPS 1.0e -4
#include <Eigen/Dense>
#include <vector>
using namespace std;
using namespace Eigen;

class LQRControl{
  private:
    int N;
  public:
    LQRControl(int n);

    MatrixXd calRicatti(MatrixXd A, MatrixXd B, MatrixXd Q, MatrixXd R);

    double lqrControl(vector<double> robot_state, vector<vector<double>> refer_path, double s0, MatrixXd A, MatrixXd B, MatrixXd Q, MatrixXd R);
};
