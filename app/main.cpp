#include "Matrix.h"
#include <iostream>
using namespace std;
int main() {
	Matrix<double> C(3,3, 10, 100);
	Matrix<double> M = C * 100;
	Matrix<double> P = C / 1000;
	Matrix<double> A = P * C;
	C.print();
	M.print();
	P.print();
	A.print();
}