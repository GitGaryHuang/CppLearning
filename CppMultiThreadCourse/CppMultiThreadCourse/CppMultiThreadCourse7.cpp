#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<list>
#include<mutex>
#include<thread>
using namespace std;

//mutex resource_mutex;
//once_flag g_flag;//ϵͳ����ı�ǣ���δ����λ
//
//class MyCAS //����һ��������
//{
//private:
//	MyCAS() { } // ˽�л����캯��
//	static MyCAS *m_instance; //��̬��Ա����
//
//public:
//	static MyCAS *GetInstance()
//	{
//		//���Ч��
//		//a)���if(m_instance != NULL)������������϶���ʾm_instance�Ѿ���new��
//		//b)���if(m_instance == NULL)����������������m_instanceû��new��
//		//if (m_instance == NULL) //˫��������˫�ؼ�飩
//		//{
//		//	unique_lock<mutex> m_i_lock(resource_mutex);//�Զ�����
//		//	if (m_instance == NULL)
//		//	{
//		//		m_instance = new MyCAS();
//		//		static Del Del; //Del������m_instance����ռ��ͬʱ������MyCAS�������ʧʱ��Del����������Ҳ���������������������ͷ�MyCAS����Ŀռ䲢
//		//	}
//		//}
//		call_once(g_flag, CreateInstance);//���������̶߳�ִ�е��������һ���̳߳ɹ�����call_once������һ���߳�Ҫ����ִ����ϣ���ִ�С���ʱ��g_flagҲ�൱��һ����
//		return m_instance;
//	}
//
//	class Del//�������࣬�����ͷŶ���
//	{
//	public:
//		~Del()//�����������
//		{
//			if (MyCAS::m_instance)
//			{
//				delete MyCAS::m_instance;
//				MyCAS::m_instance = NULL;
//			}
//		}
//	};
//
//	static void CreateInstance() //ֻ������һ�εĺ�����
//	{
//		chrono::milliseconds last(5000);
//		this_thread::sleep_for(last);
//		m_instance = new MyCAS();
//		cout << "**!!!!!!!!!!!!!!!!!!!!!**" << endl;
//		static Del Del; //Del������m_instance����ռ��ͬʱ������MyCAS�������ʧʱ��Del����������Ҳ���������������������ͷ�MyCAS����Ŀռ䲢
//	}
//	void func()
//	{
//		cout << "Hello" << endl;
//	}
//};
//
////�ྲ̬������ʼ��
//MyCAS* MyCAS::m_instance = NULL;//��Ҫ��˽�о�̬��Ա������ʹ��ǰ�����ʼ��
//void mythread()
//{
//	cout << "�ҵ��߳̿�ʼ��:" << this_thread::get_id() << endl;
//	MyCAS *p_a = MyCAS::GetInstance(); //������ܳ�������
//	cout << "�ҵ��߳�ִ�����:" << this_thread::get_id() << endl;
//}
//int main()
//{
//	//һ�����ģʽ���̸
//	//�����ģʽ���������һЩд����������ά�����㣬�����˽ӹܺ��Ķ�����Ƚ�ʹ�ࡣ
//	//�á����ģʽ������д�����Ĵ���ܻ�ɬ��
//	//�������Ŀ�Ŀ������顢ģ�黮�־����ܽ�����ģʽ��
//	//Ӳ�����ģʽ�Ǳ�ĩ���õģ�Ӧ��ѧ���ã��м�����Ӳ�ס�
//
//	//�����������ģʽ��ʹ��Ƶ�ʸߣ�
//	//������������Ŀ�У���ĳ����ĳЩ������࣬���ڸ���Ķ���ֻ�ܴ���һ�������˴������ˡ�
//	//������
//
//	//MyCAS *p_a = MyCAS::GetInstance(); //����һ�����󣬷���һ����������ָ��
//	//MyCAS *p_b = MyCAS::GetInstance();
//	//p_a->func();
//	//MyCAS::GetInstance()->func();//��װ�ص�����װ��
//	//�����������ģʽ��������������������
//	//���ٵ����⣺��Ҫ�������Լ��������̣߳����������̣߳��д���MyCAS���������Ķ��������߳̿��ܲ�ֹһ��������������
//		//GetInstance()���ֳ�Ա��������Ҫ���⡣
//	//��Ȼ�����̶߳���ͬһ����ں������������������̣߳����Ի�������ͨ·ͬʱִ��mythread��
//
//	//�ġ�std::call_once() 
//	//c++11����ĺ���,�ڶ���������һ��������a()��
//	//call_once()��֤����a()ֻ������һ�Ρ�
//	//�߱����������������Ҹ���Ч����Ч��û��26��˫������Ҫ�ã�
//	//call_once()��Ҫ��һ����ǽ��ʹ�ã���������std::once_flag����һ���ṹ����
//	//call_once()����ͨ����������������Ӧ�ĺ���a()�Ƿ�ִ�У�����call_once�ɹ��󣬰�once_flag����Ϊ�ѵ���״̬����ʱ��Ӧ�ĺ���a()������ִ��
//	//�˴����ô����˵�26�е�˫������
//	//��Ȼ���鵥��ģʽ�ĵ��������ڳ���ʼǰ�����߳��У��ȳ�ʼ������ٽ������̡߳�
//
//
//	thread mytobj1(mythread);
//	thread mytobj2(mythread);
//	mytobj1.join();
//	mytobj2.join();
//	return 0;
//}