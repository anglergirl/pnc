#include "BSpline.h"
/**
  *基函数定义
    @param i
    @param k B样条阶数k
    @param u 自变量
    @param node_vector 节点向量 array([u0, u1, u2,.....,u_n+k]), shape = [1, n+k+1]
*/

double baseFunction(int i, int k, double u, vector<double> node_vector) {
  //0次B样条 （1阶B样条）
  double Bik_u;
  if(k == 1) {
    if(u >= node_vector[i] && u < node_vector[i + 1]) {
        Bik_u = 1;
    } else {
        Bik_u = 0;
    }
  } else {
    //编写公式
      //两个分母
      double denominator_1 = node_vector[i + k - 1]- node_vector[i];
      double denominator_2 = node_vector[i + k] - node_vector[i + 1];
      
      if(denominator_1 == 0) denominator_1 = 1;
      if(denominator_2 == 0) denominator_2 = 1;

      Bik_u = (u - node_vector[i]) / denominator_1 * baseFunction(i, k - 1, u, node_vector) + (node_vector[i + k] - u) / denominator_2 * baseFunction(i + 1, k - 1, u, node_vector)
  }

  return Bik_u;
}
