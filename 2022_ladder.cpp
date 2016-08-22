#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
double x, y, c;
bool decision(double mid){
	double h1 = sqrt(x*x - mid*mid);
	double h2 = sqrt(y*y - mid*mid);
	double check = (h1*h2) / (h2 + h1);
	return c <= check;
}
int main(){
	while (cin >> x >> y >> c){
		double high = max(x, y);
		double low = 0;
		double mid;
		for (int i = 0; i < 10000; i++){
			mid = (high + low) / 2;
			if (decision(mid)){
				low = mid;
			}
			else{
				high = mid;
			}
		}
		printf("%.3f\n", mid);
	}
}
