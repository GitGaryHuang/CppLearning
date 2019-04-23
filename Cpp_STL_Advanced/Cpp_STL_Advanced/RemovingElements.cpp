#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
#include<set>
#include<functional>
using namespace std;

// Print contents of a container
template<class T>
void print(T t, string msg)
{
	cout << msg << " { ";
	for (typename T::iterator it = t.begin(); it != t.end(); it++) // 此处typename不加也编译成功且正常运行
	{
		cout << *it << ", ";
	}
	cout << " } " << endl;
}
/*
int main()
{
	vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 }; // Remove 1's
	print(c, "Original");

	for (vector<int>::iterator itr = c.begin(); itr != c.end(); )
	{
		if (*itr == 1)
		{
			itr = c.erase(itr);
		}
		else
		{
			itr++;
		}
	}// Complexity: O(n * m)
	print(c, "After erase():");

	c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };
	vector<int>::iterator itr = remove(c.begin(), c.end(), 1); // Complexity: O(n) remove返回新的逻辑结尾
	c.erase(itr, c.end());
	print(c, "After remove():");
	c.shrink_to_fit();; // C++ 11
	vector<int>(c).swap(c);
	cout << "capacity():" << c.capacity() << endl;
}
*/
/*
int main()
{
	// Remove elements from a list
	list<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 }; // Remove 1's
	print(c, "Original");

	list<int>::iterator itr = remove(c.begin(), c.end(), 1);
	c.erase(itr, c.end());
	print(c, "After erase():");

	c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };
	c.remove(1);
	print(c, "After remove():");
}
*/
/*
int main()
{
	// Remove elements from an associative container or unordered container
	multiset<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 }; // Remove 1's
	print(c, "Original");

//	multiset<int>::iterator itr = remove(c.begin(), c.end(), 1);
//	c.erase(itr, c.end());
//	print(c, "After erase():"); 
// Multiset doesn't have remove member function
	
	c.erase(1); //O(log(n))
	print(c, "After erase():");
}
*/

/*
 * Summary of Removing Elements:
 *
 * 1. Vector or Deque: algorithm remove() followed by erase()
 * 2. List: member function remove()
 * 3. Associative Container or Unordered container(): erase()
 *
 * 4. Remove and do something else?
 */

/*
int main()
{
	// Print a message whenever an item is removed
	multiset<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };

	for (auto itr = c.begin(); itr != c.end(); )
	{
		if (*itr == 1)
		{
			cout << "Erased one item of " << *itr << endl;
			c.erase(itr++); // set的erase，使被删除的指针无效
			//cout << "Erased one item of " << *itr << endl;
		}
		else
		{
			itr++;
		}
	}
}
*/
/*
int main()
{
	// Print a message whenever an item is removed
	vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };

	for (auto itr = c.begin(); itr != c.end(); )
	{
		if (*itr == 1)
		{
			cout << "Erased one item of " << *itr << endl;
			itr == c.erase(itr); // vector的erase返回被删元素下一个元素的指针
			//cout << "Erased one item of " << *itr << endl;
		}
		else
		{
			itr++;
		}
	}
}
*/
/*
 * Summary:
 * 
 * Sequence container and unordered container: itr = c.erase(itr);
 * Associative container:                      c.erase(itr);
 */

// Better Solution
/*1.
bool equalOne(int e, int p)
{
	if (e == p)
	{
		cout << e << " will be removed" << endl;
		return true;
	}
	return false;
}

int main()
{
	// Print a message whenever an item is removed.
	vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };

	auto itr = remove_if(c.begin(), c.end(), bind(equalOne, placeholders::_1, 12));
	c.erase(itr, c.end());
}
*/

/*2. Lambda function:

int main()
{
	// Print a message whenever an item is removed.
	vector<int> c = { 1, 4, 6, 1, 1, 1, 1, 12, 18, 16 };

	// Lambda function:
	auto itr = remove_if(c.begin(), c.end(),
		[](int e)
	{
		if (e == 12)
		{
			cout << e << "will be removed" << endl;
			return true;
		}
		else
		{
			return false;
		}
	});
	c.erase(itr, c.end());
}*/