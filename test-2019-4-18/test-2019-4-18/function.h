#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;

void foo(const unordered_map<char, string>& m);
void foo(const unordered_map<char, string>& m)
{
	// M['s'] == "SUNDAY"; ERROR
	// cout << m['M'] << endl;  ERROR ±àÒëÆ÷ÈÏÎª³¢ÊÔÐ´Èëm
	auto itr = m.find('S');
	if (itr != m.end())
	{
		cout << (*itr).first << endl;
	}
}