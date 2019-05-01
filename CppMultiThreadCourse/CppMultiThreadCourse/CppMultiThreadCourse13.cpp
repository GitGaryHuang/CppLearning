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

class A
{
	//把收到的玩家消息入到一个队列的线程。
public:
	atomic<int> atm;
	A()
	{
		atm = 0;
		//auto atm2 = atm; //这种定义时初始化操作不允许，显示“尝试引用已删除的函数”编译器内部无相应的拷贝构造函数
		//atomic atm2 = 0; //赋值同样不允许
		//atm2 = atm; 
		atomic<int> atm2 = (atm.load());//load():以原子方式读atomic对象的值
		//store()以原子方式写入内容
		atm2.store(12);
	}


	unique_lock<mutex> rtn_unique_lock()
	{
		unique_lock<mutex> tmpguard(my_mutex1);
		return tmpguard; //从函数返回一个局部unique_lock对象是可以的。（移动构造函数）
						// 返回这种局部对象tmpguard会导致系统生成临时unique_lock对象,并调用unique_lock的移动构造函数
	}

	void inMsgRecvQueue()
	{
		
		//for (int i = 0; i < 10000; i++)
		//{
		//	cout << "inMsgRecvQueue 执行，插入一个元素 " << i << endl;
		//	unique_lock<mutex> loguard = rtn_unique_lock();
		//	msgRecvQueue.push_back(i); //假设数字即收到的命令。
		//	my_cond.notify_all();//我们尝试唤醒wait();若此时wait()没有堵塞，则无效
		//}
		for (int i = 0; i < 1000000; i++)
		{
			//atm += 1;
			//atm = atm + 1;
		}
	}

	void outMsgRecvQueue()
	{
		//int command = 0;
		//while (true)
		//{
		//	unique_lock<mutex> loguard(my_mutex1);
		//	my_cond.wait(loguard, [this] { //lambda即可调用对象 ***该判断有效地判断了是否是虚假唤醒
		//		if (!msgRecvQueue.empty())
		//			return true;
		//		else
		//			return false;
		//	});
		//	command = msgRecvQueue.front();//至少有一个元素
		//	msgRecvQueue.pop_front();//移除第一个元素但不返回。
		//	cout << "取出一个元素" << command << "thread ID:" << this_thread::get_id() << endl;
		//	loguard.unlock();	//由于unique_lock()的灵活性，可以随时解锁，以免锁住太长时间。
		//}
		while (true)
		{
			cout << atm << endl; //读atm是原子操作，但这行代码并不是原子操作。
		}

	}
private:
	list<int> msgRecvQueue;//容器（消息队列），专门用于代表玩家发送过来的命令。
	mutex my_mutex1;//创建互斥量 一把锁
	mutex my_mutex2;
	condition_variable my_cond;
};

int main()
{
	//一、补充知识点
	//(1.1)虚假唤醒：wait()中要有第二参数（lambda）并且这个lambda中要正确判断要处理的公共数据是否存在
	//wait()、notify_one()、notify_all();

	//(1.2）atomic

	//二、浅谈线程池
	//(2.1)场景设想
	//服务器程序：--》客户端，每来一个客户端，就创建一个新线程为该客户提供服务。
	//a)网络游戏：2w玩家，不可能给每个玩家创建新线程，此程序写法在这种场景下不通。
	//b)程序稳定性问题：编写的代码中，偶尔创建一个线程这种代码，这种写法让人不安
	//线程池：把一堆线程弄到一起，统一管理。这种统一管理调度，循环利用线程的方式，叫做线程池。
	//(2.2)实现方式
	//在程序启动时，一次性的创建一定数量的线程。更稳定

	//三、线程创建数量谈
	//(3.1)线程开的数量极限问题：2000个线程基本是极限，再创建线程容易崩溃
	//(3.2)线程创建的数量问题
	//a)采用某些技术开发程序；api接口提供商的建议：cpu数量，cpu数量*2。。**专业意见确保程序高效执行。
	//b)创建多线程完成业务，一个线程等于一条执行通路。100要的堵塞充值，开110个线程很合适。
	//c)即便需求大也尽量不要开过多的线程，尽量不要超过500个，在200个之内

	//四、C++11多线程总结
	//winodws linux
	

	A myobja;
	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//第二个参数，引用，才能保证线程里用的是同一个对象。
	//thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
	//thread myOutMsgObj3(&A::outMsgRecvQueue, &myobja);
	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
	thread myInMsgObj2(&A::inMsgRecvQueue, &myobja);
		
	myOutMsgObj.join();
	//myOutMsgObj2.join();
	//myOutMsgObj3.join();
	myInMsgObj.join();
	myInMsgObj2.join();
}