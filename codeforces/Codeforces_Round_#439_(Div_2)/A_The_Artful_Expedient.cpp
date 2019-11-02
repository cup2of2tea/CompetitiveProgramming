#include <iostream>
#include <vector>
 
 
using namespace std;
 
int main() {
  int N;
  cin>>N;
  vector<bool> isPresent(2*1e6+1);
  vector<int> v(N);
  vector<int> v2(N);
  for(int c=0;c<N;c++){isPresent[v[c]]=true; cin>>v[c];}
  for(int c=0;c<N;c++){isPresent[v2[c]]=true; cin>>v2[c];}
  int res = 0;
  for(int c=0;c<N;c++) {
    for(int c2=0;c2<N;c2++){
      int tmp = v[c]^v2[c];
      if(tmp < isPresent.size() && isPresent[tmp]) res++;
    }
  }
  if(res%2==0) cout<<"Karen";
  else cout<<"Koyomi";
}