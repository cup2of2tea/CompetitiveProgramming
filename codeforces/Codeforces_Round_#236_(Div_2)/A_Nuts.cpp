#include <iostream>
 
using namespace std;
 
int main()
{
  int k,a,b,v;
  cin>>k>>a>>b>>v;
  for(int c=0;;c++)
  {
    a-=(min(k,b+1))*v;
    a=max(a,0);
    b-=(k-1);
    b=max(b,0);
    if(a==0)
    {
      cout<<c+1;
      return 0;
    }
  }
}