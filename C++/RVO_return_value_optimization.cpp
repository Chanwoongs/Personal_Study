#include <string>
using namespace std;

string getString()
{
	string s = "program";
	return s; // RVO ����, 0 copy, no move 
}

string getString(string a, bool b)
{
	if (b)
	{
		a = "program";
	}
	return a; // RVO ���� X, �����Ϸ��� ����� Object�� Return�ؾ��� ��, program�� Return ���� �𸥴�. 0 copy
}

// ���� return ���� move�� ���� �ʿ䰡 ����.

int main()
{
	string a = getString();

	string s = "abc";
	string b = s; // copy constructor ȣ��
	string c = move(s);
	// lvalue(s) -> rvalue
	// ownership to c, 0 copy, -> move
	// move constructor ȣ��


	return 0;
} 