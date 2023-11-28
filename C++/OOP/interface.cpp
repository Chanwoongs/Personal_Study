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
	void walk() = 0; // ��� ���� �����Լ���
protected: // �ɹ� ������ ���ְ�
	int leg;
	int nose;
	int mouth;
};

class Dolphin : public Animal
{
	// �ȱ⸦ �Ͽ��µ� ���� �� ����.
	void walk() override
	{
		"we swim";
	}
private:
	int finCount; // ������� �ʴ� ������ ��� �޴´�.
};

class Chicken;
class Spider; // �ʿ���� ������ �þ.

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