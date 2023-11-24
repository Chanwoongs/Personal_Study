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
	// const �� ���̰� �Ǹ� Copy�� �Ͼ
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
	storeByLRef(a); // L-Value�� ���ڷ� ������ �������� ���� �����ϴٴ� �ǹ�
	cout << "a : " << a << '\n';
	// output
	// a : 
	
	Cat kitty;
	string s = "kitty";
	kitty.setName(s); // copy 1��
	kitty.setName("nabi"); // copy 0�� 
}