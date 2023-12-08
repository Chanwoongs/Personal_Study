#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Cat
{
public:
	Cat(int age, string name) : mAge{ age }, mName{ name } {}

	const int age() const
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

// custom hash
struct CatHash
{
	std::size_t operator()(Cat const& c) const noexcept
	{
		std::size_t h1 = std::hash<int>{}(c.age());
		std::size_t h2 = std::hash<string>{}(c.name());
		return h1 ^ h2;
	}
};

// == operator overload
bool operator== (const Cat& lhs, const Cat& rhs) noexcept
{
	return (lhs.age() == rhs.age() && lhs.name() == rhs.name());
}

// Custom specialization of std::hash can be injected in namespace std.
namespace std
{
	template<>
	struct std::hash<Cat>
	{
		std::size_t operator()(const Cat& c) const noexcept
		{
			std::size_t h1 = std::hash<int>{}(c.age());
			std::size_t h2 = std::hash<string>{}(c.name());
			return h1 ^ h2;
		}
	};
}
int main()
{
	unordered_set<string> uSet;
	uSet.reserve(1000); // �̸� bucket size ����
	uSet.max_load_factor(10); // bucket���� ���� ������ ������ �� �ִ�. rehashing ����

	uSet.emplace("a");
	uSet.emplace("b");
	uSet.emplace("c");
	uSet.emplace("d");
	
	// ��½� �������� ���
	uSet.find("a");
	uSet.erase("a");
	// ��� O(1)

	// �� Hash ��
	cout << "Hash �� : " << hash<string>{}("a") << uSet.bucket("a") << endl;
	cout << "Hash �� : " << hash<string>{}("b") << uSet.bucket("b") << endl;
	cout << "Hash �� : " << hash<string>{}("c") << uSet.bucket("c") << endl;
	cout << "Hash �� : " << hash<string>{}("d") << uSet.bucket("d") << endl;
	
	cout << "bucket count : " << uSet.bucket_count() << endl;


	Cat kitty{ 1, "kitty" };
	Cat nabi{ 1, "nabi" };

	// error, hash ���� equal�� ���ǰ� �Ǿ������ʴ�.
	// custom hash�� == �����ڸ� �������ش�.
	unordered_set<Cat> cats;
	cats.emplace(kitty);
	cats.emplace(nabi); 
	
	// error X
	unordered_set<Cat, CatHash> cats;
	cats.emplace(kitty);
	cats.emplace(nabi);

	// with namespace injection
	unordered_set<Cat> cats;
	cats.emplace(kitty);
	cats.emplace(nabi);
	
	// multiset �̶�� �ߺ� ���
}