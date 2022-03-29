// arrays with struct
#include <iostream>
#include <string>

using namespace std;

struct Person{

	string name;
	int age;
	double salary;

};

int main()
{
	Person p[2];
	for(int i = 0; i < 2; i++)
	{
		cout<<"Enter details of person "<<i + 1<<endl;

		cin>>p[i].name;
		cin>>p[i].age;
		cin>>p[i].salary;
	}

	cout<<"\nPerson details : "<<endl;
	for(int i = 0; i < 2; i++)
	{
		cout<<"Details of person "<<i + 1<<endl;
		cout<<p[i].name<<endl;
		cout<<p[i].age<<endl;
		cout<<p[i].salary<<endl;
	}


	return 0;
}
