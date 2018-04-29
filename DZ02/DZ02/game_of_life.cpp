#include "game_of_life.h"
#include <ctime>

bool game_of_life::slucajna_vrijednost()
{
	short int status = rand() % (4 - 1 + 1) + 1;
	if(status==4) return true;
	return false;
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	int n = 0;
	
	if (j!=STUPACA-1) if (_generacija[i][j+1]) n++;
	if (j!=STUPACA-1 && i!=REDAKA-1) if (_generacija[i+1][j+1]) n++;
	if (i!=REDAKA-1) if (_generacija[i+1][j]) n++;
	if (i!=REDAKA-1 && j!=0) if (_generacija[i+1][j-1]) n++;
	if (j!=0) if (_generacija[i][j - 1]) n++;
	if (j != 0 && i != 0) if (_generacija[i - 1][j - 1]) n++;
	if (i != 0) if (_generacija[i-1][j]) n++;
	if (i != 0 && j != STUPACA-1) if (_generacija[i-1][j + 1]) n++;
	
	if(_generacija[i][j] == true && (n==2 || n==3)) return true;
	if (_generacija[i][j] == false && n == 3) return true;
	return false;
}

game_of_life::game_of_life()
{
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_sljedeca_generacija[i][j] = slucajna_vrijednost();
		}		
	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}

	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			_sljedeca_generacija[i][j] = celija_zauzeta(i, j);
		}
	}
}

void game_of_life::iscrtaj()
{
	system("cls");
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (_sljedeca_generacija[i][j] == true) cout << "*";
			else cout << "_";
		}
		cout << endl;
	}
}