#include <bits/stdc++.h>
using namespace std;
 
 
 
int main()
{
#ifndef ONLINE_JUDGE
//    #define cin in
//    ifstream in("input.txt");
#endif // ONLINE_JUDGE
    vector<int> primes;
    for(int c=2;c<=50;c++) {
        for(int c2=0;c2<primes.size();c2++) {
            if(c%primes[c2]==0) goto nop;
        }
        primes.push_back(c);
 
        nop:;
    }
 
    int bla=0;
 
    for(int c=0;c<primes.size();c++) {
        cout<<primes[c]<<endl;
        cout.flush();
        string res;
        cin>>res;
        if(res=="yes") {
            bla++;
        }
    }
 
    for(int c=0;primes[c]*primes[c]<=100;c++) {
        cout<<primes[c]*primes[c]<<endl;
        cout.flush();
        string res;
        cin>>res;
        if(res=="yes") {
            cout<<"composite"<<endl;
            return 0;
        }
    }
    if(bla > 1) {
        cout<<"composite"<<endl;
    } else {
        cout<<"prime"<<endl;
    }
 
}