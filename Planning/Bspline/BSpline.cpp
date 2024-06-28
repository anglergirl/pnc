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

/*
 准均匀B样条的节点向量计算
 首末值定义为0 和 1
 @param n 控制点个数 - 1，控制点共 n + 1个
 @param k B样条阶数k， k阶B样条， k-1次曲线
 @return
*/
vector<double> u_quasi_uniform(int n, int k) {
  vector<double> node_vector(n + k + 1);    //准均匀B样条的节点向量计算，共n+1个控制点，k-1次B样条，k阶
  double picewise = n - k + 2;   //B样条曲线的段数：控制点个数 - 次数
  if(piecewise == 1) {  //只有一段曲线时， n = k + 1
    for(int i = n + 1; i < n + k + 1; i++) node_vector[i] = 1
    
  }
 
}
