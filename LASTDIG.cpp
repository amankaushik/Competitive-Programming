#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	int test; scanf("%d", &test);
	while(test--) { int a; long int b; scanf("%d%ld", &a, &b);
		if(a == 0 && b == 0) cout<<"1";
		else if(b == 0) cout<<"1";
		else { int aux, lastDigitA = a % 10;
			if(lastDigitA == 0 || lastDigitA == 1 || lastDigitA == 5 || lastDigitA == 6) cout<<lastDigitA;
			else if(lastDigitA == 4 || lastDigitA == 9) { aux = b % 2;
				cout<<(int)pow((double)lastDigitA, (double)aux) % 10; }
			else if (lastDigitA == 2 || lastDigitA == 3 || lastDigitA == 7 || lastDigitA == 8){ aux = b % 4;
				cout<<(int)pow((double)lastDigitA, (double)aux) % 10; }
		} printf("\n"); } return 0; }