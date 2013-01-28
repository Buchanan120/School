// MyArray.h

// insure that this header file is not included more than once
#pragma once
#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <stdexcept>

// elemType must support '=' and '==' operators
template <class elemType>
class MyArray
{
private:
	int _size; // number of elements the current instance is holding
	int _capacity; // number of elements the current instance can hold
	elemType * list; // ptr to the first element in the array

	// UTILITY FUNCTION(S)
	// MakeRoom
	// doubles _capacity and builds a new list
	//   maintains current data
	void MakeRoom();

public:
	// Ctors
	MyArray(); // default
	MyArray(int capacity); // initialize to capacity
	MyArray( MyArray & original); // copy constructor

	// Dtor
	~MyArray();


	// METHODS

	// Add
	// Takes an argument of the templated type and
	// adds it to the end of the list/array
	void Add(const elemType & elem);

	// At
	// Takes an int argument
	// Returns a reference to the element at a specified location in this MyArray
	elemType & At(int index);

	// Find
	// Takes an argument of the templated type
	// Returns the int index were this element is found
	// Returns -1 if element is not found
	int Find(const elemType & elem);

	// Insert
	// Takes an argument of the templated type and
	// An integer index argument
	// Inserts the element at that index in the list/array
	// moving the element currently at that index and all subsequent
	// elements up one index
	void Insert(const elemType & elem, int index);

	// RemoveAt
	// Takes an int argument
	// Removes the element at that index in the list/array
	void RemoveAt(int index);

	// RemoveDuplicates
	// Removes any duplicate entries
	// Returns number elements removed
	int RemoveDuplicates();

	// SetValue
	// Takes an item to assign and an int index to assign it at
	// Assigns the item to the specified index of this MyArray
	void SetValue(const elemType & elem, int index);

	// Size
	// Returns the number of elements in this MyArray
	int Size();


	// OPERATORS
	// = (assignment - takes a MyArray and makes a deep copy)
	MyArray & operator= (const MyArray & aMyArray);

	// [] (read/write char access by index)
	// Returns a reference to the element at that index
	// throws an exception if index is < 0 or >= _length
	elemType & operator[] (int index) const;

	// ==, != (boolean relational test operators)
	//  compares arrays for element by element equality
	bool operator== (const MyArray & aMyArray) ;
	bool operator!= (const MyArray & aMyArray) ;
};
// ^^^ Interface here ^^^

// VVV Implementation here VVV

// Constructors!
template<class elemType>
MyArray<elemType>::MyArray()
{
	_size = 0;
	_capacity = 16;
	//_string = new char [_capacity + 1];
	list = new elemType[_capacity];
}

template<class elemType>
MyArray<elemType>::MyArray(int capacity)
{
	_size = 0;
	_capacity = capacity;
	list = new elemType[_capacity];
}

template<class elemType>
MyArray<elemType>::MyArray(MyArray & original)
{
	_size = original._size;
	_capacity = original._capacity;
	list = new elemType[_capacity];

	for(int i = 0; i < _size; i++)
	{
		list[i] = original.list[i];
	}
}

// Destructor!
template<class elemType>
MyArray<elemType>::~MyArray()
{
	delete [] list;
}

// Utility Functions!
// MakeRoom
// doubles _capacity and builds a new list
//   maintains current datatemplate<class elemType>
template<class elemType>
void MyArray<elemType>::MakeRoom()
{
	_capacity *= 2;
	elemType* newOne = new elemType[_capacity];

	for(int i = 0; i < _size; i++)
	{
		newOne[i] = list[i];
	}

	delete [] list;
	list = newOne;
}

// Methods!
// Add
// Takes an argument of the templated type and
// adds it to the end of the list/array
template<class elemType>
void MyArray<elemType>::Add(const elemType & elem)
{
	if(_size == _capacity)
	{
		MakeRoom();
	}

	list[_size] = elem;
	_size++;
}

// At
// Takes an int argument
// Returns a reference to the element at a specified location in this MyArray
template<class elemType>
elemType & MyArray<elemType>::At(int index)
{
	if(index >= _size)
		throw std::runtime_error("Parameter 'index' out of bounds");
	if(index < 0)
		throw std::runtime_error("Parameter 'index' less than zero");

	return list[index];
}

// Find
// Takes an argument of the templated type
// Returns the int index were this element is found
// Returns -1 if element is not found
template<class elemType>
int MyArray<elemType>::Find(const elemType & elem)
{
	for(int i = 0; i < _size; i++)
	{
		if(list[i] == elem)
			return i;
	}
	return -1;
}

// Insert
// Takes an argument of the templated type and
// An integer index argument
// Inserts the element at that index in the list/array
// moving the element currently at that index and all subsequent
// elements up one index
template<class elemType>
void MyArray<elemType>::Insert(const elemType & elem, int index)
{
	if(index > _size)
		throw std::runtime_error("Parameter 'index' out of bounds");
	if(index < 0)
		throw std::runtime_error("Parameter 'index' may not be negative");

	for(int i = _size-1; i >= index; i--)
	{
		list[i+1] = list[i];
	}

	list[index] = elem;

	_size++;
}

// RemoveAt
// Takes an int argument
// Removes the element at that index in the list/array
template<class elemType>
void MyArray<elemType>::RemoveAt(int index)
{
	if(index >= _size)
		throw std::runtime_error("Parameter 'index' out of bounds");
	if(index < 0)
		throw std::runtime_error("Parameter 'index' may not be negative");

	for(int i = index; i < _size; i++)
	{
		list[i] = list[i+1];
	}

	_size--;
}


// RemoveDuplicates
// Removes any duplicate entries
// Returns number of elements removed
template<class elemType>
int MyArray<elemType>::RemoveDuplicates()
{
	int numberRemoved = 0;
	for(int i = 0; i < _size; i++)
	{
		for(int j = i+1; j < _size; j++)
		{
			if(list[i] == list[j])
			{
				RemoveAt(j);
				j--;
				numberRemoved++;
			}
		}
	}
	return numberRemoved;
}

// SetValue
// Takes an item to assign and an int index to assign it at
// Assigns the item to the specified index of this MyArray
template<class elemType>
void MyArray<elemType>::SetValue(const elemType & elem, int index)
{
	if(index >= _size)
		throw std::runtime_error("Parameter 'index' out of bounds");
	if(index < 0)
		throw std::runtime_error("Parameter 'index' may not be negative");

	list[index] = elem;
}

// Size
// Returns the number of elements in this MyArray
template<class elemType>
int MyArray<elemType>::Size()
{
	return _size;
}

// Operators!
// = (assignment - takes a MyArray and makes a deep copy)
template<class elemType>
MyArray<elemType> & MyArray<elemType>::operator= (const MyArray<elemType> & aMyArray)
{
	_size = aMyArray._size;
	_capacity = aMyArray._capacity;

	delete [] list;
	list = new elemType[_capacity];

	for(int i = 0; i < _size; i++)
	{
		list[i] = aMyArray.list[i];
	}
	return *this;
}

// [] (read/write char access by index)
// Returns a reference to the element at that index
// throws an exception if index is < 0 or >= _length
template<class elemType>
elemType & MyArray<elemType>::operator[] (int index) const
{
	if(index >= _size)
		throw std::runtime_error("Parameter 'index' out of bounds");
	if(index < 0)
		throw std::runtime_error("Parameter 'index' may not be negative");

	return list[index];
}

// ==, != (boolean relational test operators)
//  compares arrays for element by element equality
template<class elemType>
bool MyArray<elemType>::operator== (const MyArray & aMyArray)
{
	if(_size != aMyArray._size)
		return false;
	for(int i = 0; i < _size; i++)
	{
		if(list[i] != aMyArray.list[i])
			return false;
	}
	return true;
}
template<class elemType>
bool MyArray<elemType>::operator!= (const MyArray & aMyArray)
{
	if(_size != aMyArray._size)
		return true;
	for(int i = 0; i < _size; i++)
	{
		if(list[i] != aMyArray.list[i])
			return true;
	}
	return false;
}

#endif