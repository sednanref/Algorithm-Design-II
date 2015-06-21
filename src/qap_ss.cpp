#include <bits/stdc++.h>
using namespace std;
#define MAX_INT 999999
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
//evaluated population
vector< pair < vector <int> , long long int > > population;
//reference set vector
vector< pair < vector <int> , long long int > > reference_set_vector;
//reference set 
set< vector <int> > reference_set;
//subsets in the reference sets
vector < pair <pair < vector <int>, long long int>, pair < vector <int> , long long int> > > subsets;


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
	Procedure that print the solution introduced by parameter.
*/
void print_solution(vector <int> sol){
	
	for (int i = 0; i < n; i++){
		cout<<sol[i]+1<<" ";
	}
	cout<<endl;

}

/*
	solution_is_better, compair two solutions by their evaluation function.
*/
bool solution_is_better(pair< vector < int> , long long int> a,
						pair< vector < int> , long long int> b){
	return a.second < b.second;
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
	Procedure that generate the subsets list just once.
*/
void generate_subsets(){
	//clear the subsets.
	subsets.resize(0);
	for (int i=0; i < reference_set_vector.size() - 1; i++ ){
		for(int j = i+1; j < reference_set_vector.size(); j++){
			//insert the movements in the movements_list
			subsets.push_back(make_pair(reference_set_vector[i], reference_set_vector[j]));
		}
	}
}

/*
	Procedure that generates the neighbourhood of a solution,
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
	This Function receive a 
*/
pair <vector <int>, long long int> tabu_search(vector<int> solution){
	//best value in the local search, 
	//initialized with the value of the initial solution
	int best_value = evaluation_function(solution);
	//best solution in this function, initialized with the first one.
	vector <int> best_solution = solution;
	//Number of iterations as the stop condition.
	int iterations = 200;
	//set for the tabu list.
	set < pair <int, int> > tabu_set;
	//set of the tabu list.
	queue < pair <int, int> > tabu_list;

	//cleaning the tabu_set just in case.
	tabu_set.clear();
	
	for(int k = 1; k <= iterations; k++){
		//generate a neighbourhood of the actual solution.
		generate_evaluated_neighbourhood(solution);
		//best value of the neighbourhood.
		vector <int> best_neighbourhood_solution;
		//best value of the neighbourhood.
		int best_neighbourhood_value = MAX_INT;
		//value to see if a better solution than the best is achieved.
		bool exists_a_better = false;
		//The best solution will be the initial solution, so the best value.
		best_solution = solution;
		//movement made, initialized with the first possible move.
		pair <int, int> movement_made;
		//movement made in the neighbourhood with a "bad" solution.
		pair <int, int> movement_made_n = movements_list[0];
		
		
		//explore the neighbourhood
		for(int j = 0; j < movements_list.size(); j++){
			//if the solution has a better value than the best solution
			if(neighbourhood[j].second < best_value){
				//change the actual solution, it doesn't matter if it is
				//in the tabu list or not.
				solution = neighbourhood[j].first;
				best_value = neighbourhood[j].second;
				//save the movement made.
				movement_made = movements_list[j];
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
					//save the movement to made.
					movement_made_n = movements_list[j];
				//if the movement is in the tabu list, don't do it!
				}else{
					continue;
				}
			}
		}
				
		//if a better solution was encountered, jump to the start of the loop.
		if(exists_a_better){
			//if the movement is not in the tabu search, add it,
			//else simply continue to the next iteration.
			if(tabu_set.find(movement_made) == tabu_set.end()){
				//if the tabu list has achieved its maximun size
				if(tabu_list.size()==n){
					//take the first element from the list, 
					//(to remove it later from the set)
					pair<int,int> aux_movement = tabu_list.front();
					//remove that element from the list.
					tabu_list.pop();
					//remove that element from the set.
					tabu_set.erase(tabu_set.find(aux_movement));
				//if the tabu list isn't full...
				}else{
					//add the movement made to the tabu set and list.
					tabu_set.insert(movement_made);
					tabu_list.push(movement_made);	
				}
			}
			continue;
		}

		//if the tabu list has achieved its maximun size
		if(tabu_list.size()==n){
			//take the first element from the list, 
			//(to remove it later from the set)
			pair<int,int> aux_movement = tabu_list.front();
			//remove that element from the list.
			tabu_list.pop();
			//remove that element from the set.
			tabu_set.erase(tabu_set.find(aux_movement));
		//if the tabu list isn't full...
		}else{
			//add the movement made to the tabu set and list.
			tabu_set.insert(movement_made_n);
			tabu_list.push(movement_made_n);	
		}
		//change the solution with the best of the neighbourhood (not in tabu_list)
		solution = best_neighbourhood_solution;
	}

	return make_pair(best_solution, best_value);
}

/*
	Function that returns a random solution.x
*/
vector<int> random_solution(){

	vector<int> solution;
	//Assign to the i-th facility the i-th location.
	
	for(int i = 0; i < n; i++) solution.push_back(i);
	 
	//randomize the solution.
	random_shuffle(solution.begin(), solution.end());
	//return the created solution
	return solution;
}


/*
	Procedure that builds an initial population based on
	get "k" random solutions and rotate it to generate 
	good scattered solutions.
*/
void build_initial_population(int k){
	//clear the population, just in case
	population.resize(0);
	//set the best value as the MAX_INT value (worst value)
	best_value = MAX_INT;
	//outer loop, generate k random solutions
	for(int i = 0; i < k; i++){
		//generate a random solution
		vector <int> solution = random_solution();
		//get its objective function value
		long long int value = evaluation_function(solution);
		//if it is the best solution, save it
		if(value < best_value){
			best_value = value;
			best_solution = solution;
		}
		//add it to the population vector
		population.push_back(make_pair(solution, value));
		//inner loop, generation of the circular permutations of the solution
		for(int j = 1; j < n; j++){
			//rotate the solution by 1 element
			rotate(solution.begin(),solution.begin()+1, solution.end());
			//get its objective function value
			value = evaluation_function(solution);
			//if it is the best solution, save it
			if(value < best_value){
				best_value = value;
				best_solution = solution;
			}
			//add it to the population vector
			population.push_back(make_pair(solution, evaluation_function(solution)));

		}
	}
}

/*
	Procedure that build the reference set based on the evaluation function
	of the solutions in the population.
*/
void build_reference_set(int size){
	//clear the reference set vector and the reference set, just in case
	reference_set_vector.resize(size);
	reference_set.clear();
	//sort the population.
	sort(population.begin(), population.end(), solution_is_better);
	//add the best solutions to the reference set.
	for(int i = 0; i < size; i++){
		pair <vector <int>, long long int> solution = tabu_search(population[i].first);
		//if it is the best solution, save it
		if(solution.second < best_value){
			best_solution = solution.first;
			best_value = solution.second;
		}
		reference_set_vector[i] = solution;
		reference_set.insert(solution.first);
	}


}

/*
	Crossover procedure, the index of the subset vector, take random values to
	return two new child solutions.
*/
	
pair < vector <int>, vector <int> > crossover(int index){
	//generate random values for the indexes that will remain untouched.
	int k1 = rand() % n;
	int k2 = rand() % n;
	//readjust the indexes so k1 <= k2...
	if(k2 < k1){
		int aux = k1;
		k1 = k2;
		k2 = aux;
	}
	//get the parents
	vector<int> parent1 = subsets[index].first.first;
	vector<int> parent2 = subsets[index].second.first;

	//Generation of child 1;
	vector <int> child1;
	child1.resize(n, -1);
	//vector of used facilities.
	vector <bool> used_facilities;
	used_facilities.resize(n, false);

	//set the values of parent1 on child1
	for (int i = k1; i <= k2; i++){
		child1[i] = parent1[i];
		used_facilities[parent1[i]] = true;
	}

	//set the values of parent2 on child1
	int o = 0; //<- index of the other parent.
	for (int i = 0; i < n; i++){
		//if the value is not set yet...
		if(child1[i] == -1){
			//go to the next value of the parent2 that is not used yet.
			while(used_facilities[parent2[o]]){
				o++;
			}
			child1[i] =  parent2[o];
			used_facilities[parent2[o]] = true;
		}
	}

	//Generation of child 2;
	vector <int> child2;
	child2.resize(n, -1);
	//resize the used facilities.
	vector<bool> used_facilities2;
	used_facilities2.resize(n, false);


	//set the values of parent2
	for (int i = k1; i <= k2; i++){
		child2[i] = parent2[i];
		used_facilities2[parent2[i]] = true;
	}

	//set the values of parent1
	o = 0; //<- index of the other parent.

	for (int i = 0; i < n; i++){
		//if the value is not set yet...
		if(child2[i] == -1){
			//go to the next value of the parent1 that is not used yet.
			while(used_facilities2[parent1[o]]){
				o++;
			}
			child2[i] =  parent1[o];
			used_facilities2[parent1[o]] = true;
		}
	}

	return make_pair(child1, child2);
}

/*
	Procedure that performs a scattered search.
*/
void scatter_search(){
	bool new_solutions = true;
	while(new_solutions){
		new_solutions = false;
		//generate the subsets of the reference set.
		generate_subsets();
		for (int i = 0; i < subsets.size(); i++){
			//make the childs of the i-th subset.
			pair <vector <int>, vector <int> > childs = crossover(i);
			//take the values of the childs.
			pair <long long int, long long int > childs_values = 
				make_pair(evaluation_function(childs.first), 
						  evaluation_function(childs.second));
			//take the worst ref set value to compare...
			int worst_ref_set_value = reference_set_vector[reference_set_vector.size() - 1].second;
			//look if the child1 could be part on reference set, if so
			//add it 
			if(reference_set.find(childs.first) == reference_set.end() &&
				childs_values.first < worst_ref_set_value){
				//remove the worst solution in reference set
				reference_set.erase(reference_set.find(reference_set_vector[reference_set_vector.size() - 1].first));
				//add the child1 to the reference set and to the reference set vector
				reference_set.insert(childs.first);
				reference_set_vector[reference_set_vector.size() -1] = make_pair(childs.first, childs_values.first);
				//if it is also the best solution... save it
				if(childs_values.first < best_value){
					best_solution = childs.first;
					best_value = childs_values.first;
				}
				//sort the reference set 
				sort(reference_set_vector.begin(), reference_set_vector.end(), solution_is_better);
				//there is a new solution in ref set
				new_solutions = true;
			}
			//look if the child2 could be part on reference set, if so
			//add it 
			if(reference_set.find(childs.second) == reference_set.end() &&
				childs_values.second < worst_ref_set_value){
				//remove the worst solution in reference set
				reference_set.erase(reference_set.find(reference_set_vector[reference_set_vector.size() - 1].first));
				//add the child1 to the reference set and to the reference set vector
				reference_set.insert(childs.second);
				reference_set_vector[reference_set_vector.size() -1] = make_pair(childs.second, childs_values.second);
				//if it is also the best solution... save it
				if(childs_values.second < best_value){
					best_solution = childs.second;
					best_value = childs_values.second;
				}
				//sort the reference set 
				sort(reference_set_vector.begin(), reference_set_vector.end(), solution_is_better);
				//there is a new solution in ref set
				new_solutions = true;
			}
		}

	}

}

/*
	Main Procedure.
*/
int main(){
	//read the input
	read_input();
	//randomize the seed with the actual time.
	srand(time(0));
	//generate the movement list (for the tabu searchs)
	generate_movement_list();
	//build the initial population
	build_initial_population(1);
	//generate the reference set
	build_reference_set(n/2);
	//Do the scatter search
	scatter_search();
	//output
	cout<<best_value<<endl;
}