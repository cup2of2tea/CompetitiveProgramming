#include <iostream>
#include <vector>
 
 
using namespace std;
 
int main() {
  long long a, b;
  cin>>a>>b;
  if(a==b) {
      cout<<1;
      return 0;
  }
  a++;
  
  long long tmp = a%10;
  long long tmp2 = b%10;
 
   if(tmp2 < tmp|| a + 5 <= b) cout<<0;
  else {
    long long res = tmp;
    for(int c=tmp+1;c<=tmp2;c++) {
      res *= c;
    }
    cout<<res%10;
  }
}