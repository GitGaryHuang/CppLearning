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

////atomic<int> g_mycount = 0;
////atomic<bool> g_ifend = false;
////
////void mythread()
////{
////	for (int i = 0; i < 1000000; i++)
////	{
////		g_mycount++;
////		//g_mycount = g_mycount + 1; �������
////	}
////	return;
////}
//
////int mythread()
////{
////	cout << "mythread start ! Thread ID" << this_thread::get_id() << endl;
////	return 1;
////}
//
//int mythread()
//{
//		cout << "mythread start thread id : " << this_thread::get_id() << endl;//��ӡ���߳�idֵ
//		chrono::milliseconds dura(500);//��Ϣ5��
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id : " << this_thread::get_id() << endl;
//		return 5;
//}
//
//int main()
//{
//	//һ��ԭ�Ӳ���std::atomic��̸
//	//һ��ԭ�Ӳ����������+= ++ -- _= &=�Ȳ�������֧�ֵģ��������ܲ�֧�֡�
//
//	//����std::async����̸
//	//(2.1)std::async����������
//	//std::launch::deferred �ӳٵ���   std::launch::async ǿ�ƴ����߳�
//	//std::thread()��ϵͳ��Դ���ţ����ܴ���ʧ�ܣ���ôִ��std::thread()ʱ����������ܱ���
//	//std::async()����һ�㲻�д����̶߳��ǽд����첽����
//	//std::async()��std::thread()��ֱ�ӵ������ǣ�std::async()�������Ǵ������̡߳�
//	//a)����std::launch::deferred������async��������deferred�ӳٵ��ã������������̣߳��ӳٵ�future�������wait()��get()����û����wait()��get()���߳���ں������ᱻ���á�
//	//b)std::launch::asyncǿ���첽���������߳���ִ�У������������߳��������߳���ں�����
//	//c)std::launch::async | std::launch::deferred������ͬʱ�ã�������async��ͬ��ʵ�ʲ�ͬ����|����ζ�ſ�����async��Ҳ������deferred������
//	//D)����������ֻ��async����һ�������������ΪĬ��ֵ��(std::launch::async | std::launch::deferred) ����Cһ�¡�
//		//��ϵͳ���о�����
//	//(2.2)std::async��std::thread������
//	//std::thread�����̣߳���ϵͳ��Դ���ţ������߳�ʧ�ܣ�����ᱨ�쳣�������
//	//std::thread�����̵߳ķ�ʽ������̷߳���ֵ�������õ����ֵ
//	//std::async���ܴ����߳�Ҳ���ܲ������߳�
//	//std::async�������õ��߳���ں����ķ���ֵ
//	//����ϵͳ��Դ���ƣ�
//	//(1)���std::thread�������߳�̫�࣬����ܴ���ʧ�ܣ�����
//	//(2)std::asyncһ�㲻�ᱨ��������쳣����Ϊ����Դ���ţ�Ĭ�ϵ��û��Զ�ѡ��
//		//��Ҫ��asyncһ��Ҫ�������̣߳��������ܻ����
//	//(3)һ��������߳�����������100-200
//	//(2.3)std::async��ȷ��������Ľ����
//	//���Ӷ����������ϵͳ���о����Ƿ񴴽����߳�
//	//���⽹����������д�����첽�����Ƿ��Ƴٽ���
//	
//	//thread mytobj1(mythread);
//	//thread mytobj2(mythread);
//
//	//mytobj1.join();
//	//mytobj2.join();
//
//	//cout << "g_mycount : " << g_mycount << endl;
//
//
//	//cout << "Main start ! Thread ID" << this_thread::get_id() << endl;
//	//future<int> result = async(launch::async, mythread);//deferred�ӳٵ��ã������������̣߳��ӳٵ�future�������wait()��get()����û����wait()��get()����mythread���ᱻ���á�
//	//cout << result.get();
//
//		//ö������
//	future<int> result = async(mythread);
//	future_status status = result.wait_for(chrono::seconds(0));// �ȴ�1��
//	if (status == future_status::deferred)
//	{
//		//��ʾ�̱߳��ӳ�ִ��
//		cout << "deferred" << endl;
//		cout << result.get() << endl;
//	}
//	else if (status == future_status::ready)
//	{
//		//�߳�δ���ӳ�ִ�С�
//		cout << "ready" << endl;
//		cout << result.get() << endl;
//	}
//	else if (status == future_status::timeout)
//	{
//		cout << "timeout" << endl;
//		cout << result.get() << endl;
//	}
//	return 0;
//}