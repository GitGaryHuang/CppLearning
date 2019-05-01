#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<mutex>
#include<thread>
#include<future>

#include<windows.h>
using namespace std;

////#define __WINDOWSJQ_
//
////本来用于自动释放windows下的临界区，防止忘记LeaveCriticalSection导致死锁情况的发生，类似于c++中的std::lock_guard<mutex>
//class CWinLock//RAII类 Resource Acquisition is initialization 资源获取即初始化 。容器、智能指针都属于RAII类
//{
//public:
//	CWinLock(CRITICAL_SECTION *pCritmp)//构造函数
//	{
//		m_pCritical = pCritmp;
//		EnterCriticalSection(m_pCritical);
//	}
//	~CWinLock()
//	{
//		LeaveCriticalSection(m_pCritical);
//	}
//private:
//	CRITICAL_SECTION *m_pCritical;
//};
//
//class A
//{
//	//把收到的玩家消息入到一个队列的线程。
//public:
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "插入一个元素 : "  << i << endl;
//#ifdef __WINDOWSJQ_
//			//EnterCriticalSection(&my_winsec);//进入临界区，相当于加锁
//			//EnterCriticalSection(&my_winsec);
//			CWinLock Wlock(&my_winsec);
//			CWinLock Wlock2(&my_winsec);
//			msgRecvQueue.push_back(i);
//			//LeaveCriticalSection(&my_winsec);//离开临界区，相当于解锁。
//			//LeaveCriticalSection(&my_winsec);
//#else
//			//lock_guard<recursive_mutex> loguard(my_mutex);
//			//lock_guard<mutex> loguard1(my_mutex);
//			//my_mutex.lock();
//			//my_mutex.lock(); c++11不允许调用2次
//			chrono::milliseconds timeout(1000);
//			//if (my_mutex.try_lock_for(timeout))
//			if (my_mutex.try_lock_until(chrono::steady_clock::now() + timeout))
//			{
//				msgRecvQueue.push_back(i); //假设数字即收到的命令。
//				my_mutex.unlock();
//			}
//			//msgRecvQueue.push_back(i); //假设数字即收到的命令。
//			//my_mutex.unlock();
//			//my_mutex.unlock();
//			else
//			{
//				chrono::milliseconds dura(100);
//				this_thread::sleep_for(dura);
//			}
//#endif // !__WINDOWSJQ_
//		}
//	}
//
//	bool outMsgLULProc(int &command)
//	{
//#ifdef __WINDOWSJQ_
//		EnterCriticalSection(&my_winsec);
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//									 //处理数据。
//			LeaveCriticalSection(&my_winsec);
//			return true;
//		}
//		LeaveCriticalSection(&my_winsec);
//		
//#else
//		my_mutex.lock();
//		
//		//this_thread::sleep_for(chrono::milliseconds(1000000));
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//									 //处理数据。
//			my_mutex.unlock();
//			return true;
//		}
//		else
//		{
//			my_mutex.unlock();
//			return false;
//		}
//#endif
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
//	A() {
//#ifdef __WINDOWSJQ_
//		InitializeCriticalSection(&my_winsec); //初始化临界区
//#endif // !__WINDOWSJQ_
//	}
//
//	//void testfunc1()
//	//{
//	//	lock_guard<recursive_mutex> sbguard(my_mutex);
//	//	//干各种事
//	//	testfunc2();//崩溃 lock超过一次必异常
//	//}
//
//	//void testfunc2()
//	//{
//	//	lock_guard<recursive_mutex> sbguard(my_mutex);
//	//	//干各种事
//	//}
//
//private:
//	list<int> msgRecvQueue;//容器（消息队列），专门用于代表玩家发送过来的命令。
//	//mutex my_mutex;
//	//recursive_mutex my_mutex;
//	timed_mutex my_mutex;
//
//#ifdef __WINDOWSJQ_
//	CRITICAL_SECTION my_winsec;// windows中的临界区，类似mutex
//#endif // !__WINDOWSJQ_
//
//};
//
//
//
//int main()
//{
//	//一、windows临界区
//	//二、多次进入临界区试验
//	//同一个线程（不同线程会卡住等待），windows临界区的相同临界区变量代表的临界区的进入可以多次调用，但进几次就要出几次（相当于lock与unlock）。
//	//C++11中，不允许同一个互斥量lock多次。
//	//三、自动析构技术
//	//std::lock_guard
//	//四、recursive_mutex递归互斥量
//	//std::mutex 独占互斥量，自己lock时，别人lock不了
//	//recursive_mutex:递归的独占互斥量，允许同一个线程，同一个互斥量多次被lock()
//		//也有lock()、unlock()
//			//用到recursive_mutex时，需要考虑到代码是否有优化空间了。
//		//递归次数据说有限。
//	//五、带有超时的互斥量std::timed_mutex，std::recursive_timed_mutex
//	//std::timed_mutex 带超时的独占互斥量
//		//try_lock_for(): 等待一段时间。如果我拿到了锁，或者超时未拿到锁，则流程走下去
//		//try_lock_until(): 参数是一个未来的时间点，在未来的时间没到的时间内，如果拿到锁，则流程走下去，或到点了没拿到锁，也走下去。
//	//std::recursive_timed_mutex 带超时的递归独占互斥量
//	A myobja;
//	thread myOutnMsgobj(&A::outMsgRecvQueue, &myobja);
//	thread myInMsgobj(&A::inMsgRecvQueue, &myobja);
//
//	myOutnMsgobj.join();
//	myInMsgobj.join();
//
//	return 0;
//}