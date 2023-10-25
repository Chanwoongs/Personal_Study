#include <iostream>
#include <memory>
using namespace std;

class Person
{
public:
    Person()
    {
        this->name = "alanwalker";
        this->IQ = 100;
        this->str = 100;

        cout << "Person Constructor\n";
    }
    Person(string name, int IQ, int str) : name(name), IQ(IQ), str(str)
    { cout << "Person Constructor\n"; }
    ~Person() { cout << "Person Destructor\n"; }

    //맴버 함수 (메서드)
public:
    void levelUp()
    {
        this->IQ += 1;
        this->str += 1;
        cout << this->name << " IQ, str increased. IQ : " << this->IQ << ", str : " << this->str << '\n';
    }

    // 맴버 변수 (속성)
private:
    string name;
    int IQ;
    int str;
};

int main()
{
    Person* p; // 객체
    p = new Person("chanwoong", 140, 140); // 인스턴스
    p->levelUp();
    delete p;

    unique_ptr<Person> person = make_unique<Person>("Bang", 150, 150);
    person->levelUp();
}