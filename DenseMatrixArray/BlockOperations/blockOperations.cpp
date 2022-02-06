#include <iostream>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. matrix.block(i, j, p, q) and matrix.block<p, q>(i, j) ==> block of size(p, q), starting at (i, j)
	Eigen::MatrixXf m(4, 4);
	m << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
	std::cout << "Block in the middle: " << std::endl;
	std::cout << m.block<2, 2>(1, 1) << std::endl;
	for (int i = 1; i <= 3; ++i) {
		std::cout << "Block of size£º " << i << "x" << i << std::endl;
		std::cout << m.block(0, 0, i, i) << std::endl;
	}

	// 2. block used as LValues
	Eigen::Array22f m2;
	m2 << 1, 2, 3, 4;

	Eigen::Array44f a2 = Eigen::Array44f::Constant(0.6);
	std::cout << "Here is the array a2: " << std::endl << a2 << std::endl;

	a2.block<2, 2>(1, 1) = m2;
	std::cout << "Here is now a2 with m2 copied into its central 2*2 block" << std::endl << a2 << std::endl;

	a2.block(0, 0, 2, 3) = a2.block(2, 1, 2, 3);
	std::cout << "Here is now a2 with bottom-right 2*3 block copied into top-left: " << std::endl << a2 << std::endl;

	// 3. columns and rows
	// i th row ==> matrix.row(i),  j th column ==> matrix.cols(j)
	Eigen::MatrixXf m3(3, 3);
	m3 << 1, 2, 3, 4, 5, 6, 7, 8, 9;
	std::cout << "Here is the matrix m3: " << std::endl << m3 << std::endl;
	std::cout << "2nd Row: " << std::endl << m3.row(1) << std::endl;
	m3.col(2) += 3 * m3.col(0);
	std::cout << "After adding 3 times the first column into the third col: " << std::endl << m3 << std::endl;

	// 4. Corner-releated operations
	// matrix.topLeftCorner(p, q) ==> Top left p by q block  | bottomLeftCorner/topRightCorner/bottomRightCorner
	// matrix.topRows(q) ==> block containing the first q rows |  matrix.bottomRows(q)
	// matrix.leftCols(p) ==> block containing the first p cols | matrix.rightCols(q)
	// matrix.middleCols(i, q) ==> Block containing the q cols starting from i  | matrix.middleRows(i, q)
	Eigen::Matrix4f m4;
	m4 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
	std::cout << "m.leftCols(2): " << std::endl << m4.leftCols(2) << std::endl;
	std::cout << "m.bottomRows<2>(): " << std::endl << m4.bottomRows<2>() << std::endl;
	m4.topLeftCorner(1, 3) = m4.bottomRightCorner(3, 1).transpose();
	std::cout << "After assignment, m4 = " << std::endl << m4 << std::endl;

	// 5. block operations for vectors
	// vector.head(n) ==> block containing the first n elements | vector.tail(n)
	// vector.segment(i, n) ==> block containing n elements, starting at position i
	Eigen::ArrayXf v(6);
	v << 1, 2, 3, 4, 5, 6;
	std::cout << "v.head(3): " << std::endl << v.head(3) << std::endl;
	std::cout << "v.tail<3>(): " << std::endl << v.tail(3) << std::endl;
	v.segment(1, 4) *= 2;
	std::cout << "After v.segment(1, 4) *= 2: " << std::endl << v << std::endl;

	return 0;
}
