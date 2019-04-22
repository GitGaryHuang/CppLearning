#include<iostream>
using namespace std;

//2019-04-19
/**********************************************************************************************************************************************************
STL Algorithms
#1_Non_modifying Algorithms
*
* STL Algorithms Walkthrough:
*     Non-modifying Algorithms
*     count, min and max, compare, linear search, attribute
*/

// C++ 11 Lambda Function:
//num = count_if(vec.begin(), vec.end(), [](int x) {return x < 10; });

//bool lessThan10(int x)
//{
//	return x < 10;
//}
/*
#include<vector>
#include<algorithm>
vector<int> vec = { 9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7 };
vector<int> vec2 = { 9, 60, 7, 8, 45, 87 };
vector<int>::iterator itr1, itr2;
pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;

// C++ 03: some algorithms can be found in tr1 or boost
int main()
{
	// 1. Counting 
	//      Algorithm Data                      Data
	int n = count(vec.begin(), vec.end(), 69); //2
	int m = count_if(vec.begin(), vec.end(), [](int x) { return x < 10; }); //3
	//cout << n << " " << m;

	// 2. Min and Max 
	vector<int>::iterator itr;
	itr = max_element(vec.begin() + 2, vec.end()); // 90
	//cout << *itr << endl;
	// It returns the first max value
	itr = max_element(vec.begin(), vec.end(), [](int x, int y) { return (x % 10) < (y % 10); }); // 9
	//cout << *itr << endl;

	// Most algorithms have a simple form and a generalized form

	itr = min_element(vec.begin(), vec.end()); //7
	//cout << *itr << endl;
	// Generalized form: min_element()

	pair_of_itr = minmax_element(vec.begin(), vec.end(),// {60, 69}
		[](int x, int y) { return (x % 10) < (y % 10); });
	//cout << *pair_of_itr.first << " " << *pair_of_itr.second << endl;
	// It returns a pair, which contains first of min and last of max

	// 3. Linear Searching (used when data is not sorted)
	//    Return the first match
	itr = find(vec.begin(), vec.end(), 55);
	//cout << *itr << endl;

	itr = find_if(vec.begin(), vec.end(), [](int x) { return x > 80; });
	//cout << *itr << endl;
	itr = find_if_not(vec.begin(), vec.end(), [](int x) { return x > 80; });
	//cout << *itr << endl;
	itr = search_n(vec.begin(), vec.end(), 2, 69); //Consecutive 2 items of 69 查找是否有两个连续的69
	//cout << *itr << endl;
	// Generalized form: search_n()

	// Search subrange
	vector<int> sub = { 45, 87, 90 };
	itr = search(vec.begin(), vec.end(), sub.begin(), sub.end()); //在vec中查找sub的位置
	//cout << *itr << endl;
		// search first subrange
	itr = find_end(vec.begin(), vec.end(), sub.begin(), sub.end());
	//cout << *itr << endl;
		// search last subrange
	// Generalized form: search(), find_end

	// Search any_of
	vector<int> items = { 87, 69 };
	itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end());
		// Search any one of the item in items;即返回vec中第一个与items中元素相同的元素
	//cout << *itr << endl;
	itr = find_first_of(vec.begin(), vec.end(), items.begin(), items.end(), [](int x, int y) { return x == y * 4; });
	//cout << *itr << endl;
		// Search any one of the item in items that satisfy: x == y * 4

	// Search Adjacent
	itr = adjacent_find(vec.begin(), vec.end()); // fint two adjacent items that are same
	//cout << *itr << endl;
	itr = adjacent_find(vec.begin(), vec.end(), [](int x, int y) { return x == y * 4; });
	//cout << *itr << endl;
		// find two adjacent items that satisfy: x == y * 4;

	// 4. Comparing Ranges
	//if (equal(vec.begin(), vec.end(), vec2.begin()))
	//{
	//	cout << "vec and vec2 are same." << endl;
	//}

	//if (is_permutation(vec.begin(), vec.end(), vec2.begin()))
	//{
	//	cout << "vec and vec2 have same items, but in different order" << endl;
	//}

	//pair_of_itr = mismatch(vec.begin(), vec.end(), vec2.begin()); //编译器报错
	// find first difference
	// pair_of_itr.first is an iterator of vec
	// pair_of_itr.second is an iteratof of vec2
	//cout << *pair_of_itr.first << " " << *pair_of_itr.second << endl;

	//Lexicographical Comparison: one-by-one comparison with "less than"
	lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());
	// {1, 2, 3, 5} < {1, 2, 4, 5}
	// {1, 2} < {1, 2, 3}
	//cout << lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end());

	// Generalized forms:
	//  equal(), is_permutation(), mismatch(), lexicographical_compare()

	// 5. Check Attributes
	is_sorted(vec.begin(), vec.end()); // Check if vec is sorted
	itr = is_sorted_until(vec.begin(), vec.end());
	//cout << *itr << endl;
	// itr points to the first place to where elements are no longer sorted
	// Generalized forms: is_sorted(), is_sorted_until()

	is_partitioned(vec.begin(), vec.end(), [](int x) { return x > 80; });
	// Check if vec is partitioned according to the condition of (x > 80) 是否按>80分段

	is_heap(vec.begin(), vec.end()); // Check if vec is a heap
	itr = is_heap_until(vec.begin(), vec.end()); // find the first place where it is no longer a heap
	//cout << *itr << endl;
	//Generalized forms: is_heap(), is_heap_until()

	// All, any, none
	all_of(vec.begin(), vec.end(), [](int x) { return x > 80; });
	// If all of vec is bigger than 80
	any_of(vec.begin(), vec.end(), [](int x) { return x > 80; });
	// If any of vec is bigger than 80
	none_of(vec.begin(), vec.end(), [](int x) { return x > 80; });
	// If none of vec is bigger than 80
}

*/

/**********************************************************************************************************************************************************
STL Algorithms
#2_Modifying Algorithms
 *
 * Algorithm Walkthrough:
 *   Value-changing Algorithm - Changes the element values
 *   copy, move, transform, swap, fill, replace, remove
 */
/*
#include<vector>
#include<algorithm>
#include<string>

int main()
{
	
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
	vector<int> vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 11 items
	vector<int>::iterator itr, itr2;
	pair<vector<int>::iterator, vector<int>::iterator> pair_of_itr;
	// 1. Copy
	copy(vec.begin(), vec.end(), // Source
		 vec2.begin());          // Destination
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout<< endl;

	vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	copy_if(vec.begin(), vec.end(), // Source
		    vec2.begin(),           // Destination
		    [](int x) { return x > 80; }); // Condition
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec2: {87, 90, 0, 0, 0 ,0 ,0 ,0 ,0 ,0, 0}

	vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	copy_n(vec.begin(), 4, vec2.begin());
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec2: {9, 60, 70, 8, 0, 0, 0, 0, 0, 0, 0}

	vec2 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	copy_backward(vec.begin(), vec.end(), // Source
		vec2.end());                      // Destination
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec2: {0, 0, 0, 0, 9, 60, 70, 8, 45, 87, 90}

	// 2. Move
	vector<string> vecs = { "apple", "orange", "pear", "grape" }; // 4 items
	vector<string> vecs2 = { "", "", "", "", "", ""}; // 6 items

	move(vecs.begin(), vecs.end(), vecs2.begin());
	for (vector<string>::iterator itrt = vecs2.begin(); itrt != vecs2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec:  {"", "", "", ""} //Undefined
	// vec2: {"apple", "orange", "pear", "gragpe", "", ""};
	//
	// If move semantics are defined for the element type, elements are moved over,
	// otherwise they are copied over with copy constructor, just like copu()

	vecs = { "apple", "orange", "pear", "grape" };
	vecs2 = { "", "", "", "", "", "" };
	move_backward(vecs.begin(), vecs.end(), vecs2.end());
	for (vector<string>::iterator itrt = vecs2.begin(); itrt != vecs2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vecs2: {"", "", "apple", "orange", "pear", "grape"}
	
	// 3. Transform
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
	vector<int> vec2 = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
	vector<int> vec3 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 11 items

	transform(vec.begin(), vec.end(), // Source
		vec3.begin(),                 // Destination
		[](int x) { return x - 1; }); // Operation
	for (vector<int>::iterator itrt = vec3.begin(); itrt != vec3.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec3 = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // 11 items
	transform(vec.begin(), vec.end(), // Source1
		vec2.begin(),                 // Source2
		vec3.begin(),                 // Destination
		[](int x, int y) { return x + y; }); // Operation
	for (vector<int>::iterator itrt = vec3.begin(); itrt != vec3.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
		// Add items from vec and vec2 and svae in vec3
		// vec3[0] = vec[0] + vec2[0]
		// vec3[1] = vec[1] + vec2[1]
		// ...

	// 4. Swap - two way copying
	swap_ranges(vec.begin(), vec.end(), vec2.begin());
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	
	// 5. Fill
	vector<int> vec = { 0, 0, 0, 0, 0 };
	fill(vec.begin(), vec.end(), 9); // vec: {9, 9, 9, 9, 9}
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 0, 0, 0, 0, 0 };
	fill_n(vec.begin(), 3, 9); // vec: {9, 9, 9, 0, 0}
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 0, 0, 0, 0, 0 };
	generate(vec.begin(), vec.end(), rand);
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 0, 0, 0, 0, 0 };
	generate_n(vec.begin(), 3, rand);
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl; 
	
	// 6. Replace
	vector<int> vec = { 0, 0, 6, 88, 0 };
	vector<int> vec2 = { 0, 0, 26, 0, 0 };

	replace(vec.begin(), vec.end(), // Data Range
		6,                          // Old value condition
		9);                         // New value
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 0, 0, 6, 88, 0 };
	replace_if(vec.begin(), vec.end(), // Data Range
		[](int x) { return x > 80; },  // Old value condition
		9);                            // New value
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 0, 0, 6, 88, 0 };
	replace_copy(vec.begin(), vec.end(),// Data Range
		vec2.begin(),                     // Destination  
		6,                              // Old value condition
		9);                             // new value
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	// Generalized form: replace_copy_if()
	
	// 7. Remove
	vector<int> vec = { 3, 6, 10, 10, 2, 92 };
	remove(vec.begin(), vec.end(), 3); // Remove all 3's
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 3, 6, 10, 10, 2, 92 };
	remove_if(vec.begin(), vec.end(), [](int x) { return x > 80; }); // Remove items bigger than 80
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 3, 6, 10, 10, 2, 92 };
	vector<int> vec2 = { 0, 0, 0, 0, 0, 0 };
	remove_copy(vec.begin(), vec.end(), // Source
		vec2.begin(),                   // Destination
		6);                             // Condition
	// Remove all 6's, and copy the remain items to vec2
	// Generalized form: remove_copy_if()
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 3, 6, 10, 10, 2, 92 };
	unique(vec.begin(), vec.end()); // Remove consecutive equal items 实际是把不重复的元素移到前面来。
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 3, 6, 10, 10, 2, 92 };
	unique(vec.begin(), vec.end(), less<int>()); // Remove elements whose previous element is less than itself
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;

	vec = { 3, 6, 10, 10, 2, 92 };
	vec2 = { 0, 0, 0, 0, 0, 0 };
	unique_copy(vec.begin(), vec.end(), vec2.begin());
	// Remove consecutive equal elements, and then copy the uniquified items to vec2
	// Generalized form: unique_copy
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	*/
/*
 * Order-Changing Algorithms:
 *   - reverse, rotate, permute, shuffle
 *
 * They changes the order or elements in container, but not necessarily the elements themselves
 */
	/*
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
	vector<int> vec2 = { 0, 0, 0, 0, 0, 0, 0 }; // 7 items;

	// 1. Reverse
	reverse(vec.begin() + 1, vec.end() - 1);
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec: {9, 87, 45, 8, 70, 60, 90}; // 7 items

	vec = { 9, 60, 70, 8, 45, 87, 90 };
	reverse_copy(vec.begin() + 1, vec.end() - 1, vec2.begin());
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec2: {87, 45, 8, 70, 60, 0, 0};

	// 2. Rotate
	vec = { 9, 60, 70, 8, 45, 87, 90 };
	rotate(vec.begin(), vec.begin() + 3, vec.end());
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
	// vec: {8, 45, 87, 90, 9, 60, 70}; 7 items

	vec = { 9, 60, 70, 8, 45, 87, 90 };
	vec2 = { 0, 0, 0, 0, 0, 0, 0 }; // 7 items;
	rotate_copy(vec.begin(), vec.begin() + 3, vec.end(),
		vec2.begin());
	for (vector<int>::iterator itrt = vec2.begin(); itrt != vec2.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;
		// Copy vec to vec2 in rotated order
		// vec is unchanged
	
	// 3. Permute
	next_permutation(vec.begin(), vec.end());
		//Lexicographically next greater permutation
	prev_permutation(vec.begin(), vec.end());
		//Lexicographically next smaller permutation
	// {1, 2, 3, 5} < {1, 2, 4, 4}
	// {1, 2} < {1, 2, 3}

	//Sorted in ascending order: {8, 9, 45, 60, 70 87, 90} 逐步升序
	//							  - Lexicographically smallest
	//
	//Sorted in descending order: {90, 87, 70, 60, 45, 9, 8} 逐步降序
	//							  - Lexicographically greatest

	// Generalized form: next_permutation(), prev_permutation()

	// 4. Shuffle
	//    - Rearrange the elements randomly
	//		(swap each element with a randomly selected element)
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90 }; // 7 items
	random_shuffle(vec.begin(), vec.end());
	for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
		cout << *itrt << " ";
	cout << endl;


	//random_shuffle(vec.begin(), vec.end(), rand); //编译错误
	//for (vector<int>::iterator itrt = vec.begin(); itrt != vec.end(); ++itrt)
	//	cout << *itrt << " ";
	//cout << endl;

	// C++ 11
//

	//shuffle(vec.begin(), vec.end(), default_random_engine()); //编译错误
	// Better random number generation
	
}
*/

/**********************************************************************************************************************************************************
STL Algorithms
#3_Sorting
 *
 * Sortings in STL
 */
// Sorting algorithm requires random access iterators:
//    vector, deque, container array, native array
/*
#include<vector>
#include<algorithm>
#include<functional>

bool lsb_less(int x, int y)
{
	return (x % 10) < (y % 10);
}

bool lessThan10(int i)
{
	return (i < 10);
}

int main()
{
	
	vector<int> vec = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };

	sort(vec.begin(), vec.end()); //sort with operator<
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 1 2 3 4 5 8 9 9 10 45 90

	sort(vec.begin(), vec.end(), lsb_less); //sort with lsb_less
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec : 10 90 1 2 3 4 45 5 8 9 9
	
	// Sometime we don't need complete sorting.

	// Problem #1: Finding top 5 students according to their test scores.
	//
	//  - partial sort
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };

	partial_sort(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 90 87 70 69 69 8 9 45 60 55 7

	// Overloaded:
	vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
	partial_sort(vec.begin(), vec.begin() + 5, vec.end());
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 7 8 9 45 55 90 60 87 70 69 69
	
	// Problem #2: Finding top 5 students according to their score, but I don't care their order.
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };

	nth_element(vec.begin(), vec.begin() + 5, vec.end(), greater<int>());
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	
	// Problem #3: Move the students whose score is less than 10 to the front
	vector<int> vec = { 9, 60, 70, 8, 45, 87, 90, 69, 69, 55, 7 };
	partition(vec.begin(), vec.end(), lessThan10);
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 9 7 8 70 45 87 90 69 69 55

	// To preserve the original order within each partition:
	stable_partition(vec.begin(), vec.end(), lessThan10);
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 9 7 8 70 45 87 90 69 69 55
	
	// Heap Algorithms
	// 
	// Heap:
	// 1. First element is always the largest
	// 2. Add/remove takes O(log(n)) time

	vector<int> vec = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };
	make_heap(vec.begin(), vec.end());
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 90 45 10 9 8 3 9 4 2 5 1

	// Remove the largest element:
	pop_heap(vec.begin(), vec.end()); // 1. Swap vec[0] with last item vec[size - 1]
									  // 2. Heapify [vec.begin(), vec.end() - 1)
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 45 9 10 4 8 3 9 1 2 5 90
	vec.pop_back(); // Remove the last item (the largest one)
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 45 9 10 4 8 3 9 1 2 5
	
	// Add a new element:
	vec.push_back(100);
	push_heap(vec.begin(), vec.end()); //Heapify the last item in vec
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec : 100 45 10 4 9 3 9 1 2 5 8

	// Heap Sorting:
	vector<int> vec2 = { 9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8 };
	make_heap(vec2.begin(), vec2.end());
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	sort_heap(vec2.begin(), vec2.end());
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: 1 2 3 4 5 8 9 9 10 45 100
	// Note: sort_heap can only work on a heap.
}
*/


/**********************************************************************************************************************************************************
STL Algorithms
#4_Sorted Data Algorithms and Numeric Algorithms
 *Sorted Data Algorithms
 *  - Algorithms that require data being pre-sorted
 *  - Binary search, merge, set operations
 */

// Note: Every sorted data algorithms has a generalized form with a same name
/*
#include<vector>
#include<algorithm>
#include<numeric>

int main()
{
	
	vector<int> vec = { 8, 9, 9, 9, 45, 87, 90 }; //7 items
	// 1. Binary Search
	// Search Elements
	bool found = binary_search(vec.begin(), vec.end(), 9); // check if 9 is in vec
	cout << found << endl;

	vector<int> s = { 9, 45, 66 };
	found = includes(vec.begin(), vec.end(), // Range #1
		s.begin(), s.end());                      // Range #2
	cout << found << endl;
	// Return true if all elements of s is include vec
	// Both vec and s must be sorted

	// Search Position
	vector<int>::iterator itr = lower_bound(vec.begin(), vec.end(), 9); // vec[1]
	// Find the first position where 9 could be inserted and still keep the sorting
	cout << *itr << endl;

	itr = lower_bound(vec.begin(), vec.end(), 9); // vec[4]
	// Find the last position where 9 could be inserted and still keep the sorting
	cout << *itr << endl;

	pair<vector<int>::iterator, vector<int>::iterator> pari_of_itr = equal_range(vec.begin(), vec.end(), 9);
	// Returns both first and last position
	cout << *pari_of_itr.first << " " << *pari_of_itr.second << endl;

	// 2. Merge
	vector<int> vec = { 8, 9, 9, 10 };
	vector<int> vec2 = { 7, 9, 10 };
	vector<int> vec_out = { 0, 0, 0, 0, 0, 0, 0 };
	merge(vec.begin(), vec.end(), // Input Range #1
		vec2.begin(), vec2.end(), // Input Range #2
		vec_out.begin()); // Output
	for (vector<int>::iterator itrout = vec_out.begin(); itrout != vec_out.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// Both vec and vec2 should be sorted (same for the set operation)
	// Nothing is dropped, all duplicates are kept
	// vec_out: { 7, 8, 9, 9, 9, 10, 10}

	vector<int> vec3 = { 1, 2, 3, 4, 1, 2, 3, 4, 5 }; // Both part of vec are already sorted
	inplace_merge(vec3.begin(), vec3.begin() + 4, vec3.end());
	for (vector<int>::iterator itrout = vec3.begin(); itrout != vec3.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// vec: {1, 1, 2, 2, 3, 3, 4, 4, 5} - One step of merge sort
	
	// 3. Set operations
	//    - Both vec and vec3 should besorted
	//    - The resulted data ia also sorted
	vector<int> vec = { 8, 9, 9, 10 }; 
	vector<int> vec2 = { 7, 9, 10 };   
	vector<int> vec_out = { 0, 0, 0, 0 ,0 }; 
	set_union(vec.begin(), vec.end(),   // Input Range #1
		vec2.begin(), vec2.end(),       // Input Range #2
		vec_out.begin());               // Output
	for (vector<int>::iterator itrout = vec_out.begin(); itrout != vec_out.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// if X is in both vec and vec2, only one X is kept in vec_out
	// vec_out: {7, 8, 9, 9, 10}

	vec_out = { 0, 0, 0, 0 ,0 };
	set_intersection(vec.begin(), vec.end(),
		vec2.begin(), vec2.end(),
		vec_out.begin());
	for (vector<int>::iterator itrout = vec_out.begin(); itrout != vec_out.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// Only the items that are in both vec and vec2 are saved in vec_out
	// vec_out: {9, 10, 0, 0, 0}
	
	vec_out = { 0, 0, 0, 0 ,0 };
	set_difference(vec.begin(), vec.end(),   // Input Range #1
		vec2.begin(), vec2.end(),       // Input Range #2
		vec_out.begin());               // Output
	for (vector<int>::iterator itrout = vec_out.begin(); itrout != vec_out.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// Only the items that are in vec but note in vec2 are saved in vec_out
	// vec_out: {8, 9, 0, 0, 0}

	set_symmetric_difference(vec.begin(), vec.end(),   // Input Range #1
		vec2.begin(), vec2.end(),       // Input Range #2
		vec_out.begin());               // Output
	for (vector<int>::iterator itrout = vec_out.begin(); itrout != vec_out.end(); ++itrout)
		cout << *itrout << " ";
	cout << endl;
	// vec_out has items from either vec or vec2, but note from both
	// vec_out: {7, 8, 9, 0, 0}
	*/
	/*
	 * Numeric Algorithms (in <numeric>)
	 *  - Accumulate, inner product, partial sum, adjacent difference

	// 1. Accumulate
	vector<int> vec = { 10, 21, 32 };
	int x = accumulate(vec.begin(), vec.end(), 10);
	cout << x << endl;
	// 10 + vec[0] + vec[1] + vec[2] + ...

	vec = { 10, 21, 32 };
	x = accumulate(vec.begin(), vec.end(), 10, multiplies<int>());
	cout << x << endl;
	// 10 * vec[0] * vec[1] * vec[2] * ...
	
	// 2. Inner Product
	vector<int> vec = {1, 2, 3, 4, 5, 6}; // 7 items
	int x = inner_product(vec.begin(), vec.begin() + 3, // Range #1
		vec.end() - 3,                                  // Range #2
		10);                                            //Init Value
	// 10 +  vec[0] * vec[3] + vec[1] * vec[4] + vec[2] * vec[5]
	cout << x << endl;

	x = inner_product(vec.begin(), vec.begin() + 3, // Range #1
		vec.end() - 3,                                  // Range #2
		10,
		multiplies<int>(),
		plus<int>());                                            //Init Value
	//10 *  (vec[0] + vec[3]) * (vec[1] + vec[4]) * (vec[2] + vec[5])
	cout << x << endl;
	
	// 3. Partial Sum
	vector<int> vec = {1, 2, 3, 4, 5};
	vector<int> vec2 = {0, 0, 0, 0, 0};
	partial_sum(vec.begin(), vec.end(), vec2.begin());
	// vec2[0] = vec[0]
	// vec2[1] = vec[0] + vec[1]
	// vec2[2] = vec[0] + vec[1] + vec[2]
	// ...
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	vec2 = { 0, 0, 0, 0, 0 };
	partial_sum(vec.begin(), vec.end(), vec2.begin(), multiplies<int>());
	// vec2[0] = vec[0]
	// vec2[1] = vec[0] * vec[1]
	// vec2[2] = vec[0] * vec[1] * vec[2]
	// ...
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	
	// 4. Adjacent Difference
	vector<int> vec = { 1, 2, 3, 4, 5 };
	vector<int> vec2 = { 0, 0, 0, 0, 0 };
	adjacent_difference(vec.begin(), vec.end(), vec2.begin());
	// vec2[0] = vec[0]
	// vec2[1] = vec[1] - vec[0]
	// vec2[2] = vec[2] - vec[1]
	// ...
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	vec2 = { 0, 0, 0, 0, 0 };
	adjacent_difference(vec.begin(), vec.end(), vec2.begin(), plus<int>());
	// vec2[0] = vec[0]
	// vec2[1] = vec[1] + vec[0]
	// vec2[2] = vec[2] + vec[1]
	// ...
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	
}
*/