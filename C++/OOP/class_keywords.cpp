#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
	Cat(string name) : mName {move(name)} {}
	explicit Cat(int age) : mAge{ age } {}
	void speak() const // 어떤 맴버 변수를 바꾸지 않는다.
	{
		mName = " "; // error
		cout << mName << '\n';
	}
	void printAge() const
	{
		cout << "age : " << mAge << '\n';
	}

private:
	mutable string mName; // mutable이 붙은 변수는 const 함수에서 마음대로 변경이 가능하다, 가급적 사용 X
	int mAge;
};

int main()
{
	Cat kitty{ "kitty" };
	kitty.speak();

	const Cat nabi{ "nabi" };
	nabi.speak(); // error, const가 붙은 함수만 호출 가능

	const Cat kit = 3; // implicit conversion으로 3이 들어감
	kit.printAge();
}