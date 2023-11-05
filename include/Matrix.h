#pragma once


	template<typename T>
	class Matrix
	{
		T** _matrix;
		int _width;
		int _height;
	public:
		Matrix();										//����������� �� ���������
		Matrix(int width, int height, T value);			//����������� � �����������
		Matrix(int width, int height);					//����������� �� ���������� �����������
		Matrix(const Matrix& other);					//����������� �����������
		~Matrix();										//����������


		T& operator()(int i, int j);
		Matrix& operator()(int i, int j);
		Matrix operator=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);		//�������� +=
		Matrix operator+(const Matrix other) const;		//�������� ��������
		Matrix& operator-=(const Matrix& other);		//�������� -=
		Matrix operator-(const Matrix other) const;		//�������� ���������
		Matrix operator*(const Matrix other) const;		//�������� ��������� ������
		Matrix operator*(const T scalar) const;			//�������� ��������� �� ������
		Matrix operator/(const T scalar) const;			//�������� ������� ������� �� ������
		T track(const Matrix& other);					//���������� �����

		friend std::ostream& operator<<(std:: ostream& out, const Matrix<T>& matrix);
	};