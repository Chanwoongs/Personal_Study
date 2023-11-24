#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a = "program";
	cout << "a : " << a << '\n';
	// output
	// a : program

	string b = move(a); // Resource Ownership Changed
	cout << "b : " << b << '\n';
	// output
	// b : program
	cout << "a : " << a << '\n';
	// output
	// a : 

	return 0;
}