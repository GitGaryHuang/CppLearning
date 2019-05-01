#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<mutex>
#include<thread>
#include<future>
using namespace std;
//
////int mythread(int mypar)
////{
////		cout << "mythread start thread id : " << this_thread::get_id() << endl;//打印新线程id值
////		chrono::milliseconds dura(500);//休息5秒
////		this_thread::sleep_for(dura);
////		cout << "mythread end . thread id : " << this_thread::get_id() << endl;
////		return 5;
////}
////
//////void mythread2(future<int> &tmpf)
////void mythread2(shared_future<int> &tmpf)
////{
////	cout << "My thread2 start thread id = " << this_thread::get_id() << endl;
////	auto result = tmpf.get();//std::future::get()函数是一个移动语义，因此只能调用一次
////	cout << "My thread2 result = " << result << endl;
////	return;
////}
//
////int g_mycount = 0;//定义一个全局量
//atomic<int> g_mycount = 0;//封装了一个类型为int的对象(值）可以像操作一个int类型一样用
////mutex g_my_mutex;
////void mythread()
////{
////	for (int i = 0; i < 1000000; i++)
////	{
////		//g_my_mutex.lock();
////		g_mycount++;
////		//g_my_mutex.unlock();
////	}
////	return;
////}
//atomic<bool> g_ifend = false; //原子操作，防止同时写。
//
//void mythread()
//{
//	chrono::milliseconds dura(1000);
//
//	while (!g_ifend)
//	{
//		cout << "thread id ： " << this_thread::get_id() << "executing..." << endl;
//		this_thread::sleep_for(dura);
//	}
//	cout << "thread id ： " << this_thread::get_id() << "end..." << endl;
//}
//int main()
//{
//	//一、std::future的其他成员函数。
//	//二、std::shared_future：类模板，get()函数复制数据。
//
//
//
//
//
//
//
//	cout << "main thread id : " << this_thread::get_id() << endl;
//
//	//future<int> result = async(launch::deferred, mythread);
//	//cout << "continue....!" << endl;
//	////cout << result.get() << endl; 
//
//
//	////枚举类型
//	//future_status status = result.wait_for(chrono::milliseconds(3000));// 等待1秒
//	//if (status == future_status::timeout)
//	//{
//	//	//表示线程未执行完
//	//	cout << "timeout" << endl;
//	//}
//	//else if (status == future_status::ready)
//	//{
//	//	cout << "ready" << endl;
//	//}
//	//else if (status == future_status::deferred)
//	//{
//	//	cout << "deferred" << endl;
//	//	cout << result.get() << endl;
//	//}
//
////	packaged_task<int(int)> mypt(mythread);//我们把函数mythread()通过packaged_task包装起来
////	thread tl(ref(mypt), 1);//线程直接开始执行，第二个参数为线程入口函数的参数。
////	tl.join();
////	//future<int> result = mypt.get_future();//std::future里包含有线程入口函数的返回结果，这里result保存mythread的返回值
////	shared_future<int> result_s = mypt.get_future();
////	//bool ifcanget = result.valid();
////	//if (ifcanget)
////	//	cout << "*****" << endl;
////
////	//shared_future<int> result2 = (move(result));//或shared_future<int> result2 = (result.share());
////	//shared_future<int> result2 = (result.share()); //执行完毕后result为空 result2有值
////	//ifcanget = result.valid();
////	//if (ifcanget)
////	//	cout << "*****" << endl;
////	
////	thread t2(mythread2, ref(result_s));
//////	cout << result.get() << endl;
////	t2.join();
////	cout << "I LOVE CHINA! " << endl;
////	return 0;
//
//	//三、原子操作std::atomoic
//	//(3.1)原子操作概念引出范例
//		//互斥量：多线程编程中保护共享数据：锁、操作共享数据、开锁
//		//有两个线程，对一个变量进行操作，一个线程读，另一个线程写
//		//
//	//int atomvalue = 5; //atomvalue代表的是多线程间的共享变量
//	////读线程A
//	//int tmpvalue = atomvalue; 
//	////写线程B
//	//atomvalue = 6;
//
//	//把原子操作理解成一种不需要互斥量（无锁）的多线程并发方式
//	//或者说原子操作是在多线程中不会被打断的程序片段。
//	//互斥量的加锁一般针对一个代码段，原子操作一般针对变量。
//	//效率上比互斥量更好
//	//原子操作一般指不可分割的操作。原子操作不存在中间状态
//	//std::atomic代表原子操作，是类模板，用来封装某个类型的值
//	//(3.2)基本的std::atomic()用法范例。
//	//(3.3)心得：原子操作只能处理变量的增减。一般用于统计（累计收发多少数据包）
//	//对吃不准的代码 不要写 尤其是商业中。
//	thread mytobj1(mythread);
//	thread mytobj2(mythread);
//
//	chrono::milliseconds dura(5000);
//	this_thread::sleep_for(dura);
//
//	g_ifend = true;
//
//	mytobj1.join();
//	mytobj2.join();
//
//	cout << "END" << endl;
//	cout << "g_mycount : " << g_mycount << endl;
//	return 0;
//};