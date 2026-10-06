#include <iostream>

#pragma once
template <class F, class S>
class Pair
{
	F first;
	S second;
public:
	Pair(F f, S s);
	F getFirst();
	S getSecond();
	void setFirst(F f);
	void setSecond(S s);

	template <class F, class S>
	friend std::ostream& operator<<(std::ostream& out, Pair<F, S>& p);
};
template<class F, class S>
std::ostream& operator<<(std::ostream& out, Pair<F, S>& p)
{
	return out << p.first << " -> " << p.second << std::endl;
}

template <class F, class S>
Pair<F, S>::Pair(F f, S s)
{
	this->first = f;
	this->second = s;
}

template <class F, class S>
F Pair<F, S>::getFirst()
{
	return first;
}
template <class F, class S>
S Pair<F, S>::getSecond()
{
	return second;
}
template <class F, class S>
void Pair<F, S>::setFirst(F f)
{
	first = f;
}
template <class F, class S>
void Pair<F, S>::setSecond(S s)
{
	second = s;
}