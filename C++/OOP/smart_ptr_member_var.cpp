#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// Cat has shared ptr member variable
class Cat
{
public:
	Cat(int n) : mVar{ make_unique<int>(n) }
	{
		cout << "constructor" << '\n';
	}
	Cat(const Cat& other) : mVar { make_unique<int>(*other.mVar) }{}

	Cat() : mVari{ make_shared<int>(3) }
	{
		cout << "constructor" << '\n';
	}
	Cat clone() // create deep copied object
	{
		Cat tmp{*mVar};
		return tmp;
	}
	~Cat()
	{
		cout << " destructor" << '\n';
	}

private:
	unique_ptr<int> mVar;

	shared_ptr<int> mVari;
};

int main()
{
	// case unique_ptr member
	Cat kitty;
	Cat nabi{ kitty }; // complie error
	nabi = kitty; // compile error

	// case shared_ptr member
	Cat kitty;
	Cat nabi{ kitty.clone() }; // complie error
}
