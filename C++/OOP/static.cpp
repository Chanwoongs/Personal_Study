#include <iostream>
using namespace std;
class Cat
{
public:
	void speak()
	{
		static count = 0; // speak �Լ������� ���̱� ������ �Լ� �ȿ��� �ʱ�ȭ
		count++;
		cout << count << '\n';
		cout << "meow" << '\n';
	}
	static void StaticSpeak()
	{
		cout << "meow" << '\n';
		cout << mAge << '\n'; // error, this�� ����Ǿ����� �ʱ� ������ member ���� ȣ�� �Ұ�, this ������ ����
		speak(); // error, this��� object �ּҰ� ����.
	}
	//static int count; 
private:
	//static int count; private���� ���� �� �ִ�. Cat::count ����
	int mAge;
};
//int Cat::count = 0; // ���α׷��� ����Ǳ� ���� �ʱ�ȭ�� ���������.

int main()
{
	Cat kitty;
	kitty.speak();
	kitty.StaticSpeak(); // member �Լ��� ȣ�� ����

	Cat nabi;
	nabi.speak(); // count -> 2, �����ϰ� �ִ�.



	Cat::StaticSpeak();

	return 0;
}