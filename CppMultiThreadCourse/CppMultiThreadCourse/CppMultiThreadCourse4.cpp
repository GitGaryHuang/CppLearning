#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>

#include<thread>
using namespace std; 

//vector<int> g_v = { 1, 2, 3 };
////�߳���ں���
//void myprint(int num)
//{
//	//cout << "myprint��ʼִ��,�̱߳��: " << num << endl;
//	////...
//	//cout << "myprintִ�����,�̱߳��: " << num << endl;
//	cout << "Thread ID: " << this_thread::get_id() << "��ӡg_v" << g_v[0] << g_v[1] << g_v[2] << endl;
//}
//class A
//{
//	//���յ��������Ϣ�뵽һ�����е��̡߳�
//public:
//	void inMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			cout << i << " " << endl;
//			msgRecvQueue.push_back(i); //�������ּ��յ������
//		}
//	}
//	void outMsgRecvQueue()
//	{
//		for (int i = 0; i < 10000; i++)
//		{
//			if (!msgRecvQueue.empty())
//			{
//				int command = msgRecvQueue.front();//���ص�һ��Ԫ�أ��������Ԫ���Ƿ���ڡ�
//				msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
//				//�������ݡ�
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
//};

//int main()
//{
	//һ�������͵ȴ�����߳�
	//vector<thread> mythreads;
	//����10���̣߳��߳���ں���ͳһΪmyprint
	//a):����̵߳�ִ��˳�����ҵģ�������ϵͳ�ڲ����̵߳����е��Ȼ����й�
	//b):���̵߳ȴ��������߳����н�����������߳̽������Ƽ�ʹ��join()����д�����ȶ��ĳ���
	//c):��thread������������й�����������һ��thread�������飬�������һ�δ��������̲߳����й���ܷ��㡣
	//for (int i = 1; i <= 10; i++)
	//{
	//	mythreads.push_back(thread(myprint, i)); //��������ʼִ���̡߳�
	//}
	//for (auto itr = mythreads.begin(); itr != mythreads.end(); itr++)
	//{
	//	itr->join(); // �ȴ�10���̷߳��ء�
	//}

	//cout << "I LOVE CHINA!" << endl;//

	//�������ݹ����������
	//(2.1)ֻ�������ݣ��ǰ�ȫ�ȶ��ģ�����Ҫ�ر����ֶΣ�ֱ�Ӷ�����
	//(2.2)�ж���д��2���߳�д��8���̶߳����������û���ر�Ĵ�������϶�������
		//��򵥵Ĳ�������������ʱ����д��д��ʱ���ܶ���2���̲߳���ͬʱд��8���̲߳���ͬʱ����
		//д�Ķ�����10С�������������л������¸��ֹ�������鷢��������ܵļ�����
	//(2.3)��������
	//���ݹ���
	//ĳһ����10����Ʊ���ڣ���������ͬʱ��99����
	
	//�����������ݵı�����������
	//������Ϸ�������������Լ��������̣߳�һ���߳��ռ���ҵ����������������д��һ�������С�
		//��һ���̴߳Ӷ�����ȡ��������������Ȼ��ִ�������Ҫ�Ķ�����
	//vector��list������list��Ƶ����˳������ɾ������ʱЧ�ʸߣ�vector���漴�����ɾ������Ч�ʸ�

//	A myobja;
//	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//�ڶ������������ã����ܱ�֤�߳����õ���ͬһ������
//	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
//
//	myOutMsgObj.join();
//	myInMsgObj.join();
//	return 0;
//}