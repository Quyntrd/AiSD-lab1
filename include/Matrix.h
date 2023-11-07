#pragma once
#include <random>
#include <stdexcept>
#include <complex>
#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
	T** _matrix;
	int _width;
	int _height;
public:
	Matrix():_width(0), _height(0), _matrix(nullptr) {};
	Matrix(int width, int height, T value) : _width(width), _height(height)
	{
		if (width < 0 || height < 0) throw runtime_error("Incorrect size of matrix");
		_matrix = (T**) new T * [width];
		for (int i = 0; i < width; i++) {
			_matrix[i] = (T*) new T[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				_matrix[i][j] = value;
			}
		}
	};
	Matrix(int width, int height) : _width(width), _height(height)
	{
		if (width < 0 || height < 0) throw runtime_error("Incorrect size of matrix");
		_matrix = (T**) new T * [width];
		for (int i = 0; i < width; i++) {
			_matrix[i] = (T*) new T[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				_matrix[i][j] = 0;
			}
		}
	};
	Matrix(int width, int height, T up, T low) : _width(width), _height(height)
	{
		if (width < 0 || height < 0) throw runtime_error("Incorrect size of matrix");
		srand(time(0));
		_matrix = (T**) new T * [width];
		for (int i = 0; i < width; i++) {
			_matrix[i] = (T*) new T[height];
		}
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				_matrix[i][j] = low+static_cast<T>(rand())/(static_cast<T>(RAND_MAX)/(up-low));
			}
		}
	};
	Matrix(const Matrix& other) {
		_width = other._width;
		_height = other._height;

		_matrix = (T**) new T * [_width];
		for (int i = 0; i < _width; i++) {
			_matrix[i] = (T*) new T[_height];
		}
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				_matrix[i][j] = other._matrix[i][j];
			}
		}

	};
	~Matrix() {
		if (_height > 0) {
			for (int i = 0; i < _width; i++) {
				delete[] _matrix[i];
			}
		}
		if (_width > 0) {
			delete[] _matrix;
		}
	};
	int get_rows() {
		return _width;
	};
	int get_columns() {
		return _height;
	};
	T get_matij(int i, int j) {
		if (_height < 0 && _width < 0) throw runtime_error("Invalid row/column");
		return _matrix[i][j];
	};

	T& operator()(int i, int j) {
		if ((i >= 0 && i <= _width) && (j >= 0 && j <= _height)) {
			return _matrix[i][j];
		}
		else throw runtime_error("Invalid row/column");
	};
	Matrix operator=(const Matrix& other) {
		if (_height > 0) {
			for (int i = 0; i < _width; i++) delete[] _matrix[i];
		}
		if (_width > 0) {
			delete[] _matrix;
		}
		_width = other._width;
		_height = other._height;
		_matrix = (T**) new T * [_width+1];
		for (int i = 0; i < _width; i++) {
			_matrix[i] = (T*) new T[_height+1];
		}
		for (int i = 0; i < _width; i++) {
			for (int j = 0; i < _height; j++) {
				_matrix[i][j] = other._matrix[i][j];
			}
		}
		return *this;
	};
	Matrix operator+(const Matrix other) const
	{
		if (_width != other._width || _height != other._height) {
			throw runtime_error("Invalid row/column");
		}
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
			}
		}
		return result;
	};
	Matrix operator-(const Matrix other) const
	{
		if (_width != other._width || _height != other._height) {
			throw runtime_error("Invalid row/column");
		}
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
			}
		}
		return result;
	};
	Matrix operator*(const Matrix other) const
	{
		if (_width != other._height) {
			throw runtime_error("Can't multiply these matrixes");
		}
		Matrix<T> result(_width, other._height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < other._height; j++) {
				T sum = 0;
				for (int k = 0; k < other._width; k++) {
					sum += _matrix[i][k] * other._matrix[k][j];
				}
				result(i, j) = sum;
			}
		}
		return result;
	};
	Matrix operator*(const T scalar) const
	{
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] * scalar;
			}
		}
		return result;
	};
	Matrix operator/(const T scalar) const
	{
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] / scalar;
			}
		}
		return result;
	};
	T track() {
		if (_width != _height) {
			throw runtime_error("Matrix is not square");
		}
		T result = 0;
		for (int i = 0; i < _width; i++) {
			result += _matrix[i][i];
		}
		return result;
	};
	void print()
	{
		cout << "Matrix: " << endl;
		for (int i = 0; i < get_rows(); i++) {
			for (int j = 0; j < get_columns(); j++) {
				cout << "\t" << get_matij(i, j) << "\t";
			}
			cout << endl;
		}
		cout << "_______________________________________________" << endl << endl;
	};
	bool operator==(const Matrix& other) {
		bool result = true;
		if ((_width == other._width) && (_height == other._height)) {
			for (int i = 0; i < _width; i++) {
				for (int j = 0; j < _height; j++) {
					if (_matrix[i][j] != other._matrix[i][j])
						result = false;
				}
			}
		}
		else {
			result = false;
		}
		return result;
	};
	bool operator!=(const Matrix& other) {
		if (*this == other) {
			return false;
		}
		return true;
	};
};


template<typename T>
void submatrix(Matrix<T>& matrix, Matrix<T>& temp, int p, int q, int n) {
	int i = 0, j = 0;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (row != p && col != q) {
				temp(i, j++) = matrix(row, col);
				if (j == n - 1) {
					j = 0;
					i++;
				}
			}
		}
	}
}

template<typename T>
T det(Matrix<T>& matrix, int n) {
	if (matrix.get_rows() != matrix.get_columns()) {
		throw runtime_error("Matrix is not square");
	}
	T determinant = 0;
	if (n == 1) {
		return matrix(0,0);
	}
	if (n == 2) {
		return (matrix(0, 0) * matrix(1, 1) - (matrix(0, 1) * matrix(1, 0)));
	}
	Matrix<T> temp(n, n, 0);
	int sign = 1;
	for (int i = 0; i < n; i++) {
		submatrix(matrix, temp, 0, i, n);
		determinant += sign * matrix(0, i) * det(temp, n - 1);
		sign = -sign;
	}
	return determinant;
}

template<typename T>
void complanar(Matrix<T>& matrix, int n) {
	if (det(matrix, n) == 0) {
		cout << "These vectors are complanar"<< endl;
	}
	else cout << "These vectors are not complanar" << endl;
}