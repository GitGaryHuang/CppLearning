#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>

#include<thread>
using namespace std; 

//vector<int> g_v = { 1, 2, 3 };
////线程入口函数
//void myprint(int num)
//{
//	//cout << "myprint开始执行,线程编号: " << num << endl;
//	////...
//	//cout << "myprint执行完毕,线程编号: " << num << endl;
//	cout << "Thread ID: " << this_thread::get_id() << "打印g_v" << g_v[0] << g_v[1] << g_v[2] << endl;
//}
//class A
//{
//	//把收到的玩家消息入到一个队列的线程。
//public:
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << i << " " << endl;
//			msgRecvQueue.push_back(i); //假设数字即收到的命令。
//		}
//	}
//	void outMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			if (!msgRecvQueue.empty())
//			{
//				int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//				msgRecvQueue.pop_front();//移除第一个元素但不返回。
//				//处理数据。
//			}
//			else
//			{
//				cout << "outMsgRecvQueue执行，但队列为空" << i << endl;
//			}
//		}
//		cout << "end" << endl;
//	}
//private:
//	list<int> msgRecvQueue;//容器（消息队列），专门用于代表玩家发送过来的命令。
//};

//int main()
//{
	//一、创建和等待多个线程
	//vector<thread> mythreads;
	//创建10个线程，线程入口函数统一为myprint
	//a):多个线程的执行顺序是乱的，跟操作系统内部对线程的运行调度机制有关
	//b):主线程等待所有子线程运行结束，最后主线程结束，推荐使用join()，能写出更稳定的程序。
	//c):把thread对象放入容器中管理，看起来像一个thread对象数组，这对我们一次创建大量线程并进行管理很方便。
	//for (int i = 1; i <= 10; i++)
	//{
	//	mythreads.push_back(thread(myprint, i)); //创建并开始执行线程。
	//}
	//for (auto itr = mythreads.begin(); itr != mythreads.end(); itr++)
	//{
	//	itr->join(); // 等待10个线程返回。
	//}

	//cout << "I LOVE CHINA!" << endl;//

	//二、数据共享问题分析
	//(2.1)只读的数据，是安全稳定的，不需要特别处理手段，直接读即可
	//(2.2)有读有写：2个线程写，8个线程读，如果代码没有特别的处理，程序肯定崩溃。
		//最简单的不崩溃处理，读的时候不能写，写的时候不能读，2个线程不能同时写，8个线程不能同时读。
		//写的动作分10小步，由于任务切换，导致各种诡异的事情发生，最可能的即崩溃
	//(2.3)其他案例
	//数据共享
	//某一火车有10个售票窗口，各个窗口同时订99号座
	
	//三、共享数据的保护案例代码
	//网络游戏服务器，两个自己创建的线程，一个线程收集玩家的命令，并把命令数据写到一个队列中。
		//另一个线程从队列中取出玩家命令，解析，然后执行玩家需要的动作。
	//vector、list的区别。list：频繁按顺序插入和删除数据时效率高，vector对随即插入和删除数据效率高

//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//第二个参数，引用，才能保证线程里用的是同一个对象。
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myInMsgObj.join();
//	return 0;
//}