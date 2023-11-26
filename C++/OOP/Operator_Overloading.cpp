#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct complexNum
{
	double real;
	double imag;

	complexNum(double r, double i) : real{r}, imag{i} {}
	void print() const
	{
		cout << real << ' ' << imag << 'i' << '\n';
	}
};
complexNum operator+(const complexNum& lhs, const complexNum& rhs)
{
	complexNum c{ lhs.real + rhs.real, lhs.imag + lhs.imag };
	return c;
}

class Cat
{
public:
	Cat(string name, int age) : mName{ name }, mAge{ age } {}
	const string& name() const
	{
		return mName;
	}
	int age() const
	{
		return mAge;
	}
	void print(ostream& os) const
	{
		os << mName << " " << mAge << '\n';
	}


private:
	string mName;
	int mAge;
};

bool operator==(const Cat& lhs, const Cat& rhs)
{
	return lhs.age() == rhs.age() && lhs.name() == rhs.name();
}

bool operator<(const Cat& lhs, const Cat& rhs)
{
	if (lhs.age() < rhs.age())
		return true;
	else return false;
}

ostream& operator<<(ostream& os, const Cat& c)
{
	return os << c.name() << ' ' << c.age();
}

int main()
{
	complexNum c1{ 1,1 };
	complexNum c2{ 1,2 };

	complexNum c{ c1 + c2 };

	Cat kitty{ "kitty", 1 };
	Cat nabi{ "nabi", 2 };
	vector<Cat> cats;
	// == , <, <<
	if (kitty == nabi) cout << "same\n";
	else cout << "not same\n";

	if (kitty < nabi) cout << "nabi old\n";
	else cout << "kitty old\n";

	cout << kitty << '\n';

	sort(cats.begin(), cats.end());

	//kitty.print();
	//nabi.print();
}