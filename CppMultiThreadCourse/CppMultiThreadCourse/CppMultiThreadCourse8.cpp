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
//			unique_lock<mutex> loguard = rtn_unique_lock();
//			msgRecvQueue.push_back(i); //�������ּ��յ������
//			my_cond.notify_all();//���ǳ��Ի���wait();����ʱwait()û�ж���������Ч
//		}
//	}
//
//	//bool outMsgLULProc(int &command)
//	//{
//	//	//˫������ ���ȶ��ķ���
//	//	if (!msgRecvQueue.empty())
//	//	{
//	//		unique_lock<mutex> loguard1(my_mutex1);
//	//		if (!msgRecvQueue.empty())
//	//		{
//	//			command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//	//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//	//									 //�������ݡ�
//	//			return true;
//	//		}
//	//		else
//	//		{
//	//			return false;
//	//		}
//	//	}
//	//	
//		
//	//}
//	void outMsgRecvQueue()
//	{
//		int command = 0;
//		while (true)
//		{
//			unique_lock<mutex> loguard(my_mutex1);
//
//			//wait()�����ȴ�һ������
//			//���ڶ�����������true����wait()���أ����̼�����
//			//���ڶ�����������Ϊfalse����wait()�������������������������У�ֱ������ĳ���̵߳���notify_one()��Ա����Ϊֹ��
//			//��wait()�޵ڶ�����,��ô�ͺ͵ڶ�����������falseЧ����ͬ
//			//�������̰߳�wait()�Ӷ���״̬����(notify)��wait()�����ɻ�
//				//a)���ϳ������»�ȡ��������������ȡ���������̿����������ȡ���ˣ������b
//				//b)��ȡ����������
//					//b.1)��wait()�еڶ������������ж�������Ϊfalse��wait���������������������������ȴ�notify��
//					//b.2)��Ϊtrue�����̼�������Ϊ����״̬����
//					//b.3)��wait()�޵ڶ�����������wait()���أ������������ѣ�
//			my_cond.wait(loguard, [this] { //lambda���ɵ��ö���
//				if (!msgRecvQueue.empty())
//					return true;
//				else
//					return false;
//			});
//			command = msgRecvQueue.front();//������һ��Ԫ��
//			msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//			cout << "ȡ��һ��Ԫ��" << command << "thread ID:" << this_thread::get_id() << endl;
//			loguard.unlock();	//����unique_lock()������ԣ�������ʱ������������ס̫��ʱ�䡣
//			
//			//ִ������������Ϊ....
//		}
//
//		//for (int i = 0; i < 10000; i++)
//		//{
//		//	bool result = outMsgLULProc(command); 
//		//	if (result)
//		//	{
//		//		cout << "outMsgRecvQueue()ִ�У�ȡ��һ��Ԫ��" << command << endl;
//		//		//...
//		//	} 
//		//	else
//		//	{
//		//		cout << "outMsgRecvQueueִ�У�������Ϊ��" << i << endl;
//		//	}
//		//}
//		//cout << "end" << endl;
//	}
//private:
//	list<int> msgRecvQueue;//��������Ϣ���У���ר�����ڴ�����ҷ��͹��������
//	mutex my_mutex1;//���������� һ����
//	mutex my_mutex2;
//	condition_variable my_cond;
//};
//
//
//int main()
//{
//
//	//һ����������std::condition_variable��wait()��notify_one()
//	//�߳�A���ȴ�һ����������
//	//�߳�B��ר������Ϣ����������Ϣ
//	//std::condition_variableʵ������һ���࣬��һ����������ص�һ���࣬�ȴ�һ��������ɡ�
//	//�������Ҫ�뻥����������ɹ������õ�ͬʱ������Ҫ������Ķ���
//
//	//�����������������˼����
//
//	//����notify_all()
//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//�ڶ������������ã����ܱ�֤�߳����õ���ͬһ������
//	thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
//	thread myOutMsgObj3(&A::outMsgRecvQueue, &myobja);
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myOutMsgObj2.join();
//	myOutMsgObj3.join();
//	myInMsgObj.join();
//	
//	return 0;
//}