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
////���������Զ��ͷ�windows�µ��ٽ�������ֹ����LeaveCriticalSection������������ķ�����������c++�е�std::lock_guard<mutex>
//class CWinLock//RAII�� Resource Acquisition is initialization ��Դ��ȡ����ʼ�� ������������ָ�붼����RAII��
//{
//public:
//	CWinLock(CRITICAL_SECTION *pCritmp)//���캯��
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
//	//���յ��������Ϣ�뵽һ�����е��̡߳�
//public:
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "����һ��Ԫ�� : "  << i << endl;
//#ifdef __WINDOWSJQ_
//			//EnterCriticalSection(&my_winsec);//�����ٽ������൱�ڼ���
//			//EnterCriticalSection(&my_winsec);
//			CWinLock Wlock(&my_winsec);
//			CWinLock Wlock2(&my_winsec);
//			msgRecvQueue.push_back(i);
//			//LeaveCriticalSection(&my_winsec);//�뿪�ٽ������൱�ڽ�����
//			//LeaveCriticalSection(&my_winsec);
//#else
//			//lock_guard<recursive_mutex> loguard(my_mutex);
//			//lock_guard<mutex> loguard1(my_mutex);
//			//my_mutex.lock();
//			//my_mutex.lock(); c++11���������2��
//			chrono::milliseconds timeout(1000);
//			//if (my_mutex.try_lock_for(timeout))
//			if (my_mutex.try_lock_until(chrono::steady_clock::now() + timeout))
//			{
//				msgRecvQueue.push_back(i); //�������ּ��յ������
//				my_mutex.unlock();
//			}
//			//msgRecvQueue.push_back(i); //�������ּ��յ������
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
//			command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//									 //�������ݡ�
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
//			command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//									 //�������ݡ�
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
//	A() {
//#ifdef __WINDOWSJQ_
//		InitializeCriticalSection(&my_winsec); //��ʼ���ٽ���
//#endif // !__WINDOWSJQ_
//	}
//
//	//void testfunc1()
//	//{
//	//	lock_guard<recursive_mutex> sbguard(my_mutex);
//	//	//�ɸ�����
//	//	testfunc2();//���� lock����һ�α��쳣
//	//}
//
//	//void testfunc2()
//	//{
//	//	lock_guard<recursive_mutex> sbguard(my_mutex);
//	//	//�ɸ�����
//	//}
//
//private:
//	list<int> msgRecvQueue;//��������Ϣ���У���ר�����ڴ�����ҷ��͹��������
//	//mutex my_mutex;
//	//recursive_mutex my_mutex;
//	timed_mutex my_mutex;
//
//#ifdef __WINDOWSJQ_
//	CRITICAL_SECTION my_winsec;// windows�е��ٽ���������mutex
//#endif // !__WINDOWSJQ_
//
//};
//
//
//
//int main()
//{
//	//һ��windows�ٽ���
//	//������ν����ٽ�������
//	//ͬһ���̣߳���ͬ�̻߳Ῠס�ȴ�����windows�ٽ�������ͬ�ٽ�������������ٽ����Ľ�����Զ�ε��ã��������ξ�Ҫ�����Σ��൱��lock��unlock����
//	//C++11�У�������ͬһ��������lock��Ρ�
//	//�����Զ���������
//	//std::lock_guard
//	//�ġ�recursive_mutex�ݹ黥����
//	//std::mutex ��ռ���������Լ�lockʱ������lock����
//	//recursive_mutex:�ݹ�Ķ�ռ������������ͬһ���̣߳�ͬһ����������α�lock()
//		//Ҳ��lock()��unlock()
//			//�õ�recursive_mutexʱ����Ҫ���ǵ������Ƿ����Ż��ռ��ˡ�
//		//�ݹ������˵���ޡ�
//	//�塢���г�ʱ�Ļ�����std::timed_mutex��std::recursive_timed_mutex
//	//std::timed_mutex ����ʱ�Ķ�ռ������
//		//try_lock_for(): �ȴ�һ��ʱ�䡣������õ����������߳�ʱδ�õ���������������ȥ
//		//try_lock_until(): ������һ��δ����ʱ��㣬��δ����ʱ��û����ʱ���ڣ�����õ���������������ȥ���򵽵���û�õ�����Ҳ����ȥ��
//	//std::recursive_timed_mutex ����ʱ�ĵݹ��ռ������
//	A myobja;
//	thread myOutnMsgobj(&A::outMsgRecvQueue, &myobja);
//	thread myInMsgobj(&A::inMsgRecvQueue, &myobja);
//
//	myOutnMsgobj.join();
//	myInMsgobj.join();
//
//	return 0;
//}