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
//	//���յ��������Ϣ�뵽һ�����е��̡߳�
//public:
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << i << " " << endl;
//			//my_mutex1.lock(); //ʵ�ʿ���������ͷ�м��д��롣����
//			//my_mutex2.lock();
//			//lock_guard<mutex> loguard(my_mutex);
//
//			lock(my_mutex1, my_mutex2);
//			lock_guard<mutex> loguard1(my_mutex1, adopt_lock);
//			lock_guard<mutex> loguard2(my_mutex2, adopt_lock);
//			//my_mutex.lock();
//			msgRecvQueue.push_back(i); //�������ּ��յ������
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
//		//lock_guard<mutex> loguard(my_mutex);//lock_guard���캯��ִ����mutex::lock()������ʱִ����mutex::unlock()
//		//my_mutex2.lock();
//		//my_mutex1.lock();
//		if (!msgRecvQueue.empty())
//		{
//			int command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//									 //�������ݡ�
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
//				cout << "outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��" << command << endl;
//				//...
//			} 
//			else
//			{
//				cout << "outMsgRecvQueueִ�У�������Ϊ��" << i << endl;
//			}
//		}
//		cout << "end" << endl;
//	}
//private:
//	list<int> msgRecvQueue;//��������Ϣ���У���ר�����ڴ�����ҷ��͹��������
//	mutex my_mutex1;//���������� һ����
//	mutex my_mutex2;
//};
//
//int main()
//{
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//�ڶ������������ã����ܱ�֤�߳����õ���ͬһ������
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//	
//	myOutMsgObj.join();
//	myInMsgObj.join();
	//�����������ݣ�����ʱ��ĳ���߳��ô���ѹ���������ס���������ݡ�������
		//����������������ݵ��̱߳���ȴ�������Ȼ����ס��������������

	//һ����������mutex���Ļ�������
	//��������һ�����������һ����������̳߳�����lock()��Ա���������Լ�����ֻ��һ���߳��������ɹ�����־Ϊlock�������أ���
		//��δ�ɹ����߳̿���lock()�����ϳ���ֱ���ɹ���
	//������ʹ��ҪС�ģ����˱��������٣�����Ӱ��Ч��

	//�������������÷�
	//(2.1)lock()��unlock();
		//��lock()�������������ݡ�unlock()
		//lock() unlock()�ɶ�ʹ�á�����Գ�ʹ�á��ǶԳ�ʹ�ûᵼ�´��벻�ȶ���������
		//��lock��û��unlock�����Ų�
		//Ϊ��ֹ����unlock���⣬��lock_guard����ģ�壬�����unlock()
	//(2.2)std::lock_guard:ֱ��ȡ��lock(),unlock()

	//��������
		//������վ�ڱ���������
		//���ģ�վ�����ڵ�����
		//c++�У�
		//���������������� ����������
		//�����߳�A��B
		//(1)�߳�A�Ȱѽ���lock()�ɹ�����ȥ��������
		//�������������л���
		//(2)�߳�Bִ�У���������������ȥ��������
		//��ʱ��������
		//(3)��ΪA�ò������������̲��ߣ������򲻿�
		//(4)��Ϊb�ò������������̲��ߣ������򲻿�

	//(3.1)������ʾ
	//(3.2)������һ��������
		//ֻҪ��֤����������������˳��Ͳ���������
	//(3.3)std::lock()ģ�塣�����������������ǲų��֡�
		//������һ����ס�����������ϵĻ�����������������һ�����У�
		//��������������Ϊ�ڶ���߳��У���Ϊ����˳���������ķ�������
		//lock()���������������һ��û��ס�����͵ȴ��������ж���ס�������������ߡ�
		//Ҫô��������������ס��Ҫô������������û��ס��
		//���ֻ����һ������һ��û�ɹ����������̽�������ס�Ľ�����
	//(3.4)std::lock_guard()��std::adopt_lock����
		//std::adopt_lock�Ǹ��ṹ�������һ��������ã� ���þ��Ǳ�ʾ����������Ѿ�lock()������Ҫ��std::lock_guard<std::mutex>���캯�������mutex�����ٴν���lock()
	//�ܽ᣺std::lock()һ����ס���������������ʹ�á�
//	return 0;
//}