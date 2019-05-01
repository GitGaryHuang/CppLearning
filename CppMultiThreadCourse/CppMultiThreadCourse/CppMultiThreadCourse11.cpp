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

////atomic<int> g_mycount = 0;
////atomic<bool> g_ifend = false;
////
////void mythread()
////{
////	for (int i = 0; i < 1000000; i++)
////	{
////		g_mycount++;
////		//g_mycount = g_mycount + 1; 结果不对
////	}
////	return;
////}
//
////int mythread()
////{
////	cout << "mythread start ! Thread ID" << this_thread::get_id() << endl;
////	return 1;
////}
//
//int mythread()
//{
//		cout << "mythread start thread id : " << this_thread::get_id() << endl;//打印新线程id值
//		chrono::milliseconds dura(500);//休息5秒
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id : " << this_thread::get_id() << endl;
//		return 5;
//}
//
//int main()
//{
//	//一、原子操作std::atomic续谈
//	//一般原子操作符，针对+= ++ -- _= &=等操作符是支持的，其他可能不支持。
//
//	//二、std::async深入谈
//	//(2.1)std::async参数详述。
//	//std::launch::deferred 延迟调用   std::launch::async 强制创建线程
//	//std::thread()若系统资源紧张，可能创建失败，那么执行std::thread()时整个程序可能崩溃
//	//std::async()我们一般不叫创建线程而是叫创建异步任务
//	//std::async()与std::thread()最直接的区别是，std::async()并不总是创建新线程。
//	//a)若用std::launch::deferred来调用async会怎样：deferred延迟调用，并不创建新线程，延迟到future对象调用wait()或get()，若没调用wait()或get()，线程入口函数不会被调用。
//	//b)std::launch::async强制异步任务在新线程上执行，即必须在新线程上运行线程入口函数。
//	//c)std::launch::async | std::launch::deferred，两者同时用，看似与async相同，实际不同。“|”意味着可能是async，也可能是deferred，根据
//	//D)不带参数，只给async函数一个函数入口名，为默认值即(std::launch::async | std::launch::deferred) ，与C一致。
//		//即系统自行决定，
//	//(2.2)std::async与std::thread的区别
//	//std::thread创建线程，若系统资源紧张，创建线程失败，程序会报异常出错崩溃
//	//std::thread创建线程的方式，如果线程返回值，难以拿到这个值
//	//std::async可能创建线程也可能不创建线程
//	//std::async很容易拿到线程入口函数的返回值
//	//由于系统资源限制：
//	//(1)如果std::thread创建的线程太多，则可能创建失败，崩溃
//	//(2)std::async一般不会报错崩溃或异常，因为若资源紧张，默认调用会自动选择。
//		//若要求async一定要创建新线程，则程序可能会崩溃
//	//(3)一个程序里，线程数量不超过100-200
//	//(2.3)std::async不确定性问题的解决。
//	//不加额外参数，让系统自行决定是否创建新线程
//	//问题焦点在于这种写法，异步任务是否被推迟进行
//	
//	//thread mytobj1(mythread);
//	//thread mytobj2(mythread);
//
//	//mytobj1.join();
//	//mytobj2.join();
//
//	//cout << "g_mycount : " << g_mycount << endl;
//
//
//	//cout << "Main start ! Thread ID" << this_thread::get_id() << endl;
//	//future<int> result = async(launch::async, mythread);//deferred延迟调用，并不创建新线程，延迟到future对象调用wait()或get()，若没调用wait()或get()，则mythread不会被调用。
//	//cout << result.get();
//
//		//枚举类型
//	future<int> result = async(mythread);
//	future_status status = result.wait_for(chrono::seconds(0));// 等待1秒
//	if (status == future_status::deferred)
//	{
//		//表示线程被延迟执行
//		cout << "deferred" << endl;
//		cout << result.get() << endl;
//	}
//	else if (status == future_status::ready)
//	{
//		//线程未被延迟执行。
//		cout << "ready" << endl;
//		cout << result.get() << endl;
//	}
//	else if (status == future_status::timeout)
//	{
//		cout << "timeout" << endl;
//		cout << result.get() << endl;
//	}
//	return 0;
//}