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
	Matrix():_width(0), _height(0), _matrix(nullptr) {};										//конструктор по умолчанию
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
	};			//конструктор с параметрами
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
				_matrix[i][j] = rand() % up + low;
			}
		}
	};					//конструктор со случайными параметрами
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

	};					//конструктор копирования
	~Matrix() {
		if (_height > 0) {
			for (int i = 0; i < _width; i++) {
				delete[] _matrix[i];
			}
		}
		if (_width > 0) {
			delete[] _matrix;
		}
	};										//деструктор

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
	};		//оператор сложения
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
	};		//оператор вычитания
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
					sum = _matrix[i][k] * other._matrix[k][j];
				}
				result[i][j] = sum;
			}
		}
		return result;
	};		//оператор умножения матриц
	Matrix operator*(const T scalar) const
	{
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] * scalar;
			}
		}
		return result;
	};			//оператор умножения на скаляр
	Matrix operator/(const T scalar) const
	{
		Matrix<T> result(_width, _height);
		for (int i = 0; i < _width; i++) {
			for (int j = 0; j < _height; j++) {
				result._matrix[i][j] = _matrix[i][j] / scalar;
			}
		}
		return result;
	};			//оператор деления матрицы на скаляр
	T track(const Matrix& other);					//вычисление следа
	void print()
	{
		cout << "Matrix: " << endl;
		for (int i = 0; i < get_rows(); i++) {
			for (int j = 0; j < get_columns(); j++) {
				cout << get_matij(i, j) << "\t";
			}
			cout << endl;
		}
		cout << "_________________" << endl << endl;
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