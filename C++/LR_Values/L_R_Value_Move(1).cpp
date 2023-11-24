#include <string>
using namespace std;

void storeByValue(string s)
{
	string b = s;
}

void storeByRef(string& s)
{
	string b = s;
}

void storeByRRef(string&& s)
{
	// string b = s; // wrong! 이 순간 s는 다시 사용가능한 L-Value 이다
	string b = move(s);
}

int main()
{
	string a = "abc";
	storeByValue(a);
	storeByRef(a);

	//storeByRRef(a); // wrong!
	storeByRRef(move(a));
	storeByRRef("abc");
}