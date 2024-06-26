#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <Eigen/Dense>
using namespace std;
using namespace Eigen;

double baseFunction(int i, int k, double u, vector<double> node_vector);

vector<double> u_quasi_uniform(int n, int k);

vector<double> u_piecewise_B_Spline(int n, int k);
