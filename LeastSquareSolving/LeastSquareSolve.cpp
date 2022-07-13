#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	Eigen::MatrixXd w(3, 3);
	w(0, 0) = 8.0;
	w(0, 1) = -4.0;
	w(0, 2) = 0.0;
	w(1, 0) = -4.0;
	w(1, 1) = 16.0;
	w(1, 2) = -4.0;
	w(2, 0) = 0.0;
	w(2, 1) = -4.0;
	w(2, 2) = 8.0;

	Eigen::Vector3d b{ 4.816496, -3.550510, 3.632993 };

	// 1. Using SVD decomposition, the input w need set to dynamic
	/*Eigen::JacobiSVD<Eigen::MatrixXd> svd(w, Eigen::ComputeThinU | Eigen::ComputeThinV);
	Eigen::Vector3d x = svd.solve(b); */
	// Eigen::Vector3d x = w.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b);  // need set attribute==> C/C++ ==> command line ==> other == /bigobj

	/*Eigen::CompleteOrthogonalDecomposition<Eigen::Matrix3d> dec(w);   // svd's faster alternative method
	Eigen::Vector3d x = dec.solve(b);*/

	// 2. Using QR decomposition
	// Eigen::Vector3d x = w.colPivHouseholderQr().solve(b);

	// 3. Using normal equations
	Eigen::Vector3d x = (w.transpose() * w).ldlt().solve(w.transpose() * b);   // w^T w x = w^T b

	std::cout << "x : \n" << x << std::endl;

	return 0;
}
