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
//Vector with the neighbourhood and their evaluation.
vector< pair < vector <int> , int > > neighbourhood;


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
bool pair_is_less(pair <int, int> a, pair <int, int> b){
	return a.second < b.second;
}


/*
	Procedure that generates a Greedy Solution to the problem.
*/
void greedy_solution(){
	vector< pair <int, int> > facilities_total_flow;
	vector< pair <int, int> > location_total_distances;

	/*Getting the total flow of each facility*/
	for(int i = 0; i < n; i++){
		int total_flow = 0;
		for(int j = 0; j < n; j++){
			total_flow += flow_matrix[i][j];
		}
		facilities_total_flow.push_back(make_pair(i,total_flow));
	}
	//Sort the facilities by their total flow.
	sort(facilities_total_flow.begin(), facilities_total_flow.end(), pair_is_less);

	/*Getting the total distance of each location*/
	for(int i = 0; i < n; i++){
		int total_distance = 0;
		for(int j = 0; j < n; j++){
			total_distance += distance_matrix[i][j];
		}
		location_total_distances.push_back(make_pair(i,total_distance));
	}
	//Sort the locations by their total distance.
	sort(location_total_distances.begin(), location_total_distances.end(), pair_is_less);

	//Building the solution
	solution.resize(n);
	for(int i = 0; i < n; i++){
		solution[facilities_total_flow[n-i].first] = location_total_distances[i].first;
	}


}

void generate_neighbourhood(){
	//Auxiliar neighbour (for rotation)
	vector <int> aux_solution;
	//Auxiliar neighbour (for swaping)
	vector <int> aux_neighbour;

	//Copy the actual solution to the aux_solution.
	aux_solution = solution;
	/*Just testing.*/
	for(int i = 0; i < n; i++){
		cout<<aux_solution[i]<<" ";
	}
	cout<<endl;
	cout<<"-------------"<<endl;
	cout<<"Let's play: "<<endl;
	for(int i = 0; i < n; i++){
		//Copy the aux_solution to generate new neighbours
		aux_neighbour = aux_solution;


		for(int j = 0; j < n/2; j++){
			//Auxiliar to make the swap.
			int aux;
			//Swap the value of j with n - j
			aux = aux_neighbour[j];
			aux_neighbour[j] = aux_neighbour[n - j];
			aux_neighbour[n - j] = aux;
			//Add the swapped solution to the neighbourhood.
			neighbourhood.push_back(make_pair(aux_neighbour,0));
		}
		//Rotate the aux solution by one.
		rotate(aux_solution.begin(),aux_solution.begin()+1,aux_solution.end());
		//Add the rotated solution to the neighbourhood.
		neighbourhood.push_back(make_pair(aux_neighbour,0));
	}

	for(int i = 0; i < neighbourhood.size(); i++){
		vector <int> aux = neighbourhood[i].first;
		for(int j = 0; j < n; j++){
			cout<<aux[j]<<" ";
		}
		cout<<endl;
	}

}

void best_first_local_search(){


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
	generate_neighbourhood();
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