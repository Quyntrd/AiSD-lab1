#include "Matrix.h"
#include <iostream>
#include <complex>
using namespace std;
int main() {
	srand(42);
	Matrix<int> A(3, 4);
	Matrix<int> B(4, 6, 10);
	Matrix<int> C(4, 4, 10, 1);
	Matrix<int> F(4, 4, 20, 1);
	Matrix<float> D(2, 2, 5.3);
	Matrix<float> D1(2, 2, 5.0);
	Matrix<double> E(2, 3, 25.0, 1.0);
	Matrix<int> AB = C * F;
	Matrix<int> AG = C + F;
	Matrix<int> Af = C - F;
	Matrix<int> Bs = B * 10;
	Matrix<float> Dj = D / 10;
	Matrix<complex<float>> Com(3, 3, complex<float>(10.0, 12.0), complex<float>(1.0, 1.0));
	cout << A;
	cout << C.track() << endl;
	if (D == D1) {
		cout << "True" << endl;
	}
	if (D != D1) {
		cout << "False" << endl;
	}
	cout << det(F, F.get_rows()) << endl;
	complanar(F, F.get_rows());
	complanar(D, D.get_rows());
	C(0, 0) = 1;
	C(0, 1) = 2;
	C(0, 2) = 3;
	C(0, 3) = 4;
	C(1, 0) = 5;
	C(1, 1) = 6;
	C(1, 2) = 7;
	C(1, 3) = 8;
	C(2, 0) = 2;
	C(2, 1) = 4;
	C(2, 2) = 6;
	C(2, 3) = 8;
	C(3, 0) = 10;
	C(3, 1) = 12;
	C(3, 2) = 14;
	C(3, 3) = 16;
	cout << det(C, C.get_rows()) << endl;
	complanar(C, C.get_rows());

}