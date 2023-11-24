#include <vector>

void fooV(int a)
{
	int b = a + 1;
}

void fooP(int* ap)
{
	int b = *ap + 1;
}

void fooR(const int& a)
{
	int b = a + 1;
	a = 100; // error
}

int main()
{
	int a = 0;
	fooV(a);
	fooP(&a);
	fooR(a);

	return 0;
}