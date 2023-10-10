#pragma once
template<typename T>

class Matrix
{
	T _value;
	int _width;
	int _height;
public:
	Matrix(T value, int width, int height): _value(value), _width(width), _height(height){}

};

