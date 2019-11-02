#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int main() {
    int trash;
    string s;
    cin>>trash>>s;
    vector<bool> present(26,false);
 
    int gauche = 0, droite = 0;
    int res = 0;
    int act = 0;
    for(droite = 0; droite < s.size(); droite++) {
        if(s[droite]>='A' && s[droite]<='Z') {
            for(int c2=0;c2<26;c2++) present[c2] = 0;
            act = 0;
        } else {
            if(!present[s[droite]-'a']){
                present[s[droite]-'a']=true;
                act++;
            }
            res = max(res, act);
        }
    }
    cout<<res;
    return 0;
}