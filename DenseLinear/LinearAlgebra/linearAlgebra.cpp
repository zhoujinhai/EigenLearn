#include <iostream>
#include "Eigen/Dense"


int main(int argc, char * argv[]){
	// 1. Basic linear solving, Ax = b
	Eigen::Matrix3f A;
	Eigen::Vector3f b;
	A << 1, 2, 3, 4, 5, 6, 7, 8, 10;
	b << 3, 3, 4;
	std::cout << "Here is A: \n" << A << std::endl;
	std::cout << "Here is b: \n" << b << std::endl;
	Eigen::Vector3f x = A.colPivHouseholderQr().solve(b);
	std::cout << "The solution is :\n" << x << std::endl;

	Eigen::ColPivHouseholderQR<Eigen::Matrix3f> dec(A);
	Eigen::Vector3f x_ = dec.solve(b);
	std::cout << "The solution is :\n" << x_ << std::endl;

	Eigen::Matrix2f A1, b1;
	A1 << 2, -1, -1, 3;
	b1 << 1, 2, 3, 1;
	std::cout << "Here is the matrix A1: \n" << A1 << std::endl;
	std::cout << "Here is the right hand side b1: \n" << b1 << std::endl;
	Eigen::Matrix2f x1 = A1.ldlt().solve(b1);
	std::cout << "The solution is: \n" << x1 << std::endl;

	// 2. Least squares solving
	Eigen::MatrixXf A2 = Eigen::MatrixXf::Random(3, 2);
	std::cout << "Here is the matrix A2: \n" << A2 << std::endl;
	Eigen::VectorXf b2 = Eigen::VectorXf::Random(3);
	std::cout << "Here is the right hand side b2: \n" << b2 << std::endl;
	/*std::cout << "The least-squares solution is :\n" <<
		A2.bdcSvd(Eigen::ComputeThinU | Eigen::ComputeThinV).solve(b2) << std::endl;*/

	// 3. Checking if a matrix is singular
	// judge the error 
	Eigen::MatrixXd A3 = Eigen::MatrixXd::Random(100, 100);
	Eigen::MatrixXd b3 = Eigen::MatrixXd::Random(100, 50);
	Eigen::MatrixXd x3 = A3.fullPivLu().solve(b3);
	double relativeErr = (A3 * x3 - b3).norm() / b3.norm(); 
	std::cout << "The relative error is : \n" << relativeErr << std::endl;

	// 4. Computing eigenvalues and eigenvectors
	Eigen::Matrix2f A4;
	A4 << 1, 2, 2, 3;
	std::cout << "Here is the matrix A: \n" << A4 << std::endl;
	Eigen::SelfAdjointEigenSolver<Eigen::Matrix2f> eigenSolver(A4);
	if (eigenSolver.info() != Eigen::Success) {
		abort();
	}
	std::cout << "The eigenvalues of A4 are: \n" << eigenSolver.eigenvalues() << std::endl;
	std::cout << "The eigenvectors of A4 are: \n" << eigenSolver.eigenvectors() << std::endl;

	// 5. Computing inverse and determinant
	Eigen::Matrix3f A5;
	A5 << 1, 2, 1, 2, 1, 0, -1, 1, 2;
	std::cout << "Here is the matrix A5: \n" << A5 << std::endl;
	std::cout << "The determinant of A5 is: \n" << A5.determinant() << std::endl;
	std::cout << "The inverse of A: \n" << A.inverse() << std::endl;

	// 6. Separating the computation from the construction
	Eigen::Matrix2f A6, b6;
	Eigen::LLT<Eigen::Matrix2f> llt;
	A6 << 2, -1, -1, 3;
	b6 << 1, 2, 3, 1;
	std::cout << "Here is the matrix A6: \n" << A6 << std::endl;
	std::cout << "Here is the right hand side b6: \n" << b6 << std::endl;
	std::cout << "Computing LLT decomposition... \n" << std::endl;
	llt.compute(A6);
	std::cout << "The solution is: \n" << llt.solve(b6) << std::endl;
	
	// 7. Rank-revealing decompositions
	Eigen::Matrix3f A7;
	A7 << 1, 2, 5, 2, 1, 4, 3, 0, 3;
	std::cout << "Here is the matrix A7: \n" << A7 << std::endl;
	Eigen::FullPivLU<Eigen::Matrix3f> luDecomp(A7);
	std::cout << "The rank of A7 is: \n" << luDecomp.rank() << std::endl;
	std::cout << "Here is a matrix whose col from a basic of the null-space of A7: \n"
		<< luDecomp.kernel() << std::endl;
	std::cout << "Here is a matrix whose col from a basic of the col-space of A7: \n"
		<< luDecomp.image(A7);

	return 0;
}
