#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N,r;
    cin>>N>>r;
    vector<int> v(N);
    for(int c=0;c<N;c++) cin>>v[c];
 
    int i = 0;
    int res = 0;
    while(i < N) {
        int previousI = i;
        for(int c=min(N-1,i+r-1);c>=max(0,i-r+1);c--) {
            if(v[c] == 1){
                res++;
                i = c+r;
                break;
            }
        }
        if(previousI == i) {
            cout<<-1;
            return 0;
        }
    }
    cout<<res;
 
}