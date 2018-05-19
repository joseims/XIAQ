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

void insert(int difficulty, rank r)
{
	rank *rank_selected = get_rank(difficulty);

	// inserir dando shift nas posicoes, lembrar (era o erro)

	sort_rank(difficulty);

}

int main(int argc, char** argv)
{

	rank r1;
	r1.name_user = "hiago";

	r1.score = 100;

	insert(1, r1);

	rank r2;

	r2.score = 101;
	r2.name_user = "ls";

	insert(1, r2);

	see_score(1);

	return 0;
}
