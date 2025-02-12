#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include<cstdlib>

template <typename T>
class Array
{
	private:
		T *array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		T&	operator[](size_t index);
		size_t	size();
		Array(int size);
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
	for(size_t i = 0; i < other._size; i++)
	{
		this->array[i] = other.array[i];
	}
	this->_size = other._size;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	//free array
	if(this != &other)
	{
		this->array = new T[other._size];
		for(size_t i = 0; i < other._size; i++)
		{
			this->array[i] = other.array[i];
		}
		this->_size = other._size;
	}
	return (*this);
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw(std::out_of_range("index is out of range"));
	return array[index];
}

template <typename T>
inline size_t Array<T>::size()
{
	return this->_size;
}

template <typename T>
inline Array<T>::Array(int size)
{
	this->_size = size;
	this->array = new T[size];
}

template <typename T>
Array<T>::~Array()
{
	// delete 
}

#endif