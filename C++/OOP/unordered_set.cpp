#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

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
}