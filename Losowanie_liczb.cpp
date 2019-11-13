#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


int main()
{
	int tab[10];
	int line = 0;
	int column = 0;
	int counter = 0;
	srand(time(NULL));

	while (counter < 15) {
		system("cls");
		for (int i = 0; i <= 9; i++) {
			tab[i] = rand() % 10;
			printf_s("%d", tab[i]);
		}
		printf_s("\n");

		while (line <= 9) {
			column = 0;
			while (column <= 9) {
				if (line < tab[column]) {
					printf_s("#");
				}
				else {
					printf_s(" ");
				}

				column++;
			}

			line++;
			printf_s("\n");
		}

		line = 0;
		column = 0;
		counter++;
		Sleep(1000);
	}
}
/*#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>


int main()
{
	int tab[10];
	int line = 0;
	int column = 0;
	int counter = 0;
	srand(time(NULL));


	DWORD start = GetTickCount();
	while (GetTickCount() - start<15000) {
		system("cls");
		for (int i = 0; i <= 9; i++) {
			tab[i] = rand() % 10;
			printf_s("%d", tab[i]);
		}
		printf_s("\n");

		while (line <= 9) {
			column = 0;
			while (column <= 9) {
				if (line < tab[column]) {
					printf_s("#");
				}
				else {
					printf_s(" ");
				}

				column++;
			}

			line++;
			printf_s("\n");
		}

		line = 0;
		column = 0;
		if (round(GetTickCount()-start % 1000) != 0) {
			Sleep(950);
		}
	}
	printf("Czas wykonywania: %lu ms\n", GetTickCount() - start);
}*/
