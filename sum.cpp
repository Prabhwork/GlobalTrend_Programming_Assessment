# include <iostream>
using namespace std;
int sum_of_digits(int n)
{
return n == 0 ? 0 : n%10 + sum_of_digits(n/10) ;
}

int main()
{
int n;
cout << "Enter a number : ";
cin >> n;
cout << "Sum of digits is :"<< sum_of_digits(n) << endl;
return 0;
}