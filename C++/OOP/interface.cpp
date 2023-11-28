#include <iostream>
using namespace std;

// interface 
// only pure virtual function
// no member variable

class Animal
{
public:
	virtual void speak() = 0;
	void walk()
	{
		///
	}
	void walk() = 0; // 모두 순수 가상함수로
protected: // 맴버 변수를 없애고
	int leg;
	int nose;
	int mouth;
};

class Dolphin : public Animal
{
	// 걷기를 하였는데 걸을 수 없다.
	void walk() override
	{
		"we swim";
	}
private:
	int finCount; // 사용하지 않는 변수를 상속 받는다.
};

class Chicken;
class Spider; // 필요없는 변수가 늘어남.

class Cat : public Animal
{
	void speak() override
	{
		cout << "meow\n";
	}
	Cat()
	{
		leg = 4;
		nose = center(face);
	}
};