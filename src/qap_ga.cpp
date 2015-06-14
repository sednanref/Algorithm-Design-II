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
//Set with the population and their evaluation.
set <  vector <int>  > evaluated_population_set;
//Vector with the population and their evaluation.
vector< pair < vector <int> , long long int > > evaluated_population;
//Overall value of the population (sum of the Objective Function, for the selection with Fitness)
long long int population_value;



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
	Procedure that returns a random solution with its objective value.
*/
void build_initial_population(){
	//Size of the population.
	int population_size = 0;
	//Vector with a Solution for the problem.
	pair <vector <int>, long long int> evaluated_solution;
	vector <int> aux_solution;
	//cleaning the population, just in case.
	evaluated_population.clear();
	evaluated_population_set.clear();
	//clear the auxiliar solution
	aux_solution.clear();
	//set the initial population value.
	population_value = 0;
	//initialization of the best value
	best_value = MAX_INT;
	//Assign to the i-th facility the i-th location.
	for(int i = 0; i < n; i++) aux_solution.push_back(i);
	
	//generator loop
	while(population_size < n*n*n){
		//randomize the solution.
		random_shuffle(aux_solution.begin(), aux_solution.end());
		//if the generated solution is not already in the population...
		if(evaluated_population_set.find(aux_solution) == evaluated_population_set.end()){
			//calculate its evaluation function...
			long long int value = evaluation_function(aux_solution);
			//if the encountered solution is the best, change the best_solution
			if(value < best_value){
				best_value = value;
				best_solution = aux_solution;
			}
			//add the solution to the population vector
			evaluated_population.push_back(make_pair(aux_solution, value));
			//add the solution to the population set
			evaluated_population_set.insert(aux_solution);
			//add the value of the aux_solution to the population value
			population_value += value;
			//increment the population size.
			population_size++;
		}

	}

}

/*
	Procedure that returns the index of two random solutions in the population,
	the probability of take a solution is the evaluation of that solution
	between the sum of the whole population.
*/
pair <int, int> get_indexes_solutions(){
	//First get a random value for a
	int a = rand() % population_value;
	int b;
	//next, get a random value for b, until b != a
	do{
		b = rand() % population_value;
	}while(a == b);

	//now, let's search the indexes corresponding those values
	int i, j;	//indexes to return.
	long long int acum = 0; //acumulator of the values
	//search the first index
	for(i = 0; i < n; i++){
		acum = acum + evaluated_population[i].second;
		if(a <= acum){
			break;
		}
	}
	acum = 0;
	//search the other one.
	for(j = 0; j < n; j++){
		acum = acum + evaluated_population[j].second;
		if(b <= acum){
			break;
		}
	}
	//if i == j... just take another value, one more or one less for j
	if (i == j){
		if (i == n - 1){
			j = i - 1;
		}else{
			j = i + 1;
		}
	}

	return make_pair(i, j);
}

/*
	Crossover procedure, with the selected solutions, take random values to
	generate two new child solutions, and replace the 2 childs with the parents.
*/
void crossover(int a, int b){
	//generate random values for the indexes that will remain untouched.
	int k1 = rand() % n;
	int k2 = rand() % n;
	//readjust the indexes so k1 <= k2...
	if(k2 < k1){
		int aux = k1;
		k1 = k2;
		k2 = aux;
	}

	
/*	
	cout<<"Parents: "<<endl;
	cout<<a<<endl;
	print_solution(evaluated_population[a].first);
	cout<<b<<endl;
	print_solution(evaluated_population[b].first);
	cout<<endl<<endl;
*/
	//Generation of child 1;
	vector <int> child1;
	child1.resize(n, -1);
	//vector of used facilities.
	vector <bool> used_facilities;
	used_facilities.resize(n, false);

	//set the values of parent1
	for (int i = k1; i <= k2; i++){
		child1[i] = evaluated_population[a].first[i];
		used_facilities[evaluated_population[a].first[i]] = true;
	}

	//set the values of parent2
	int o = 0; //<- index of the other parent.
	for (int i = 0; i < n; i++){
		//if the value is not set yet...
		if(child1[i] == -1){
			//go to the next value of the parent2 that is not used yet.
			while(used_facilities[evaluated_population[b].first[o]]){
				o++;
			}
			child1[i] =  evaluated_population[b].first[o];
			used_facilities[evaluated_population[b].first[o]] = true;
		}
	}

	//Generation of child 2;
	vector <int> child2;
	child2.resize(n, -1);
	//resize the used facilities.
	vector<bool> used_facilities2;
	used_facilities2.resize(n, 0);


	//set the values of parent2
	for (int i = k1; i <= k2; i++){
		child2[i] = evaluated_population[b].first[i];
		used_facilities2[evaluated_population[b].first[i]] = true;
	}

	//set the values of parent1
	o = 0; //<- index of the other parent.

	for (int i = 0; i < n; i++){
		//if the value is not set yet...
		if(child2[i] == -1){
			//go to the next value of the parent1 that is not used yet.
			while(used_facilities2[evaluated_population[a].first[o]]){
				o++;
			}
			child2[i] =  evaluated_population[a].first[o];
			used_facilities2[evaluated_population[a].first[o]] = true;
		}
	}

	//get the values of the childs.
	long long int value_child1 = evaluation_function(child1);
	long long int value_child2 = evaluation_function(child2);

	//evaluate if they are a better solution.
	if(value_child1 < best_value){
		best_value = value_child1;
		best_solution = child1;
	}

	if(value_child2 < best_value){
		best_value = value_child2;
		best_solution = child2;
	}


	//Now replace the parents with the childs!
	//Delete the parents from the set.
	if(evaluated_population_set.find(evaluated_population[a].first) != evaluated_population_set.end()){
		evaluated_population_set.erase(evaluated_population_set.find(evaluated_population[a].first));
	}

	if (evaluated_population_set.find(evaluated_population[b].first) != evaluated_population_set.end()){
		evaluated_population_set.erase(evaluated_population_set.find(evaluated_population[b].first));
	}
	//change the population value with the new one.
	population_value = population_value - evaluated_population[a].second 
						- evaluated_population[b].second + value_child1 
						+ value_child2;

	//replace the population vector and set with the new solutions.
	evaluated_population_set.insert(child1);
	evaluated_population_set.insert(child2);
	evaluated_population[a] = make_pair(child1, value_child1);
	evaluated_population[b] = make_pair(child2, value_child2);
//	cout<<"BBB"<<endl;
}

/*
	Mutation Procedure, mutate each solution of the population with a 
	probability of 0.2 to diversificate the population a bit.
*/
void mutation(){
	int probability = 2; //probability/10
	for (int i = 0; i < evaluated_population.size(); i ++){
		//if it has to mutate...
		if(rand()%10 < probability){
			//take the solution to mutate.
			vector <int> mutated_solution = evaluated_population[i].first;
			//indexes of the solution to swap.
			int a = rand() % n; 
			int b;
			do{
				b = rand() % n;
			}while(a == b);

			//swap the values of that solution.
			int aux = mutated_solution[a];
			mutated_solution[a] = mutated_solution[b];
			mutated_solution[b] = aux;

			//update the population value
			long long int mutated_solution_value = evaluation_function(mutated_solution);
			population_value = population_value - evaluated_population[i].second
								+ mutated_solution_value;

			//drop the old solution
			if(evaluated_population_set.find(evaluated_population[i].first) != evaluated_population_set.end()){
				evaluated_population_set.erase(evaluated_population_set.find(evaluated_population[i].first));
			}
			//insert the mutated solution.
			evaluated_population_set.insert(mutated_solution);
			evaluated_population[i] = make_pair(mutated_solution, mutated_solution_value);

			//look if it is a new best solution
			if(mutated_solution_value < best_value){
				best_value = mutated_solution_value;
				best_solution = mutated_solution;
			}
		}
	}
}

/*
	Genetic Algorithm, the metaheuristic.
*/
void genetic_algorithm(){
	//number of iterations for the genetic algorithm.
	int iterations = 2000;
	
	//iteration loop
	for(int k = 0; k < iterations; k++){
		//get the index of a solution to make the crossover (selection)
		pair <int, int> indexes_solutions = get_indexes_solutions();
		//make the crossover with those indexes, they are the selected solutions.
		crossover(indexes_solutions.first, indexes_solutions.second);
		mutation();
		/*cout<<"Indexes: "<<indexes_solutions.first<<"-"<<indexes_solutions.second<<endl;
		cout<<"Population: "<<endl;
		for (int i= 0; i < n ; i++){
			print_solution(evaluated_population[i].first);
		}*/
	}

}

int main(){
	//read the input
	read_input();
	//randomize the seed with the actual time.
	srand(time(0));
	//Build the initial population.
	build_initial_population();
	//Do the Genetic Algorithm.
	genetic_algorithm();
	//output
	cout<<best_value<<endl;

	return 0;
}