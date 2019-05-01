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
//	unique_lock<mutex> rtn_unique_lock()
//	{
//		unique_lock<mutex> tmpguard(my_mutex1);
//		return tmpguard; //从函数返回一个局部unique_lock对象是可以的。（移动构造函数）
//						// 返回这种局部对象tmpguard会导致系统生成临时unique_lock对象,并调用unique_lock的移动构造函数
//	}
//
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "inMsgRecvQueue 执行，插入一个元素 " << i << endl;
//			unique_lock<mutex> loguard = rtn_unique_lock();
//			msgRecvQueue.push_back(i); //假设数字即收到的命令。
//			my_cond.notify_all();//我们尝试唤醒wait();若此时wait()没有堵塞，则无效
//		}
//	}
//
//	//bool outMsgLULProc(int &command)
//	//{
//	//	//双重锁定 最稳定的方法
//	//	if (!msgRecvQueue.empty())
//	//	{
//	//		unique_lock<mutex> loguard1(my_mutex1);
//	//		if (!msgRecvQueue.empty())
//	//		{
//	//			command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//	//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//	//									 //处理数据。
//	//			return true;
//	//		}
//	//		else
//	//		{
//	//			return false;
//	//		}
//	//	}
//	//	
//		
//	//}
//	void outMsgRecvQueue()
//	{
//		int command = 0;
//		while (true)
//		{
//			unique_lock<mutex> loguard(my_mutex1);
//
//			//wait()用来等待一个东西
//			//若第二个参数返回true，则wait()返回，流程继续。
//			//若第二个参数返回为false，则wait()将解锁互斥量，并堵塞到本行，直到其他某个线程调用notify_one()成员函数为止。
//			//若wait()无第二参数,那么就和第二个参数返回false效果相同
//			//当其他线程把wait()从堵塞状态唤醒(notify)后，wait()继续干活
//				//a)不断尝试重新获取互斥量锁，若获取不到，流程卡在这里。若获取到了，则继续b
//				//b)获取到锁、上锁
//					//b.1)若wait()有第二个参数，就判断它，若为false，wait继续解锁互斥量，继续堵塞，等待notify。
//					//b.2)若为true，流程继续（仍为加锁状态）。
//					//b.3)若wait()无第二个参数，则wait()返回（即无条件唤醒）
//			my_cond.wait(loguard, [this] { //lambda即可调用对象
//				if (!msgRecvQueue.empty())
//					return true;
//				else
//					return false;
//			});
//			command = msgRecvQueue.front();//至少有一个元素
//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//			cout << "取出一个元素" << command << "thread ID:" << this_thread::get_id() << endl;
//			loguard.unlock();	//由于unique_lock()的灵活性，可以随时解锁，以免锁住太长时间。
//			
//			//执行其他具体行为....
//		}
//
//		//for (int i = 0; i < 10000; i++)
//		//{
//		//	bool result = outMsgLULProc(command); 
//		//	if (result)
//		//	{
//		//		cout << "outMsgRecvQueue()执行，取出一个元素" << command << endl;
//		//		//...
//		//	} 
//		//	else
//		//	{
//		//		cout << "outMsgRecvQueue执行，但队列为空" << i << endl;
//		//	}
//		//}
//		//cout << "end" << endl;
//	}
//private:
//	list<int> msgRecvQueue;//容器（消息队列），专门用于代表玩家发送过来的命令。
//	mutex my_mutex1;//创建互斥量 一把锁
//	mutex my_mutex2;
//	condition_variable my_cond;
//};
//
//
//int main()
//{
//
//	//一、条件变量std::condition_variable、wait()、notify_one()
//	//线程A：等待一个条件满足
//	//线程B：专门往消息队列中扔消息
//	//std::condition_variable实际上是一个类，是一个和条件相关的一个类，等待一个条件达成。
//	//这个类需要与互斥量合作完成工作，用的同时我们需要生成类的对象。
//
//	//二、上述代码的深入思考。
//
//	//三、notify_all()
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//第二个参数，引用，才能保证线程里用的是同一个对象。
//	thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
//	thread myOutMsgObj3(&A::outMsgRecvQueue, &myobja);
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myOutMsgObj2.join();
//	myOutMsgObj3.join();
//	myInMsgObj.join();
//	
//	return 0;
//}