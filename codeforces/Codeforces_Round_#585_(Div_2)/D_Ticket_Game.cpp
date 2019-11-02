#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
 
using namespace std;
 
 
int main() {
    ios_base::sync_with_stdio(false);
 
    int n;
    cin>>n;
    string s;
    cin>>s;
    int leftSlots = 0;
    int rightSlots = 0;
    int res = 0;
    for(int c=0;c<s.size();c++) {
        if(c*2 < s.size()){
            if(s[c]=='?') leftSlots++;
            else res -= (int)(s[c]-'0');
        }else{
            if(s[c]=='?') rightSlots++;
            else res += (int)(s[c]-'0');
        }
    }
 
 
    int r1 = (leftSlots+rightSlots+1)/2;
    int r2 = (leftSlots+rightSlots)/2;
    int left1 = (leftSlots/2);
    int left2 = (leftSlots - left1);
    r1 -= left1;
    r2 -= left2;
    int right1 = r1;
    int right2 = rightSlots - right1;
    if(res-(leftSlots*9) <= 0 && res-(left1)*9 + right2*9>= 0 && res+(rightSlots*9) >= 0 && res+right1*9-left2*9 <= 0){
        cout<<"Bicarp"<<endl;
        return 0;
    }
    else {
        cout<<"Monocarp"<<endl;
    }
 
}