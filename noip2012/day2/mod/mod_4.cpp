// 4 Point getted
#include <iostream>
using namespace std;
int main()
{
	int a, b, i;
	cin >> a >> b;
	i = 0;
	while ( true ) {
		i++;
		if ( a * i % b == 1 )
			break;
	}
	cout << i << endl;
	return 0;
}		
