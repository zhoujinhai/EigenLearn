#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	Eigen::MatrixXd m = Eigen::MatrixXd::Random(3, 3);
	std::cout << "MatrixXd is : \n" << m << std::endl;

	m = (m + Eigen::MatrixXd::Constant(3, 3, 1.2)) * 50;  // 3 * 3 的常量矩阵，值为1.2
	std::cout << "add constant and mul: \n" << m << std::endl;

	Eigen::VectorXd v(3);
	v << 1, 2, 3;
	std::cout << "vector is: \n" << v << std::endl;

	std::cout << "m * v = \n" << m * v << std::endl;

	return 0;
}
