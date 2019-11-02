#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
	double d,L,v1,v2;
	cin>>d>>L>>v1>>v2;
	double gauche = 0, droite = 10000000;
	while(abs(gauche-droite) >= 1e-8){
		double mid = gauche + droite;
		mid /= 2;
		double x1 = v1*mid;
		double x2 = L-v2*mid;
		
		if(x1 + d >= x2) {
			droite = mid;
		} else {
			gauche = mid;
		}
	}
	
	cout<<fixed<<setprecision(13)<<gauche;
} 