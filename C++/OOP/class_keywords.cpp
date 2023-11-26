#include <iostream>
#include <string>

using namespace std;

class Cat
{
public:
	Cat(string name) : mName {move(name)} {}
	explicit Cat(int age) : mAge{ age } {}
	void speak() const // � �ɹ� ������ �ٲ��� �ʴ´�.
	{
		mName = " "; // error
		cout << mName << '\n';
	}
	void printAge() const
	{
		cout << "age : " << mAge << '\n';
	}

private:
	mutable string mName; // mutable�� ���� ������ const �Լ����� ������� ������ �����ϴ�, ������ ��� X
	int mAge;
};

int main()
{
	Cat kitty{ "kitty" };
	kitty.speak();

	const Cat nabi{ "nabi" };
	nabi.speak(); // error, const�� ���� �Լ��� ȣ�� ����

	const Cat kit = 3; // implicit conversion���� 3�� ��
	kit.printAge();
}