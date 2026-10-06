#pragma once
template <class T>
class DynamicArray
{
	T* arr;
	int m_size;
	int m_capacity;
	void grow();
public:
	DynamicArray(int initialCapacity = 10);
	T get(int index);
	void add(T item);
	void insert(T item, int index);
	void remove(int index);
	int size();
	T& operator[](int index);

};
template <class T>
void DynamicArray<T>::grow()
{
	T* newArr = new T[m_capacity * 2];
	for (int i = 0; i < m_capacity;i++)
	{
		newArr[i] = arr[i];
	}
	delete[]arr;
	arr = newArr;
	m_capacity = m_capacity * 2;
}

template <class T>
DynamicArray<T>::DynamicArray(int initialCap)
{
	arr = new T[initialCap];
	m_capacity = initialCap;
	m_size = 0;
}

template <class T>
int DynamicArray<T>::size()
{
	return m_size;
}
template <class T>
T DynamicArray<T>::get(int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::logic_error("Index out of bounds");
	}
	return arr[index];
}
template <class T>
void DynamicArray<T>::add(T item)
{
	if (m_size == m_capacity)
	{
		grow();
	}
	arr[m_size] = item;
	m_size++;
}
template <class T>
void DynamicArray<T>::insert(T item, int index)
{

}
template <class T>
void DynamicArray<T>::remove(int index)
{

}

template <class T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= m_size)
	{
		throw std::logic_error("Index out of bounds");
	}
	return arr[index];
}