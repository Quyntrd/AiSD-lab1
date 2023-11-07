#include "Matrix.h"
#include <iostream>
#include <complex>
using namespace std;
int main() {
	Matrix<int> A(3, 4);
	Matrix<int> B(4, 6, 10);
	Matrix<int> C(4, 4, 10, 1);
	Matrix<int> F(4, 4, 20, 1);
	Matrix<float> D(2, 2, 5.0);
	Matrix<float> D1(2, 2, 5.0);
	Matrix<double> E(2, 3, 25.0, 25.0);
	Matrix<int> AB = C * F;
	Matrix<int> AG = C + F;
	Matrix<int> Af = C - F;
	Matrix<int> Bs = B * 10;
	Matrix<float> Dj = D / 10;
	Matrix<complex<int>> Com(3, 3, complex<int>(1, 1));
	A.print();
	B.print();
	C.print();
	F.print();
	D.print();
	E.print();
	AB.print();
	AG.print();
	Af.print();
	Bs.print();
	Dj.print();
	Com.print();
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

}