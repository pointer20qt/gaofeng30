//��������1�����������ָ��ʵ�ֶ�̬Ч����ʵ����������ʵ�� ���ء���ҵ2��ʵ�ִ��麯��
#include<iostream>
using namespace std;
class Human
{
public:
	Human();
	virtual ~Human();
public:
	virtual void eat();
	virtual void eat2()=0;
};
Human::Human()
{
	cout<<"������Human::Human()"<<endl;
}
void Human::eat()
{
	cout<<"�˳Է�"<<endl;
}
Human::~Human()
{
	cout<<"������Human::~Human()"<<endl;
}

class Men:public Human
{
public:
	Men();
	~Men();
public:
	virtual void eat();
	virtual void eat2();
};
void Men::eat()
{
	cout<<"���˳Է�"<<endl;
}
void Men::eat2()
{
	cout<<"���˳Դ��׷�"<<endl;
}
Men::Men()
{
	cout<<"������Men::Men()"<<endl;
}
Men::~Men()
{
	cout<<"������Men::~Men()"<<endl;
}
int main()
{
	Human *p=new Men();
	p->eat();
	delete p;

	Human*p2=new Men();
	p2->eat2();
	delete p2;

	Men *p3=new Men();
	 delete p3;
	Human *p4=new Men();
	delete p4;
	return 0;

}