#include <string>
using namespace std;

string getString()
{
	string s = "program";
	return s; // RVO 개입, 0 copy, no move 
}

string getString(string a, bool b)
{
	if (b)
	{
		a = "program";
	}
	return a; // RVO 개입 X, 컴파일러가 복사된 Object를 Return해야할 지, program을 Return 할지 모른다. 0 copy
}

// 굳이 return 값에 move를 붙일 필요가 없다.

int main()
{
	string a = getString();

	string s = "abc";
	string b = s; // copy constructor 호출
	string c = move(s);
	// lvalue(s) -> rvalue
	// ownership to c, 0 copy, -> move
	// move constructor 호출


	return 0;
} 