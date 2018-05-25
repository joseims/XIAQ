#include <bits/stdc++.h>

using namespace std;

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

void see_all_score(int difficulty)
{

	vector<ranking> get_vector = get_ranking(difficulty);

	for(int i = 0; i < get_vector.size(); i++)
	{
		cout << "score atual " << get_vector[i].name_user << " " << get_vector[i].score << endl;
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
	
	if(get_vector.size() < 3) {
		for(int i = get_vector.size() - 1; i >= 0; i--)
		{
			cout << get_vector[i].name_user << " " << get_vector[i].score << endl;
		}
	} else
	{
		for(int i = get_vector.size() - 1; i >= get_vector.size() - 3; i--)
		{
			cout << get_vector[i].name_user << " " << get_vector[i].score << endl;	
		}
	}

}