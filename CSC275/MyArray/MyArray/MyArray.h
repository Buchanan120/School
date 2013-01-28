// MyArray.h
//	MyArray is a custom C++ vector implementation

// insure that this header file is not included more than once
#pragma once
#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <iostream>

template <class elemType>
class MyArray
{
private:
	// number of elements the current instance is holding
	int _size; 
	// number of elements the current instance can hold
	int _capacity; 
	// ptr to the first element in the array
	elemType *list;
 
// UTILITY FUNCTION(S)

	// MakeRoom
		// doubles _capacity and builds a new list
		//	maintains current data
	void MakeRoom();
public:
 
// CONSTRUCTORS

	// Default constructor
		// Initializes _capacity to 2 elements
		//	Initializes _size to 0 elements
	MyArray(); 
	// Parameterized constructor
		// Initialize _capacity to capacity
		//	Initialize _size to 0 elements
	MyArray(int capacity); 
	// Copy constructor
		// Initialize this MyArray to a copy of the original
	MyArray( MyArray & original); 

// DESTRUCTOR
		// Deallocate dynamic storage
	~MyArray();
 
// METHODS

	// Add
		// Takes an argument of the templated type and
		//	adds it to the end of the list/array
	void Add(const elemType & elem);

	// At
		// Takes an int argument
		//	Returns a reference to the element at a specified location in this MyArray
	elemType &At(int index);

	// Find
		// Takes an argument of the templated type
		//	Returns the int index were this element is found
		//	Returns -1 if element is not found
	int Find(const elemType & elem);

	// Insert
		// Takes an argument of the templated type and
		//	An integer index argument
		//	Inserts the element at that index in the list/array
		//	moving the element currently at that index and all subsequent
		//	elements up one index
	void Insert(const elemType & elem, int index);

	// RemoveAt
		// Takes an int argument
		//	Removes the element at that index in the list/array
	void RemoveAt(int index);

	// SetValue
		// Takes an item to assign and an int index to assign it at
		//	Assigns the item to the specified index of this MyArray
	void SetValue(const elemType & elem, int index);

	// Size
		// Returns the number of elements in this MyArray
	int Size();
 
// OPERATORS

	// = (assignment - takes a MyArray and makes a deep copy)
	MyArray & operator= (const MyArray & aMyArray);
 
	// [] (read/write char access by index)
		// Returns a reference to the element at that index
		//	throws an exception if index is < 0 or >= _length
	elemType & operator[] (int index) const;
 
	// ==, != (boolean relational test operators)
		// compares arrays for element by element equality
	bool operator== (const MyArray & aMyArray);
	bool operator!= (const MyArray & aMyArray);
};
//**************************** IMPLEMENTATIONS ******************************\\

// CONSTRUCTORS

	// Default constructor
		// Initializes _capacity to 16 elements
		//	Initializes _size to 0 elements
	template <class elemType>
	MyArray<typename elemType>::MyArray() {
		_capacity = 16;
		_size = 0;
		list = new elemType[_capacity];
	}
	// Parameterized constructor
		// Initialize _capacity to capacity
		//	Initialize _size to 0 elements
	template <class elemType>
	MyArray<typename elemType>::MyArray(int capacity) {
		if(capacity < 0)
			throw std::runtime_error("DAMMITJIM Negative capacity given");
		_capacity = capacity;
		_size = 0;

		list = new elemType[_capacity];
	}
	// Copy constructor
		// Initialize this MyArray to a copy of the original
	template <class elemType>
	MyArray<typename elemType>::MyArray( MyArray & original) {
		_capacity = original._capacity;
		_size = original._size;

		list = new elemType[_capacity];

		for (int i = 0; i = _size; i++)
			list[i] = original.list[i];
	}

// DESTRUCTOR
		// Deallocate dynamic storage
	template <class elemType>
	MyArray<typename elemType>::~MyArray() {
		delete [] list;
	}

// UTILITY FUNCTION(S)

	// MakeRoom
		// doubles _capacity and builds a new list
		//	maintains current data
	template <class elemType>
	void MyArray<typename elemType>::MakeRoom() {
		// double _capacity
		_capacity *= 2;
		// create new list with new capacity
		elemType *temp;
		temp = new elemType[_capacity];
		// populate temp with data from list
		for(int i = 0; i < (_capacity / 2); i++)
			temp[i] = list[i];
		// change pointer to replace list
		delete [] list;
		list = temp;				
	}

// METHODS

	// Add
		// Takes an argument of the templated type and
		//	adds it to the end of the list/array
	template <class elemType>
	void MyArray<typename elemType>::Add(const elemType & elem) {
		if(_size == _capacity - 1)
			MakeRoom();
		list[_size++] = elem;
	}

	// At
		// Takes an int argument
		//	Returns a reference to the element at a specified location in this MyArray
	template <class elemType>
	elemType& MyArray<typename elemType>::At(int index) {
		if(index > _size)
			throw std::out_of_range("DAMMITJIM Index given greater than _size");
		return list[index];
	}

	// Find
		// Takes an argument of the templated type
		//	Returns the int index were this element is found
		//	Returns -1 if element is not found
	template <class elemType>
	int MyArray<typename elemType>::Find(const elemType & elem) {
		for(int i = 0; i < _size; i++)
			if(list[i] == elem) return i;
		return -1;
	}

	// Insert
		// Takes an argument of the templated type and
		//	An integer index argument
		//	Inserts the element at that index in the list/array
		//	moving the element currently at that index and all subsequent
		//	elements up one index
	template <class elemType>
	void MyArray<typename elemType>::Insert(const elemType & elem, int index) {
		if(_size == _capacity - 1)
			MakeRoom();
		if(index > _size + 1)
			throw std::out_of_range("DAMMITJIM Index given greater than _size + 1");

		_size++;
		for(int i = _size; i > index; i--)
			list[i] = list[i - 1];

		list[index] = elem;
	}
	
	// RemoveAt
		// Takes an int argument
		//	Removes the element at that index in the list/array
	template <class elemType>
	void MyArray<typename elemType>::RemoveAt(int index) {
		if(index > _size + 1)
			throw std::out_of_range("DAMMITJIM Index given greater than _size + 1");

		for(int i = index; i < _size; i++)
			list[i] = list[i + 1];
		_size--;
	}

	// SetValue
		// Takes an item to assign and an int index at which to assign it
		//	Assigns the item to the specified index of this MyArray
	template <class elemType>
	void MyArray<typename elemType>::SetValue(const elemType & elem, int index) {
		if(index > _size)
			throw std::out_of_range("DAMMITJIM Index given greater than _size");

		list[index] = elem;
	}

	// Size
		// Returns the number of elements in this MyArray
	template <class elemType>
	int MyArray<typename elemType>::Size() {
		return _size;
	}

// OPERATORS

	// = (assignment - takes a MyArray and makes a deep copy)
	template<class elemType>
	MyArray<elemType> & MyArray<elemType>::operator= (const MyArray<elemType> & aMyArray) {
		_capacity = aMyArray._capacity;
		_size = aMyArray._size;

		elemType *newList;
		newList = new elemType[_capacity];

		for(int i = 0; i < _size; i++)
			newList[i] = aMyArray.list[i];

		delete [] list;
		list = newList;

		return *this;
	}
 
	// [] (read/write char access by index)
		// Returns a reference to the element at that index
		//	throws an exception if index is < 0 or >= _length
	template<class elemType>
	elemType & MyArray<elemType>::operator[] (int index) const {
		if(index > _size)
			throw std::out_of_range("DAMMITJIM index given greater than _size");

		return list[index];
	}
 
	// ==, != (boolean relational test operators)
		// compares arrays for element by element equality
	template<class elemType>
	bool MyArray<elemType>::operator== (const MyArray & aMyArray) {
		if(_size != aMyArray._size)
			return false;

		for(int i = 0; i < _size; i++)
			if(aMyArray.list[i] != list[i]) return false;

		return true;
	}

	template<class elemType>
	bool MyArray<elemType>::operator!= (const MyArray & aMyArray) {
		if(_size == aMyArray._size)
			return false;

		for(int i = 0; i < _size; i++)
			if(aMyArray.list[i] == list[i]) return false;

		return true;
	}

#endif