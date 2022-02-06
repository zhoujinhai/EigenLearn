#include <iostream>
#include <algorithm>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. map types and declaring map variables
	// Map<typename MatrixType, int MapOptions, typename StrideType>
	int arr[8];
	for (int i = 0; i < 8; ++i) {
		arr[i] = i;
	}
	std::cout << "Column-major: \n" << Eigen::Map<Eigen::Matrix<int, 2, 4>>(arr) << std::endl;
	std::cout << "Row-major: \n" << Eigen::Map<Eigen::Matrix<int, 2, 4, Eigen::RowMajor>>(arr) << std::endl;
	std::cout << "Row-major using stride:\n" << 
		Eigen::Map<Eigen::Matrix<int, 2, 4>, Eigen::Unaligned, Eigen::Stride<1, 4>>(arr) << std::endl;

	// 2. Using map variables
	typedef Eigen::Matrix<float, 1, Eigen::Dynamic> MatrixType;
	typedef Eigen::Map<MatrixType> MapType;
	typedef Eigen::Map<const MatrixType> MapTypeConst;  // read only
	const int dims = 5;

	MatrixType m1(dims), m2(dims);
	m1.setRandom();
	m2.setRandom();
	float* p = &m2(0);   // get the address storing the data for m2
	MapType m2Map(p, m2.size());  // m2map shares data with m2
	MapTypeConst m2MapConst(p, m2.size());

	std::cout << "m1: \n" << m1 << std::endl;
	std::cout << "m2: \n" << m2 << std::endl;
	std::cout << "Squared euclidean distance: \n" << (m1 - m2).squaredNorm() << std::endl;
	std::cout << "Squared euclidean distance: \n" << (m1 - m2Map).squaredNorm() << std::endl;
	m2Map(3) = 10;    // this will change m2
	std::cout << "Updated m2: \n" << m2 << std::endl;
	std::cout << "m2 coefficient 2, constant accessor: \n" << m2MapConst(2) << std::endl;

	/// 3. Changing the mapped array
	int data[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	Eigen::Map<Eigen::RowVectorXi> v(data, 3);
	std::cout << "The mapped vector v is: \n" << v << std::endl;
	new (&v) Eigen::Map<Eigen::RowVectorXi>(data + 3, 5);
	std::cout << "Now v is : \n" << v << std::endl;
	return 0;
}
