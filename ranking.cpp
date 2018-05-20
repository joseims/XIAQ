#include <bits/stdc++.h>

using namespace std;

struct rank
{
	string name_user;
	int score;
};

vector<rank> storage_easy;
vector<rank> storage_medium;
vector<rank> storage_hard;

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

void see_score(int difficulty)
{

	vector<rank> get_vector = get_rank(difficulty);

	for(int i = 0; i < get_vector.size(); i++)
	{
		cout << "score atual " << get_vector[i].name_user << " " << get_vector[i].score << endl;
	}

}

bool operator<(const rank& r1, const rank& r2)
{
	return r1.score < r2.score;
}

void sort_vector()
{
	sort(storage_easy.begin(), storage_easy.end());
	sort(storage_medium.begin(), storage_medium.end());
	sort(storage_hard.begin(), storage_hard.end());
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

int main(int argc, char** argv)
{

	rank r1;
	r1.name_user = "hiago";

	r1.score = 100;

	insert(1, r1.name_user, r1.score);

	rank r2;

	r2.score = 101;
	r2.name_user = "ls";

	insert(1, r2.name_user, r2.score);

	insert(1, "oi", 1000);

	insert(1, "blabla", 102);

	insert(1, "hiago2", 100);

	//see_score(1);

	see_three_highest_score(1);

	return 0;
}
