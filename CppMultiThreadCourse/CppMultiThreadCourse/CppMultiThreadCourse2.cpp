#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>

#include<thread>
using namespace std;

/*
//自行创建的线程也要从一个函数开始运行。
void myprint()
{
	cout << " My Thread Start" << endl;
	//...
	//...
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	cout << " My Thread Executing" << endl;
	 
	cout << " My Thread End" << endl;
}

class TA
{
public:
	int m_i;
	TA(int i) : m_i(i)
	{
		cout << "TA()构造函数被执行" << endl;
	}
	TA(const TA& ta) : m_i(ta.m_i)
	{
		cout << "TA()拷贝构造函数被执行" << endl;
	}
	~TA()
	{
		cout << "TA()析构函数被执行" << endl;
	}
	void operator()()//不能带参数。一个类重载了()后就变成了可调用对象
	{
		//cout << " My Thread Start" << endl;
		////...
		////...
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;
		//cout << " My Thread Executing" << endl;

		//cout << " My Thread End" << endl;

		cout << "m_i的值为1：" << m_i << endl;
		cout << "m_i的值为2：" << m_i << endl;
		cout << "m_i的值为3：" << m_i << endl;
		cout << "m_i的值为4：" << m_i << endl;
	}
};

int main()
{
	//一：范例演示线程的开始与结束
	//程序运行起来：生成一个进程，该进程所属的主线程开始自动运行

	cout << "I love China" << endl; //主线程从main()函数返回，则整个进程执行完毕

	//主线程从main()函数开始执行，那么我们自己创建的线程，也需要从一个函数开始运行（初始函数）。一旦函数运行完毕，代表我们的线程结束

	//整个进程是否执行完毕的标志是主线程是否执行完。如果主线程执行完毕了，就代表整个进程执行完毕了。
		//此时，一般情况下：如果其他子线程还未执行完毕，那么这些子线程也会被操作系统强行终止。
		//所以一般情况下，如果我们想保持子线程的运行状态，那么就要让主线程一直保持运行，不要让它运行完毕。
		//这条规律有例外，见后续，先如此记忆。

	//a)头文件thread要包含进来
	//b)初始函数编写
	//c)main中开始写代码
	//明确一点： 有两个线程在跑，相当于程序有两条线在同时走，即使一条线被堵住了，另一条仍可以执行，这就是多线程。
	//(1.1)thread是一个标准库中的类。
	//(1.2)join():加入/汇合，即阻塞，阻塞主线程。让主线程等待子线程执行完毕，然后子线程和主线程汇合，然后主线程再往下走。
		//如果主线程执行完毕了，但子线程未执行完，这种程序是不合格也不稳定的。
		//一个书写良好的程序，应该是主线程等待子线程执行完毕后自己才能最终退出。
	//(1.3)detach():传统多线程程序，主线程要等待子线程执行完毕，最后自己才退出。
		//detach:分离， 也就是主线程不与子线程汇合，各自执行，主线程可以先自行结束而不必等待子线程。
		//为何引入detach():创建了很多子线程，让主线程逐个等待子线程不太好。
		//一旦detach()之后，与主线程关联的thread对象，将失去与主线程的关联，此时子线程就会驻留在后台运行（主线程与子线程失去联系）
		//这个子线程相当于被c++运行时刻接管，当子线程执行完任务后，由运行时库负责清理该线程相关的资源（守护线程）
	//(1.4)joinable():判断是否可以用join()或detach(). 返回true即可以，false即不可
	//mytobj是一个可调用对象。
	//thread mytobj(myprint);  //(1)创建了线程，线程执行起点(入口)为myprint()。 (2)myprint开始执行。


	//mytobj.join(); //主线程阻塞到这里等待myprint()执行完，当子线程执行完毕，join()执行完毕，主线程就继续往下走。 总结：阻塞主线程并等待。
	//mytobj.detach(); //一旦调用了detach(),就无法再用join(),否则系统会报告异常
	//if (mytobj.joinable())
	//{
	//	cout << "joinable: true" << endl;
	//}
	//else
	//{
	//	cout << "joinable: false" << endl;
	//}
	//cout << "I love China!" << endl;
	//cout << "Program exit safely" << endl;


	//二、其他创建线程的方法。
	//(2.1)用类，以及一个问题范例
		//一旦调用了detach(),那主线程执行结束，ta对象不在了，
		//因为ta是被复制到线程中去了；执行完主线程够，ta会被销毁，但被复制的ta对象依旧存在。
		//所以只要ta类中没有指针和引用，就不会产生问题。
	//TA ta;
	//thread mytobj3(ta); //可调用类对象
	//mytobj3.join();
	//int m_i = 9;
	//TA ta(m_i);
	//thread mytobj4(ta);
	//mytobj4.join(); //当主线程执行结束后 m_i作为局部变量已被回收
	
	//(2.2)用lambda表达式
	auto mylambdathread = [] {
		cout << "My Thread Start" << endl;
		//...
		//...
		cout << "My Thread End" << endl;
	};
	thread mytobj5(mylambdathread);
	mytobj5.join();

	

	cout << "I love China!";
	
}*/