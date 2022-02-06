#include <iostream>
#include <vector>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. Reductions
	Eigen::VectorXf v(2);
	Eigen::MatrixXf m(2, 2), n(2, 2);
	v << -1, 2;
	m << 1, -2, -3, 4;
	// ·¶Êý
	std::cout << "v.squaredNorm() = " << v.squaredNorm() << std::endl;
	std::cout << "v.norm() = " << v.norm() << std::endl;
	std::cout << "v.lpNorm<1>() = " << v.lpNorm<1>() << std::endl;
	std::cout << "v.lpNorm<Infinity>() = " << v.lpNorm<Eigen::Infinity>() << std::endl;

	std::cout << "m.squaredNorm() = " << m.squaredNorm() << std::endl;
	std::cout << "m.norm() = " << m.norm() << std::endl;
	std::cout << "m.lpNorm<1>() = " << m.lpNorm<1>() << std::endl;
	std::cout << "v.lpNorm<Infinity>() = " << m.lpNorm<Eigen::Infinity>() << std::endl;

    // 2. Boolean reductions
	Eigen::ArrayXXf a(2, 2);
	a << 1, 2, 3, 4;
	std::cout << "(a > 2).all() = " << (a > 2).all() << std::endl;
	std::cout << "(a > 2).any() = " << (a > 2).any() << std::endl;
	std::cout << "(a > 2).count() = " << (a > 2).count() << std::endl;
	
	// 3. Visitors
	Eigen::MatrixXf::Index maxRow, maxCol;
	float max = m.maxCoeff(&maxRow, &maxCol);
	Eigen::MatrixXf::Index minRow, minCol;
	float min = m.minCoeff(&minRow, &minCol);
	std::cout << "Max: " << max << " at: " << maxRow << ", " << maxCol << std::endl;
	std::cout << "Min: " << min << " at: " << minRow << ", " << minCol << std::endl;

	// 4. Partial reductions
	Eigen::MatrixXf mat(2, 4);
	mat << 1, 2, 6, 9,
		3, 1, 7, 2;
	std::cout << "Column's maximum: " << std::endl << mat.colwise().maxCoeff() << std::endl;

	// 5. Combining partial reductions with other operations
	Eigen::MatrixXf::Index  maxIndex;
	float maxNorm = mat.colwise().sum().maxCoeff(&maxIndex);

	std::cout << "Maximum sum at position " << maxIndex << std::endl;

	std::cout << "The corresponding vector is: " << std::endl;
	std::cout << mat.col(maxIndex) << std::endl;
	std::cout << "And its sum is is: " << maxNorm << std::endl;

	// 6. Broadcasting
	mat.colwise() += v;
	std::cout << "Boardcasting result: \n" << mat << std::endl;

	return 0;
}
