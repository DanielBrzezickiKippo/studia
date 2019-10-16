#include "pch.h"
#include <iostream>
#include <stdio.h>


int day, month, year;

int wyliczenie_dnia(int a) {
	if (a % 7 == 0) {
		printf_s("\nDzien: %d. %d. %d to sroda.\n", day, month, year);
	}
	else if (a % 7 == 1) {
		printf_s("\nDzien: %d. %d. %d to czwartek\n", day, month, year);
	}
	else if (a % 7 == 2) {
		printf_s("\nDzien: %d. %d. %d to piatek\n", day, month, year);
	}
	else if (a % 7 == 3) {
		printf_s("\nDzien: %d. %d. %d to sobota\n", day, month, year);
	}
	else if (a % 7 == 4) {
		printf_s("\nDzien: %d. %d. %d to niedziela\n", day, month, year);
	}
	else if (a % 7 == 5) {
		printf_s("\nDzien: %d. %d. %d to poniedzialek\n", day, month, year);
	}
	else if (a % 7 == 6) {
		printf_s("\nDzien: %d. %d. %d to wtorek\n", day, month, year);
	}
	return 0;
}
int wyliczenie_kalendarza(int sum_of_first_day, int month, int year) {
	printf_s("Pn Wt Sr Cz Pt Sb Nd\n");
	//warunki dla miesiecy obliczają dni

	//warunek na przestępny oblicza + 1 dla powyżej lutego

	if ((month == 2) && (year % 4 == 0)|| (year % 100 == 0)|| (year % 500 == 0)) {

		int day_begin = sum_of_first_day + 4 % 7;
		int dni_miesiaca = 29;
		while (day_begin<dni_miesiaca) {
			printf_s(" %d ", day_begin);

			if (day_begin == dni_miesiaca) {
				break;
			}

			day_begin++;
		}
	}
	else if ((month == 2) && (year % 4 != 0)) {

		int day_begin = sum_of_first_day + 4 % 7;
		int dni_miesiaca = 28;
		while (day_begin < dni_miesiaca) {
			printf_s("%d", day_begin);


			if (day_begin == dni_miesiaca) {
				break;
			}

			day_begin++;
		}
	}
	else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {

		//int day_begin = sum_of_first_day + 4 % 7;
		//int day_begin = sum_of_first_day % 7;
		int dni_miesiaca = 31;
		int day_begin = 1;
		int kolumna = 0;

		while (day_begin < dni_miesiaca) {
			if (kolumna < day_begin) {

				printf_s("  ");
				kolumna++;
			}
			else{
				printf_s(" %d", day_begin);
				kolumna++;
			}


			if (day_begin == dni_miesiaca) {
				break;
			}

			day_begin++;
		}
	}

	//if ((month == 2) && (year % 4 == 0)) {
	//	if (b % 7 == 0) {
	//		       1  2  3  4  5\n 6  7  8  9 10 11 12\n13 14 15 16 17 18 19\n20 21 22 23 24 25 26\n27 28 29\n");
	//	}
	//	else if (b % 7 == 1) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n          1  2  3  4\n 5  6  7  8  9 10 11\n12 13 14 15 16 17 18\n19 20 21 22 23 24 25\n26 27 28 29\n");
	//	}
	//	else if (b % 7 == 2) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n             1  2  3\n 4  5  6  7  8  9 10\n11 12 13 14 15 16 17\n18 19 20 21 22 23 24\n25 26 27 28 29\n");
	//	}
	//	else if (b % 7 == 3) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                1  2\n 3  4  5  6  7  8  9\n10 11 12 13 14 15 16\n17 18 19 20 21 22 23\n24 25 26 27 28 29\n");
	//	}
	//	else if (b % 7 == 4) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                   1\n 2  3  4  5  6  7  8\n 9 10 11 12 13 14 15\n16 17 18 19 20 21 22\n23 24 25 26 27 28 29\n");
	//	}
	//	else if (b % 7 == 5) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n 1  2  3  4  5  5  7\n 8  9 10 11 12 13 14\n15 16 17 18 19 20 21\n22 23 24 25 26 27 28\n29\n");
	//	}
	//	else if (b % 7 == 6) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n    1  2  3  4  5  6\n 7  8  9 10 11 12 13\n14 15 16 17 18 19 20\n21 22 23 24 25 26 27\n28 29\n");
	//	}
	//}
	//else if ((month == 2) && (year % 4 != 0)) {
	//	if (b % 7 == 0) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n       1  2  3  4  5\n 6  7  8  9 10 11 12\n13 14 15 16 17 18 19\n20 21 22 23 24 25 26\n27 28\n");
	//	}
	//	else if (b % 7 == 1) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n          1  2  3  4\n 5  6  7  8  9 10 11\n12 13 14 15 16 17 18\n19 20 21 22 23 24 25\n26 27 28\n");
	//	}
	//	else if (b % 7 == 2) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n             1  2  3\n 4  5  6  7  8  9 10\n11 12 13 14 15 16 17\n18 19 20 21 22 23 24\n25 26 27 28\n");
	//	}
	//	else if (b % 7 == 3) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                1  2\n 3  4  5  6  7  8  9\n10 11 12 13 14 15 16\n17 18 19 20 21 22 23\n24 25 26 27 28\n");
	//	}
	//	else if (b % 7 == 4) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                   1\n 2  3  4  5  6  7  8\n 9 10 11 12 13 14 15\n16 17 18 19 20 21 22\n23 24 25 26 27 28\n");
	//	}
	//	else if (b % 7 == 5) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n 1  2  3  4  5  5  7\n 8  9 10 11 12 13 14\n15 16 17 18 19 20 21\n22 23 24 25 26 27 28\n");

	//	}
	//	else if (b % 7 == 6) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n    1  2  3  4  5  6\n 7  8  9 10 11 12 13\n14 15 16 17 18 19 20\n21 22 23 24 25 26 27\n28\n");
	//	}
	//}
	//else if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) {
	//	if (b % 7 == 0) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n       1  2  3  4  5\n 6  7  8  9 10 11 12\n13 14 15 16 17 18 19\n20 21 22 23 24 25 26\n27 28 29 30 31\n");
	//	}
	//	else if (b % 7 == 1) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n          1  2  3  4\n 5  6  7  8  9 10 11\n12 13 14 15 16 17 18\n19 20 21 22 23 24 25\n26 27 28 29 30 31\n");
	//	}
	//	else if (b % 7 == 2) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n             1  2  3\n 4  5  6  7  8  9 10\n11 12 13 14 15 16 17\n18 19 20 21 22 23 24\n25 26 27 28 29 30 31\n");
	//	}
	//	else if (b % 7 == 3) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                1  2\n 3  4  5  6  7  8  9\n10 11 12 13 14 15 16\n17 18 19 20 21 22 23\n24 25 26 27 28 29 30\n31\n");
	//	}
	//	else if (b % 7 == 4) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                   1\n 2  3  4  5  6  7  8\n 9 10 11 12 13 14 15\n16 17 18 19 20 21 22\n23 24 25 26 27 28 29\n30 31\n");
	//	}
	//	else if (b % 7 == 5) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n 1  2  3  4  5  5  7\n 8  9 10 11 12 13 14\n15 16 17 18 19 20 21\n22 23 24 25 26 27 28\n29 30 31\n");
	//	}
	//	else if (b % 7 == 6) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n    1  2  3  4  5  6\n 7  8  9 10 11 12 13\n14 15 16 17 18 19 20\n21 22 23 24 25 26 27\n28 29 30 31\n");
	//	}
	//}
	//else if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
	//	if (b % 7 == 0) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n       1  2  3  4  5\n 6  7  8  9 10 11 12\n13 14 15 16 17 18 19\n20 21 22 23 24 25 26\n27 28 29 30\n");
	//	}
	//	else if (b % 7 == 1) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n          1  2  3  4\n 5  6  7  8  9 10 11\n12 13 14 15 16 17 18\n19 20 21 22 23 24 25\n26 27 28 29 30\n");
	//	}
	//	else if (b % 7 == 2) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n             1  2  3\n 4  5  6  7  8  9 10\n11 12 13 14 15 16 17\n18 19 20 21 22 23 24\n25 26 27 28 29 30\n");
	//	}
	//	else if (b % 7 == 3) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                1  2\n 3  4  5  6  7  8  9\n10 11 12 13 14 15 16\n17 18 19 20 21 22 23\n24 25 26 27 28 29 30\n");
	//	}
	//	else if (b % 7 == 4) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n                   1\n 2  3  4  5  6  7  8\n 9 10 11 12 13 14 15\n16 17 18 19 20 21 22\n23 24 25 26 27 28 29\n30\n");
	//	}
	//	else if (b % 7 == 5) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n 1  2  3  4  5  5  7\n 8  9 10 11 12 13 14\n15 16 17 18 19 20 21\n22 23 24 25 26 27 28\n29 30\n");
	//	}
	//	else if (b % 7 == 6) {
	//		printf_s("Pn Wt Sr Cz Pt Sb Nd\n    1  2  3  4  5  6\n 7  8  9 10 11 12 13\n14 15 16 17 18 19 20\n21 22 23 24 25 26 27\n28 29 30\n");
	//	}
	//}
	if (year % 4 == 0) {
		printf_s("Rok jest przystepny.");
	}
	else {
		printf_s("Rok nie jest przystepny.");
	}
	return 0;
}


int main()
{

	printf_s("Podaj dzien: ");
	scanf_s("%d", &day);

	printf_s("Podaj miesiac: ");
	scanf_s("%d", &month);

	printf_s("Podaj rok: ");
	scanf_s("%d", &year);

	int sum = 0;
	int i = 1970;
	int j = 1;

	int rok_przystepny = 366;
	int rok = 365;
	int days_in_month = 0;
	int february = 0;
	int all_days = 0;
	int first_day_of_month;

	while (i <= year) {
		if (i != year) {
			if (i % 4 == 0) {
				sum += rok_przystepny;
			}
			else {
				sum += rok;
			}
		}
		else if (i == year) {
			while (j <= month) {
				if (j == 1) {
					all_days = day + sum;
				}
				else if (j == 2) {
					days_in_month = 31;
					all_days = day + days_in_month + sum;
				}
				else if (j == 3) {
					if (i == 0) {
						february = 29;
						days_in_month = february + 31;
					}
					else {
						february = 28;
						days_in_month = february + 31;
					}
					all_days = day + days_in_month + sum;
				}
				else if (j == 4) {
					days_in_month = february + (31 * 2);
					all_days = day + days_in_month + sum;
				}
				else if (j == 5) {
					days_in_month = february + (31 * 2) + 30;
					all_days = day + days_in_month + sum;
				}
				else if (j == 6) {
					days_in_month = february + (31 * 3) + 30;
					all_days = day + days_in_month + sum;
				}
				else if (j == 7) {
					days_in_month = february + (31 * 3) + (30 * 2);
					all_days = day + days_in_month + sum;
				}
				else if (j == 8) {
					days_in_month = february + (31 * 4) + (30 * 2);
					all_days = day + days_in_month + sum;
				}
				else if (j == 9) {
					days_in_month = february + (31 * 5) + (30 * 2);
					all_days = day + days_in_month + sum;
				}
				else if (j == 10) {
					days_in_month = february + (31 * 5) + (30 * 3);
					all_days = day + days_in_month + sum;
				}
				else if (j == 11) {
					days_in_month = february + (31 * 6) + (30 * 3);
					all_days = day + days_in_month + sum;
				}
				else if (j == 12) {
					days_in_month = february + (31 * 6) + (30 * 4);
					all_days = day + days_in_month + sum;
				}
				j++;
			}
		}
		i++;
	}

	wyliczenie_dnia(all_days);

	first_day_of_month = all_days - day + 1;
	wyliczenie_kalendarza(first_day_of_month, month, year);


}