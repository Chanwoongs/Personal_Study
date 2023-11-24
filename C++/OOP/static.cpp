#include <iostream>
using namespace std;
class Cat
{
public:
	void speak()
	{
		static count = 0; // speak 함수에서만 쓰이기 때문에 함수 안에서 초기화
		count++;
		cout << count << '\n';
		cout << "meow" << '\n';
	}
	static void StaticSpeak()
	{
		cout << "meow" << '\n';
		cout << mAge << '\n'; // error, this에 연결되어있지 않기 때문에 member 변수 호출 불가, this 정보가 없다
		speak(); // error, this라는 object 주소가 없다.
	}
	//static int count; 
private:
	//static int count; private으로 숨길 수 있다. Cat::count 방지
	int mAge;
};
//int Cat::count = 0; // 프로그램이 실행되기 전에 초기화를 시켜줘야함.

int main()
{
	Cat kitty;
	kitty.speak();
	kitty.StaticSpeak(); // member 함수라 호출 가능

	Cat nabi;
	nabi.speak(); // count -> 2, 공유하고 있다.



	Cat::StaticSpeak();

	return 0;
}