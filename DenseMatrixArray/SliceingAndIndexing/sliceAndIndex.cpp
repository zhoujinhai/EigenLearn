#include <iostream>
#include <vector>
#include "Eigen/Dense"

int main(int argc, char * argv[]){
	
	// 1. basic slicing
	// seq(fisrtIdx, lastIdx, incr=1) ==> seq(2, 5) is {2, 3, 4, 5}
	// seqN(fisrtIdx, size. incr=1) ==> seqN(2, 3) is {2, 3, 4}
	// idx can be Eigen::last
	Eigen::Matrix4f m1;
	m1 << 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16;
	std::cout << m1(Eigen::seq(1, 3), Eigen::seqN(0, 3)) << std::endl;
	std::cout << m1(Eigen::all, Eigen::last - 1) << std::endl;

	// 2. vector lastN
	// lastN(size, incr=1) ==> lastN(3) is the vector's last 3 items
	Eigen::ArrayXf v(5);
	v << 1, 2, 3, 4, 5;
	std::cout << "The last 2 items of v is: " << std::endl << v(Eigen::lastN(2)) << std::endl << std::endl;

	// 3. Eigen::fix
	// v(seq(last - fix<7>, last - fix<2>)) == v(seqN(last - 7, fix<6>))
	std::cout << v(Eigen::seq(Eigen::last - Eigen::fix<3>, Eigen::last - Eigen::fix<1>)) << std::endl << std::endl;
	std::cout << v(Eigen::seqN(Eigen::last - 3, 3)) << std::endl;

	// 4. reverse order
	std::cout << "reverse: \n" << m1(Eigen::all, Eigen::seq(3, 1, Eigen::fix<-1>)) << std::endl;

	// 5. Array of indices
	std::vector<int> ind{4, 2, 5, 5, 3};
	Eigen::MatrixXi A = Eigen::MatrixXi::Random(4, 6);
	std::cout << "Init Matrix A: \n" << A << std::endl;
	std::cout << "A(all, ind): \n" << A(Eigen::all, ind) << std::endl;

	// 6. Custom index list
	struct pad {
		Eigen::Index size() const { return out_size; }
		Eigen::Index operator[](Eigen::Index i) const {
			return std::max<Eigen::Index>(0, i - (out_size - in_size));
		}
		Eigen::Index in_size, out_size;
	};
	Eigen::Matrix3i B;
	B.reshaped() = Eigen::VectorXi::LinSpaced(9, 1, 9);
	std::cout << "Init Matrix B: \n" << B << std::endl;
	Eigen::MatrixXi C(5, 5);
	C = B(pad{ 3, 5 }, pad{ 3, 5 });
	std::cout << "pad£º \n" << C << std::endl;

	return 0;
}
