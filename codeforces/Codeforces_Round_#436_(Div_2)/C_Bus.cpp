#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main() {
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int res = 0;
    int act = b;
    for(int c=0;c<k;c++) {
        int ecart = (c%2==0?f:a-f);
        int rev = a-ecart;
 
        if(act >= a + rev || (act >= a && c+1 == k)) {
            act -= a;
        } else if(act >= ecart && b >= rev) {
            res++;
            act = b - rev;
        } else {
            cout<<-1;
            return 0;
        }
    }
 
    cout<<res;
    return 0;
}