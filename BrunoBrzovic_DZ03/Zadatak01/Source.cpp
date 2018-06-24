#include <iostream>
#include <Windows.h>
using namespace std;

int main() {

	int a[2], b[2], x[2];

	//odabir pozicija

	do {
		cout << "Redak A (1-20):";
		cin >> a[0];
		
		if (a[0] > 20 || a[0] == 0) {
			a[0] = -1;
			cout << "Nedozvoljena vrijednost!" << endl;
		}
	} while (a[0] < 0);
	
	do {
		cout << "Stupac A (1-40):";
		cin >> a[1];

		if (a[1] > 40 || a[1] == 0) {
			a[1] = -1;
			cout << "Nedozvoljena vrijednost!" << endl;
		}
	} while (a[1] < 0);

	do {
		cout << "Redak B (1-20):";
		cin >> b[0];

		if (b[0] > 20 || b[0] == 0) {
			b[0] = -1;
			cout << "Nedozvoljena vrijednost!" << endl;
		}
	} while (b[0] < 0);

	do {
		cout << "Stupac B (1-40):";
		cin >> b[1];

		if (b[1] > 40 || b[1] == 0) {
			b[1] = -1;
			cout << "Nedozvoljena vrijednost!" << endl;
		}
	} while (b[1] < 0);

	x[0] = a[0];
	x[1] = a[1];

	//ispis
	do {
		system("CLS");

		if (x[0] < b[0]) x[0]++;
		else if (x[0] > b[0]) x[0]--;

		if (x[1] < b[1]) x[1]++;
		else if (x[1] > b[1]) x[1]--;

		for (int i = 1; i <= 20; i++)
		{
			for (int j = 1; j <= 40; j++)
			{
				if (i == a[0] && j == a[1])	cout << "A";
				else if (i == x[0] && j == x[1]) cout << "x";
				else if (i == b[0] && j == b[1]) cout << "B";
				else cout << "_";
			}
			cout << endl;
		}		

		Sleep(100);
		
	} while (x[0] != b[0] || x[1] != b[1]);

	return 0;
}