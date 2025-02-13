#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include<cstdlib>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T&	operator[](unsigned int index);
		unsigned int	size();
		~Array();
};

template <typename T>
Array<T>::Array(): array(NULL), _size(0)
{

}

template <typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &other)
{
	this->array = new T[other._size];
	for(unsigned int i = 0; i < other._size; i++)
	{
		this->array[i] = other.array[i];
	}
	this->_size = other._size;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if(this->array )
		delete []this->array;
	if(this != &other)
	{
		this->array = new T[other._size];
		for(unsigned int i = 0; i < other._size; i++)
		{
			this->array[i] = other.array[i];
		}
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw(std::out_of_range("index is out of range"));
	return array[index];
}

template <typename T>
unsigned int Array<T>::size()
{
	return this->_size;
}

template <typename T>
Array<T>::~Array()
{
	delete []array;
}

#endif