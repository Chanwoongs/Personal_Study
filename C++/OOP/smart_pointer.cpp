#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
class Cat
{
public:
	Cat() = default;
	Cat(string name, int age) : mName{ move(name) }, mAge{ age }
	{
		cout << mName << " constructor" << '\n';
	}
	~Cat()
	{
		cout << mName << " destructor" << '\n';
	}
private:
	int mAge;
	string mName;
};

void foo()
{
	cout << "before function\n";
	unique_ptr<Cat> catPtr = make_unique<Cat>(3); // Scope base life cycle
	cout << "after function\n";
}

int main()
{
	Cat* catPtr = new Cat{ "cat", 3 };

	cout << "before scope\n";
	{
		unique_ptr<Cat> catPtr = make_unique<Cat>(3); // Scope base life cycle
	}
	cout << "after scope\n";

	Cat* cats = new Cat[5];
	delete[] cats;

	// vector 는 자동으로 할당 해제
	vector<Cat> cats(5);

	return 0;
}