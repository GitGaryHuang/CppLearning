#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<mutex>
#include<thread>
using namespace std;

//mutex resource_mutex;
//once_flag g_flag;//系统定义的标记，还未被置位
//
//class MyCAS //这是一个单例类
//{
//private:
//	MyCAS() { } // 私有化构造函数
//	static MyCAS *m_instance; //静态成员变量
//
//public:
//	static MyCAS *GetInstance()
//	{
//		//提高效率
//		//a)如果if(m_instance != NULL)条件成立，则肯定表示m_instance已经被new过
//		//b)如果if(m_instance == NULL)条件成立，不代表m_instance没被new过
//		//if (m_instance == NULL) //双重锁定（双重检查）
//		//{
//		//	unique_lock<mutex> m_i_lock(resource_mutex);//自动加锁
//		//	if (m_instance == NULL)
//		//	{
//		//		m_instance = new MyCAS();
//		//		static Del Del; //Del对象与m_instance申请空间的同时构建，MyCAS类对象消失时，Del的生命周期也结束，调用析构函数来释放MyCAS申请的空间并
//		//	}
//		//}
//		call_once(g_flag, CreateInstance);//假设两个线程都执行到这里，其中一个线程成功调用call_once，另外一个线程要等它执行完毕，再执行。此时的g_flag也相当于一把锁
//		return m_instance;
//	}
//
//	class Del//类中套类，用来释放对象。
//	{
//	public:
//		~Del()//类的析构函数
//		{
//			if (MyCAS::m_instance)
//			{
//				delete MyCAS::m_instance;
//				MyCAS::m_instance = NULL;
//			}
//		}
//	};
//
//	static void CreateInstance() //只被调用一次的函数。
//	{
//		chrono::milliseconds last(5000);
//		this_thread::sleep_for(last);
//		m_instance = new MyCAS();
//		cout << "**!!!!!!!!!!!!!!!!!!!!!**" << endl;
//		static Del Del; //Del对象与m_instance申请空间的同时构建，MyCAS类对象消失时，Del的生命周期也结束，调用析构函数来释放MyCAS申请的空间并
//	}
//	void func()
//	{
//		cout << "Hello" << endl;
//	}
//};
//
////类静态变量初始化
//MyCAS* MyCAS::m_instance = NULL;//重要，私有静态成员变量在使用前必须初始化
//void mythread()
//{
//	cout << "我的线程开始了:" << this_thread::get_id() << endl;
//	MyCAS *p_a = MyCAS::GetInstance(); //这里可能出现问题
//	cout << "我的线程执行完毕:" << this_thread::get_id() << endl;
//}
//int main()
//{
//	//一、设计模式大概谈
//	//“设计模式”：代码的一些写法：程序灵活，维护方便，但别人接管和阅读代码比较痛苦。
//	//用“设计模式”理念写出来的代码很晦涩。
//	//老外把项目的开发经验、模块划分经验总结成设计模式。
//	//硬套设计模式是本末倒置的，应活学活用，切忌生搬硬套。
//
//	//二、单例设计模式（使用频率高）
//	//单例：整个项目中，有某个或某些特殊的类，属于该类的对象，只能创建一个，多了创建不了。
//	//单例类
//
//	//MyCAS *p_a = MyCAS::GetInstance(); //创建一个对象，返回一个该类对象的指针
//	//MyCAS *p_b = MyCAS::GetInstance();
//	//p_a->func();
//	//MyCAS::GetInstance()->func();//该装载的数据装载
//	//三、单例设计模式共享数据问题分析、解决
//	//面临的问题：需要在我们自己创建的线程（而不是主线程）中创建MyCAS这个单例类的对象，这种线程可能不止一个（最少两个）
//		//GetInstance()这种成员函数可能要互斥。
//	//虽然两个线程都是同一个入口函数，但是这是两个线程，所以会有两条通路同时执行mythread。
//
//	//四、std::call_once() 
//	//c++11引入的函数,第二个参数是一个函数名a()。
//	//call_once()保证函数a()只被调用一次。
//	//具备互斥量能力，而且更高效。（效率没有26号双重锁定要好）
//	//call_once()需要与一个标记结合使用，这个标记是std::once_flag（是一个结构）。
//	//call_once()就是通过这个标记来决定对应的函数a()是否执行，调用call_once成功后，把once_flag设置为已调用状态。此时对应的函数a()不会再执行
//	//此处调用代替了第26行的双重锁定
//	//仍然建议单例模式的单例对象在程序开始前（主线程中）先初始化完毕再进入子线程。
//
//
//	thread mytobj1(mythread);
//	thread mytobj2(mythread);
//	mytobj1.join();
//	mytobj2.join();
//	return 0;
//}