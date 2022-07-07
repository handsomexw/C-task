#include <iostream>
using namespace std;

int global_int=66;
int main()
{
	int local_int = 0;
	cout << global_int << " "<< local_int << endl;
	int global_int = 1;
	cout << global_int << " "<< local_int<< endl;
	cout << ::global_int << " " << local_int << endl;
	return 0;
}