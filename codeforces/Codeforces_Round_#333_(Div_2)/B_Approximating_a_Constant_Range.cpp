#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    int one = -1;
    int two = -1;
    int lastOne = -1;
    int lastTwo = -1;
    int firstOne = -1;
    int firstTwo = -1;
    int res = 0;
    for(int c=0;c<n;c++) {
        if(one == v[c]) {
            lastOne = c;
        } else if(two == v[c]) {
            lastTwo = c;
        }else if(one == -1){
          one = v[c];
          firstOne = lastOne = c;
        } else if(two == -1) {
            if(abs(one-v[c]) > 1){
                one = v[c];
                firstOne = lastOne = c;
            } else {
                two = v[c];
                firstTwo = lastTwo = c;
            }
        } else {
            if(lastOne > lastTwo) {
                firstOne = max(lastTwo+1,firstOne);
                if(abs(v[c]-one) <= 1) {
                    lastTwo = firstTwo = c;
                    two = v[c];
                } else {
                    lastTwo = firstTwo = -1;
                    two = -1;
                }
            } else {
                firstTwo = max(lastOne+1,firstTwo);
                if(abs(v[c]-two) <= 1) {
                    lastOne = firstOne = c;
                    one = v[c];
                } else {
                    lastOne = firstOne = -1;
                    one = -1;
                }
            }
        }
        
        if(one != -1) {
            res = max(res, lastOne-firstOne+1);
        }
        if(two != -1) {
            res = max(res, lastTwo-firstTwo+1);
        }
        if(two != -1 && one != -1) {
            res = max(res, max(lastTwo,lastOne)-min(firstTwo,firstOne)+1);
        }
    }
    cout<<res;
}