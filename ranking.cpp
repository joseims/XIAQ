#include <bits/stdc++.h>

using namespace std;

struct rank
{
	string name_user;
	int score;
};

vector<rank> storage_easy, storage_medium, storage_hard;

vector<rank> get_rank(int difficulty)
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

	vector<rank> get_vector = get_rank(difficulty);

	for(int i = 0; i < get_vector.size(); i++)
	{
		cout << "score atual " << get_vector[i].name_user << " " << get_vector[i].score << endl;
	}

}

bool compare(const rank& r1, const rank& r2)
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

	rank r_insert;
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

	int count = 1;

	while (count != 4)
	{
		cout << get_rank(difficulty)[get_rank(difficulty).size() - count].name_user << " " << get_rank(difficulty)[get_rank(difficulty).size() - count].score << endl;
		count++;
	}

}

int main() {
	
	insert(2, "hiago", 100);
	
	see_all_score(2);
	
}

