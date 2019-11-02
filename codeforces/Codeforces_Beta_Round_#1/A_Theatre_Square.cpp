#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
   unsigned long long int a,b,c;
   cin>>a>>b>>c;
   cout<<(a%c!=0?a/c+1:a/c)*(b%c!=0?b/c+1:b/c);
}