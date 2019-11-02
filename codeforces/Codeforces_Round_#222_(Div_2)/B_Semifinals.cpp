#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
 
int main()
{
  int n;
  cin>>n;
  vector<vector<pair<int,int> > > semi(2,vector<pair<int,int> > (n));
  vector<pair<int,int> > flat(2*n);
  for(int c=0;c<n;c++)
  {
    for(int c2=0;c2<2;c2++)
    {
      cin>>semi[c2][c].first;
      flat[c*2+c2].first=semi[c2][c].first;
      flat[c*2+c2].second=c*2+c2;
      semi[c2][c].second=c;
    }
  }
  for(int c=0;c<2;c++)
    sort(semi[c].begin(),semi[c].end());
  sort(flat.begin(),flat.end());
  vector<string> possible(2);
  for(int c=0;c<possible.size();c++)
  {
    possible[c].resize(n);
    for(int c2=0;c2<n;c2++) possible[c][c2]='0';
  }
  for(int c=0;2*c+1<n;c++)
  {
    possible[0][semi[0][c].second]='1';
    possible[1][semi[1][c].second]='1';
  }
  for(int c=0;c<n;c++)
  {
    possible[flat[c].second%2][flat[c].second/2]='1';
  }
  cout<<possible[0]<<endl<<possible[1];
}