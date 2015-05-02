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


/*
	Evaluation Function of the problem.
*/
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

/*
	Function to determine the order of a pair.
*/
bool pair_is_less(pair <int, float> a, pair <int, float> b){
	return a.second < b.second;
}


/*
	Procedure that generates a Greedy Solution to the problem.
*/
void greedy_solution(){
	vector< pair <int, float> > facilities_total_flow;
	vector< pair <int, float> > location_total_distances;

	/*Getting the total flow of each facility*/
	for(int i = 0; i < n; i++){
		float total_flow = 0;
		float count_zero = -1;
		for(int j = 0; j < n; j++){
			total_flow += flow_matrix[i][j];
			if(flow_matrix[i][j] == 0){
				count_zero++;
			}
		}
		cout<<count_zero/(n-1)<<endl;
		facilities_total_flow.push_back(make_pair(i,total_flow*(n-1/count_zero)));
	}

	sort(facilities_total_flow.begin(), facilities_total_flow.end(), pair_is_less);

	for(int i = 0; i < n; i++){
		cout<<facilities_total_flow[i].first<<" "<<
			facilities_total_flow[i].second<<endl;
	}

	cout<<"-------------"<<endl;
	/*Getting the total distance of each location*/
	for(int i = 0; i < n; i++){
		int total_distance = 0;
		for(int j = 0; j < n; j++){
			total_distance += distance_matrix[i][j];
		}
		location_total_distances.push_back(make_pair(i,total_distance));
	}

	sort(location_total_distances.begin(), location_total_distances.end(), pair_is_less);

	for(int i = 0; i < n; i++){
		cout<<location_total_distances[i].first<<" "<<
		location_total_distances[i].second<<endl;
	}
	cout<<"-------------"<<endl;
	//Building the solution
	solution.resize(n);
	for(int i = 0; i < n; i++){
		solution[facilities_total_flow[n-i].first] = location_total_distances[i].first;
	}


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

	//Printin Matrixes
/*	cout<<n<<endl<<endl;
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
*/
	//get a solution
	//random_solution();
	greedy_solution();
//	for chr12a.dat
/*	solution.clear();
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