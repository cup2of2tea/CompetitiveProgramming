#include <bits/stdc++.h>
using namespace std;
 
 
int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    double a,b;
    cin>>a>>b;
    if(a>b) {
        double res = 0;
        int gauche = 0, droite = a + 1;
        while(gauche < droite) {
            int mid = (gauche+droite+1)/2;
            if((double)(a-b)/(2.*mid) >= b){
                gauche = mid;
            } else {
                droite = mid - 1;
            }
        }
        res = (double)(a-b)/(2.*gauche);
        gauche = 0;
        droite = a + 1;
        while(gauche < droite) {
            int mid = (gauche+droite+1)/2;
            double tmp = (double)(a+b)/(2.*mid);
            if( tmp >= b && (a+b)-2*tmp >= 0){
                gauche = mid;
            } else {
                droite = mid - 1;
            }
        }
        res = min(res,(double)(a+b)/(2.*gauche));
        cout<<fixed<<setprecision(15)<<res;
    }
    else if(a==b) {
        cout<<fixed<<setprecision(15)<<a;
    } else {
        cout<<-1;
    }
}