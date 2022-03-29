//implementation of indirection of pointers
#include <iostream>

using namespace std;

int main()
{

	int x = 5;
	int *p = &x;
	int **q = &p;
	cout<<" x = "<<x<<"\np = "<<p<<"\nq = "<<q<<"\n*p = "<<*p<<"\n*q = "<<*q<<"\n**q = "<<**q<<endl;

	return 0;
}
