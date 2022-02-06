#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1.Accessing values inside an Array
	Eigen::ArrayXXf m(2, 2);
	m(0, 0) = 1.0;
	m(0, 1) = 2.0;
	m(1, 0) = 3.0;
	m(1, 1) = m(0, 1) + m(1, 0);
	std::cout << "m: \n" << m << std::endl;

	m << 1.0, 2.0, 3.0, 4.0;
	std::cout << "m: \n" << m << std::endl;

	// 2.Addition and subtraction
	Eigen::ArrayXXf a(3, 3);
	Eigen::ArrayXXf b(3, 3);
	a << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	b << 1, 2, 3, 1, 2, 3, 1, 2, 3;
	std::cout << "a + b = \n" << a + b << std::endl;
	std::cout << "a - b = \n" << a - b << std::endl;

	// 3.Array multiplication
	Eigen::ArrayXXf a3(2, 2);
	Eigen::ArrayXXf b3(2, 2);
	a3 << 1, 2, 3, 4;
	b3 << 5, 6, 7, 8;
	std::cout << "a * b = \n" << a3 * b3 << std::endl; // 对应相乘 类似系数

	// 4.Other coefficient-wise operations
	Eigen::ArrayXf a4 = Eigen::ArrayXf::Random(5);
	a *= 2;
	std::cout << "a = \n" << a4 << std::endl;
	std::cout << "a.abs() = \n" << a4.abs() << std::endl;
	std::cout << "a.abs().sqrt() = \n" << a4.abs().sqrt() << std::endl;
	std::cout << "a.min(a.abs().sqrt()) = \n" << a4.min(a4.abs().sqrt()) << std::endl;

	// 5.Converting between array and matrix expressions  
	// Array.matrix() convert array to matrix
	// Matrix.array() convert matrix to array
	Eigen::MatrixXf m5(2, 2);
	Eigen::MatrixXf n5(2, 2);
	Eigen::MatrixXf res(2, 2);
	m5 << 1, 2, 3, 4;
	n5 << 5, 6, 7, 8;
	res = m5 * n5;
	std::cout << "Matrix m*n : \n" << res << std::endl;
	
	res = m5.array() * n5.array();
	std::cout << "Array m*n: \n" << res << std::endl;

	res = m5.cwiseProduct(n5);
	std::cout << "With cwiseProduce: \n" << res << std::endl;

	res = m.array() + 4;
	std::cout << "Array m + 4: \n" << res << std::endl;

	return 0;
}
