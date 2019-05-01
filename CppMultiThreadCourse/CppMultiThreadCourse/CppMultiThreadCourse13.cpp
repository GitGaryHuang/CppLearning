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

class A
{
	//���յ��������Ϣ�뵽һ�����е��̡߳�
public:
	atomic<int> atm;
	A()
	{
		atm = 0;
		//auto atm2 = atm; //���ֶ���ʱ��ʼ��������������ʾ������������ɾ���ĺ������������ڲ�����Ӧ�Ŀ������캯��
		//atomic atm2 = 0; //��ֵͬ��������
		//atm2 = atm; 
		atomic<int> atm2 = (atm.load());//load():��ԭ�ӷ�ʽ��atomic�����ֵ
		//store()��ԭ�ӷ�ʽд������
		atm2.store(12);
	}


	unique_lock<mutex> rtn_unique_lock()
	{
		unique_lock<mutex> tmpguard(my_mutex1);
		return tmpguard; //�Ӻ�������һ���ֲ�unique_lock�����ǿ��Եġ����ƶ����캯����
						// �������־ֲ�����tmpguard�ᵼ��ϵͳ������ʱunique_lock����,������unique_lock���ƶ����캯��
	}

	void inMsgRecvQueue()
	{
		
		//for (int i = 0; i < 10000; i++)
		//{
		//	cout << "inMsgRecvQueue ִ�У�����һ��Ԫ�� " << i << endl;
		//	unique_lock<mutex> loguard = rtn_unique_lock();
		//	msgRecvQueue.push_back(i); //�������ּ��յ������
		//	my_cond.notify_all();//���ǳ��Ի���wait();����ʱwait()û�ж���������Ч
		//}
		for (int i = 0; i < 1000000; i++)
		{
			//atm += 1;
			//atm = atm + 1;
		}
	}

	void outMsgRecvQueue()
	{
		//int command = 0;
		//while (true)
		//{
		//	unique_lock<mutex> loguard(my_mutex1);
		//	my_cond.wait(loguard, [this] { //lambda���ɵ��ö��� ***���ж���Ч���ж����Ƿ�����ٻ���
		//		if (!msgRecvQueue.empty())
		//			return true;
		//		else
		//			return false;
		//	});
		//	command = msgRecvQueue.front();//������һ��Ԫ��
		//	msgRecvQueue.pop_front();//�Ƴ���һ��Ԫ�ص������ء�
		//	cout << "ȡ��һ��Ԫ��" << command << "thread ID:" << this_thread::get_id() << endl;
		//	loguard.unlock();	//����unique_lock()������ԣ�������ʱ������������ס̫��ʱ�䡣
		//}
		while (true)
		{
			cout << atm << endl; //��atm��ԭ�Ӳ����������д��벢����ԭ�Ӳ�����
		}

	}
private:
	list<int> msgRecvQueue;//��������Ϣ���У���ר�����ڴ�����ҷ��͹��������
	mutex my_mutex1;//���������� һ����
	mutex my_mutex2;
	condition_variable my_cond;
};

int main()
{
	//һ������֪ʶ��
	//(1.1)��ٻ��ѣ�wait()��Ҫ�еڶ�������lambda���������lambda��Ҫ��ȷ�ж�Ҫ����Ĺ��������Ƿ����
	//wait()��notify_one()��notify_all();

	//(1.2��atomic

	//����ǳ̸�̳߳�
	//(2.1)��������
	//����������--���ͻ��ˣ�ÿ��һ���ͻ��ˣ��ʹ���һ�����߳�Ϊ�ÿͻ��ṩ����
	//a)������Ϸ��2w��ң������ܸ�ÿ����Ҵ������̣߳��˳���д�������ֳ����²�ͨ��
	//b)�����ȶ������⣺��д�Ĵ����У�ż������һ���߳����ִ��룬����д�����˲���
	//�̳߳أ���һ���߳�Ū��һ��ͳһ��������ͳһ������ȣ�ѭ�������̵߳ķ�ʽ�������̳߳ء�
	//(2.2)ʵ�ַ�ʽ
	//�ڳ�������ʱ��һ���ԵĴ���һ���������̡߳����ȶ�

	//�����̴߳�������̸
	//(3.1)�߳̿��������������⣺2000���̻߳����Ǽ��ޣ��ٴ����߳����ױ���
	//(3.2)�̴߳�������������
	//a)����ĳЩ������������api�ӿ��ṩ�̵Ľ��飺cpu������cpu����*2����**רҵ���ȷ�������Чִ�С�
	//b)�������߳����ҵ��һ���̵߳���һ��ִ��ͨ·��100Ҫ�Ķ�����ֵ����110���̺߳ܺ��ʡ�
	//c)���������Ҳ������Ҫ��������̣߳�������Ҫ����500������200��֮��

	//�ġ�C++11���߳��ܽ�
	//winodws linux
	

	A myobja;
	thread myOutMsgObj(&A::outMsgRecvQueue, &myobja);//�ڶ������������ã����ܱ�֤�߳����õ���ͬһ������
	//thread myOutMsgObj2(&A::outMsgRecvQueue, &myobja);
	//thread myOutMsgObj3(&A::outMsgRecvQueue, &myobja);
	thread myInMsgObj(&A::inMsgRecvQueue, &myobja);
	thread myInMsgObj2(&A::inMsgRecvQueue, &myobja);
		
	myOutMsgObj.join();
	//myOutMsgObj2.join();
	//myOutMsgObj3.join();
	myInMsgObj.join();
	myInMsgObj2.join();
}