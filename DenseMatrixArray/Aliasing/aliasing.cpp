#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. two unexpect result
	// first
	Eigen::MatrixXi mat(3, 3);
	mat << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	std::cout << "Here is the matrix mat: \n" << mat << std::endl;
	mat.bottomRightCorner(2, 2) = mat.topLeftCorner(2, 2);
	std::cout << "After the assignment, mat is : \n" << mat << std::endl;  
	// mat(1, 1) = mat(0, 0), mat(1, 2) = mat(0, 1), mat(2, 1) = mat(1, 0), mat(2, 2) = mat(1, 1)

	// second 
	Eigen::Matrix2i a;
	a << 1, 2, 3, 4;
	std::cout << "Here is the matrix a: \n" << a << std::endl;
	// a = a.transpose();  //DEBUG
	//std::cout << "the result of transpose a is: \n" << a << std::endl; // 1, 2, 2, 4

	// resolving
	// first  eval()
	Eigen::MatrixXi mat1(3, 3);
	mat1 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	std::cout << "Here is the matrix mat: \n" << mat1 << std::endl;
	mat1.bottomRightCorner(2, 2) = mat1.topLeftCorner(2, 2).eval();
	std::cout << "After the assignment, mat = \n" << mat1 << std::endl;

	// second XXInplace()
	Eigen::Matrix2i a1;
	a1 << 1, 2, 3, 4;
	std::cout << "Here is the matrix a1: \n" << a1 << std::endl;
	a1.transposeInPlace();
	std::cout << "the result of transpose a1 is: \n" << a1 << std::endl;

	// 2. Aliasing and component-wise operations
	Eigen::MatrixXf mat2(2, 2);
	mat2 << 1, 2, 4, 7;
	std::cout << "Here is the matrix mat: \n" << mat2 << std::endl;
	mat2 = (2 * mat2 - Eigen::MatrixXf::Identity(2, 2)).array().square();
	std::cout << "mat2: \n" << mat2 << std::endl;

	// 3. Aliaing and matrix multiplication
	Eigen::MatrixXf matA(2, 2), matB(2, 2);
	matA << 2, 0, 0, 2;
	matB = matA * matA;
	std::cout << "matB: \n" << matB << std::endl;
	matB.noalias() = matA * matA;   // more efficient
	std::cout << "matB: \n" << matB << std::endl;
	return 0;
}
