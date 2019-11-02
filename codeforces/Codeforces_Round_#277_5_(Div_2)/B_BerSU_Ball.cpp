#include <iostream>
#include <vector>
#include <algorithm>
 
 
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int> boys(n);
  for(int c=0;c<n;c++) cin>>boys[c];
  sort(boys.begin(),boys.end());
  int m;
  cin>>m;
  vector<int> girls(m);
  for(int c=0;c<m;c++) cin>>girls[c];
  sort(girls.begin(),girls.end());
 
  int i = 0, j = 0;
  int res = 0;
  for(i = 0; i < n; i++) {
    while(j<m && abs(boys[i]-girls[j]) > 1 && girls[j] < boys[i]) j++;
    if(abs(boys[i]-girls[j]) <= 1) {
      res++;
      j++;
    }
  }
  cout<<res;
}