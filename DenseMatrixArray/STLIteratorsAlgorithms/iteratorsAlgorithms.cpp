#include <iostream>
#include <algorithm>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. Iterating over 1D arrays and vectors
	Eigen::VectorXi v = Eigen::VectorXi::Random(4);
	std::cout << "Here is the vector v:\n";
	for (auto x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::sort(v.begin(), v.end());
	std::cout << "Here is sorted vector v: \n" << v.transpose() << std::endl;

	// 2. Iterating over coefficients of 2D arrays and matrices
	Eigen::Matrix2i A = Eigen::Matrix2i::Random();
	std::cout << "A: \n" << A << std::endl << "A.reshaped(): " << A.reshaped() << std::endl;
	std::cout << "Here is the coeffs of the 2*2 matrix A:\n";
	for (auto x : A.reshaped()) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	// 3. Iterating over rows or columns of 2D arrays and matrices
	Eigen::ArrayXXi B = Eigen::ArrayXXi::Random(4, 4).abs();
	std::cout << "Here is the initial matrix B: \n" << B << std::endl;
	for (auto row : B.rowwise()) {
		std::sort(row.begin(), row.end());
	}
	std::cout << "Here is the sorted matrix B by row: \n" << B << std::endl;

	return 0;
}
