#include <bits/stdc++.h>
//#include "qap_utils.h"
using namespace std;

vector<int> solution;


vector<int>  random_solution(){
	
	for(int i = 0; i < 10; i++) solution.push_back(i);

	//randomize the seed with the actual time.
	srand(time(0)); 
	//randomize the solution.
	random_shuffle(solution.begin(), solution.end());

	return solution;
	
}

int main(){


	for(int i = 0; i < 10; i++){
		cout<<solution[i]<<endl;
	}
	//cout<<rand()<<endl;
}