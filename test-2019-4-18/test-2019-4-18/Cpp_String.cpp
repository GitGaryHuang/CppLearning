#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//2019-04-20
/**********************************************************************************************************************************************************

int main()
{

	/*C++ String
	#1_Constructor and Size
	*/
	/*
	// Constructors
	string s1("Hello");
	cout << s1.size() << " " << s1.capacity() << endl;

	string s2("Hello", 3);
	string s3(s1, 2); // s3:llo
	string s4(s1, 2, 2); // s4:ll
	string s5(5, 'a'); // s5: "aaaaa"
	string s6({ 'a', 'b', 'c' }); // s6: "abc"

	// Size
	s1 = "Goodbye";
	s1.size(); 
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.length(); // Synonymous, both returns 7 
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.capacity(); // size of storage space currently allocated to s1
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.reserve(100); // 100 chars because 100 > 7
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.reserve(5); // s1: Goodbye s1.size() == 7 because 5 < 7 
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.shrink_to_fit(); // shrink the capacity to hold the content
	cout << s1.size() << " " << s1.capacity() << endl;

	s1.resize(9); // s1: Goodbye\0\0 
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.resize(12, 'x'); // s1: Goodbye\0\0xxx  
	cout << s1.size() << " " << s1.capacity() << endl;
	s1.resize(3); // s1: Goo
	cout << s1.size() << " " << s1.capacity() << endl;
	*/

/**********************************************************************************************************************************************************
C++ String
#2_Accessing String Characters
 */
	/*
	// String 

	// Single Element Access
	string s1 = "Goodbye";
	s1[2]; // 'o'
	s1[2] = 'x'; // Goxdbye
	s1.at(2) = 'y'; // Goydbye
	s1.at(20); // throw exception of out_of_range
	s1[20]; // undefined behavior

	s1.front(); // 'G'
	s1.back(); // 'e'
	s1.push_back('z'); 
	s1.pop_back();
	s1.begin(); // iterator at the beginning of s1
	s1.end(); // ... end ...
	// Like vector, string doesn't have push_front() and pop_front()

	string s3(s1.begin(), s1.begin() + 3); // s3: Goo
	
	// Ranged Access
	// assign, append, insert, replace
	string s2 = "Dragon Land";
	string s1;
	s1.assign(s2); // s1 =s2
	cout << s1 << endl;
	s1.assign(s2, 2, 4); // s1: agon
	cout << s1 << endl;
	s1.assign("Wisdom"); // s1: Wisdom
	cout << s1 << endl;
	s1.assign("Wisdom", 3); // s1: Wis
	cout << s1 << endl;
	//s1.assign(s1, 3); // Error
	s1.assign(3, 'x'); // s1: "xxx";
	cout << s1 << endl;
	s1.assign({ 'a', 'b', 'c' }); // s1:abc
	cout << s1 << endl;
	
	s1.append(" def"); // s1: abc def
	cout << s1 << endl;
	s1.insert(2, "mountain", 4); // s1 abmounc def
	cout << s1 << endl;
	s1.replace(2, 5, s2, 3, 3); // abgon def
	cout << s1 << endl;

	s1.erase(1, 4); // s1: a def
	cout << s1 << endl;
	s2.substr(2, 4); // agon

	s1 = "abc";
	s1.c_str(); // "abc\0"
	s1.data(); // "abc"

	s1.swap(s2);
	cout << s1 << endl;
	*/

/**********************************************************************************************************************************************************
C++ String
#3_Member Function Algorithms

	// Member Function Algorithms: copy, find, compare
	string s1 = "abcdefg";
	string s2 = "abcefgh";
	char buf[10];
	size_t len = s1.copy(buf, 3); // buf: abc  len == 3
	cout << len << " " << buf << endl;
	len = s1.copy(buf, 4, 2);     // buf: cdef  len == 4 
	cout << len << " " << buf << endl;

	s1 = "If a job is worth doing, it's worth doing well";
	size_t found = s1.find("doing"); // found == 18
	cout << found << endl;
	found = s1.find("doing", 20); // found == 36
	cout << found << endl;
	found = s1.find("doing well", 0); // found ==36
	cout << found << endl;
	found = s1.find("doing well", 0, 5); // found == 18 , third parameter means only match the first 5 characters 
	cout << found << endl;

	found = s1.find_first_of("doing"); // found == 6 找到s1中的第一个doing中所包含的字符，此处为o
	cout << found << endl;
	found = s1.find_first_of("doing", 10); // found == 13 
	cout << found << endl;
	found = s1.find_first_of("doing", 10, 1); // found == 18 
	cout << found << endl;

	found = s1.find_last_of("doing"); // found == 40
	cout << found << endl;
	found = s1.find_first_not_of("doing"); // found == 0
	cout << found << endl;
	found = s1.find_last_not_of("doing"); // found == 45
	cout << found << endl;

	s1.compare(s2); // return postive if (s1 > s2); negative if (s1 < s2); 0 if (s1 = s2)
	cout << s1.compare(s2) << endl;
	if (s1 > s2) {} // equivalent to if(s1.compare(s2) > 0)
	s1.compare(3, 2, s2);
	cout << s1.compare(s2) << endl;

	string ss = s1 + s2; // 
	cout << ss << endl;
	*/

/**********************************************************************************************************************************************************
C++ String
#4_Non-Member Function


	string s1 = "abcdefg";
	string s2 = "abcefgh";
	cout << s1 << endl;
	//cin >> s1;
	//getline(cin, s1);// default delimeter of "\n"
	cout << s1 << endl; 
	//getline(cin, s1, ';'); // delimeter is ';'
	
	s1 = to_string(8);
	cout << s1 << endl;
	s1 = to_string(2.3e7); // s1: 23000000.000000
	cout << s1 << endl;
	s1 = to_string(0xa4); // s1: 164
	cout << s1 << endl;
	s1 = to_string(034); // s1: 28
	cout << s1 << endl;

	// convert a string into a number
	s1 = "190";
	int i = stoi(s1); // i: 190
	cout << i << endl;
	s1 = "190 monkeys";
	size_t pos;
	i = stoi(s1, &pos); // i : 190 pos == 3
	cout << i << endl;
	s1 = "a monkey";
	i = stoi(s1, &pos); // exception of invalid_argument
	i = stoi(s1, &pos, 16); // i == 10

	// stol, stod, stof, etc

	// stringstream

	// lexical_cast()
*/


/**********************************************************************************************************************************************************
C++ String
#5_String and Algorithms

	// <string>
	// String and Algorithms

	string s1 = "Variety is the spice of life.";
	string s2 = "Variety is the ispce of lif.e";
	int num = count(s1.begin(), s1.end(), 'e'); // 4
	cout << num << endl;
	num = count_if(s1.begin(), s1.end(), [](char c) { return c <= 'e' && c >= 'a'; }); // 6
	cout << num << endl;

	s1 = "Goodness is better than beauty.";
	string::iterator itr = search_n(s1.begin(), s1.begin() + 20, 2, 's'); // itr -> first 's'
	cout << *itr << endl;
	s1.erase(itr, itr + 5);
	cout << s1 << endl;
	s1.insert(itr, 3, 'x'); // last time we use integer parameter , this time we use iterator parameter
	cout << s1 << endl;
	s1.replace(itr, itr + 3, 3, 'y'); // replacing substring
	cout << s1 << endl;

	s1 = "Variety is the spice of life.";
	is_permutation(s1.begin(), s1.end(), s2.begin()); // permutation n. 排列 组合 ，即s2是否是s1的字符重新排列组合而成的
	cout << is_permutation(s1.begin(), s1.end(), s2.begin()) << endl;
	replace(s1.begin(), s1.end(), 'e', ' '); // replacing characters
	cout << s1 << endl;

	transform(s1.begin(), s1.end(), s2.begin(),
		[](char c)
	{
		if (c < 'n')
			return 'a';
		else
			return 'z';
	});
	cout << s1 << endl << s2 << endl;

	s1 = "abcdefg";
	rotate(s1.begin(), s1.begin() + 3, s1.end()); // s1: defgabc
	cout << s1 << endl;

	string s;
	u16string s8; // string char16_t
	u32string s9;  // string char32_t
	wstring s0; // string wchar_t (wide character)
	//to_wstring();

} 
*/