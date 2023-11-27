#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Cat
{
public:
	Cat() : mAge{ 1 }
	{
		cout << "constructor" << '\n';
	}
	void speak()
	{
		cout << "meow" << mAge << '\n';
	}
	~Cat()
	{
		cout << " destructor" << '\n';
	}

	weak_ptr<Cat> mFriend;

private:
	int mAge;
};

int main()
{
	// same scope
	weak_ptr<Cat> wPtr;
	{
		shared_ptr<Cat> sPtr = make_shared<Cat>();
		wPtr = sPtr;
		cout << "count : " << sPtr.use_count() << '\n'; // output count : 1

		if (const auto spt = wPtr.lock()) // shared ptr ����
		{
			cout << "count : " << sPtr.use_count() << '\n'; // count : 2
			spt->speak(); // meow 1
		}
	}

	// diff scope
	weak_ptr<Cat> wPtr;
	{
		shared_ptr<Cat> sPtr = make_shared<Cat>();
		wPtr = sPtr; // ������ object�� ����Ų��
	}
	if (const auto spt = wPtr.lock()) // shared_ptr ���� ����
	{
		cout << "count : " << spt.use_count() << '\n'; // 
		spt->speak(); // meow 1
	}
	else
	{
		cout << "pointing nothing" << '\n';
	}
}
