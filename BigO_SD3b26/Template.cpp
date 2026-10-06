#include <iostream>
#include "Pair.h"
#include "DynamicArray.h"
using namespace std;
struct Book
{
	string title;
	Book()
	{ }
	Book(string s)
	{
		title = s;
	}

	friend ostream& operator<<(ostream& out, Book& b)
	{
		return out << "Book(" <<b.title<<")";
	}
};

void question1();
void question2();
void question3();
void question4();
void question5();


template <class T>
void print(T* arr, int size)
{
	for (int i = 0; i < size;i++)
	{
		if (i != 0)
			cout << ", ";
		cout << arr[i];
	}
	cout << endl;
}


int main()
{
	/*int arr[] = {1,2,3,4};
	print(arr, 4);
	char charArr[] = { 'A','B','C', 'D'};
	print(charArr, 4);
	Book bookArr[] = { Book("the widow"),Book("the general"),Book("the lord of the rings"),Book("the hobbit") };
	print(bookArr, 4);*/
	question5();
}

template <class T>
T greaterThan(T& x, T& y)
{
	T largest = x > y ? x : y;
	return largest;
}

void question1()
{
	int x = 10, y = 5;
	char c1 = 'A', c2 = 'B';
	string s1 = "Hello", s2 = "Goodbye";
	cout << x << " and " << y << " Greatest: " << greaterThan(x, y)<<endl;
	cout << c1 << " and " << c2 << " Greatest: " << greaterThan(c1, c2) << endl;
	cout << s1 << " and " << s2 << " Greatest: " << greaterThan(s1, s2) << endl;
}

template <class T>
T lessThan(T& x, T& y)
{
	return x < y ? x : y;
}

void question2()
{
	int x = 10, y = 5;
	char c1 = 'A', c2 = 'B';
	string s1 = "Hello", s2 = "Goodbye";
	cout << x << " and " << y << " less: " << lessThan(x, y) << endl;
	cout << c1 << " and " << c2 << " least: " << lessThan(c1, c2) << endl;
	cout << s1 << " and " << s2 << " least: " << lessThan(s1, s2) << endl;
}


void question4()
{
	Pair<int, string> p1(1, "Hello");
	cout << p1;
	Pair<int, Book> p2(2, Book("The Hobbit"));
	cout << p2;
	Pair<string, double> p3("Two hundred", 200.0);
	cout << p3;
}

void question5()
{
	DynamicArray<char> arr;
	for (int i = 0; i < 26;i++)
	{
		arr.add(65 + i);
	}
	for (int i = 0; i < arr.size();i++)
	{
		cout << arr[i] << " ";
	}
}