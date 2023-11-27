#include <iostream>

using namespace std;

class Plus
{
public:
	explicit Plus(int a) : localVar{a} {}
	int operator() (int x) const
	{
		return localVar + x;
	}
private:
	int localVar;
};

int main()
{
	// capture by value
	int three{ 3 };
	auto lambdaPlus3 = [localVar = 3](int x)
	{
		return localVar + x;
	};
	auto lambdaPlus3 = [three](int x)
	{
		return three + x;
	};
	auto lambdaPlus3 = [=](int x)
	{
		return three + x; // 바깥에서 three를 찾음
	};
	// capture by ref
	VERYLARGEOBJECT obj;
	auto lambdaPlus3 = [&obj](int x)
	{
		return obj + x;
	};
	auto lambdaPlus3 = [&](int x)
	{
		return obj + x; // 바깥에서 obj를 찾음
	};

	Plus plus3{ 3 };
	Plus plus5{ 5 };

	cout << plus3(10) << '\n';
	cout << lambdaPlus3(10) << '\n';
	cout << plus5(10) << '\n';
}