//ʵ��һ��vec�࣬vec����һ��Int*��Ա ʹ�ó�ʼ�������б���Ϊ���캯������ ����operator[]��ʵ�ֶ�ȡ�͸�ֵ
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
		cout << "���ó�ʼ���б��캯��" << endl;
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
		cout << "���õ��������캯��" << endl;
	}
	vec(int i1, int i2)
	{
		cout << "����2�������Ĺ��캯��" << endl;
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