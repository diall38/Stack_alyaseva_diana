#pragma once
#include "iostream"
template <class T = int>
class Vector
{
public:
	T* data;
	size_t capacity;  //размер выделенной памяти
	size_t size;      //размер занятой памяти
public:
	Vector();           // Конструктор по умолчанию
	Vector(int n);        // Конструктор с параметром
	Vector(T* arr, int n);
	~Vector();
	void push_back(T elem);
	void pop_back();
	void push_front(T elem);
	void pop_front();
	size_t length() { return size; }
	T& operator[](int pos) {
		if (pos<0 || pos>size - 1)
			throw "incorrect index";
		else return data[pos];
	}
	T operator[](int pos) const {
		if (pos<0 || pos>size - 1) throw "incorrect index";
		else return data[pos];
	}
	void insert(T elem, int index);
	void erase(int index);
	friend std::ostream& operator<<(std::ostream& stream, const Vector<T>& v) {
		for (int i = 0; i < v.size; i++)
			stream << v.data[i] << ' ';
		return stream;
	}
protected:
	void resize(size_t capacity_);
};

template <class T>
inline Vector<T>::Vector() {
	data = nullptr;
	capacity = 0;
	size = 0;
}
template <class T>
inline Vector<T>::Vector(int n) {
	if (n <= 0) throw "incorrect index";
	data = new T[n];
	for (int i = 0; i < n; i++)
		data[i] = 0;
	capacity = n;
	size = 0;
}
template <class T>
inline Vector<T>::Vector(T* arr, int n) {
	if (n <= 0) throw "incorrect index";
	data = new T[n];
	for (int i = 0; i < n; i++)
		data[i] = arr[i];
	capacity = n;
	size = n;
}
template <class T>
inline Vector<T>::~Vector() {
	if (data) {
		delete[] data;
		data = nullptr;
	}
}
template <class T>
inline void Vector<T>::resize(size_t capacity_s) {
	if (capacity_s > size) {
		T* tmp = new T[capacity_s];
		for (size_t i = 0; i < size; i++)
			tmp[i] = data[i];
		capacity = capacity_s;
		delete[] data;
		data = tmp;
	}
	if (capacity_s <= size) {
		T* tmp = new T[capacity_s];
		for (size_t i = 0; i < capacity_s; i++)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
		size = capacity_s;
		capacity = capacity_s;
	}
}
template <class T>
inline void Vector<T>::push_back(T elem) {
	if (capacity >= 2 * size && capacity>7)
		resize(1.3 * size);
	if (size + 1 > capacity) {
		if (capacity > 3)
			resize(1.3 * capacity);
		else resize(2 + capacity);
		data[++size - 1] = elem;
	}
	else data[++size - 1] = elem;
}
template <class T>
inline void Vector<T>::pop_back() {
	if (size == 0) throw "empty";
	if (capacity >= 2 * size) {
		resize(1.3 * size--);
	}
	else {
		--size;
	}
}
template <class T>
inline void Vector<T>::push_front(T elem) {
	insert(elem,0);
}
template <class T>
inline void Vector<T>::pop_front() {
	erase(0);
}
template <class T>
inline void Vector<T>::erase(int index) {
	if (size - 1 < index || index < 0) throw "incorrect index";
	if (!size) throw "empty";
	if (capacity >= 2 * size && capacity>7)
		resize(1.3 * size);
	for (size_t i = index + 1; i < size; i++)
		data[i - 1] = data[i];
	size--;
}
template <class T>
inline void Vector<T>::insert(T elem, int index) {
	if (size < index || index < 0) throw "incorrect index";
	if (capacity >= 2 * size && capacity>7)
		resize(1.3 * size);
	if (size + 1 > capacity)
		if (capacity > 3)
			resize(1.3 * capacity);
		else resize(2 + capacity);
	size++;
	for (size_t i = size - 1; i > index; i--)
		data[i] = data[i - 1];
	data[index] = elem;
}

template <class T = int>
class Stack : public Vector<T>
{
public:
	Stack() :Vector() {}       //конструктор по умолчанию

	Stack(size_t n) :Vector(n) {}
	T top() { return data[size - 1]; }
	bool empty() const { return (!size); }
	bool full() const { return size == capacity; }
	void push(const T Val) { Vector<T>::push_back(Val); }
	void pop() { Vector<T>::pop_back(); }
	size_t Size() { return size; }
};


template <class T = int>
class Queue : public Vector<T>
{
protected:
	size_t pfront;
	size_t pback;
public:
	Queue() :Vector() {
		pfront = 0;
		pback = 0
	}     
	Queue(size_t n) :Vector(n) {
		pfront = 0; 
		pback = n - 1;
	}
	T front() { return data[pfront]; }
	T back() { return data[pback]; }
	bool empty() const { return (!size); }
	bool full() const { return size == capacity; }
	void push(const T Val);
	void pop();
	size_t Size() { return size; }
};

template <class T>
inline void Queue<T>::push(T elem) {
	if (full()) {   //если очередь переполнена , то делаем resize
		if (capacity > 3)
			resize(1.3 * capacity);
		else resize(2 + capacity);
		if (pfront) {                                  //если front не 0, то сдвигаем front в 0,
			T* tmp = new T[capacity];                 //чтобы не перезаписывать элементы в случае если back==front-1
			for (size_t i = 0; i < size - pfront; i++) //иначе сработает data[++back] = elem;
				tmp[i] = data[i + pfront];
			for (size_t i = size - pfront; i < size; i++)
				tmp[i] = data[i + pfront-size];
			delete[] data;
			data = tmp;
			pfront = 0;
		}
	}
	if (pback == capacity-1) {
		pback = 0;
		data[pback] = elem;
	} else data[++pback] = elem;
	size++;
}
template <class T>
inline void Queue<T>::pop() {
	if (empty()) throw "empty";
	if (pfront == capacity - 1) {
		pfront = 0;
	} else pfront++;
	size--;
}