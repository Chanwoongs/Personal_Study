#include <iostream>
#include <string>
#include <string_view>

using namespace std;

// C++ 17
void printString(string_view s) // char[], const char*, string ���� ��밡��, �ӽ� string ��ü �������� reference�� ����
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
	// size 4 + 1(pointer), length 3 ,read only �� ���ڿ� ���� c[0] = 'c' ���� �Ұ�

	const char* c = "pro";
	// warning �����, size 4, length 3

	// string�� class
	// �����Ӱ� ���氡��, Heap allocation performance ����

}