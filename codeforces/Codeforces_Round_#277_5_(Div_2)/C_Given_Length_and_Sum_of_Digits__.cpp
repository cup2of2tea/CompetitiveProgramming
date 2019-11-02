#include <iostream>
 
using namespace std;
 
int main() {
  int m,s;
  cin>>m>>s;
  if(m*9 < s) {
    cout<<"-1 -1";
    return 0;
  }
  if(s == 0) {
    if(m == 1){
      cout<<"0 0";
      return 0;
    } else {
      cout<<"-1 -1";
      return 0;
    }
  } else {
    int sori = s;
 
    for(int c=0;c<m;c++) {
      int d = max(s-(m-c-1)*9,(c==0?1:0));
      cout<<d;
      s-=d;
    }
    cout<<" ";
    s=sori;
    for(int c=0;c<m;c++) {
        int d = min(s,9);
        cout<<d;
        s-=d;
    }
  }
}