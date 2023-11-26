#include <iostream>
#include <string>
using namespace std;
class Cat
{
public:
	void age(int age)
	{
		mAge = age;
	}
	int age() const
	{
		return mAge;
	}
	void name(string name)
	{
		mName = move(name);
	}
	const string& name() const
	{
		return mName;
	}

private:
	int mAge;
	string mName;
}; 

int main()
{
	const Cat kitty;
	string name = kitty.name(); // deep copy
	const string& nameRef = kitty.name(); // no deep copy

	return 0;
}