#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 20;
	srand (time(NULL));
	int a = rand() % n + 1;
	int b = rand() % n + 1;
	while(b == a){
		b = rand() % n + 1;
	}

	cout<<a<<" "<<b<<endl;

	return 0;
}