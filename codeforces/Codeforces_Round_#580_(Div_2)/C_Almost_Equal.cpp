#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;
 
void bruteforce(int N){
    vector<int> v(2*N);
    for(int c=0;c<2*N;c++) v[c] = c+1;
    bool valid = false;
    do {
        vector<int> sums;
        for(int c=0;c<v.size();c++) {
            int act = 0;
            for(int c2=0;c2<N;c2++) {
                act += v[(c+c2)%v.size()];
            }
            sums.push_back(act);
        }
        if((*min_element(sums.begin(),sums.end())) + 1 < (*max_element(sums.begin(),sums.end()))) {
            continue;
        }
        valid = true;
        break;
 
    }while(next_permutation(v.begin(),v.end()));
    if(valid) {
        for(int c=0;c<v.size();c++) {
            cout<<v[c]<<" ";
        }
    } else {
    cout<<"NO";}
    cout<<endl;
}
 
vector<int> res;
 
 
 
void greedy(int N) {
    if(N%2==0) {
        cout<<"NO"<<endl;
        return ;
    }
    res.resize(2*N);
    int i = 1;
    long long int sum = 0;
    long long bigN = N*2LL;
    long long target = (bigN*(bigN+1))/2LL;
    target /= 2LL;
    for(int c=0;c<N;c++) {
        res[c]=i;
        if(i%2==0) {
            i++;
        } else {
            i+=3;
        }
        sum += res[c];
    }
    for(int c=0;c<N;c++) {
        if(sum <= target) {
            res[c+N] = res[c]+1;
        } else {
            res[c+N] = res[c]-1;
        }
        sum -= res[c];
        sum += res[c+N];
    }
    cout<<"YES"<<endl;
    for(int c=0;c<res.size();c++) {
        cout<<res[c]<<" ";
    }
}
 
 
int main() {
    int N;
    cin>>N;
    greedy(N);
}
 