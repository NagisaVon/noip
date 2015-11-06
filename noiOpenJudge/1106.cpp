#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	char a;
	int b;
	float c;
	double d;
	cin >> a >> b >> c >> d;
	printf("%c %d %.06f %.06lf", a, b, c, d);
	
	return 0;
}
