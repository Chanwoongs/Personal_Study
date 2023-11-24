#include <iostream>
#include <string>
using namespace std;

void storeByLRef(string& s)
{
	string b = move(s);
}

void storeByLRef(const string& s)
{
	string b = move(s);
	cout << "b : " << b << '\n';
	// b : abc
	// a : abc 
	// const 를 붙이게 되면 Copy가 일어남
}

void storeByRRef(string&& s)
{
	string b = move(s);
}

class Cat
{
public:
	void setName(string name)
	{
		mName = move(name);
	}
private:
	string mName;
};

int main()
{
	string a = "abc";
	storeByLRef(a); // L-Value를 인자로 받으면 언제든지 변경 가능하다는 의미
	cout << "a : " << a << '\n';
	// output
	// a : 
	
	Cat kitty;
	string s = "kitty";
	kitty.setName(s); // copy 1번
	kitty.setName("nabi"); // copy 0번 
}