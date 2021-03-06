#include <bits/stdc++.h>

using namespace std;

string difficulties[3] = {"Fácil", "Médio","Difícil"};

struct ranking
{
	string name_user;
	int score;
};

vector<ranking> storage_easy, storage_medium, storage_hard;

vector<ranking> get_ranking(int difficulty)
{
	if(difficulty == 1)
	{
		return storage_easy;
	}
	else if(difficulty == 2)
	{
		return storage_medium;
	}
	else if(difficulty == 3)
	{
		return storage_hard;
	}
}

bool compare(const ranking& r1, const ranking& r2)
{
	return r1.score < r2.score;
}

void sort_vector()
{
	stable_sort(storage_easy.begin(), storage_easy.end(), compare);
	stable_sort(storage_medium.begin(), storage_medium.end(), compare);
	stable_sort(storage_hard.begin(), storage_hard.end(), compare);
}

void insert(int difficulty, string name, int new_score)
{

	ranking r_insert;
	r_insert.name_user = name;
	r_insert.score = new_score;

	if(difficulty == 1)
	{
		storage_easy.push_back(r_insert);
	}
	else if(difficulty == 2)
	{
		storage_medium.push_back(r_insert);
	}
	else if(difficulty == 3)
	{
		storage_hard.push_back(r_insert);
	}

	sort_vector();

}

void see_three_highest_score(int difficulty)
{
	vector<ranking> get_vector = get_ranking(difficulty);

	if (get_vector.size() == 0) {
		cout << "Nenhum score" << endl;
		return;
	}
	
	if (get_vector.size() == 0) {
		cout << "Nenhum score" << endl;
		return;
	}
	if(get_vector.size() < 3) {
		cout << "Score atual: " << endl; 
		for(int i = get_vector.size() - 1; i >= 0; i--)
		{
			cout << "[" << i+1 << "] " << get_vector[i].name_user << " " << get_vector[i].score << endl << endl;
		}
	} else
	{
		cout << "Score atual: " << endl;
		for(int i = get_vector.size() - 1; i >= get_vector.size() - 3; i--)
		{
			cout << "[" << i+1 << "] " <<  get_vector[i].name_user << " " << get_vector[i].score << endl << endl;	
		}
	}

}

void see_all_three_highest_score() {
	printf("\n------------------------------------------\n");
	for (int i = 0; i <= 2;i++) {
		cout << "Recordes para " << difficulties[i] << endl;
		see_three_highest_score(i+1);
		printf("------------------------------------------\n");

	}
}
