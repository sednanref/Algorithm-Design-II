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
	solution_is_better, compair two solutions by their evaluation function.
*/
bool solution_is_better(pair< vector < int> , long long int> a,
						pair< vector < int> , long long int> b){
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
	//clear the neighbourhood.
	neighbourhood.clear();
	//clear the movements set and list.
	movements_set.clear();
	movements_list.clear();
	//auxiliar solution to generate the neighbourhood.
	vector <int> aux_solution;
	//number of neighbours to generate.
	int neighbours_num = n*(n-1)/2;
	
	//neighbourhood generation loop.
	for (int i=0; i < n - 1; i++ ){
		for(int j = i+1; j < n; j++){
			//making the movement pair.
			pair <int, int> aux_pair = make_pair(i, j);
			//insert the movements in the movements_set and movements_list
			movements_set.insert(aux_pair);
			movements_list.push_back(aux_pair);
			//generate the auxiliar solution
			aux_solution = solution;
			//save the value in aux_solution[a]
			int aux = aux_solution[i];
			//swap the values in aux_solution
			aux_solution[i] = aux_solution[j];
			aux_solution[j] = aux;
			//save this solution into the neighbourhood (with its evaluation)
			neighbourhood.push_back(make_pair(aux_solution, evaluation_function(aux_solution)));
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
	//index of the best value in the neighbourhood.
	int best_index = -1;
	//best value in the local search, 
	//initialized with the value of the initial solution
	long long int best_value = evaluation_function(solution);
	//Best solution of the neighbourhood of the actual solution,
	//initialized with the initial solution.
	vector <int> best_neighbourhood_solution = solution;
	//Number of iterations as the stop condition.
	int iterations = 1;
	

	for(int k = 1; k <= iterations; k++){
		//generate a neighbourhood of the actual solution.
		generate_evaluated_neighbourhood(solution);
		
		//explore the neighbourhood
		for(int j = 0; j < neighbourhood.size(); j++){
			if(neighbourhood[j].second < best_value){
				best_neighbourhood_solution = neighbourhood[j].first;
				best_value = neighbourhood[j].second;
				best_index = j;
			}
		}
		if(best_index!=-1){
			print_solution(solution);
			cout<<movements_list[best_index].first<<" "<<movements_list[best_index].second<<endl;
			print_solution(best_neighbourhood_solution);
		}


		//Loof for the best solution in the neighbourhood.
		/*for(int i = 0; i < neighbourhood.size(); i++){
			
			if(neighbourhood[i].second < best_value){
				best_neighbourhood_solution = neighbourhood[i].first;
				best_value = neighbourhood[i].second;
			}
		}
	
		//Update the actual solution.
		solution = best_neighbourhood_solution;
		//cout<<"Iteration "<<k<<":"<<endl;
		print_solution(solution);
		cout<<evaluation_function(solution)<<endl;
		*/
	}
}


int main(){
	//read the input
	read_input();
	//get a solution
	//randomize the seed with the actual time.
	srand(time(0));
	random_solution();
	//greedy_solution();
	
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
	//cout<<evaluation_function(best_solution)<<endl;
}