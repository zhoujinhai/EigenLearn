#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. Reshaped 2D views
	Eigen::Matrix4i m = Eigen::Matrix4i::Random();
	std::cout << "Here is the matrix m: \n" << m << std::endl;
	std::cout << "Here is m.reshaped(2, 8): \n" << m.reshaped(2, 8) << std::endl;

	// 2. 1D linear views
	std::cout << "Here is m.reshaped().transpose(): \n" << m.reshaped().transpose() << std::endl;
	std::cout << "Here is m.reshaped<RowMajor>().transpose(): \n" << m.reshaped<Eigen::RowMajor>().transpose() << std::endl;

	// 3. reshape inplace
	Eigen::MatrixXi m1 = Eigen::Matrix4i::Random();
	std::cout << "The m is \n" << m << std::endl;
	std::cout << "Here is m.reshaped(2, 8): \n" << m1.reshaped(2, 8) << std::endl;
	m1.resize(2, 8);
	std::cout << "Here is the matrix m after m.resize(2, 8): \n" << m1 << std::endl;

	return 0;
}
