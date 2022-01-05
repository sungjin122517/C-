#include <iostream>		/* File: num-zeros-main.cpp */
using namespace std;	

int num_zeros(int n)
{
  cout << "num_zeros(" << n << ")" << endl;
    if (n==0)
      return 1;
    if (n>0 && n<10)
      return 0;
    return num_zeros(n/10) + num_zeros(n%10);
}

int main()	
{
    int n;

    while (cin >> n)
		cout << "num_zeros(" << n << ") = " << num_zeros(n) << endl;
	
    return 0;
}
