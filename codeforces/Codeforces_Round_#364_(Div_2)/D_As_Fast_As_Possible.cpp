#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
 
using namespace std;
 
bool simulate(double objectif, int n, double l, double v1, double v2, int k) {
	double act = 0;
	double tact = 0;
	double xact = 0;
	for(int c=0;c<n;c+=k){
	    //cout<<act<<" "<<xact<<" "<<tact<<endl;
		if((l-xact)/v1 <= objectif-tact) return true;
		double timeTwo = (act-xact)/(v1+v2);
		//cout<<timeTwo<<endl;
		xact += timeTwo*v1;
		act = xact;
		tact += timeTwo;
		double tRemaining = objectif - tact;
		double xRemaining = l - xact;
		double tBus = (xRemaining - tRemaining*v1)/(v2-v1);
		if(tBus > tRemaining) return false;
		act += tBus*v2;
		tact += tBus;
		xact += tBus*v1;
	}
		    //cout<<act<<" "<<xact<<" "<<tact<<endl;
 
	if(tact > objectif) return false;
	return true;
}
 
 
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	int k;
	double l;
	double v1, v2;
 
	cin>>n>>l>>v1>>v2>>k;
 
	double gauche = 0, droite = l/v1;
	while(abs(gauche-droite) >= 1e-6) {
	    //cout<<gauche<<" "<<droite<<endl;
		double mid = (gauche+droite)/2.;
		if(simulate(mid,n,l,v1,v2,k)) {
			droite = mid;
		} else {
			gauche = mid;
		}
	}
	cout<<fixed<<setprecision(10)<<gauche;
}