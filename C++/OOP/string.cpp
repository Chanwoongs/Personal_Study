#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// C++ 17
void printString(string_view s) // char[], const char*, string 전부 사용가능, 임시 string 객체 생성없이 reference로 접근
{
	cout << s << endl;
}

int main()
{
	int code = 65;
	cout << (char)code << endl; // A

	char a[6] = { 'p','r','\0','g'};
	cout << a << endl; // pr
	cout << sizeof(a) << endl; // 4
	cout << strlen(a) << endl; // 2

	char b[] = "prog";
	// size 5, length 4

	char* c = "pro";
	// size 4 + 1(pointer), length 3 ,read only 에 문자열 생성 c[0] = 'c' 접근 불가

	const char* c = "pro";
	// warning 사라짐, size 4, length 3

	// string은 class
	// 자유롭게 변경가능, Heap allocation performance 영향

}