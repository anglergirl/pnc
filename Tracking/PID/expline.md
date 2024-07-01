[tcp]
# PID实现思路
## 创建运动模型
![avatar](https://img-blog.csdnimg.cn/973fa55b5b4a45989767b8be63eb11c3.png)

横向跟踪误差为车辆中心点(rx, ry)到最近路径点(px, py)的距离
![avatar](https://img-blog.csdnimg.cn/6dccc25c2a90468d88a716f92a6b751d.png)

假设车辆运动学模型为以后轴中心为车辆中心的单车运动学模型，公式如下
```
x = V * sin(γ)
y = V * sin(γ)
γ = V/L tan(theta_f)
V = a


//对应代码
void KinematicModel::updateState(double accel, double delta_f) {
    x = x + v* cos(psi)*dt;
    y = y + v*sin(psi)*dt;
    psi = psi + v / L * tan(delta_f)*dt;
    v = v + accel*dt;
}
```

```
根据上图可知：
theta_e = a - γ
γ：航向角
ey:横向跟踪误差
ld:前视距离-----后轴中心离当前露点的距离

ey = ld * sin(theta_e)
```
