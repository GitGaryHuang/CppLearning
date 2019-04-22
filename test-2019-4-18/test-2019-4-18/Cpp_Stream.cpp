#include<iostream>
#include<fstream>
#include<bitset>
#include<complex>
#include<iomanip>
using namespace std;


struct Dog
{
	int age_;
	string name_;
};

ostream& operator<<(ostream& sm, const Dog& d)
{
	sm << "My name is " << d.name_ << " and my age is " << d.age_ << endl;
	return sm;
}

istream& operator >> (istream& sm, Dog& d)
{
	sm >> d.age_;
	sm >> d.name_;
	return sm;
}
//2019-04-21
/**********************************************************************************************************************************************************
C++ Stream

*/
int main()
{
/*
1#_Introductory	

	// C++ Input/Output Library -- Stream
	cout << "Hello" << endl;
	// cout: a global object of ostream ( typedef basic_ostream<char> ostream )
	// <<: ostream& ostream::operator<< (string v);
	// endl: '\n' + flush

	// What is stream? Serial IO Interface to external devices (file, stdin/stdout, network, etc.)
	string s("Hello");
	s[3] = 't'; // Random access
	//cout[3] = 't'; // ERROR

	{
		ofstream of("MyLog.txt"); // Creates a new file for write, if the file didn't exsit //#include<fstream>
		of << "Experience is the mother of wisdom" << endl;
		of << 234 << endl;
		of << 2.3 << endl;

		of << bitset<8>(14) << endl; // 00001110 //#include<bitset>
		of << complex<int>(2, 3) << endl; //  (2,3) //#include<complex>
	} // RAII 技术 ，即将代码写在｛｝内，就不需要打开和关闭文件。 

	// IO Operation: (2 steps)
	// formatting the data <-----> communicating the data with external devices;

	// Software Engineer Principle: Low Coupling -> Reusability 低耦合 
	*/

/**********************************************************************************************************************************************************
2#_File Stream and Error Handling

	{
		//ofstream of("MyLog.txt"); // Open file for write, clear the content of the file
		ofstream of("MyLog.txt", ofstream::app); // Move the output pointer to the end of the file
		of << "Honesty is the best policy." << endl;
	}
	{
		ofstream of("MyLog.txt", ofstream::in | ofstream::out);
		of.seekp(10, ios::beg); // Move the output pointer 10 chars after begin
		of << "12345"; // Overwrite 5 chars
		of.seekp(-5, ios::end); // Move the output pointer 5 chars before end
		of << "Nothing ventured, nothing gained." << endl;
		of.seekp(-5, ios::cur); // Move the output pointer 5 chars before current position
	}

	ifstream inf("MyLog.txt");
	int i;
	inf >> i; // read one word
	// Error status: goodbit, badbit, failbit, eofbit
	inf.good(); // Everything is OK (goodbit == 1)
	inf.bad();  // Non-recoverable error (badbit == 1)
	inf.fail(); // Failed stream operation. (failbit == 1, badbit == 1)
	inf.eof();  // End of file (eofbit ==1)

	inf.clear(); // Clear all the error status   clear(ios::goodbit)
	inf.clear(ios::badbit); // sets a new value to the error flag

	inf.rdstate(); // Read the current status flag
	inf.clear(inf.rdstate() & ~ios::failbit); // Clear only the failbit

	if (inf) // Equivalent to if (!inf.fail())
		cout << "Read successfully";
	if (inf >> i)
		cout << "Read successfully";

	// Handle the errors with exceptions
	inf.exceptions(ios::badbit | ios::failbit); // Setting the exception mask
	// When badbit or failbit set to 1, exception of ios::failure will be thrown
	// when eofbit set to 1, no exception
	inf.exceptions(ios::goodbit); // No execption

	*/
/**********************************************************************************************************************************************************
3#_Formatted and Uniformatted IO

	// Formatting
	cout << 34 << endl; //34
	cout.setf(ios::oct, ios::basefield);
	cout << 34 << endl;; // 42
	cout.setf(ios::showbase);
	cout << 34 << endl;; //042
	cout.setf(ios::hex, ios::basefield);
	cout << 34 << endl;; // 0x22

	cout.unsetf(ios::showbase);
	cout << 34 << endl;; // 22

	cout.setf(ios::dec, ios::basefield);
	cout.width(10);
	cout << 26 << endl; //           26
	cout.setf(ios::left, ios::adjustfield); // 26

	// Floating point value
	cout.setf(ios::scientific, ios::floatfield);
	cout << 340.1 << endl; // 3.401000e+002
	cout.setf(ios::fixed, ios::floatfield);
	cout << 340.1 << endl;
	cout.precision(3);
	cout << 340.1 << endl; // 340.100

	int i;
	cin.setf(ios::hex, ios::basefield);
	cin >> i; //Enter
	cout << i << endl;

	ios::fmtflags f = cout.flags();
	cout << f << endl;
	cout.flags(ios::oct | ios::showbase);

	// Member functions for unformatted IO
	// input
	ifstream inf("MyLog.txt");
	char buf[80];
	inf.get(buf, 80); // read up to 80 chars and save into buf
	inf.getline(buf, 80); // read up to 80 chars or until '\n'
	inf.read(buf, 20); // read 20 chars
	inf.ignore(3);
	inf.peek();
	inf.unget(); // return a char back to the stream
	inf.get();
	inf.gcount(); // return the number of chars being read by last unformatted read

	// output
	ofstream of("MyLog.txt");
	of.put('c');
	of.write(buf, 6); // write first 6 chars of buf into the stream
	of.flush();
	*/
/**********************************************************************************************************************************************************
4#_Manipulators
*/
	/*
	ostream& endl(ostream& sm) // Manipulator
	{
		sm.put('\n');
		sm.flush();
		return sm;
	}
	*/
	/*
	ostream& ostream::operator<<(ostream& (*func)(ostream&))
	{
	return (*func)(*this);
	}*/
/*
	cout << "Hello" << endl; // endl: '\n' and flush
	// Object? Build-in data type? function? 
	cout << ends; // '\0'
	cout << flush;
	cin >> ws; // read and discard white spaces

	cout << setw(8) << left << setfill('_') << 99 << endl;
	cout << hex << showbase << 14; // 0xe
*/
/**********************************************************************************************************************************************************
#5_Stream Buffer

	// IO operation:
	// formatting data -- stream
	// communicating data to external devices -- stream buffer
	cout << 34; 
	streambuf* pbuf = cout.rdbuf();

	ostream myCout(pbuf);
	myCout << 34; // 34 to stdout

	myCout.setf(ios::showpos);
	myCout.width(20);
	myCout << 12 << endl; //          +12
	cout << 12 << endl; //12

	ofstream of("MyLog.txt");
	streambuf* origBuf = cout.rdbuf();
	cout.rdbuf(of.rdbuf());
	cout << "Hello" << endl; // MyLog.txt has "Hello"
	// Redirecting

	cout.rdbuf(origBuf);

	cout << "Goodbye" << endl; // stdout: Goodbye

	// Stream Buffer Iterator
	istreambuf_iterator<char> i(cin);
	ostreambuf_iterator<char> o(cout);
	while (*i != 'x')
	{
		*o = *i;
		++o;
		++i;
	}
	copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
*/
/**********************************************************************************************************************************************************
#6_String Stream

	// String stream
	stringstream ss; // Stream without IO operation
	// read/write of string 
	ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89;
	cout << ss.str() << endl;  // 89  Hex: 59 Oct: 131

	int a, b, c;
	string s1;

	ss >> hex >> a; // Formatted input works token by token. spaces, tabs, newlines
	cout << a << endl; // a ==137
	ss >> s1; // s1: "Hex:"
	cout << s1 << endl;
	ss >> dec >> b; // b == 59
	cout << b << endl;
	
	ss.ignore(6);

	ss >> oct >> c;// c == 89 1*64+3*8+1

	// ostringstream -- formatted output
	// istringstream -- formatted input
*/
/**********************************************************************************************************************************************************
#7_Enable Streaming for Your Own Class
*/
	// Creating Stream-enabled Class
	Dog d{ 2, "Bob" }; // Universal Initialization
	cout << d;

	cin >> d;
	cout << d;
}
