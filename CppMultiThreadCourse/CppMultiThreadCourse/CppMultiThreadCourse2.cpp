#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>

#include<thread>
using namespace std;

/*
//���д������߳�ҲҪ��һ��������ʼ���С�
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
		cout << "TA()���캯����ִ��" << endl;
	}
	TA(const TA& ta) : m_i(ta.m_i)
	{
		cout << "TA()�������캯����ִ��" << endl;
	}
	~TA()
	{
		cout << "TA()����������ִ��" << endl;
	}
	void operator()()//���ܴ�������һ����������()��ͱ���˿ɵ��ö���
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

		cout << "m_i��ֵΪ1��" << m_i << endl;
		cout << "m_i��ֵΪ2��" << m_i << endl;
		cout << "m_i��ֵΪ3��" << m_i << endl;
		cout << "m_i��ֵΪ4��" << m_i << endl;
	}
};

int main()
{
	//һ��������ʾ�̵߳Ŀ�ʼ�����
	//������������������һ�����̣��ý������������߳̿�ʼ�Զ�����

	cout << "I love China" << endl; //���̴߳�main()�������أ�����������ִ�����

	//���̴߳�main()������ʼִ�У���ô�����Լ��������̣߳�Ҳ��Ҫ��һ��������ʼ���У���ʼ��������һ������������ϣ��������ǵ��߳̽���

	//���������Ƿ�ִ����ϵı�־�����߳��Ƿ�ִ���ꡣ������߳�ִ������ˣ��ʹ�����������ִ������ˡ�
		//��ʱ��һ������£�����������̻߳�δִ����ϣ���ô��Щ���߳�Ҳ�ᱻ����ϵͳǿ����ֹ��
		//����һ������£���������뱣�����̵߳�����״̬����ô��Ҫ�����߳�һֱ�������У���Ҫ����������ϡ�
		//�������������⣬������������˼��䡣

	//a)ͷ�ļ�threadҪ��������
	//b)��ʼ������д
	//c)main�п�ʼд����
	//��ȷһ�㣺 �������߳����ܣ��൱�ڳ�������������ͬʱ�ߣ���ʹһ���߱���ס�ˣ���һ���Կ���ִ�У�����Ƕ��̡߳�
	//(1.1)thread��һ����׼���е��ࡣ
	//(1.2)join():����/��ϣ����������������̡߳������̵߳ȴ����߳�ִ����ϣ�Ȼ�����̺߳����̻߳�ϣ�Ȼ�����߳��������ߡ�
		//������߳�ִ������ˣ������߳�δִ���꣬���ֳ����ǲ��ϸ�Ҳ���ȶ��ġ�
		//һ����д���õĳ���Ӧ�������̵߳ȴ����߳�ִ����Ϻ��Լ����������˳���
	//(1.3)detach():��ͳ���̳߳������߳�Ҫ�ȴ����߳�ִ����ϣ�����Լ����˳���
		//detach:���룬 Ҳ�������̲߳������̻߳�ϣ�����ִ�У����߳̿��������н��������صȴ����̡߳�
		//Ϊ������detach():�����˺ܶ����̣߳������߳�����ȴ����̲߳�̫�á�
		//һ��detach()֮�������̹߳�����thread���󣬽�ʧȥ�����̵߳Ĺ�������ʱ���߳̾ͻ�פ���ں�̨���У����߳������߳�ʧȥ��ϵ��
		//������߳��൱�ڱ�c++����ʱ�̽ӹܣ������߳�ִ���������������ʱ�⸺��������߳���ص���Դ���ػ��̣߳�
	//(1.4)joinable():�ж��Ƿ������join()��detach(). ����true�����ԣ�false������
	//mytobj��һ���ɵ��ö���
	//thread mytobj(myprint);  //(1)�������̣߳��߳�ִ�����(���)Ϊmyprint()�� (2)myprint��ʼִ�С�


	//mytobj.join(); //���߳�����������ȴ�myprint()ִ���꣬�����߳�ִ����ϣ�join()ִ����ϣ����߳̾ͼ��������ߡ� �ܽ᣺�������̲߳��ȴ���
	//mytobj.detach(); //һ��������detach(),���޷�����join(),����ϵͳ�ᱨ���쳣
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


	//�������������̵߳ķ�����
	//(2.1)���࣬�Լ�һ�����ⷶ��
		//һ��������detach(),�����߳�ִ�н�����ta�������ˣ�
		//��Ϊta�Ǳ����Ƶ��߳���ȥ�ˣ�ִ�������̹߳���ta�ᱻ���٣��������Ƶ�ta�������ɴ��ڡ�
		//����ֻҪta����û��ָ������ã��Ͳ���������⡣
	//TA ta;
	//thread mytobj3(ta); //�ɵ��������
	//mytobj3.join();
	//int m_i = 9;
	//TA ta(m_i);
	//thread mytobj4(ta);
	//mytobj4.join(); //�����߳�ִ�н����� m_i��Ϊ�ֲ������ѱ�����
	
	//(2.2)��lambda���ʽ
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