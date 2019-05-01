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

//class A
//{
//public:
//	int mythread(int mypar)
//	{
//		cout << mypar;
//		cout << "mythread id : " << this_thread::get_id() << endl;//打印新线程id值
//		chrono::milliseconds dura(5000);//休息5秒
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id " << this_thread::get_id() << endl;
//		return 5;
//	}
//};

//int mythread(int mypar)
//{
//		cout << mypar;
//		cout << "mythread id : " << this_thread::get_id() << endl;//打印新线程id值
//		chrono::milliseconds dura(5000);//休息5秒
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id " << this_thread::get_id() << endl;
//		return 5;
//}

//vector<packaged_task<int(int)>> mytask;//容器
// 
//void mythread(promise<int> &tmp, int calc)
//{
//	//做一系列复杂运算
//	calc++;
//	calc *= 100;
//	chrono::milliseconds dura(500);
//	this_thread::sleep_for(dura);
//
//	int result = calc;
//	tmp.set_value(result);//结果保存到了tmp对象中。
//
//	return;
//}
//
//void mythread2(future<int> &tmpf)
//{
//	auto result = tmpf.get();
//	cout << "My thread2 result = " << result << endl;
//	return;
//}
//
//int main()
//{
	//一、std::async、std::future创建后台任务并返回值
	//希望线程返回一个结果。
	//std::async是一个函数模版，用来启动一个异步任务，启动后返回一个std::future对象，std::future是个类模板
	//启动一个异步任务，就是自动创建一个线程并开始执行对应的线程入口函数，它返回一个std::future对象。
		//这个std::future对象里面就含有线程入口函数所返回的结果（线程返回的结果），我们可以通过调用future对象的成员函数get()来获取结果。
		//"future":将来的意思，有人也称呼std::future提供了一种访问异步操作结果的机制，就是说这个结果可能没办法马上得到。
		//在线程执行完毕后，可以拿到结果。
		//简易理解：future对象中保存着一个将来某个时候能拿到的值

	//下列函数通过std::future的对象get()成员函数等待线程执行结束并返回结果。
	//get()一直阻塞直到得到返回值 
	//std::thread
	//我们通过额外想std::async()传递一个参数，该参数类型是std::lunnch类型（枚举类型），来达到一些目的。
	//a)std::launch::deferred:表示线程入口函数调用被延迟到std::future的wait()或get()函数调用才执行，即延迟执行。
		//若wait()和get()未执行,线程不执行（实际上未创建)
		//std::launch::deferred:延迟调用，并没有创建新线程，而是在主线程中调用线程入口函数。
	//b)std::launch::async,在调用async函数的时候就开始创建线程。
		//async()函数默认使用std::launch::async参数标记

	//  ·std::launch::async
	//	保证异步行为，即传递函数将在单独的线程中执行
	//	·std::launch::deferred
	//	当其他线程调用get()来访问共享状态时，将调用非异步行为
	//	·std::launch::async | std::launch::deferred
	//  默认行为。有了这个启动策略，它可以异步运行或不运行，这取决于系统的负载，但我们无法控制它。


	//二、std::packaged_task:打包任务，把任务包装起来
	//类模板，把各种可调用对象包装起来，方便将来作为线程入口函数。
	//std::package_task包装起来的可调用对象还可以直接调用，从这个角度讲，packaged_task对象也是一个可调用对象。


	//三、std::promise,类模板
	//我们能够在某个线程中给它赋值，然后可以再其他线程中取出它。
	//总结：通过promise保存一个值，在将来通过把future与promise绑定起来来得到这个值。

	//四、小结：到底怎么用，什么时候用
	//并不是为了完全用到实际开发中，
	//相反能写出稳定高效的多线程程序更好。
	//阅读源码，积累经验，提升自己。
	//在此学习为将来阅读源码铺路。



	//A a;
	//int mypar = 12;

	/*cout << "main thread id" << this_thread::get_id() << endl;*/

	////future<int> result = async(mythread);
	////future<int> result = async(launch::deferred, &A::mythread, &a, mypar); //第二个参数是对象引用,才能保证线程中用的是同一个对象。
	//future<int> result = async(launch::async, &A::mythread, &a, mypar);
	//cout << "continue....!" << endl;
	//int def;
	//def = 0;
	//cout << result.get() << endl; //卡在这里等待mythread()执行完毕，拿到结果.只能调用一次！！
	////result.wait(); //等待线程返回，本身不返回结果


	//packaged_task<int(int)> mypt(mythread);//我们把函数mythread()通过packaged_task包装起来
	//thread tl(ref(mypt), 1);//线程直接开始执行，第二个参数为线程入口函数的参数。
	//tl.join();
	//future<int> result = mypt.get_future();//std::future里包含有线程入口函数的返回结果，这里result保存mythread的返回值
	//cout << result.get() << endl;

	//packaged_task<int(int)> mypt([](int mypar) {
	//	cout << mypar;
	//	cout << "mythread id : " << this_thread::get_id() << endl;//打印新线程id值
	//	chrono::milliseconds dura(5000);//休息5秒
	//	this_thread::sleep_for(dura);
	//	cout << "mythread end . thread id " << this_thread::get_id() << endl;
	//	return 5;
	//});
	//thread tl(ref(mypt), 1);//线程直接开始执行，第二个参数为线程入口函数的参数。
	//tl.join();
	//future<int> result = mypt.get_future();//std::future里包含有线程入口函数的返回结果，这里result保存mythread的返回值
	//cout << result.get() << endl;

	//mypt(105);//直接调用，相当于函数调用
	//future<int> result = mypt.get_future();
	//cout << result.get() << endl;

	//mytask.push_back(move(mypt));
	//packaged_task<int(int)> mypt2;
	//auto iter = mytask.begin();
	//mypt2 = move(*iter);//移动语义
	//mytask.erase(iter);//删除第一个元素，后续不可再使用iter
	//mypt2(123);
	//future<int> result = mypt2.get_future();
	//cout << result.get() << endl;

//	promise<int> myprom;//声明一个std::promise对象myprom，保存值类型为int
//	thread t1(mythread, ref(myprom), 180);
//	t1.join();
//	future<int> ful = myprom.get_future(); //promise和future绑定用于获取线程返回值。
//	//auto result = ful.get();//get()只能调用一次
//	//cout << "result = " << result << endl;
//
//	thread t2(mythread2, ref(ful));
//	t2.join();
//	cout << "my thread2 end" << endl;
//
//	cout << "I LOVE CHINA!" << endl;
//}