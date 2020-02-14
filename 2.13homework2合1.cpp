//今天任务1：子类对象父类指针实现多态效果。实现虚析构。实现 隐藏。作业2：实现纯虚函数
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
	cout<<"调用了Human::Human()"<<endl;
}
void Human::eat()
{
	cout<<"人吃饭"<<endl;
}
Human::~Human()
{
	cout<<"调用了Human::~Human()"<<endl;
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
	cout<<"男人吃饭"<<endl;
}
void Men::eat2()
{
	cout<<"男人吃大米饭"<<endl;
}
Men::Men()
{
	cout<<"调用了Men::Men()"<<endl;
}
Men::~Men()
{
	cout<<"调用了Men::~Men()"<<endl;
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