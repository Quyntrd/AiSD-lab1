#pragma once
template<typename T>

class Matrix
{
	T _value;
	int _width;
	int _height;
public:
	Matrix();										//конструктор по умолчанию
	Matrix(int width, int height);					//конструктор с параметрами
	Matrix(int width, int height);					//конструктор со случайными параметрами
	Matrix(const Matrix& other);					//конструктор копирования
	~Matrix();										//деструктор


	T& operator()(int i, int j);
	Matrix& operator+=(const Matrix& other);		//оператор +=
	Matrix operator+(const Matrix other) const;		//оператор сложения
	Matrix& operator-=(const Matrix& other);		//оператор -=
	Matrix operator-(const Matrix other) const;		//оператор вычитания
	Matrix operator*(const Matrix other) const;		//оператор умножения матриц
	Matrix operator*(const int scalar) const;		//оператор умножения на скаляр
	Matrix operator/(const int scalar) const;		//оператор деления матрицы на скаляр
	T track(const Matrix& other);					//вычисление следа
};

