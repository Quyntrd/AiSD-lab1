#pragma once
template<typename T>

class Matrix
{
	T _value;
	int _width;
	int _height;
public:
	Matrix();										//����������� �� ���������
	Matrix(int width, int height);					//����������� � �����������
	Matrix(int width, int height);					//����������� �� ���������� �����������
	Matrix(const Matrix& other);					//����������� �����������
	~Matrix();										//����������


	T& operator()(int i, int j);
	Matrix& operator+=(const Matrix& other);		//�������� +=
	Matrix operator+(const Matrix other) const;		//�������� ��������
	Matrix& operator-=(const Matrix& other);		//�������� -=
	Matrix operator-(const Matrix other) const;		//�������� ���������
	Matrix operator*(const Matrix other) const;		//�������� ��������� ������
	Matrix operator*(const int scalar) const;		//�������� ��������� �� ������
	Matrix operator/(const int scalar) const;		//�������� ������� ������� �� ������
	T track(const Matrix& other);					//���������� �����
};

