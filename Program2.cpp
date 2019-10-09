// Program2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>


int day, month, year, x;


int wyliczenie_dnia(int a) {
	if (a % 7 == 0) {
		printf_s("Dzien: %d, %d, %d to sroda.\n", day, month,year);
	}
	else if (a % 7 == 1) {
		printf_s("Dzien: %d, %d, %d to czwartek\n", day, month, year);
	}
	else if (a % 7 == 2) {
		printf_s("Dzien: %d, %d, %d to piatek\n", day, month, year);
	}
	else if (a % 7 == 3) {
		printf_s("Dzien: %d, %d, %d to sobota\n", day, month, year);
	}
	else if (a % 7 == 4) {
		printf_s("Dzien: %d, %d, %d to niedziela\n", day, month, year);
	}
	else if (a % 7 == 5) {
		printf_s("Dzien: %d, %d, %d to poniedzialek\n", day, month, year);
	}
	else if (a % 7 == 6) {
		printf_s("Dzien: %d, %d, %d to wtorek\n", day, month, year);
	}
	return 0;
}

//b = month   c = day
/*int ilosc_dni(int b,int c) {

	while(j)
}*/

//1.1.1970
int main()
{

	printf_s("Podaj dzien: ");
	scanf_s("%d", &day);

	printf_s("Podaj miesiac: ");
	scanf_s("%d", &month);

	printf_s("Podaj rok: ");
	scanf_s("%d", &year);

	int ilosc=0;
	int i=1970;
	int j=1;
	while(i<=year){
		printf_s("%d\n", i);
		i++;
		while (j <= month) {
			if (j == 1) {
				day = day + ilosc;
			}
			if (j == 2) {

			}

		}
	}


}


