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
	// string b = s; // wrong! �� ���� s�� �ٽ� ��밡���� L-Value �̴�
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