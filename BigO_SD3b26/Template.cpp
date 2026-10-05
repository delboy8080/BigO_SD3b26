#include <iostream>

using namespace std;
struct Book
{
	string title;
	Book(string s)
	{
		title = s;
	}

	friend ostream& operator<<(ostream& out, Book& b)
	{
		return out << b.title;
	}
};

void question1();
void question2();
void question3();
void question4();


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

template <class T>
T greaterThan(T& x, T& y)
{
	T largest = x > y ? x : y;
	return largest;
}

int main()
{
	int arr[] = { 1,2,3,4 };
	print(arr, 4);
	char charArr[] = { 'A','B','C', 'D'};
	print(charArr, 4);
	Book bookArr[] = { Book("the widow"),Book("the general"),Book("the lord of the rings"),Book("the hobbit") };
	print(bookArr, 4);
	question1();
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