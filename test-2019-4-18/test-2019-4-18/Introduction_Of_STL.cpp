#include<iostream>
using namespace std;

//2019-04-18
/************************************************************************************************************************************************************
Introduction of Templates
#0
template<typename T>
T square(T x)
{
	return x * x;
}

template<typename T>
class BoVector
{
	T arr[1000];
	int size;
public:
	BoVector() : size(0) {}
	void push(T x) { arr[size] = x; size++; }
	T get(int i) const { return arr[i]; }
	int getSize() const { return size; }
	void printf() const { for (int i = 0; i < size; i++) { cout << arr[i] << endl; } }
};

template<typename T>
BoVector<T> operator* (const BoVector<T>& rhs1, const BoVector<T>& rhs2)
{
	BoVector<T> ret;
	for (int i = 0; i < rhs1.getSize(); i++)
	{
		ret.push(rhs1.get(i) * rhs2.get(i));
	}
	return ret;
}
int main()
{
	cout << square(5) << endl;
	cout << square(5.5) << endl;

	BoVector<int> bv;
	bv.push(2);
	bv.push(3);
	bv.push(6);
	bv.printf();

	cout << "Print squared bv:" << endl;
	bv = square(bv);
	bv.printf();

	return 0;
}
*/


/************************************************************************************************************************************************************
Introduction of STL
#1_Overview
#include<vector>
#include<algorithm>
int main()
{
	vector<int> vec;
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(5);

	vector<int>::iterator itr1 = vec.begin();
	vector<int>::iterator itr2 = vec.end();

	for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
	{
		cout << *itr << " ";
	}

	sort(itr1, itr2);

	for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
	{
		cout << *itr << " ";
	}


}
*/



/************************************************************************************************************************************************************
Introduction of STL
#2_Sequence Container
 * Vector
 * Properties of Vector:
 * 1. fast insert/remove at the end: O(1)
 * 2. slow insert/remove at the beginning or in the middle: O(N)
 * 3. slow search: O(n)
 *
 * Deque
 * Properties:
 * 1. fast insert/remove at beginning and the end;
 * 2. slow insert/remove in the middle: O(n)
 * 3. slow search: O(n)
 *
 * List
 *  --double linked list
 * Properties:
 * 1. fast insert/remove at any place: O(1)
 * 2. slow search: O(n)
 * 3. no random access, no [] operator.
 *
 * ForwardList
 *  --single linked list
 *
 * Array 长度一旦定义无法改变
 */
/*
#include<vector>
#include<deque>
#include<list>
int main()
{
	cout << "Now Vector Test:" << endl;
	vector<int> vec;  //vec.size() == 0
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(8); //vec: {5, 2, 8}; vec.size() == 3;

	// Vector specific operations:
	cout << vec[2] << endl;    //8 (no range check)
	cout << vec.at(2) << endl; //8 (throw range_error exception of out of range)

	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " " ;
	}
	cout << endl;
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) //faster , more universal
	{
		cout << *itr << " ";
	}
	cout << endl;
	
	//Vector is a dynamically allocated contigous array in memory   (contigous adj. 邻近的)

	int* p = &vec[0];

	// Common member functions of all containers.
	// vec: {5, 2, 8}
	if (vec.empty()) { cout << "Not possible. \n"; }

	cout << vec.size() << endl; // 3

	vector<int> vec2(vec); //Copy constructor, vec2:{5, 2 , 8}
	vec.clear(); // Remove all items in vec; vec.size == 0;
	vec2.swap(vec); // vec2 become empty ,and vec has 3 items.

	//Notes: No penalty of abstraction, very efficient.


	cout << "Now Deque Test:" << endl;
	deque<int> deq = { 4, 6, 7 };
	deq.push_front(2); // deq: {2, 4, 6, 7}
	deq.push_back(3); // deq: {2, 4, 6, 7, 3}

	// Deque has similar interface with vector
	cout << deq[1] << endl; // 4

	cout << "Now List Test:" << endl;
	list<int> mylist = { 5, 2, 9 };
	mylist.push_back(6); // mylist: {5, 2, 9, 6}
	mylist.push_front(4); // mylist: {4, 5, 2, 9, 6}

	list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
	mylist.insert(itr, 8); // mylist: {4, 5, 8, 2, 9, 6}
	cout << *itr << endl;
	itr++;                 // O(1), faster than vector/deque
                           // itr -> 9
	cout << *itr << endl;
	mylist.erase(itr);     // mylist: {4, 5, 8, 2, 6} O(1)

	//mylist1.splice(itr, mylist2, itr_a, itr_b);  list::splice实现list拼接的功能。将源list的内容部分或全部元素删除，拼插入到目的list。
	
}
*/



/************************************************************************************************************************************************************
Introduction of STL
#3_Associative Container 
 * Key : Value
 * set/multiset (Key == Value) 
 * map/multimap (Key != Value)
 * 
 * 
 * Always sorted, default criteria is <
 * No push_back(), push_front()
 * 
 * Set
 * - No duplicates
 * 
 * Multiset 
 * - Allow duplicates 
 * 
 * Properties:
 * 1. Fast search: O(log(n))
 * 2. Traversing is slow (compared to vector & deque)
 * 3. No random access, no [] operator
 * 4. sorted by value
 *
 * Map
 * - No duplicated key
 *
 * Multimap
 * - Allow duplicates
 *
*/
/*
#include<set>
#include<map>
int main()
{
	cout << "Now Set test:" << endl;
	set<int> myset;
	myset.insert(3); // myset: {3}
	myset.insert(1); // myset: {1, 3}
	myset.insert(7); // myset; {1, 3, 7}, O(log(n))

	set<int>::iterator it;
	it = myset.find(7); // O(log(n)), it points to 7
	                    // Sequence container don't even have find() member function
	pair<set<int>::iterator, bool> ret;
	ret = myset.insert(3); // no new element inserted;
	if (ret.second == false)
		it = ret.first; // "it" now points to element 3

	myset.insert(it, 9); // myset: {1, 3, 7, 9,} O(log(n)) => O(1)
	                     // it points to 3
	myset.erase(it);     // myset: {1, 7, 9}
	myset.erase(7);      // myset: {1, 9}
	// Note: none of the sequence containers provide this kind of erase

	// multiset is a set that allows duplicated items;
	//multiset<int> myset;

	// set/multiset : value of the elements cannot be modified
	//*it = 10; *it is read-only(const)

	cout << "Now Map Test:" << endl;
	map<char, int> mymap;
	mymap.insert(pair<char, int>('a', 100));
	mymap.insert(pair<char, int>('z', 80));

	map<char, int>::iterator it2 = mymap.begin();
	mymap.insert(it2, pair<char, int>('b', 300)); //"it2" is a hint

	it2 = mymap.find('z'); //O(log(n))

	// showing contents：
	for (map<char, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << (*it).first << "=>" << (*it).second << endl;
	}

	multimap<char, int> mymultimap;
	//Map / Multimap:
	//--keys connot be modified
    //  type of *it : pair<const, int>
	// (*it).first = 'd'; //Error
}
*/



/************************************************************************************************************************************************************
Introduction of STL
#4_Unordered Container 
 *
 * Unordered set
 *
 * Properties of Unordered Containers:
 * 1. Fasteset search/insert at any place: O(1)
 *    Associative Containers takes O(log(n))
 *    Vector, Deque takes O(n)
 *    List takes O(1) to insert, O(n) to search
 * 2. Unordered set/multiset: element value cannot be changed.
 *    Unordered map/multimap: element key cannot be changed.
 *
 * Associative Array
 * - map and unordered map
 * 
 * Notes about Associative Array:
 * 1. Search time: unordered_map, O(1); map, O(log(n))
 * 2. Unordered_map may degrade to O(N)
 * 3. Can't use multimap and unordered_multimap, they don't have [] operator.
 */
/*
#include<unordered_set>
#include<unordered_map>
#include<string>
//#include"function.h"
int main()
{
	unordered_set<string> myset = { "red", "green", "blue" };
	unordered_set<string>::const_iterator itr = myset.find("green"); // O(1)
	if (itr != myset.end()) // Important check
	{
		cout << *itr << endl;
	}
	myset.insert("yellow");

	vector<string> vec = { "purple", "pink"};
	myset.insert(vec.begin(), vec.end());

	// Hash table specific APIs:
	cout << "load_factor = " << myset.load_factor() << endl;
	string x = "red";
	cout << x << " is in bucket #" << myset.bucket(x) << endl;
	cout << "Total bucket #" << myset.bucket_count() << endl;
	// unordered set
	// unordered multiset: unordered set that allows duplicated elements
	// unordered map: unordered set of pairs
	// unordered multimap: unordered map that allows duplicated keys

	// hash collision => performance degrade (哈希冲突导致性能下降)

	unordered_map<char, string>day = { {'S', "Sunday"}, {'M', "Monday"} };

	cout << day['S'] << endl;    // No range check
	cout << day.at('S') << endl; // Has range check

	vector<int> vec2 = { 1, 2, 3 };
	//vec[5] = 5; Compile Error

	day['W'] = "Wednesday"; // Inserting {'W', "Wednesday"}
	day.insert(make_pair('F', "Friday")); // Inserting {'F', "Friday"}

	day.insert(make_pair('M', "Monday")); // Fail to modify, it's an unordered_map
	day['M'] = "MONDAY";                  // Succeed to modify

	vector<int> vec3 = { 1, 2, 3, 4 };
	int* p = &vec3[2]; //p points to 3
	vec3.insert(vec3.begin(), 0);
	cout << *p << endl; //2, or ? 通常会报错
	//void foo(const unordered_map<char, string>& m); 调用出错
	//foo(day);
}
*/
/*
 * Container Adaptor
 *  - Provide a restricted interface to meet special needs
 *  - Implemented with fundamental container classes
 *
 *  1. stack:   LIFO, push(), pop(), top()
 *
 *  2. queue:   FIFO, push(), pop(), front(), back()
 *
 *  3. priority queue: first item always has the greatest priority  
 *                    push(), pop(), top()
 */
/*
 * Another way of categorizing containers:
 *
 * 1. Array based containers: vector, deque
 *
 * 2. Node based containers: list + associative containers + unordered containers
 *
 * Array based containers invalidates pointers:
 *    - Native pointers, iterators, references
 *
 *
 */
/* 该函数调用出错
void foo(const unordered_map<char, string>& m)
{
	// M['s'] == "SUNDAY"; ERROR
	// cout << m['M'] << endl;  ERROR 编译器认为尝试写入m
	auto itr = m.find('S');
	if (itr != m.end())
	{
		cout << *itr << endl;
	}
}
*/



/************************************************************************************************************************************************************
Introduction of STL
#5_Iterators and Algorithms
 *
 * Iterators
 *
*/
/*
// 1. Random Access Iterator: Vector, Deque, Array
vector<int> itr;
itr = itr + 5; // advance itr by 5
itr = itr - 4;
if (itr2 > itr1)...
++itr; //faster than itr++
--itr;

// 2. Bidirectional Iterator: List, Set/Multiset, Map/Multimap
list<int> itr;
++itr;
--itr;

// 3. Forward Iterator: Forward_list
forward_list<int> itr;
++itr;

// Unordered containers provide "at least" forward iterators.

// 4. Input Iterator: read and process value while iterator forward.
int x = *itr;

// 5. Output Iterator: output values while iteratoring forward.
*itr = 100;

// Every container has a iterator and a const_iterator
set<int>::iterator itr;
set<int>::const_iterator citr; // Read_only access to container elements

set<int> myset = { 2, 4, 5, 1, 9 };
for (citr = myset.begin(); citr != myset.end(); ++citr)
{
	cout << *citr << endl;
	//*citr = 3
}
for_each(myset.cbegin(), myset.cend(), MyFunction); // Only in c++ 11

//Iterator Functions:
advance(itr, 5);      // Move itr forward 5 spots. For random_access iterator, this is equivalent to itr += 5
distance(itr1, itr2); //Measure the distance between  itr1 and itr2
*/

/* Iterator Adaptor(Predefined Iterator
 *  - A special, more powerful iterator
 * 1. Insert iterator
 * 2. Stream iterator
 * 3. Reverse iterator
 * 4. Move iterator (C++ 11)
 *
*/
/*
#include<vector>
#include<iterator>
#include<algorithm>

// 1. Insert Iterator
struct print
{
	void operator () (int i)
	{
		cout << i << endl;
	}
};
int main()
{
	vector<int> vec1 = { 4, 5 };
	vector<int> vec2 = { 12, 14, 16, 18 };
	vector<int>::iterator it = find(vec2.begin(), vec2.end(), 16);
	insert_iterator< vector<int>> i_itr(vec2, it);
	copy(vec1.begin(), vec1.end(), i_itr);
	for_each(vec2.begin(), vec2.end(), print());
}
// Other insert iterators: back_insert_iterator, front_insert_iterator


// 2. Stream Iterator:
vector<string> vec4;
copy(istream_iterator<string>(cin), istream_iterator<string>(), back_inserter(vec4));
copy(vec4.begin(), vec4.end(), ostream_iterator<string>(cout, " "));

// Make it terse
unique_copy(istream_iterator<string>(cin), istream_iterator<string>(), ostream_iterator<string>(cout, " "));

// 3. Reverse Iterator:
vector<int> vec = {4, 5, 6, 7};
reverse_iterator<vector<int>:iterator> ritr;
for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
	cout << *ritr << endl; // Prints 7 6 5 4
*/


/*
 * Algorithms
 *  - mostly loops
 */
/*
#include<vector>
#include<iterator>
#include<algorithm>

int main()
{
	vector<int> vec = { 4, 2, 5, 1, 6, 3, 9 };
	vector<int>::iterator itr = min_element(vec.begin(), vec.end());
	cout << *itr << endl;

	// Note 1: Algorithms always process ranges in half-open way: [begin, end)
	sort(vec.begin(), itr); // vec: {2, 4, 5, 1, 6, 3, 9}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) 
		cout << *itr << " ";
	cout << endl;
	reverse(itr, vec.end());// vec: {2, 4, 5, 9, 3, 6, 1}
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	cout << *itr << endl;// itr => 9

	//Note 2: 
	vector<int> vec2(4);
	copy(itr, vec.end(), // Source
		vec2.begin());    // Destination 
		// vec2 needs to have at least space for 4 elements.
	for (vector<int>::iterator itr = vec2.begin(); itr != vec2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// Note 3:
	vector<int> vec3;
	copy(itr, vec.end(), back_inserter(vec3)); // Inserting instead of overwriting
		              // back_insert_iterator     Not efficient ( insert 1 item at a time)
	for (vector<int>::iterator itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	vec3.insert(vec3.end(), itr, vec.end());   // Efficient and safe
	for (vector<int>::iterator itr = vec3.begin(); itr != vec3.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	// Note 4: Algorithm with function
	bool isOdd(int i);
	vector<int> vec5 = { 2, 4, 5, 6, 8, 9, 2 };
	vector<int>::iterator itr5 = find_if(vec5.begin(), vec5.end(), isOdd);
	cout << *itr5 << " ";
	cout << endl;

	// Note 5: Algorithm with native C++ array
	int arr[4] = { 6, 3, 7, 4 };
	sort(arr, arr + 4);
	for (int i = 0; i < 4; ++i)
		cout << arr[i];
}
bool isOdd(int i)
{
	return i % 2;
}
*/



/************************************************************************************************************************************************************
Introduction of STL
#6_Functors
 *Function Objects (funtors)
 *
 * Benefits of functor:
 * 1. Smart function: capabilities beyond operator()
 *    It can remember state.
 * 2. It can have its own type.
 * Example:
 */
/*
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<iterator>
#include<algorithm>
#include<functional>
#include<math.h>
#include<deque>
using namespace std;

//
// Parameterized Function
//

class Y
{
public:
	Y(int i) {}
	void operator() (string str)
	{
		cout << "Calling functor Y with parameter " << str << endl;
	}
};
class X
{
public:
	void operator() (string str)
	{
		cout << "Calling functor X with parameter " << str << endl;
	}
};
*/
//
/* Build-in Functors
 * less greater greater_equal less_equal not_equal_to 
 * logical_and logical_not logical_or multiplies minus plus divide negate
 */
/*
double Pow(double x, double y)
{
	return pow(x, y);
}

bool needCopy(int x)
{
	return (x > 20) || (x < 5);
}
*/

/*
* Predicate
*
* A functor or function that:
* 1. Returns a boolean
* 2. Does not modify data
*/

/*
class NeedCopy
{
	bool operator()(int x)
	{
		return (x > 20) || (x < 5);
	}
};

transform(myset.begin(), myset.end(),
	back_inserter(d),
	NeedCopy()
);

// Predicate is used for comparison or condition check
*/
/*
int main()
{
	int x = multiplies<int>()(3, 4); // x = 3 * 4;
	if (!equal_to<int>()(x, 10))
		cout << x << endl;
	X foo;
	foo("Hi"); // Calling functor X with parameter Hi
	Y(8)("Hi");
	//
	// Parameter Binding
	//
	set<int> myset = { 2, 3, 4, 5 };
	vector<int> vec;

	//int x = multiplies<int>()(3, 4); // x = 3 * 4

	// Multiply myset's elemetns by 10 and save in vec:
	transform(myset.begin(), myset.end(), // Source
		back_inserter(vec), // Destination
		bind(multiplies<int>(), placeholders::_1, 10));// Functor
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	// vec: {20, 30, 40, 50}
	// First parameter of multiplies<int>() is substituded with myset's element

	//Convert a regular function to a functor

	set<int> myset2 = { 3, 1, 25, 7, 12 };
	deque<int> d;
	auto f = function<double(double, double)>(Pow);
	transform(myset2.begin(), myset2.end(), // Source
		back_inserter(d), // Destination
		bind(f, placeholders::_1, 2)); //functor
	// d: {1, 9, 49, 144, 625
	for (deque<int>::iterator itr = d.begin(); itr != d.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	set<int> myset3 = { 3, 1, 25, 7, 12 };
	// when (x > 20) || (x < 5),
	deque<int> d2;
	transform(myset3.begin(), myset3.end(), // Source
		back_inserter(d2), // Destination
		bind(logical_or<bool>(),//原文是logical_or<bool>,没有圆括号，会报错
			bind(greater<int>(), placeholders::_1, 20),
			bind(less<int>(), placeholders::_1, 5))
		); //functor
	for (deque<int>::iterator itr = d2.begin(); itr != d2.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	deque<int> d3;
	transform(myset3.begin(), myset3.end(), // Source
		back_inserter(d3), // Destination
		needCopy); //functor
	for (deque<int>::iterator itr = d3.begin(); itr != d3.end(); ++itr)
		cout << *itr << " ";
	cout << endl;

	//c++ 11 lambda function:
	deque<int> d4;
	transform(myset3.begin(), myset3.end(),
		back_inserter(d4),
		[](int x) {return (x > 20) || (x < 5); }
	);
	for (deque<int>::iterator itr = d4.begin(); itr != d4.end(); ++itr)
		cout << *itr << " ";
	cout << endl;
	
}
*/
/*
 * Why do we need functor in STL
 */
/*
set<int> myset = { 3, 1, 25, 7, 12 }; //myset: {1, 3, 7, 12, 25}
// same as:
set<int, less<int>> myset = { 3, 1, 25, 7, 12 }; 

bool lsb_less(int x, int y) // a function doesn't complie ,we need a functor
{
	return (x % 10) < (y % 10);
}

class Lsb_Less // this is a functor
{
public:
	bool operator() (int x, int y)
	{
		return (x % 10) < (y % 10);
	}
};
int main()
{
	set<int, Lsb_Less> myset = { 3, 1, 25, 7, 12 }; // myset: {1, 12, 3, 25, 7}
}
*/



