#include <bits/stdc++.h>

using namespace std;

struct rank
{
	string name_user;
	int score;
} storage_easy[3], storage_medium[3], storage_hard[3];

// ta meio seboso ainda no else, mas tava dando problema no ponteiro, dps mudo
rank* get_rank(int difficulty)
{
	if(difficulty == 1)
	{
		return storage_easy;
	}
	else if(difficulty == 2)
	{
		return storage_medium;
	}
	else
	{
		return storage_hard;
	}
}

void see_score(int difficulty)
{
	rank *rank_selected = get_rank(difficulty);

	string show;
	for(int i = 0; i < 3; i++)
	{
		if(rank_selected[i].name_user != "" && rank_selected[i].score != 0)
		{
			cout << "score atual " << rank_selected[i].name_user << " " << rank_selected[i].score << endl;
		}
	}

}


bool operator<(const rank& r1, const rank& r2)
{
	return r1.score < r2.score;
}

void sort_rank(int difficulty)
{

	rank *rank_selected = get_rank(difficulty);

	sort(rank_selected, rank_selected + 3);

}

// problemas na insercao, ta inserindo o ultimo maior
void insert(int difficulty, rank r)
{
	rank *rank_selected = get_rank(difficulty);

	for(int i = 3; i > 0; i--)
	{
		if(rank_selected[i].score < r.score)
		{
			rank_selected[i].score = r.score;
			rank_selected[i].name_user = r.name_user;
		}
	}

	sort_rank(difficulty);

}