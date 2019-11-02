#include <iostream>
#include <vector>
#include <algorithm>
 
 
using namespace std;
 
int main() {
  string s;
  cin>>s;
  int miniAB = 1e9, maxiAB = -1e9, miniBA = 1e9, maxiBA = -1e9;
  for(int c=0;c+1<s.size();c++) {
    if(s[c] == 'A' && s[c+1] == 'B') {
      miniAB = min(miniAB,c);
      maxiAB = max(maxiAB,c);
    }
    if(s[c] == 'B' && s[c+1] == 'A') {
      miniBA = min(miniBA,c);
      maxiBA = max(maxiBA,c);
    }
  }
  if(maxiAB >= 0 && maxiBA >= 0 && (miniAB + 1 < maxiBA || miniBA + 1 < maxiAB)){
    cout<<"YES";
  }
  else {
    cout<<"NO";
  }
}