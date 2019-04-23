#include<deque>
#include<string>
#include<iostream>
using namespace std;
/*
class Dog
{
public:
	virtual void bark() { cout << "I don't have a name." << endl;  }
};

class YellowDog : public Dog
{
	string m_name;
public:
	YellowDog(string name):m_name(name){}
	void bark() { cout << "My name is " << m_name << endl; }
};

void foo(Dog d) {}
int main()
{
	deque<Dog*> d;
	YellowDog y("Gunner");
	y.bark();
	d.push_front(&y);
	
	d[0]->bark();

	Dog d2 = y;
	foo(y);
}
*/