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
//			////lock_guard<mutex> loguard1(my_mutex1);
//			////my_mutex1.lock();
//			//unique_lock<mutex> loguard1(my_mutex1, try_to_lock);
//			//if (loguard1.owns_lock())
//			//{
//			//unique_lock<mutex> loguard1(my_mutex1, defer_lock);//没有加锁的mutex1
//			//loguard1.lock();//不用自己unlock()
//			//共享代码需要处理。
//			//loguard1.unlock();
//			//非共享代码需要处理。
//			//loguard1.lock();
//			//共享代码需要处理。
//
//			//unique_lock<mutex> loguard1(my_mutex1);
//			//mutex *ptx =loguard1.release();//接管过来，有责任自己解锁。
//
//			//unique_lock<mutex> loguard1(my_mutex1);
//			//unique_lock<mutex> loguard2(my_mutex1);
//			//unique_lock<mutex> loguard2(loguard1); //复制所有权是非法的。
//			//unique_lock<mutex> loguard2(move(loguard1)); //移动语义， 现在相当于loguard2与my_mutex绑定在一起。loguard1指向空，loguard2指向my_mutex2
//
//			unique_lock<mutex> loguard = rtn_unique_lock();
//
//			//if(loguard1.try_lock())
//				msgRecvQueue.push_back(i); //假设数字即收到的命令。
//			//}
//			//else
//			//{
//				//cout << "no keys" << endl;
//			//}
//			//loguard1.unlock();
//				//ptx->unlock(); //自己负责mutex的unlock()
//		}
//	}
//
//	bool outMsgLULProc(int &command)
//	{
//		//lock_guard<mutex> loguard1(my_mutex1);
//		unique_lock<mutex> loguard1(my_mutex1);
//		//chrono::milliseconds dura(200);
//		//this_thread::sleep_for(dura); //休息200毫秒
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();//返回第一个元素，但不检查元素是否存在。
//			msgRecvQueue.pop_front();//移除第一个元素但不返回。
//									 //处理数据。
//			return true;
//		}
//		else
//		{
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
//
//int main()
//{
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//第二个参数，引用，才能保证线程里用的是同一个对象。
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myInMsgObj.join();
//	
//	//一、unique_lock取代lock_guard
//	//unique_lock是个类模板，工作中一般用lock_guard(它取代了mutex的lock()和unlock();
//	//unique_lock比lock_guard更灵活，但效率差一些、占用内存多一些。
//
//	//二、unique_lock的第二个参数。
//	//lock_guard的第二个参数：std::lock_guard<std::mutex> sbguard(my_mutex1, std::adopt_lock); //adopt_lock标记作用
//	//(2.1)std::adopt_lock:表示互斥量已经被lock(必须提前lock，否则会报异常)
//		//std::adopt_lock标记的效果就是调用方线程已经拥有了互斥的所有权（已经lock成功）
//		//通知lock_guard不需要在构造函数中lock这个互斥量。
//		//unique_lock中同样可以用std::adopt_lock标记，效果相同。
//	//(2.2)std::try_to_lock(禁止提前lock，否则会报异常)
//		//尝试用mutex的lock()去锁定mutex，若未锁定成功也会立即返回不会阻塞
//		//用这个try_to_lock的前提自己不会先去lock
//	//(2.3)std::defer_lock(禁止提前lock，否则会报异常)
//		//defer_lock的意思是没有给mutex加锁，初始化了一个没有加锁的mutex
//			//
//
//	//三、unique_lock的成员函数
//	//(3.1)lock()
//	//(3.2)unlock() 有非共享代码需要处理的时候可以解锁，让给别人
//	//(3.3)try_lock() 拿到锁返回true 否则返回false
//	//(3.4)release(),返回它所管理的mutex指针并释放所有权。 也就是unique_lock与mutex不再有关系。
//		//严格区分unlock和release的关系
//		//如果原来的mutex对象处于加锁状态，你有责任接管并负责解锁
//		//将返回一个原始的mutex指针
//	//为何有时需要unlock()，因为锁住的代码越少，执行越快，整个程序效率越高。
//	//也有人把锁住代码的多少成为锁的粒度，用粗细来描述
//	//a)代码少，粒度细，执行效率高。（可能漏掉共享数据保护）
//	//b)代码多，粒度粗，执行效率低。（影响执行效率）
//	//选择合适的粒度很关键，高级程序猿的能力和实力的体现。 
//
//	//四、unique_lock所有权的传递
//	//std::unique_lock(std::mutex> sbguard1(my_mutex1); 所有权概念
//	//sbguard1拥有my_mutex1的所有权。
//	//sbguard1可以把它对my_mutex的所有权转移给其他unique_lock对象；
//	//所以unique_lock对mutex的所有权是属于可以转移但不可复制的概念。
//	//a)std::move
//	//b)return std::unique_lock<mutex>
//	return 0;
//}