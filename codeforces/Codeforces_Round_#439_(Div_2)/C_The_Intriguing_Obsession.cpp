#include <iostream>
#include <vector>
 
#define MOD 998244353
 
using namespace std;
 
long long int pascal[5002][5002];
 
void generatePascal() {
  pascal[0][0] = 1;
  for(int c=1;c<5002;c++) {
    for(int c2=0;c2<=c;c2++) {
      pascal[c][c2]=0;
      if(c2 > 0) pascal[c][c2]+=pascal[c-1][c2-1];
      if(c2 < c) pascal[c][c2]+=pascal[c-1][c2];
      pascal[c][c2] %= MOD;
      //cerr<<pascal[c][c2]<<" ";
    }
    //cerr<<endl;
  }
}
 
 
int main() {
  generatePascal();
  long long a,b,c;
  cin>>a>>b>>c;
  long long res = 1;
  long long fac[5002];
  fac[0] = 1;
  for(int i = 1 ; i < 5002;i++){fac[i]=static_cast<long long>(i)*fac[i-1];fac[i]%=MOD;}
  long long tmp = 0;
  for(int i = 0; i <= min(a,b); i++) {
    tmp+=(((pascal[a][i]*pascal[b][i])%MOD)*fac[i])%MOD;
    tmp%=MOD;
  }
  res*=tmp;
  res%=MOD;
  tmp=0;
  for(int i = 0; i <= min(c,b); i++) {
    tmp+=(((pascal[c][i]*pascal[b][i])%MOD)*fac[i])%MOD;
    tmp%=MOD;
  }
  res*=tmp;
  res%=MOD;
  tmp=0;
  for(int i = 0; i <= min(a,c); i++) {
    tmp+=(((pascal[a][i]*pascal[c][i])%MOD)*fac[i])%MOD;
    tmp%=MOD;
  }
  res*=tmp;
  res%=MOD;
  tmp=0;
  cout<<res;
}