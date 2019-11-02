#include <bits/stdc++.h>
using namespace std;
 
 
double check(double n, vector<double> &v){
    double res = 0;
    double pos = 0;
    double neg = 0;
    for(int c=0;c<v.size();c++){
        pos += (v[c]-n);
        neg += (v[c]-n);
        if(pos < 0) pos = 0;
        if(neg > 0) neg = 0;
        res = max(res, max(pos,-neg));
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<double> v(n);
    for(int c=0;c<n;c++) cin>>v[c];
    double gauche = (*min_element(v.begin(),v.end())),droite = (*max_element(v.begin(),v.end()));
    while(1) {
        double leftThird = (droite-gauche)/3+gauche;
        double rightThird = droite - (droite-gauche)/3;
        double res1 = check(leftThird,v);
        double res2 = check(rightThird,v);
        if(res1 < res2){
            droite = rightThird;
        } else {
            gauche = leftThird;
        }
        if(abs(res1-res2) <= 1e-7 && abs(leftThird-rightThird) <= 1e-7) {
            gauche = droite = leftThird;
            break;
        }
    }
    cout<<fixed<<setprecision(15)<<check(gauche,v);
}