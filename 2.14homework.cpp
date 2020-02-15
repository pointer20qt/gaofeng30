//实现一个vec类，vec类有一个Int*成员 使用初始化参数列表作为构造函数参数 重载operator[]来实现读取和赋值
#include <iostream>
using namespace std;
#include <vector>
#include<Initializer_List>
#include<assert.h>
class vec{
	int *ve;
	int num;
public:
	vec(const initializer_list<int>& list)
	{
		cout << "调用初始化列表构造函数" << endl;
		ve = new int[list.size()];
		num=list.size();
		for (int i = 0; i < list.size();i++)
		{
			ve[i] = *(list.begin() + i);
		}
		for (int i = 0; i <list.size(); i++)
		{
			cout << ve[i] << " " << endl;
		}
	}
	vec(int i1)
	{
		cout << "调用单参数构造函数" << endl;
	}
	vec(int i1, int i2)
	{
		cout << "调用2个参数的构造函数" << endl;
	}
	int& operator[](int index)
	{
		assert(index >=0&&index<num);
		return ve[index];
	}
};


int main()
{

	vector<int> v = {1,2,3,4,5};
	vec ve = { 1, 2, 3, 4, 5 };
	cout<<v[-1]<<endl;
	system("pause");
	return 0;
}