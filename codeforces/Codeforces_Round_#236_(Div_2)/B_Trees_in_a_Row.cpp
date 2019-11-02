#include <iostream>
#include <vector>
#include <cmath>
 
using namespace std;
 
int main()
{
  int n,k;
  cin>>n>>k;
  vector<int> v(n);
  for(int c=0;c<n;c++)
  {
    cin>>v[c];
  }
  int best_cost = 100000000000;
  int best = -1;
  for(int c=1;c<2000;c++)
  {
    int act = 0;
    for(int c2=0;c2<n;c2++)
    {
      if(v[c2]!=(c+k*c2))
    act++;
    }
    if(act < best_cost)
    {
      best = c;
      best_cost = act;
    }
  }
  cout<<best_cost<<endl;
  for(int c=0;c<n;c++)
  {
    if(v[c]!=(best+k*c))
    {
      cout<<(v[c]<best+k*c?"+":"-")<<" "<<c+1<<" "<<abs(v[c]-(best+k*c))<<endl;
    }
  }
}