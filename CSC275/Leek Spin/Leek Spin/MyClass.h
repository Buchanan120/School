// MyClass.h

#pragma once

template <class T>
class MyClass {
private:
	T value;
public:
	MyClass();
	T GetValue();
	void SetValue(T newValue);
};

// ****************** For class template, must include all of template, not just declarations. *************

// functions of a class template are function templates
// myClass is not a class, it's a class template
template <class T>
MyClass<T>::MyClass() {
	// cant initialize value because we don't know what data type it will be
	cout << "ctor " << sizeof(T) << "\n\n";
}

// all functions of a class template are function templates
	// have to template all of them just like class template
	// have to use fully qualified name of class template when defining
		// stuff inside function
template <class T>
T MyClass<T>::GetValue() {
	return this->value;
}

template <class T>
void MyClass<T>::SetValue(T newValue) {
	this->value = newValue;
}