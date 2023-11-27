#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Cat
{
public:
	explicit Cat(int age) : mAge{ age } {}
	
	void speak() const
	{
		cout << "meow\n";
	}
	void test() const
	{
		auto lambda = [&]() // & == this
		{
			cout << "lambda\n"; 
			cout << mAge << '\n';
			speak();
		};
		lambda();
	}

private:
	int mAge;
};

int main()
{
	Cat kitty{ 1 };
	kitty.test();

	vector<int> nums{ 1,2,3,4,5,6,7,8,9,10 };

	// for_each
	auto lambdaAdd10 = [](int& n)
	{
		n += 10;
	};
	for_each(nums.begin(), nums.end(), lambdaAdd10);

	for_each(nums.begin(), nums.end(), [](int& n)
	{
		n += 10;
	});

	// erase, remove_if
	auto filterOdd = [](int n)
	{
		return n % 2 == 1;
	};
	nums.erase(remove_if(nums.begin(), nums.end(), filterOdd));

	nums.erase(remove_if(nums.begin(), nums.end(), [](int n) 
	{
		return n % 2 == 1;
	}), nums.end());

	// sorting
	sort(nums.begin(), nums.end(), [](int a, int b)
	{
		return a < b;
	});
	sort(nums.begin(), nums.end(), [](int a, int b)
	{
		return abs(a - 5) < abs(b - 5); // 5에 가까운 숫자부터 나오게 해줌
	});

	// reduce + policy(parallel), accumulate
	int sum = reduce(nums.begin(), nums.end(), 0, [](int a, int b)
	{
		return a + b;
	});
	int multi = reduce(nums.begin(), nums.end(), 1, [](int a, int b)
	{
		return a * b;
	});
}