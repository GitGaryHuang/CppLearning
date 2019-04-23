/*
 * Container's member functions vs algorithms
 */

// Functions with same name:

/* List
void remove(const T); template<class Comp> void remove_if(Comp);
void unique();        template<class Comp) void unique(Comp);
void sort();          template<class Comp) void unique(Comp);
void merge(list&);    template<class Comp) void merge(Comp):
void reverse();
*/

/* Associative Container
size_type count(const T&) const;
iterator find(const T&) const;
iterator lower_bound(const T&) const;
iterator upper_bound(const T&) const;
pair<iterator, iterator> equal_range (const T&) const;
Note: they don't have generalized form, because comparison is defined by the container
*/

/* Unordered Container
size_type count(const T&) const;
iterator find(const T&);
std::pair<iterator, iterator> equal_range(const T&);
// Note No generalized form; use hash function to search
*/


#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

/*
int main()
{
	unordered_set<int> s = { 2, 4, 1, 8, 5, 9 }; // Hash table
	unordered_set<int>::iterator itr;
	
	// Using member function // O(1)
	itr = s.find(4);

	// Using Algorithm
	itr = find(s.begin(), s.end(), 4); // O(n)
}
*/

/*
#include<map>
// How about map/multimap?
int main()
{
	map<char, string> mymap = { {'S', "Sunday"}, {'M', "Monday"}, {'W', "Wednesday"}, ....};
	map<char, string>::iterator itr;
	// Using member function  // O(log(n));
	itr = mymap.find('F');

	// Using Algorithm
	itr = find(mymap.begin(), mymap.end(), make_pair('F', "Friday")); // O(n)
}
*/

/*
#include<list>
// How about list?
int main()
{
	list<int> s = { 2, 4, 1, 8, 5, 9 };

	// Using member function          Changing pointer 即修改指针
	s.remove(4);  // O(n) 
	// s: {2, 1, 8, 5, 9}

	//Using Algorithm                 Using copy 即后续元素前移动
	remove(s.begin(), s.end(), 4);  // O(n)
	// s: {2, 1, 8, 5, 9, 9} 因为是后续元素前移 algorithm 只接触 iterator 而不知道 container
	// 因此要完成这项操作 要这么写
	list<int>::iterator itr = remove(s.begin(), s.end(), 4);
	// s: {2, 1, 8, 5, 9, 9} 
	s.erase(itr, s.end());
	// s: {2, 1, 8, 5, 9}

	// Same time for find
	// Member function takes less time for remove

	// Sort
	//
	// Member function
	s.sort();

	// Algorithm
	sort(s.begin(), s.end()); // Undefined behavior because sort needs random access iterator but list doesn't have
}
*/

/*
 * Summary:
 *
 * 1. There are duplicated functions between containe's member functions and algorithm functions.
 * 2. Prefer member functions over algorithm functions with the same names.
 *
 */

