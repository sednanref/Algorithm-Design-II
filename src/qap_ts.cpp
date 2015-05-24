#include <bits/stdc++.h>
using namespace std;

//Size of the problem.
int n;
//Vector with a Solution for the problem.
vector<int> solution;
//Vector with the best Solution achieved for the problem.
vector<int> best_solution;
//Matrix with the flow of the problem.
vector< vector <long long int> > flow_matrix;
//Matrix with the distance of the problem.
vector< vector <long long int> > distance_matrix;
//Vector with the neighbourhood and their evaluation.
vector< pair < vector <int> , long long int > > neighbourhood;
//Tabu List Size
int tl_size;
//movements done to generate the neighbourhood.
set < pair <int, int> > movements_set;
vector < pair <int, int> > movements_list;


/*
	Procedure that reads the input.
*/
void read_input(){
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
}

/*
	Function that returns a random solution.x
*/
void random_solution(){
	//Assign to the i-th facility the i-th location.
	
	for(int i = 0; i < n; i++) solution.push_back(i);
	 
	//randomize the solution.
	random_shuffle(solution.begin(), solution.end());
}

/*
	Procedure that print the solution introduced by parameter.
*/
void print_solution(vector <int> sol){
	
	for (int i = 0; i < n; i++){
		cout<<sol[i]+1<<" ";
	}
	cout<<endl;

}

/*
	Evaluation Function of the problem.
*/
long long int evaluation_function(vector <int> sol){
	long long int cost = 0;
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			cost = cost + flow_matrix[i][j] * 
			distance_matrix[sol[i]][sol[j]];
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
	//Vector with the facilities and their total flow.
	vector< pair <int, long long int> > facilities_total_flow;
	//Vector with the locations and their total distance.
	vector< pair <int, long long int> > location_total_distances;

	//Getting the total flow of each facility
	for(int i = 0; i < n; i++){
		long long int total_flow = 0;
		for(int j = 0; j < n; j++){
			total_flow += flow_matrix[i][j];
		}
		facilities_total_flow.push_back(make_pair(i,total_flow));
	}

	//Sort the facilities by their total flow.
	sort(facilities_total_flow.begin(), facilities_total_flow.end(), pair_is_less);

	//Getting the total distance of each location
	for(int i = 0; i < n; i++){
		long long int total_distance = 0;
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
		solution[facilities_total_flow[n-1-i].first] = location_total_distances[i].first;
	}
}

/*
	Procedure that generates the neighbourhood of the actual solution,
	it also evaluate each neighbour solution and save it in the 
	neighbourhood vector. Every movement done to generate a new solution
	is saved in the movements list.
*/
void generate_evaluated_neighbourhood(vector <int> solution){
	int a, b; //auxiliar values to make the swap.
	//clear the neighbourhood.
	neighbourhood.clear();
	//clear the movements set and list.
	movements_set.clear();
	movements_list.clear();
	//neighbourhood generation loop.
	for (int i=0; i < n*n*n; i++ ){
		//generate to random values (to swap)
		a = (rand() % n) + 1;
		b = (rand() % n) + 1;
		//while b == a, generate another value for b.
		while (b == a) b = (rand() % n) + 1;
		//making the movement pair.
		pair <int, int> aux_pair = make_pair(a,b);
		//making the reverse pair, to avoid reversed pairs in the movements.
		pair <int, int> rev_aux_pair = make_pair(b,a);
		//if the pair is already in the movement set...
		if(movements_set.find(aux_pair) != movements_set.end() ||
		   movements_set.find(rev_aux_pair) != movements_set.end()){
		   	continue;	//go to look another movement.
		}else{ //if it is not already... 
			continue;
		}

	}

}

/*
	Tabu Search, initiate with an empty list of movements tabu,
	everytime a new solution is selected, the movement goes to the
	Tabu List, if a new movement is tried the algorithm try to avoid
	the movement at least it aprove the acceptation criteria.
*/
void tabu_search(){
	//best value in the local search, 
	//initialized with the value of the initial solution
	long long int best_value = evaluation_function(solution);
	//Best solution of the neighbourhood of the actual solution,
	//initialized with the initial solution.
	vector <int> best_neighbourhood_solution = solution;
	//Number of iterations as the stop condition.
	int iterations = 20;

	for(int k = 1; k <= iterations; k++){
		//generate a neighbourhood of the actual solution.
		generate_evaluated_neighbourhood(solution);
		bool solution_is_changed = false;
		//Loof for the best solution in the neighbourhood.
		for(int i = 0; i < neighbourhood.size(); i++){
			//
			if(neighbourhood[i].second < best_value){
				solution_is_changed = true;
				best_neighbourhood_solution = neighbourhood[i].first;
				best_value = neighbourhood[i].second;
			}
		}
		//If it doesn't find a better solution, quit the local search.
		if(!solution_is_changed) break;
		//Update the actual solution.
		solution = best_neighbourhood_solution;
		//cout<<"Iteration "<<k<<":"<<endl;
		/*print_solution(solution);
		cout<<evaluation_function(solution)<<endl;*/
	}
}


int main(){
	//read the input
	read_input();
	//get a solution
	//randomize the seed with the actual time.
	srand(time(0));
	//random_solution();
	greedy_solution();
	
	//cout<<"First Solution: ";
	//print_solution(solution);
	//cout<<evaluation_function(solution)<<endl;
	
	//Do the local search.
	tabu_search();
	//cout<<"Local search Solution: ";
	//print_solution(solution);
	//cout<<evaluation_function(solution)<<endl;

	
	//cout<<"Best Solution Achieved: "<<endl;
	//print_solution(best_solution);
	cout<<evaluation_function(best_solution)<<endl;
}