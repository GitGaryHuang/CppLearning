#include<vector>
#include<deque>
#include<iostream>
using namespace std;

/*
int main()
{
	vector<int> vec = { 2, 3, 4, 5 };

	cout << "vec's size: " << vec.size() << endl;
	cout << "vec's capacity:" << vec.capacity() << endl;

	vec.push_back(6);
	cout << "After push_back(6): " << vec.size() << endl;
	cout << "After push_back(6): " << vec.capacity() << endl;
	// Vector capacity grows exponentially.  
	// Drawbacks:
	// 1. Expensive reallocation
	// 2. Requires contiguous memory
}
*/
/*
class Dog{};

int main()
{
	// Example 1:
	vector<Dog> vec(6); // 6 Dogs created with default constructor
	cout << "vec: size = " << vec.size() << " capacity = " << vec.capacity() << endl;

	// Example 2:
	vector<Dog> vec2; // vec2.capacity() == 0, vec2.size() == 0
	cout << "vec2: size = " << vec2.size() << " capacity = " << vec2.capacity() << endl;
	vec2.resize(6);   // 6 Dogs created with default constructor
	cout << "vec2: size = " << vec2.size() << " capacity = " << vec2.capacity() << endl;

	// Example 3:
	vector<Dog> vec3;
	vec3.reserve(6); // no Dog's default constructor invoked 只增加capacity不增加size
	cout << "vec3: size=" << vec3.size() << " capacity = " << vec3.capacity() << endl;
}
*/
/*
 * Strategy of minimizing reallocation:
 *
 * 1. If the maximum number of item is known, reserve(MAX);
 *
 * 2. If the end of grow is known, reserve as much memory as we can, once all
 *    data a inserted, trim off the rest
 */
//c.shrink_to_fit(); // C++ 11
//vector<int>(c).swap(c); // C++ 03

/*
 * Growth of Deque:
 *
 * Deque grows linearly with a fixed size.
 *
 * Deque:
 * 
 * - No reallocation
 *   deque has no reserve() and capacity()
 *
 * - Slightly slower than vector
 *   + More complex data structure
 *   + Locality
 */

/*
 * Deque or vector, which one to use?
 *
 * - Need to push_front a lot? -> deuqe
 *
 * - Performance is important? -> vector
 */

/*
 * 1. Element type
 *    - When the elements are not of a trivial type (build-in data type), deque is not
 *    much less efficient than vector.
 */

/*
 * 2. Memory Availability
 *   Could allocation of large contiguous memory be a problem?
 *   - Limited memory size
 *   - Large trunk of data
 *   - Memory flagmentation
 */

/*
 * 3. Frequency of Unpredictable Growth (prefer using deque)
 */
/*
int main()
{
	vector<int> vec;
	for (int x = 0; x < 1025; x++)
		vec.push_back(x); // 11 reallocations performed (growth ratio = 2)
	// workaround: reserve()
}
*/

/*
 * 4. Invalidation of pointers/references/iterators because of growth
 */
/*
int main()
{
	vector<int> vec = { 2, 3, 4, 5 };
	int* p = &vec[3];
	vec.push_back(6); // reallocation, invalidate all the previous pointers
	cout << *p << endl; // Undefined behavior

	deque<int> deq = { 2, 3, 4, 5 };
	p = &deq[3];
	deq.push_back(6);
	cout << *p << endl; // OK: 5
	// push_front() is OK too
	// deque: inserting at either end won't invalidate pointers

	// Note: removing or inserting in the middle still will invalidate
	//       pointers/references/iterators
}
*/

/*
 * 5. Vector's unique function: portal to c
 */
/*
#include<list>
int main()
{
	vector<int> vec = { 2, 3, 4, 5 };
	
	void c_fun(const int* arr, int size);

	// Passing data from a list to C
	list<int> mylist;
	//...
	vector<int> vec(mylist.begin(), mylist.end());
	c_fun(&vec[0], vec.size());

	// Note: &vector[0] can be used as a raw array.
	// Exception: vector<bool>
	void cpp_fun(const bool* arr, int size);
	vector<bool> vec = { true, true, false, true };
	cpp_fun(&vec[0], vec.size()); // Compiler Error: &vec[0] is not a bool pointer

	// workaround: use vector<int>, or bitset
	
}
*/

/*
 * Summary:
 * 1. Frequent push_front()         -deque
 * 2. Build-in data type            -vector
 * 3. Not build-in data type        -deque
 * 4. Contiguous memory             -deque
 * 5. Unpredictable growth          -deque
 * 6. Pointer integrity             -deque
 * 7. Frequently passed to c        -vector
 */