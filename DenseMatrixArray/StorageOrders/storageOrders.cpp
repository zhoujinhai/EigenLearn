#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. column-major and row-major storage
	Eigen::Matrix<int, 3, 4, Eigen::ColMajor> AColMajor;
	AColMajor << 8, 2, 2, 9,
		9, 1, 4, 4,
		3, 5, 4, 5;
	std::cout << "The matrix A: " << std::endl << AColMajor << std::endl;

	std::cout << "In memory (column-major): \n";
	for (int i = 0; i < AColMajor.size(); ++i) {
		std::cout << *(AColMajor.data() + i) << " ";
	}
	std::cout << std::endl;

	Eigen::Matrix<int, 3, 4, Eigen::RowMajor> ARowMajor = AColMajor;
	std::cout << "In memory (row-major): \n";
	for (int i = 0; i < ARowMajor.size(); ++i) {
		std::cout << *(ARowMajor.data() + i) << " ";
	}
	std::cout << std::endl;

	return 0;
}
