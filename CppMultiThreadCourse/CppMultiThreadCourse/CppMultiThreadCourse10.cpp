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
//
////int mythread(int mypar)
////{
////		cout << "mythread start thread id : " << this_thread::get_id() << endl;//��ӡ���߳�idֵ
////		chrono::milliseconds dura(500);//��Ϣ5��
////		this_thread::sleep_for(dura);
////		cout << "mythread end . thread id : " << this_thread::get_id() << endl;
////		return 5;
////}
////
//////void mythread2(future<int> &tmpf)
////void mythread2(shared_future<int> &tmpf)
////{
////	cout << "My thread2 start thread id = " << this_thread::get_id() << endl;
////	auto result = tmpf.get();//std::future::get()������һ���ƶ����壬���ֻ�ܵ���һ��
////	cout << "My thread2 result = " << result << endl;
////	return;
////}
//
////int g_mycount = 0;//����һ��ȫ����
//atomic<int> g_mycount = 0;//��װ��һ������Ϊint�Ķ���(ֵ�����������һ��int����һ����
////mutex g_my_mutex;
////void mythread()
////{
////	for (int i = 0; i < 1000000; i++)
////	{
////		//g_my_mutex.lock();
////		g_mycount++;
////		//g_my_mutex.unlock();
////	}
////	return;
////}
//atomic<bool> g_ifend = false; //ԭ�Ӳ�������ֹͬʱд��
//
//void mythread()
//{
//	chrono::milliseconds dura(1000);
//
//	while (!g_ifend)
//	{
//		cout << "thread id �� " << this_thread::get_id() << "executing..." << endl;
//		this_thread::sleep_for(dura);
//	}
//	cout << "thread id �� " << this_thread::get_id() << "end..." << endl;
//}
//int main()
//{
//	//һ��std::future��������Ա������
//	//����std::shared_future����ģ�壬get()�����������ݡ�
//
//
//
//
//
//
//
//	cout << "main thread id : " << this_thread::get_id() << endl;
//
//	//future<int> result = async(launch::deferred, mythread);
//	//cout << "continue....!" << endl;
//	////cout << result.get() << endl; 
//
//
//	////ö������
//	//future_status status = result.wait_for(chrono::milliseconds(3000));// �ȴ�1��
//	//if (status == future_status::timeout)
//	//{
//	//	//��ʾ�߳�δִ����
//	//	cout << "timeout" << endl;
//	//}
//	//else if (status == future_status::ready)
//	//{
//	//	cout << "ready" << endl;
//	//}
//	//else if (status == future_status::deferred)
//	//{
//	//	cout << "deferred" << endl;
//	//	cout << result.get() << endl;
//	//}
//
////	packaged_task<int(int)> mypt(mythread);//���ǰѺ���mythread()ͨ��packaged_task��װ����
////	thread tl(ref(mypt), 1);//�߳�ֱ�ӿ�ʼִ�У��ڶ�������Ϊ�߳���ں����Ĳ�����
////	tl.join();
////	//future<int> result = mypt.get_future();//std::future��������߳���ں����ķ��ؽ��������result����mythread�ķ���ֵ
////	shared_future<int> result_s = mypt.get_future();
////	//bool ifcanget = result.valid();
////	//if (ifcanget)
////	//	cout << "*****" << endl;
////
////	//shared_future<int> result2 = (move(result));//��shared_future<int> result2 = (result.share());
////	//shared_future<int> result2 = (result.share()); //ִ����Ϻ�resultΪ�� result2��ֵ
////	//ifcanget = result.valid();
////	//if (ifcanget)
////	//	cout << "*****" << endl;
////	
////	thread t2(mythread2, ref(result_s));
//////	cout << result.get() << endl;
////	t2.join();
////	cout << "I LOVE CHINA! " << endl;
////	return 0;
//
//	//����ԭ�Ӳ���std::atomoic
//	//(3.1)ԭ�Ӳ���������������
//		//�����������̱߳���б����������ݣ����������������ݡ�����
//		//�������̣߳���һ���������в�����һ���̶߳�����һ���߳�д
//		//
//	//int atomvalue = 5; //atomvalue������Ƕ��̼߳�Ĺ������
//	////���߳�A
//	//int tmpvalue = atomvalue; 
//	////д�߳�B
//	//atomvalue = 6;
//
//	//��ԭ�Ӳ�������һ�ֲ���Ҫ���������������Ķ��̲߳�����ʽ
//	//����˵ԭ�Ӳ������ڶ��߳��в��ᱻ��ϵĳ���Ƭ�Ρ�
//	//�������ļ���һ�����һ������Σ�ԭ�Ӳ���һ����Ա�����
//	//Ч���ϱȻ���������
//	//ԭ�Ӳ���һ��ָ���ɷָ�Ĳ�����ԭ�Ӳ����������м�״̬
//	//std::atomic����ԭ�Ӳ���������ģ�壬������װĳ�����͵�ֵ
//	//(3.2)������std::atomic()�÷�������
//	//(3.3)�ĵã�ԭ�Ӳ���ֻ�ܴ��������������һ������ͳ�ƣ��ۼ��շ��������ݰ���
//	//�ԳԲ�׼�Ĵ��� ��Ҫд ��������ҵ�С�
//	thread mytobj1(mythread);
//	thread mytobj2(mythread);
//
//	chrono::milliseconds dura(5000);
//	this_thread::sleep_for(dura);
//
//	g_ifend = true;
//
//	mytobj1.join();
//	mytobj2.join();
//
//	cout << "END" << endl;
//	cout << "g_mycount : " << g_mycount << endl;
//	return 0;
//};