#include <iostream>
#include <functional>
#include <vector>
using namespace std;

class FunctionObj
{
public:
	void operator() (int i)
	{
		cout << "funtionObj" << i << endl;
	}
};

void freeFunction(int i)
{
	cout << "free" << i << endl;
}

void runFunction(int i, void(*fnPtr)(int))
{
	(*fnPtr)(i);
}

void runFunction(int i, const function<void(int)>& fn)
{
	fn(i);
}

void runFunctions(const vector<function<void(int)>>& functions)
{
	int  i = 0;
	for (const auto& fn : functions)
	{
		fn(++i);
	}
}

int main() 
{
	freeFunction(10);

	void (*fnPtr)(int);
	fnPtr = freeFunction;
	(*fnPtr)(20);
	runFunction(10, fnPtr);
	
	FunctionObj functionObj;
	functionObj(10);
	runFunction(10, functionObj);

	auto lambdaFn = [](int i)
	{
		cout << "lambda" << i << endl;
	};
	lambdaFn(10);
	runFunction(10, lambdaFn);

	vector<function<void(int)>> functions;
	functions.push_back(freeFunction);
	functions.push_back(functionObj);
	functions.push_back(lambdaFn);
	runFunctions(functions);

}