#include <bits/stdc++.h>


vector<int>  random_solution(){
	vector<int> solution;

	for(int i = 0; i < 10; i++) solution.push_back(i);

	random_shuffle(solution.begin(), solution.end());

	return solution;
	
}