#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <chrono>
 
using namespace std;
 
 
map<string,long long int> m;
 
long long int maAnswer(string s) {
    //cout<<"go "<<s<<endl;
    long long res = 0;
    for(int c=0;c<s.size();c++) {
            //cout<<"good lord "<<c<<endl;
        long long tmp = (long long)(s.size())-9-c;
        //if(tmp > 0) cout<<c<<endl;
        res += max(0LL,tmp);
        //cout<<res<<endl;
        long long int z = 0;
     //   cout<<c<<" "<<min((int)s.size()-c-1,8)<<endl;
        //string t = s.substr(c,min((int)s.size()-c,8));
   //     cout<<t<<endl;
        res += m[s.substr(c,min((int)s.size()-c,9))];
       // cout<<m[s.substr(c,min((int)s.size()-c,8))]<<endl;
       // cout<<"etape "<<c<<" "<<z<<endl;
        //cout<<res<<endl;
    }
    return res;
}
 
int oracle2(string s) {
    long long int res = 0;
    for(int c=0;c<=0;c++) {
        for(int c2=c;c2<s.size();c2++) {
                bool ok = false;
            for(int c3=c;!ok&&c3<s.size();c3++) {
                for(int c4=1;!ok&&c4<s.size();c4++) {
                    if(c4*2+c3<=c2) {
                        if(s[c3]==s[c4+c3]&&s[c3]==s[c4*2+c3]){
                            res++;
                            ok = true;
                            break;
                        }
                    }
                }
 
            }
        }
    }
    return res;
}
 
int oracle(string s) {
    int res = 0;
    for(int c=0;c<s.size();c++) {
        for(int c2=c;c2<s.size();c2++) {
                bool ok = false;
            for(int c3=c;!ok&&c3<s.size();c3++) {
                for(int c4=1;!ok&&c4<s.size();c4++) {
                    if(c4*2+c3<=c2) {
                        if(s[c3]==s[c4+c3]&&s[c3]==s[c4*2+c3]){
                            res++;
                            ok = true;
                            break;
                        }
                    }
                }
 
            }
        }
    }
    return res;
}
 
 
 
int main() {
 
    string s;
    cin>>s;
 
    for(int c=0;c<(1<<12);c++) {
        string s = "";
        for(int c2=0;c2<12;c2++){
            if((1<<c2)&c)s=s+'1';
            else s=s+'0';
            m[s]=oracle2(s);
//            cout<<s<<" "<<m[s]<<endl;
        }
 
    }
/*
    while(1) {
 
        int l = 1+rand()%100;
        s="";
        for(int c=0;c<l;c++) if(rand()%2) s=s+'1';
        else s=s+'0';
 
        int z = maAnswer(s);
        int z2 = oracle(s);
 
 
        if(z!=z2) {
            cout<<z<<" "<<z2<<endl;
            cout<<m[s]<<endl;
            cout<<s<<endl;
            return 0;
        } else {
        cout<<"ok";}
 
    }*/
    cout<<maAnswer(s);
 
 
 
    return 0;
}