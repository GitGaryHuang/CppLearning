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
//	unique_lock<mutex> rtn_unique_lock()
//	{
//		unique_lock<mutex> tmpguard(my_mutex1);
//		return tmpguard; //�Ӻ�������һ���ֲ�unique_lock�����ǿ��Եġ����ƶ����캯����
//						// �������־ֲ�����tmpguard�ᵼ��ϵͳ������ʱunique_lock����,������unique_lock���ƶ����캯��
//	}
//
//	void inMsgRecvQueue()
//	{
//		
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << "inMsgRecvQueue ִ�У�����һ��Ԫ�� " << i << endl;
//			////lock_guard<mutex> loguard1(my_mutex1);
//			////my_mutex1.lock();
//			//unique_lock<mutex> loguard1(my_mutex1, try_to_lock);
//			//if (loguard1.owns_lock())
//			//{
//			//unique_lock<mutex> loguard1(my_mutex1, defer_lock);//û�м�����mutex1
//			//loguard1.lock();//�����Լ�unlock()
//			//���������Ҫ����
//			//loguard1.unlock();
//			//�ǹ��������Ҫ����
//			//loguard1.lock();
//			//���������Ҫ����
//
//			//unique_lock<mutex> loguard1(my_mutex1);
//			//mutex *ptx =loguard1.release();//�ӹܹ������������Լ�������
//
//			//unique_lock<mutex> loguard1(my_mutex1);
//			//unique_lock<mutex> loguard2(my_mutex1);
//			//unique_lock<mutex> loguard2(loguard1); //��������Ȩ�ǷǷ��ġ�
//			//unique_lock<mutex> loguard2(move(loguard1)); //�ƶ����壬 �����൱��loguard2��my_mutex����һ��loguard1ָ��գ�loguard2ָ��my_mutex2
//
//			unique_lock<mutex> loguard = rtn_unique_lock();
//
//			//if(loguard1.try_lock())
//				msgRecvQueue.push_back(i); //�������ּ��յ������
//			//}
//			//else
//			//{
//				//cout << "no keys" << endl;
//			//}
//			//loguard1.unlock();
//				//ptx->unlock(); //�Լ�����mutex��unlock()
//		}
//	}
//
//	bool outMsgLULProc(int &command)
//	{
//		//lock_guard<mutex> loguard1(my_mutex1);
//		unique_lock<mutex> loguard1(my_mutex1);
//		//chrono::milliseconds dura(200);
//		//this_thread::sleep_for(dura); //��Ϣ200����
//		if (!msgRecvQueue.empty())
//		{
//			command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//									 //�������ݡ�
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
//
//int main()
//{
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//�ڶ������������ã����ܱ�֤�߳����õ���ͬһ������
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myInMsgObj.join();
//	
//	//һ��unique_lockȡ��lock_guard
//	//unique_lock�Ǹ���ģ�壬������һ����lock_guard(��ȡ����mutex��lock()��unlock();
//	//unique_lock��lock_guard������Ч�ʲ�һЩ��ռ���ڴ��һЩ��
//
//	//����unique_lock�ĵڶ���������
//	//lock_guard�ĵڶ���������std::lock_guard<std::mutex> sbguard(my_mutex1, std::adopt_lock); //adopt_lock�������
//	//(2.1)std::adopt_lock:��ʾ�������Ѿ���lock(������ǰlock������ᱨ�쳣)
//		//std::adopt_lock��ǵ�Ч�����ǵ��÷��߳��Ѿ�ӵ���˻��������Ȩ���Ѿ�lock�ɹ���
//		//֪ͨlock_guard����Ҫ�ڹ��캯����lock�����������
//		//unique_lock��ͬ��������std::adopt_lock��ǣ�Ч����ͬ��
//	//(2.2)std::try_to_lock(��ֹ��ǰlock������ᱨ�쳣)
//		//������mutex��lock()ȥ����mutex����δ�����ɹ�Ҳ���������ز�������
//		//�����try_to_lock��ǰ���Լ�������ȥlock
//	//(2.3)std::defer_lock(��ֹ��ǰlock������ᱨ�쳣)
//		//defer_lock����˼��û�и�mutex��������ʼ����һ��û�м�����mutex
//			//
//
//	//����unique_lock�ĳ�Ա����
//	//(3.1)lock()
//	//(3.2)unlock() �зǹ��������Ҫ�����ʱ����Խ������ø�����
//	//(3.3)try_lock() �õ�������true ���򷵻�false
//	//(3.4)release(),�������������mutexָ�벢�ͷ�����Ȩ�� Ҳ����unique_lock��mutex�����й�ϵ��
//		//�ϸ�����unlock��release�Ĺ�ϵ
//		//���ԭ����mutex�����ڼ���״̬���������νӹܲ��������
//		//������һ��ԭʼ��mutexָ��
//	//Ϊ����ʱ��Ҫunlock()����Ϊ��ס�Ĵ���Խ�٣�ִ��Խ�죬��������Ч��Խ�ߡ�
//	//Ҳ���˰���ס����Ķ��ٳ�Ϊ�������ȣ��ô�ϸ������
//	//a)�����٣�����ϸ��ִ��Ч�ʸߡ�������©���������ݱ�����
//	//b)����࣬���ȴ֣�ִ��Ч�ʵ͡���Ӱ��ִ��Ч�ʣ�
//	//ѡ����ʵ����Ⱥܹؼ����߼�����Գ��������ʵ�������֡� 
//
//	//�ġ�unique_lock����Ȩ�Ĵ���
//	//std::unique_lock(std::mutex> sbguard1(my_mutex1); ����Ȩ����
//	//sbguard1ӵ��my_mutex1������Ȩ��
//	//sbguard1���԰�����my_mutex������Ȩת�Ƹ�����unique_lock����
//	//����unique_lock��mutex������Ȩ�����ڿ���ת�Ƶ����ɸ��Ƶĸ��
//	//a)std::move
//	//b)return std::unique_lock<mutex>
//	return 0;
//}