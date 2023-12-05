#include <iostream>
#include <set>
#include <string>

using namespace std;

struct customFn
{
	bool operator() (const int lhs, const int rhs) const
	{
		return (lhs % 10) < (rhs % 10);
	}
};

class Cat
{
public:
	Cat(int age, string name) : mAge{ age }, mName{ move(name) }{ }
	void speak() const
	{
		cout << mAge << endl;
	}
	int age() const
	{
		return mAge;
	}
	const string name() const
	{
		return mName;
	}

private:
	int mAge;
	string mName;
};

bool operator< (const Cat& lhs, const Cat& rhs)
{
	return lhs.age() < rhs.age();
}

int main()
{
	// �ߺ� ����
	// ���������� ���ĵǾ� �ִ�.
	set<int, customFn> nums{ 1,2,3,4,5 };
	nums.emplace(3);
	nums.emplace(11); // 1
	nums.emplace(21); // 1

	set<Cat> cats; 
	cats.emplace(1, "a");
	cats.emplace(2, "b");
	cats.emplace(1, "c"); // ���� �浹�� ����. name���� ���ϸ�ȴ�.

	// multiset �ߺ� ���
	multiset<int> mSet{ 1,2,3,3,4,5 };

	// unordered_set hash ���
}