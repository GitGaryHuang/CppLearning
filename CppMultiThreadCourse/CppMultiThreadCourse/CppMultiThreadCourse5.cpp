#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<mutex>
#include<thread>
using namespace std;

//class A
//{
//	//把收到的玩家消息入到一个队列的线程。
//public:
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << i << " " << endl;
//			//my_mutex1.lock(); //实际可能两个锁头中间有代码。。。
//			//my_mutex2.lock();
//			//lock_guard<mutex> loguard(my_mutex);
//
//			lock(my_mutex1, my_mutex2);
//			lock_guard<mutex> loguard1(my_mutex1, adopt_lock);
//			lock_guard<mutex> loguard2(my_mutex2, adopt_lock);
//			//my_mutex.lock();
//			msgRecvQueue.push_back(i); //假设数字即收到的命令。
//			//my_mutex.unlock();
//			//my_mutex2.unlock();
//			//my_mutex1.unlock();
//		}
//	}
//
//	bool outMsgLULProc(int &command)
//	{
//		//lock_guard<mutex> loguard1(my_mutex1);
//		//lock_guard<mutex> loguard2(my_mutex2);
//		lock(my_mutex1, my_mutex2);
//		lock_guard<mutex> loguard1(my_mutex1, adopt_lock);
//		lock_guard<mutex> loguard2(my_mutex2, adopt_lock);
//		//lock_guard<mutex> loguard(my_mutex);//lock_guard构造函数执行了mutex::lock()，析构时执行了mutex::unlock()
//		//my_mutex2.lock();
//		//my_mutex1.lock();
//		if (!msgRecvQueue.empty())
//		{
//			int command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//									 //处理数据。
//			//my_mutex.unlock();
//			//my_mutex2.unlock();
//			//my_mutex1.unlock();
//			return true;
//		}
//		else
//		{
//			//my_mutex.unlock();
//			//my_mutex2.unlock();
//			//my_mutex1.unlock();
//			return false;
//		}
//		
//	}
//	void outMsgRecvQueue()
//	{
//		int command = 0;
//
//		for (int i = 0; i < 10000; i++)
//		{
//			bool result = outMsgLULProc(command); 
//			if (result)
//			{
//				cout << "outMsgRecvQueue()执行，取出一个元素" << command << endl;
//				//...
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
//	mutex my_mutex1;//创建互斥量 一把锁
//	mutex my_mutex2;
//};
//
//int main()
//{
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//第二个参数，引用，才能保证线程里用的是同一个对象。
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//	
//	myOutMsgObj.join();
//	myInMsgObj.join();
	//保护共享数据，操作时，某个线程用代码把共享数据锁住、操作数据、解锁。
		//其他想操作共享数据的线程必须等待解锁，然后锁住、操作、解锁。

	//一、互斥量（mutex）的基本概念
	//互斥量是一个类对象，理解成一把锁，多个线程尝试用lock()成员函数来尝试加锁，只有一个线程能锁定成功（标志为lock函数返回）。
		//若未成功，线程卡在lock()，不断尝试直到成功。
	//互斥量使用要小心，少了保护数据少，多了影响效率

	//二、互斥量的用法
	//(2.1)lock()、unlock();
		//先lock()、操作共享数据、unlock()
		//lock() unlock()成对使用。必须对称使用。非对称使用会导致代码不稳定及崩溃。
		//有lock而没有unlock较难排查
		//为防止忘记unlock问题，有lock_guard的类模板，会帮助unlock()
	//(2.2)std::lock_guard:直接取代lock(),unlock()

	//三、死锁
		//张三：站在北京等李四
		//李四：站在深圳等张三
		//c++中：
		//死锁至少有两把锁 金锁银锁。
		//两个线程A、B
		//(1)线程A先把金锁lock()成功，再去锁银锁。
		//出现了上下文切换。
		//(2)线程B执行，先锁了银锁，再去锁金锁。
		//此时产生死锁
		//(3)因为A拿不到银锁，流程不走，金锁打不开
		//(4)因为b拿不到金锁，流程不走，银锁打不开

	//(3.1)死锁演示
	//(3.2)死锁的一般解决方案
		//只要保证两个互斥量上锁的顺序就不会死锁。
	//(3.3)std::lock()模板。用来处理多个互斥量是才出现。
		//能力：一次锁住两个或者以上的互斥量（至少两个，一个不行）
		//它不存在这种因为在多个线程中，因为锁的顺序导致死锁的风险问题
		//lock()：如果互斥量中有一个没锁住，它就等待，等所有都锁住，它才能往下走。
		//要么两个互斥量都锁住，要么两个互斥量都没锁住。
		//如果只锁了一个，另一个没成功，则它立刻解锁已锁住的解锁。
	//(3.4)std::lock_guard()的std::adopt_lock参数
		//std::adopt_lock是个结构体对象，是一个标记作用： 作用就是表示这个互斥量已经lock()，不需要再std::lock_guard<std::mutex>构造函数里面对mutex对象再次进行lock()
	//总结：std::lock()一次锁住多个互斥量；谨慎使用。
//	return 0;
//}