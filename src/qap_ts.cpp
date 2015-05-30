#include <bits/stdc++.h>
using namespace std;

//Size of the problem.
int n;
//Vector with a Solution for the problem.
vector<int> solution;
//Vector with the best Solution achieved for the problem.
vector<int> best_solution;
//Value of the best Solution achieved for the problem.
long long int best_value;
//Matrix with the flow of the problem.
vector< vector <long long int> > flow_matrix;
//Matrix with the distance of the problem.
vector< vector <long long int> > distance_matrix;
//Vector with the neighbourhood and their evaluation.
vector< pair < vector <int> , long long int > > neighbourhood;
//Tabu List Size
int tl_size;
//movements done to generate the neighbourhood.
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
	Procedure that generate the movement list just once.
*/
void generate_movement_list(){
	for (int i=0; i < n - 1; i++ ){
		for(int j = i+1; j < n; j++){
			//insert the movements in the movements_list
			movements_list.push_back(make_pair(i, j));
		}
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
	//auxiliar solution to generate the neighbourhood.
	vector <int> aux_solution;
	
	
	//neighbourhood generation loop.
	for (int i=0; i < movements_list.size(); i++ ){
		pair <int, int > aux_pair = movements_list[i];
		//generate the auxiliar solution
		aux_solution = solution;
		//save the value in aux_solution[a]
		int aux = aux_solution[aux_pair.first];
		//swap the values in aux_solution
		aux_solution[aux_pair.first] = aux_solution[aux_pair.second];
		aux_solution[aux_pair.second] = aux;
		//save this solution into the neighbourhood (with its evaluation)
		neighbourhood.push_back(make_pair(aux_solution, evaluation_function(aux_solution)));
		
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
	best_value = evaluation_function(solution);
	//best solution achieved at the moment, initialized with the first one.
	best_solution = solution;
	//Number of iterations as the stop condition.
	int iterations = 20;
	//set for the tabu list.
	set < pair <int, int> > tabu_set;
	//set of the tabu list.
	queue < pair <int, int> > tabu_list;

	

	for(int k = 1; k <= iterations; k++){

		cout<<"Iteration "<<k<<":"<<endl;
		cout<<"Tabu List: "<<endl;
		for(int r=0; r < tabu_list.size();r++){
			pair<int,int> pa = tabu_list.front();
			tabu_list.pop();
			tabu_list.push(pa);
			cout<<pa.first<<" "<<pa.second<<endl;
		}
		cout<<"Actual Solution: ";
		print_solution(solution);
		cout<<evaluation_function(solution)<<endl;
		//generate a neighbourhood of the actual solution.
		generate_evaluated_neighbourhood(solution);
		//best value of the neighbourhood.
		vector <int> best_neighbourhood_solution = neighbourhood[0].first;
		//best value of the neighbourhood.
		int best_neighbourhood_value = neighbourhood[0].second;
		//value to see if a better solution than the best is achieved.
		bool exists_a_better = false;
		//The best solution will be the initial solution, so the best value.
		best_solution = solution;
		//movement made, initialized with the first possible move.
		pair <int, int> movement_made = movements_list[0];
		
		//explore the neighbourhood
		for(int j = 1; j < movements_list.size(); j++){
			//if the solution has a better value than the best solution
			if(neighbourhood[j].second < best_value){
				//change the actual solution, it doesn't matter if it is
				//in the tabu list or not.
				cout<<"*Changed with: ";
				cout<<movements_list[j].first<<" "<<movements_list[j].second<<endl;
				solution = neighbourhood[j].first;
				print_solution(solution);
				best_value = neighbourhood[j].second;
				cout<<best_value<<endl;
				exists_a_better = true;
				//save it as the best solution too.
				best_solution = solution;
			//try to find if it is the better of the neighbourhood.
			}else if(neighbourhood[j].second < best_neighbourhood_value){
				//if the movement is not in the tabu list...
				if(tabu_set.find(movements_list[j]) == tabu_set.end()){
					//take that solution as the best in the neighbourhood.
					best_neighbourhood_solution = neighbourhood[j].first;
					best_neighbourhood_value = neighbourhood[j].second;

					movement_made = movements_list[j];
				//if the movement is in the tabu list, don't do it!
				}else{
					continue;
				}
			}
		}
		
		//if a better solution was encountered, jump to the start of the loop.
		if(exists_a_better){
			cout<<"Existed a better."<<endl;
			continue;
		}

		cout<<"Changed with: ";
		solution = best_neighbourhood_solution;
		print_solution(solution);
		//add the movement made to the tabu set and list.
		tabu_set.insert(movement_made);
		tabu_list.push(movement_made);
		//if the tabu list has achieved its maximun size
		if(tabu_list.size()==n){
			//take the first element from the list, 
			//(to remove it later from the set)
			pair<int,int> aux_movement = tabu_list.front();
			//remove that element from the list.
			tabu_list.pop();
			//remove that element from the set.
			tabu_set.erase(tabu_set.find(aux_movement));

		}

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
	//generate the movement list.
	generate_movement_list();
	//Do the local search.
	tabu_search();
	//cout<<"Local search Solution: ";
	print_solution(best_solution);
	cout<<best_value<<endl;

	
	//cout<<"Best Solution Achieved: "<<endl;
	//print_solution(best_solution);
	//cout<<evaluation_function(best_solution)<<endl;
}