#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>

#include<thread>
using namespace std;
//
//void myprint(const int &i, char *pmybuf)
//{
//	cout << i << endl; //������Ϊ���˴�i�������߳��е�mvar���ã�ʵ����ֵ���ݣ����������߳�detach�����̣߳���ô���̵߳�iֵ��Ȼ�ǰ�ȫ�ġ�
//	cout << pmybuf << endl;//ָ����detach���߳�ʱ���Ի�������
//	return;
//}

//class A
//{
//public :
//	int m_i;
//	//����ת�����캯������Ϊ�����ֻ��һ��������
//	A(int a) : m_i(a) { cout << "[A::A(int a)���캯��ִ��]" << this << "  thread id = " << this_thread::get_id() << endl; }
//	A(const A &a) : m_i(a.m_i) { cout << "[A::A(const A& a)�������캯��ִ��]" << this << "  thread id = " << this_thread::get_id() << endl; }
//	~A() { cout << "[A::~A()��������ִ��]" << this << "  thread id = " << this_thread::get_id() << endl; }  
//
//	void thread_work(int num)
//	{
//		;
//	}
//	void operator()(int num)
//	{
//		cout << "  thread id = " << this_thread::get_id() << endl;
//	}
//};
//
////void myprint(const int i, const string &pmybuf)
////{
////	cout << i << endl;
////	cout << pmybuf.c_str() << endl;
////	return;
////}
//
////void myprint(const int i, const A& pmybuf)
////{
////	cout << &pmybuf << endl;
////	return;
////}
//
////void myprint2(const A& pmybuf) //��Ȼ�����ã���ʵ���ǿ���������һ������󣬳���ʹ��ref
////{
////	pmybuf.m_i = 199; //�޸ĸ�ֵ����Ӱ��main����
////	cout << "���߳�2�Ĳ�����ַ�ǣ�" << &pmybuf << "  thread id = " << this_thread::get_id() << endl;
////}
//
//void myprint3(unique_ptr<int> pzn) //��Ȼ�����ã���ʵ���ǿ���������һ������󣬳���ʹ��ref
//{
//	;
//}
//
//int main()
//{
//	//һ��������ʱ������Ϊ�̲߳���
//	//(1.1)Ҫ������ɾ�������1��
//	//(1.2)Ҫ������ɾ�������2��
//	//��ʵ1��ֻҪ����ʱ�����A�������Ϊ�������ݸ��̣߳���ô��һ���������߳�ִ�����ǰ�����̺߳����ĵڶ�����������������Ӷ�ȷ������detach�ˣ����߳�Ҳ�ܰ�ȫ���С�
//	//(1.3)�ܽ᣺
//	//a)������int���ּ����ͣ����鶼��ֵ���ݣ���Ҫ�����ã���ֹ������֦��detach�У���
//	//b)�����������󣬱�����ʽ����ת����ȫ�����ڴ����߳���һ���й�������ʱ����Ȼ���ں�������������������ܣ�����ϵͳ���ṹ���һ�ζ���
//	//�ռ����ۣ�
//	//c)���鲻ʹ��detach() ֻ����join(),�����Ͳ����ھֲ�����ʧЧ�������̶߳��ڴ�ķǷ���������
//	
//	//������ʱ������Ϊ�̲߳�����������
//	//(2.1)�߳�id���id�Ǹ����֣�ÿ���̣߳����������̻߳������̣߳�ʵ���϶���Ӧ��һ�����֡�
//		//Ҳ����˵��ͬ�̶߳�Ӧ��ID�����֣��ǲ�ͬ��
//		//�߳�id������c++��׼����ĺ�������ȡ��
//	//(2.2)��ʱ������ʱ��ץ��
//
//	//�����������������ָ��Ϊ�̲߳���
//	//std::ref����
//
//	//�ġ��ó�Ա����ָ�����̲߳���
//	//int mvar = 1;
//	//int &myvary = mvar;
//	//char mybuf[] = "this is a test!";
//
//	//thread mytobj(myprint, mvar, mybuf);//mybufʲôʱ��ת��string
//	//									//��ʵ�ϴ��ڵ�mybuf�����պ�ϵͳ����ͼ��mybufת��string
//	////mytobj.join();
//	//thread mytobj(myprint, mvar, string(mybuf)); //�������Ƚ�mybufתΪstring��ʱ���󣬿��Ա�֤��һ���߳����ÿ϶���Ч
//
//	/*int mvar = 1;
//	int mysecondpar = 12;*/
//	//thread mytobj(myprint, mvar, mysecondpar); //����ϣ��mysecondparת��A���Ͷ��󴫵ݸ�myprint�ĵڶ�������
//	//thread mytobj(myprint2, A(mysecondpar)); //�ڴ����̵߳�ͬʱ������ʱ����ķ������ݲ����ǿ��е� ��thread���캯���������õ�ȫ�����ɸ��ƹ��죩
//	//mytobj.join();
//	//mytobj.join(); //���߳������̷ֱ߳�ִ��
//
//	cout << "���߳�ID��" << this_thread::get_id() << endl;
//	//int mvar = 1;
//	//thread mytobj(myprint2, A(mvar));//������ʱ��������е�A�������main()�������Ѿ���������ˣ�����ᵽ���߳��й���
//	//mytobj.detach();
//	//cout << "I LOVE CHINA!" << endl;
//
//	//A myobj(10); //����һ�������
//	//thread mytobj(myprint2, ref(myobj));
//	//mytobj.join();
//	//unique_ptr<int> myp(new int(100));
//	//thread mytobj(myprint3, move(myp));
//	//A myobj(10);
//	//thread mytobj(&A::thread_work, myobj, 15);
//	//mytobj.join();
//	A myobj(10);
//	thread mytobj(ref(myobj), 15);
//	mytobj.join();
//	//while (1)
//	//{
//	//	;
//	//}
//	return 0;
//}