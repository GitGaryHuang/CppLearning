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

//class A
//{
//public:
//	int mythread(int mypar)
//	{
//		cout << mypar;
//		cout << "mythread id : " << this_thread::get_id() << endl;//��ӡ���߳�idֵ
//		chrono::milliseconds dura(5000);//��Ϣ5��
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id " << this_thread::get_id() << endl;
//		return 5;
//	}
//};

//int mythread(int mypar)
//{
//		cout << mypar;
//		cout << "mythread id : " << this_thread::get_id() << endl;//��ӡ���߳�idֵ
//		chrono::milliseconds dura(5000);//��Ϣ5��
//		this_thread::sleep_for(dura);
//		cout << "mythread end . thread id " << this_thread::get_id() << endl;
//		return 5;
//}

//vector<packaged_task<int(int)>> mytask;//����
// 
//void mythread(promise<int> &tmp, int calc)
//{
//	//��һϵ�и�������
//	calc++;
//	calc *= 100;
//	chrono::milliseconds dura(500);
//	this_thread::sleep_for(dura);
//
//	int result = calc;
//	tmp.set_value(result);//������浽��tmp�����С�
//
//	return;
//}
//
//void mythread2(future<int> &tmpf)
//{
//	auto result = tmpf.get();
//	cout << "My thread2 result = " << result << endl;
//	return;
//}
//
//int main()
//{
	//һ��std::async��std::future������̨���񲢷���ֵ
	//ϣ���̷߳���һ�������
	//std::async��һ������ģ�棬��������һ���첽���������󷵻�һ��std::future����std::future�Ǹ���ģ��
	//����һ���첽���񣬾����Զ�����һ���̲߳���ʼִ�ж�Ӧ���߳���ں�����������һ��std::future����
		//���std::future��������ͺ����߳���ں��������صĽ�����̷߳��صĽ���������ǿ���ͨ������future����ĳ�Ա����get()����ȡ�����
		//"future":��������˼������Ҳ�ƺ�std::future�ṩ��һ�ַ����첽��������Ļ��ƣ�����˵����������û�취���ϵõ���
		//���߳�ִ����Ϻ󣬿����õ������
		//������⣺future�����б�����һ������ĳ��ʱ�����õ���ֵ

	//���к���ͨ��std::future�Ķ���get()��Ա�����ȴ��߳�ִ�н��������ؽ����
	//get()һֱ����ֱ���õ�����ֵ 
	//std::thread
	//����ͨ��������std::async()����һ���������ò���������std::lunnch���ͣ�ö�����ͣ������ﵽһЩĿ�ġ�
	//a)std::launch::deferred:��ʾ�߳���ں������ñ��ӳٵ�std::future��wait()��get()�������ò�ִ�У����ӳ�ִ�С�
		//��wait()��get()δִ��,�̲߳�ִ�У�ʵ����δ����)
		//std::launch::deferred:�ӳٵ��ã���û�д������̣߳����������߳��е����߳���ں�����
	//b)std::launch::async,�ڵ���async������ʱ��Ϳ�ʼ�����̡߳�
		//async()����Ĭ��ʹ��std::launch::async�������

	//  ��std::launch::async
	//	��֤�첽��Ϊ�������ݺ������ڵ������߳���ִ��
	//	��std::launch::deferred
	//	�������̵߳���get()�����ʹ���״̬ʱ�������÷��첽��Ϊ
	//	��std::launch::async | std::launch::deferred
	//  Ĭ����Ϊ����������������ԣ��������첽���л����У���ȡ����ϵͳ�ĸ��أ��������޷���������


	//����std::packaged_task:������񣬰������װ����
	//��ģ�壬�Ѹ��ֿɵ��ö����װ���������㽫����Ϊ�߳���ں�����
	//std::package_task��װ�����Ŀɵ��ö��󻹿���ֱ�ӵ��ã�������ǶȽ���packaged_task����Ҳ��һ���ɵ��ö���


	//����std::promise,��ģ��
	//�����ܹ���ĳ���߳��и�����ֵ��Ȼ������������߳���ȡ������
	//�ܽ᣺ͨ��promise����һ��ֵ���ڽ���ͨ����future��promise���������õ����ֵ��

	//�ġ�С�᣺������ô�ã�ʲôʱ����
	//������Ϊ����ȫ�õ�ʵ�ʿ����У�
	//�෴��д���ȶ���Ч�Ķ��̳߳�����á�
	//�Ķ�Դ�룬���۾��飬�����Լ���
	//�ڴ�ѧϰΪ�����Ķ�Դ����·��



	//A a;
	//int mypar = 12;

	/*cout << "main thread id" << this_thread::get_id() << endl;*/

	////future<int> result = async(mythread);
	////future<int> result = async(launch::deferred, &A::mythread, &a, mypar); //�ڶ��������Ƕ�������,���ܱ�֤�߳����õ���ͬһ������
	//future<int> result = async(launch::async, &A::mythread, &a, mypar);
	//cout << "continue....!" << endl;
	//int def;
	//def = 0;
	//cout << result.get() << endl; //��������ȴ�mythread()ִ����ϣ��õ����.ֻ�ܵ���һ�Σ���
	////result.wait(); //�ȴ��̷߳��أ��������ؽ��


	//packaged_task<int(int)> mypt(mythread);//���ǰѺ���mythread()ͨ��packaged_task��װ����
	//thread tl(ref(mypt), 1);//�߳�ֱ�ӿ�ʼִ�У��ڶ�������Ϊ�߳���ں����Ĳ�����
	//tl.join();
	//future<int> result = mypt.get_future();//std::future��������߳���ں����ķ��ؽ��������result����mythread�ķ���ֵ
	//cout << result.get() << endl;

	//packaged_task<int(int)> mypt([](int mypar) {
	//	cout << mypar;
	//	cout << "mythread id : " << this_thread::get_id() << endl;//��ӡ���߳�idֵ
	//	chrono::milliseconds dura(5000);//��Ϣ5��
	//	this_thread::sleep_for(dura);
	//	cout << "mythread end . thread id " << this_thread::get_id() << endl;
	//	return 5;
	//});
	//thread tl(ref(mypt), 1);//�߳�ֱ�ӿ�ʼִ�У��ڶ�������Ϊ�߳���ں����Ĳ�����
	//tl.join();
	//future<int> result = mypt.get_future();//std::future��������߳���ں����ķ��ؽ��������result����mythread�ķ���ֵ
	//cout << result.get() << endl;

	//mypt(105);//ֱ�ӵ��ã��൱�ں�������
	//future<int> result = mypt.get_future();
	//cout << result.get() << endl;

	//mytask.push_back(move(mypt));
	//packaged_task<int(int)> mypt2;
	//auto iter = mytask.begin();
	//mypt2 = move(*iter);//�ƶ�����
	//mytask.erase(iter);//ɾ����һ��Ԫ�أ�����������ʹ��iter
	//mypt2(123);
	//future<int> result = mypt2.get_future();
	//cout << result.get() << endl;

//	promise<int> myprom;//����һ��std::promise����myprom������ֵ����Ϊint
//	thread t1(mythread, ref(myprom), 180);
//	t1.join();
//	future<int> ful = myprom.get_future(); //promise��future�����ڻ�ȡ�̷߳���ֵ��
//	//auto result = ful.get();//get()ֻ�ܵ���һ��
//	//cout << "result = " << result << endl;
//
//	thread t2(mythread2, ref(ful));
//	t2.join();
//	cout << "my thread2 end" << endl;
//
//	cout << "I LOVE CHINA!" << endl;
//}