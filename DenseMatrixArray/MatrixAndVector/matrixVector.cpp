#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1.Addition and subtraction
	Eigen::Matrix2d a;
	a << 1, 2, 3, 4;
	Eigen::MatrixXd b(2, 2);
	b << 2, 3, 1, 4;

	std::cout << "a + b = \n" << a + b << std::endl;
	std::cout << "a - b = \n" << a - b << std::endl;
	std::cout << "Doing a += b: " << std::endl;
	a += b;
	std::cout << "Now a = \n" << a << std::endl;
	Eigen::Vector3d v(1, 2, 3);
	Eigen::Vector3d w(1, 0, 0);
	std::cout << "-v + w - v = \n" << -v + w - v << std::endl;

	// 2. Scalar multiplication and division
	std::cout << "a * 2.5 = \n" << a * 2.5 << std::endl;
	std::cout << "0.1 * v = \n" << 0.1 * v << std::endl;
	std::cout << "Doing v*=2: " << std::endl;
	v *= 2;
	std::cout << "Now v = \n" << v << std::endl;

	// 3. A note about expression templates
	Eigen::VectorXf a3(5), b3(5), c3(5), d3(5);
	b3 << 1, 2, 3, 4, 5;
	c3 << 2, 2, 1, 1, 3;
	d3 << 1, 3, 2, 5, 2;
	a3 = 3 * b3 + 4 * c3 + 5 * d3;
	std::cout << "a5 = \n" << a3 << std::endl;

	// 4. Transposition and conjugation
	Eigen::MatrixXcf a4 = Eigen::MatrixXcf::Random(2, 2);
	std::cout << "Here is the matrix a \n" << a4 << std::endl;
	std::cout << "Here is the matrix a^T \n" << a4.transpose() << std::endl;  // 转置
	std::cout << "Here is the conjugate of a \n" << a4.conjugate() << std::endl; // 共轭
	//std::cout < "Here is the matrix a^* \n " << a4.adjoint() << std::endl;   // 共轭转置

	// 5.Matrix-maatrix and matrix-vector mltiplication
	Eigen::Matrix2d mat;
	mat << 1, 2, 3, 4;
	Eigen::Vector2d u5(-1, 1), v5(2, 0);
	std::cout << "mat: \n" << mat << " u:\n" << u5 << " v:\n" << v5 << std::endl;
	std::cout << "u5: " << u5.rows() << " " << u5.cols() << std::endl;
	std::cout << "Here is mat*mat: \n" << mat * mat << std::endl;
	std::cout << "Here is mat*u:\n" << mat * u5 << std::endl;
	std::cout << "Here is u^T*mat:\n" << u5.transpose() * mat << std::endl;
	std::cout << "Here is u^T*v:\n" << u5.transpose() * v5 << std::endl;
	std::cout << "Here is u*v^T:\n" << u5 * v5.transpose() << std::endl;
	std::cout << "Let's multiply mat by itself" << std::endl;
	mat = mat * mat;
	std::cout << "Now mat is mat:\n" << mat << std::endl;

	// 6.Dot product and cross product
	Eigen::Vector3d v6(1, 2, 3);
	Eigen::Vector3d w6(0, 1, 2);

	std::cout << "Dot product: " << v6.dot(w6) << std::endl;
	std::cout << "Dot produce via a matrix product: " << v6.adjoint() * w6 << std::endl;
	std::cout << "Cross product: " << v6.cross(w6) << std::endl;

	// 7.Basic arithmetic reduction operations
	Eigen::Matrix2d mat7;
	mat7 << 1, 2, 3, 4;
	std::cout << "Here is mat.sum():       " << mat7.sum() << std::endl;
	std::cout << "Here is mat.prod():      " << mat7.prod() << std::endl;
	std::cout << "Here is mat.mean():      " << mat7.mean() << std::endl;
	std::cout << "Here is mat.minCoeff():  " << mat7.minCoeff() << std::endl;
	std::cout << "Here is mat.maxCoeff():  " << mat7.maxCoeff() << std::endl;
	std::cout << "Here is mat.trace():     " << mat7.trace() << std::endl; // 矩阵的迹

	Eigen::Matrix3f m6 = Eigen::Matrix3f::Random(); 
	std::ptrdiff_t i, j;
	float minOfM6 = m6.minCoeff(&i, &j);
	std::cout << "Here is the matrix m6 :\n" << m6 << std::endl;
	std::cout << "Its minimum coefficient (" << minOfM6 << ") is at position (" << i << ", " << j << ")\n" << std::endl;

	return 0;
}
