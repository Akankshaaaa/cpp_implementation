//structure implementation
#include <iostream>

using namespace std;

struct Person{
	char name[100];
	int age;
	double salary;
};

int main()
{
	Person p1;
	cout<<"Enter Person name "<<endl;
	cin.getline(p1.name, 100);
	cout<<endl<<"Enter age"<<endl;
	cin>>p1.age;
	cout<<endl<<"Enter salary"<<endl;
	cin>>p1.salary;

	cout<<"\nPerson details : "<<endl<<p1.name<<endl<<p1.age<<endl<<p1.salary<<endl;
	return 0;
}
