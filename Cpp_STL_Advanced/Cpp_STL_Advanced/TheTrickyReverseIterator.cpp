/*
 * Reverse Iterator and Iterator 
 */

/*
// Two ways to declare a reverse iterator
reverse_iterator<vector<int>::iterator> ritr;
vector<int>::reverse_iterator ritr; // one is a typedef of another

// Traversing with reverse iterator
vector<int> vec = {4, 5, 6, 7};
reverse_iterator<vector<int>::iterator> ritr;
for (ritr = vec.rbegin(); ritr != vec.end(); ritr++)
	cout << *ritr << endl; // prints: 7 6 5 4
*/

/*
vector<int>::iterator itr;
vector<int>::reverse_iterator ritr;

rtir = vector<int>::reverse_interator<int>;

itr = vector<int>::iterator(ritr); // Compile Error
itr = ritr.base();

// C++ Standard: base() return current iterator
*/
#include<vector>
#include<iostream>
/*
using namespace std;
int main()
{
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int>::reverse_iterator ritr = find(vec.rbegin(), vec.rend(), 3);

	cout << (*ritr) << endl; // 3
	
	vector<int>::iterator itr = ritr.base(); // reverse iterator plus 1

	cout << (*itr) << endl; // 4

	vec = { 1, 2, 3, 4, 5 };
	ritr = find(vec.rbegin(), vec.rend(), 3);

	// Inserting
	vec.insert(itr, 9); // vec: {1, 2, 3, 9, 4, 5} // vector的insert函数不接受reverse_iterator
	// Or
	//vec.insert(ritr.base(), 9);

	//vec = { 1, 2, 3, 4, 5 };
	//ritr = find(vec.rbegin(), vec.rend(), 3);

	// Erasing 
	vec.erase(itr); // vec: {1, 2, 4, 5} // vector的erase函数不接受reverse_iterator 但此处也报错
	// or
	//vec.erase(ritr.base());
}*/