#include <random>
#include <stdexcept>
#include <complex>
#include "Matrix.h"


using namespace std;

template<typename T>
Matrix<T>::Matrix():_width(0), _height(0), _matrix(nullptr){}

template<typename T>
Matrix<T>::Matrix(int width, int height, T value) : _width(width), _height(height)
{
	if (width < 0 || height < 0) throw runtime_error("Incorrect size of matrix");
	_matrix = (T**) new T* [width];
	for (int i = 0; i < width; i++) {
		_matrix[i] = (T*) new T[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			_matrix[i][j] = value;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(int width, int height): _width(width), _height(height)
{
	if (width < 0 || height < 0) throw runtime_error("Incorrect size of matrix");
	_matrix = (T**) new T * [width];
	for (int i = 0; i < width; i++) {
		_matrix[i] = (T*) new T[height];
	}
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			_matrix[i][j] = rand()%10000+10000;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other)
{
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

}

template<typename T>
Matrix<T>::~Matrix()
{
	if (_height > 0) {
		for (int i = 0; i < _width; i++) {
			delete[] _matrix[i];
		}
	}
	if (_width > 0) {
		delete[] _matrix;
	}
}

template<typename T>
T& Matrix<T>::operator()(int i, int j)
{
	if ((i >= 0 && i <= _width) && (j >= 0 && j <= _height)) {
		return _matrix[i][j];
	}
	else throw runtime_error("Invalid row/column");
}
template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix& other) {
	if (_height > 0) {
		for (int i = 0; i < _width; i++) delete[] _matrix[i];
	}
	if (_width > 0) {
		delete[] _matrix;
	}
	_width = other._width;
	_height = other._height;
	_matrix = (T**) new T * [_width];
	for (int i = 0; i < _width; i++) {
		_matrix[i] = (T*) new T[_height];
	}
	for (int i = 0; i < _width; i++) {
		for (int j = 0; i < _height; j++) {
			_matrix[i][j] = other._matrix[i][j];
		}
	}
	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& other)
{
	// TODO: вставьте здесь оператор return
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix other) const
{
	return Matrix();
}

template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& other)
{
	// TODO: вставьте здесь оператор return
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix other) const
{
	return Matrix();
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix other) const
{
	return Matrix();
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T scalar) const
{
	return Matrix();
}

template<typename T>
Matrix<T> Matrix<T>::operator/(const T scalar) const
{
	return Matrix();
}

template<typename T>
T Matrix<T>::track(const Matrix& other)
{
	return T();
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix)
{
	// TODO: вставьте здесь оператор return
}
