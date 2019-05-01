#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>

#include<thread>
using namespace std;
//
//void myprint(const int &i, char *pmybuf)
//{
//	cout << i << endl; //分析认为，此处i并非主线程中的mvar引用，实际是值传递，但即便主线程detach了子线程，那么子线程的i值仍然是安全的。
//	cout << pmybuf << endl;//指针在detach子线程时绝对会有问题
//	return;
//}

//class A
//{
//public :
//	int m_i;
//	//类型转换构造函数（因为这个类只有一个参数）
//	A(int a) : m_i(a) { cout << "[A::A(int a)构造函数执行]" << this << "  thread id = " << this_thread::get_id() << endl; }
//	A(const A &a) : m_i(a.m_i) { cout << "[A::A(const A& a)拷贝构造函数执行]" << this << "  thread id = " << this_thread::get_id() << endl; }
//	~A() { cout << "[A::~A()析构函数执行]" << this << "  thread id = " << this_thread::get_id() << endl; }  
//
//	void thread_work(int num)
//	{
//		;
//	}
//	void operator()(int num)
//	{
//		cout << "  thread id = " << this_thread::get_id() << endl;
//	}
//};
//
////void myprint(const int i, const string &pmybuf)
////{
////	cout << i << endl;
////	cout << pmybuf.c_str() << endl;
////	return;
////}
//
////void myprint(const int i, const A& pmybuf)
////{
////	cout << &pmybuf << endl;
////	return;
////}
//
////void myprint2(const A& pmybuf) //虽然用引用，但实际是拷贝构造了一个类对象，除非使用ref
////{
////	pmybuf.m_i = 199; //修改该值不会影响main函数
////	cout << "子线程2的参数地址是：" << &pmybuf << "  thread id = " << this_thread::get_id() << endl;
////}
//
//void myprint3(unique_ptr<int> pzn) //虽然用引用，但实际是拷贝构造了一个类对象，除非使用ref
//{
//	;
//}
//
//int main()
//{
//	//一：传递临时对象作为线程参数
//	//(1.1)要避免的仙境（解释1）
//	//(1.2)要避免的仙境（解释2）
//	//事实1：只要用临时构造的A类对象作为参数传递给线程，那么在一定能在主线程执行完毕前，把线程函数的第二个参数构造出来，从而确保即便detach了，子线程也能安全运行。
//	//(1.3)总结：
//	//a)若传递int这种简单类型，建议都是值传递，不要用引用，防止节外生枝（detach中）。
//	//b)如果传递类对象，避免隐式类型转换。全部都在创建线程这一行中构建出临时对象，然后在函数参数里，用引用来接受，否则系统还会构造出一次对象
//	//终极结论：
//	//c)建议不使用detach() 只是用join(),这样就不存在局部变量失效，导致线程对内存的非法引用问题
//	
//	//二、临时对象作为线程参数继续讲。
//	//(2.1)线程id概念：id是个数字，每个线程（不管是主线程还是子线程）实际上都对应着一个数字。
//		//也就是说不同线程对应的ID（数字）是不同的
//		//线程id可以用c++标准库里的函数来获取。
//	//(2.2)临时对象构造时机抓捕
//
//	//三、传递类对象、智能指针为线程参数
//	//std::ref函数
//
//	//四、用成员函数指针做线程参数
//	//int mvar = 1;
//	//int &myvary = mvar;
//	//char mybuf[] = "this is a test!";
//
//	//thread mytobj(myprint, mvar, mybuf);//mybuf什么时候被转成string
//	//									//事实上存在当mybuf被回收后，系统才试图将mybuf转成string
//	////mytobj.join();
//	//thread mytobj(myprint, mvar, string(mybuf)); //在这里先将mybuf转为string临时对象，可以保证在一个线程里用肯定有效
//
//	/*int mvar = 1;
//	int mysecondpar = 12;*/
//	//thread mytobj(myprint, mvar, mysecondpar); //我们希望mysecondpar转成A类型对象传递给myprint的第二个参数
//	//thread mytobj(myprint2, A(mysecondpar)); //在创建线程的同时构造临时对象的方法传递参数是可行的 （thread构造函数将带引用的全部整成复制构造）
//	//mytobj.join();
//	//mytobj.join(); //子线程与主线程分别执行
//
//	cout << "主线程ID：" << this_thread::get_id() << endl;
//	//int mvar = 1;
//	//thread mytobj(myprint2, A(mvar));//用了临时对象后，所有的A类对象都在main()函数中已经构建完毕了，否则会到子线程中构建
//	//mytobj.detach();
//	//cout << "I LOVE CHINA!" << endl;
//
//	//A myobj(10); //生成一个类对象
//	//thread mytobj(myprint2, ref(myobj));
//	//mytobj.join();
//	//unique_ptr<int> myp(new int(100));
//	//thread mytobj(myprint3, move(myp));
//	//A myobj(10);
//	//thread mytobj(&A::thread_work, myobj, 15);
//	//mytobj.join();
//	A myobj(10);
//	thread mytobj(ref(myobj), 15);
//	mytobj.join();
//	//while (1)
//	//{
//	//	;
//	//}
//	return 0;
//}