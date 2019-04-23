// Question:
#include<set>
#include<iostream>
using namespace std;

class Lsb_less
{
public:
	bool operator()(int x, int y)
	{
		return (x % 10) < (y % 10);
	}
};

/*
int main()
{
	set<int, Lsb_less> s = { 21, 23, 26, 27 };
	set<int, Lsb_less>::iterator itr1, itr2;

	itr1 = find(s.begin(), s.end(), 36); // s.end()  Algorithm find() looks for equality: if( x == y)

	itr2 = s.find(36); // 26 set<int>::find() looks for equivalence: if( !(x<y) && !(y<x) )
}

*/
/*
int main()
{
	set<int> s = { 21, 23, 26, 27 };
	set<int>::iterator itr1, itr2;

	itr1 = find(s.begin(), s.end(), 36); // s.end()

	itr2 = s.find(36); // s.end()

}
*/
// Guidelines:
//
// If the function is using operator "<" or its like, it's checking equivalence
//   - Typically it's a algorithm that works with sorted data, or a member 
//     function of a container with sorted data, such as associative container.
//
// If the function is using operator "==" or its like, it's checking equality
//   - Typically the data is not required to be sorted

// Algorithms of equality:
// search
// find_end
// find_first_of
// adjacent_search 

// Algorithms of equivalence:
// binary_search // simple forms
// includes
// lower_bound
// upper_bound

/*
 * Summary:
 *    When using a function to search or remove certain element, make sure you
 * understand the difference between equality and equivalence.
 */