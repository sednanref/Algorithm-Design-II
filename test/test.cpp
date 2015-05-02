#include <bits/stdc++.h>
//#include "qap_utils.h"
using namespace std;

//Size of the problem.
int n;
//Vector with a Solution for the problem.
vector<int> solution;
//Matrix with the flow of the problem.
vector< vector <int> > flow_matrix;
//Matrix with the distance of the problem.
vector< vector <int> > distance_matrix;



/*
	Function that returns a random solution.x
*/
void random_solution(){
	
	for(int i = 0; i < n; i++) solution.push_back(i);
	//randomize the seed with the actual time.
	srand(time(0)); 
	//randomize the solution.
	random_shuffle(solution.begin(), solution.end());	
}

int objective_function(){
	int cost = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			cost = cost + flow_matrix[i][j] * 
			distance_matrix[solution[i]][solution[j]];
		}
	}
	return cost<<1;
}

int main(){
	//read the size of the problem.
	cin>>n;

	//read the flow matrix
	flow_matrix.resize(n);
	for(int i = 0; i < n; i++){
		flow_matrix[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>flow_matrix[i][j];
		}
	}

	//read the distance matrix
	distance_matrix.resize(n);
	for(int i = 0; i < n; i++){
		distance_matrix[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>distance_matrix[i][j];
		}
	}

	//OUTPUT
	cout<<n<<endl<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<flow_matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<distance_matrix[i][j]<<" ";
		}
		cout<<endl;
	}

	//get a solution
	random_solution();
/*	for chr12a.dat
	solution.clear();
	solution.push_back(6);
	solution.push_back(4);
	solution.push_back(11);
	solution.push_back(1);
	solution.push_back(0);
	solution.push_back(2);
	solution.push_back(8);
	solution.push_back(10);
	solution.push_back(9);
	solution.push_back(5);
	solution.push_back(7);
	solution.push_back(3);
*/
/*	for esc16a.
	solution.push_back(1);
	solution.push_back(13);
	solution.push_back(9);
	solution.push_back(15);
	solution.push_back(4);
	solution.push_back(2);
	solution.push_back(6);
	solution.push_back(7);
	solution.push_back(3);
	solution.push_back(5);
	solution.push_back(11);
	solution.push_back(10);	
	solution.push_back(14);
	solution.push_back(12);
	solution.push_back(8);
	solution.push_back(0);	
*/			
	//output
	for(int i = 0; i < n; i++){
		cout<<solution[i]+1<<" ";
	}

	cout<<"    "<<objective_function()<<endl;
}