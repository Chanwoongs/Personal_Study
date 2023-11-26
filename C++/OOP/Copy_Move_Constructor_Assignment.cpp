#include <iostream>
#include <string>
using namespace std;
class Cat
{
public:
	Cat() = default;
	Cat() = delete; // 자동 생성자 막기
	Cat(string name, int age) : mName{ move(name) }, mAge{ age }
	{
		cout << mName << " constructor" << '\n';
	}
	Cat(const Cat& other) = delete; // 컴파일러가 자동으로 복사 생성자를 생성하지 못하게 함.
	~Cat() noexcept 
	{
		cout << mName << " destructor" << '\n';
	}
	Cat(const Cat& other) : mName{other.mName}, mAge{other.mAge} 
	{
		cout << mName << " copy constructor" << '\n';
		memcpy() // 포인터 정보 전부 복사
	}
	Cat(Cat&& other) noexcept : mName{ move(other.mName) }, mAge{ other.mAge }
	{
		cout << mName << " move constructor" << '\n';
		mPtr = other.mPtr;
		other.mPtr = nullptr;
	}
	Cat& operator=(const Cat& other) noexcept
	{
		if (&other == this) return *this;

		mName = other.mName;
		mAge = other.mAge;
		cout << mName << " copy assignment" << '\n';
		return *this;
	}
	Cat& operator=(Cat&& other)
	{
		if (&other == this) return *this;

		mName = move(other.mName);
		mAge = other.mAge;
		cout << mName << " move assignment" << '\n';
		return *this;
	}
	void print()
	{
		cout << mName << " " << mAge << '\n';
	}
private:
	int mAge;
	string mName;
	char* mPtr;
};

int main()
{
	Cat kitty{ "kitty", 1 };
	Cat nabi; 

	Cat Kitty2{ kitty }; // copy constructor
	Cat kitty3 = kitty; // copy constructor

	Cat kitty4{ move(kitty) }; // move constructor

	Cat nabi2;
	nabi2 = kitty; // copy assignment
	nabi2 = move(kitty); // move assignment

	kitty = kitty;
	kitty = move(kitty);

	return 0;
}