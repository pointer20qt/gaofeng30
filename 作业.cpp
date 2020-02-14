#include <iostream>
using namespace std;
 
class Base_J 
{
public:
	Base_J()
	{
		cout << "Base Created" << endl;
	}
	virtual ~Base_J()
	{
		cout << "Base Destroyed" << endl;
	}
};
 
class Derived_J : public Base_J
{
public:
	Derived_J()
	{
		cout << "Derived Created" << endl;
	}
	~Derived_J()
	{
		cout << "Derived Destroyed" << endl;
	}
};
 
int main()
{
	Base_J *pB = new Derived_J();
	delete pB;
	pB = NULL;
	system("pause");
	return 0;
}