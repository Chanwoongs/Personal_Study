#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Cat
{
public:
	Cat(int age) : mAge{ age }
	{
		cout << "constructor" << '\n';
	}
	~Cat()
	{
		cout << " destructor" << '\n';
	}
public:
	// ex 1
	shared_ptr<Cat> mVar;
	// ex 2
	shared_ptr<Cat> mFriend;

private:
	int mAge;
};

int main()
{
	Cat* catPtr = new Cat(3);
	Cat* catPtr1 = catPtr;

	shared_ptr<Cat> catSharedPtr = make_shared<Cat>(3);
	cout << "count : " << catSharedPtr.use_count() << '\n';
	shared_ptr<Cat> catShared1 = catSharedPtr;
	cout << "count : " << catSharedPtr.use_count() << '\n';

	// memory leak
	// ex 1 소멸자가 1번만 호출
	shared_ptr<Cat> mPtr = make_shared<Cat>();
	mPtr->mVar = mPtr;
	cout << "count : " << mPtr.use_count() << '\n'; // count : 2 
	// ex 2 소멸자 호출 X
	shared_ptr<Cat> pKitty = make_shared<Cat>();
	shared_ptr<Cat> pNabi = make_shared<Cat>();
	pKitty->mFriend = pNabi;
	pNabi->mFriend = pKitty;


	delete catPtr;
}
