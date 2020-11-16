#include "pch.h"
#include <iostream>
#include <list>
#include <cstring>
#include <string>
#include <crtdbg.h>
#include <time.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;

//const int N = 10;

template<typename K,typename V>
class HashElement {
public:
	K key;
	V value;
	HashElement(K key, V value) {
		this->key = key;
		this->value = value;
	}
};

template<typename K, typename V>
class HashTable {
private:
	HashElement<K,V> **table;
	int N = 1;
	int size = 0;
public:
	HashTable(){
		table = new HashElement<K,V> * [N];
		for (int i = 0; i < N; i++) {
			table[i] = nullptr;
		}
	}

	~HashTable() {
		Clear();
	}

	int Hash(K key) {
		return key % N;
	}

	void Add(K key, V value) {
		int hashed = Hash(key);

		if (size >= N) {
			Rehash();
		}

		while (table[hashed] != nullptr && table[hashed]->key != key) {
			hashed = Hash(hashed + 1);
		}


		if (table[hashed] != nullptr) {
			size--;
			delete table[hashed];
		}

		table[hashed] = new HashElement<K,V>(key, value);
		size++;
	}

	string FindElement(K key) {
		int hashed = Hash(key);

		while (table[hashed] != nullptr && table[hashed]->key != key) {
			hashed = Hash(hashed + 1);
		}



		if (table[hashed] == nullptr)
			return "";
		else
			return table[hashed]->value;

	}

	bool Exists(K key) {
		int hashed = Hash(key);

		while (table[hashed] != nullptr && table[hashed]->key != key) {
			hashed = Hash(hashed + 1);
		}



		if (table[hashed] == nullptr)
			return false;
		else
			return true;
	}

	void ShowAllElements() {
		for (int i = 0; i < N; i++) {
			if (table[i] != nullptr) {
				cout<<table[i]->value.c_str()<<endl;
			}
		}
	}
	
	bool Remove(K key) {
		int hashed = Hash(key);

		while (table[hashed] != nullptr && table[hashed]->key != key) {
			hashed = Hash(hashed + 1);
		}


		if (table[hashed] == nullptr)
			return false;
		else {
			delete table[hashed];
			size--;
			return true;
		}
	}

	void Clear() {
		if(size>0){
			for (int i = 0; i < N; i++) {
				if (table[i] != nullptr) {
					delete table[i];
				}
			}
			size = 0;
			N = 1;
			delete table;
		}
	}

	void Rehash()
	{
		int oldN = N;
		N = N * 2;
		HashElement<K, V> **newTab = new HashElement<K, V> *[N];
		HashElement<K, V> **oldTab = new HashElement<K, V> *[oldN];
		
		//Add table to temp
		for (int i = 0; i < oldN; i++) {
			if (table[i] != nullptr)
				oldTab[i] = new HashElement<K, V>(table[i]->key, table[i]->value);
			else
				oldTab[i] = nullptr;
		}

		//Fill new created with nulls
		for (int i = 0; i < N; i++) {
			newTab[i] = nullptr;
		}


		//Delete table
		for (int i = 0; i < oldN; i++) {
			if (table[i] != nullptr) {
				delete table[i];
			}
		}
		delete[] table;

		//set new table
		table = newTab;

		//replace values from table to new table
		for (int i = 0; i < oldN; i++) {
			if (oldTab[i] != nullptr) {
				Add(oldTab[i]->key, oldTab[i]->value);
			}
		}

		//Delete temp
		for (int i = 0; i < oldN; i++) {
			if (oldTab[i] != nullptr) {
				delete oldTab[i];
			}
		}
		delete[] oldTab;
	}

	int Size() {
		return size;
	}

};



string RandomChar() {
	int r;
	string c;
	r = rand() % 26;
	c = 'a' + r;

	return c;
}

int RandomInt() {
	int r;
	r = rand() % 1000000;

	return r;
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL));

	HashTable<int, string> * ht = new HashTable<int, string>();

	/*ht->Add(124, "1");
	ht->Add(114, "2");
	ht->Add(1454, "3");
	ht->Add(1224, "4");
	ht->Add(1264, "5");
	ht->Add(1624, "6");

	cout << ht->FindElement(124).c_str() << endl;
	cout << ht->Exists(1) << endl;
	cout << ht->Exists(124) << endl;
	cout << ht->Exists(1) << endl;

	cout << endl;
	ht->ShowAllElements();
	cout << endl;


	ht->ShowAllElements();

	ht->Clear();*/


	const int MAX_ORDER = 2; // maksymalny rzad wielkosci dodawanych danych
	for (int o = 1; o <= MAX_ORDER; o++)
	{
		const int n = pow(10, o); // rozmiar danych
		// dodawanie do tablicy mieszajacej
		clock_t t1 = clock();
		for (int i = 0; i < n; i++) {
			ht->Add(RandomInt(), "cos");
		}


		clock_t t2 = clock();

		double time = (t2 - t1) / (double)CLOCKS_PER_SEC;
		cout << "Dlugosc tablicy: " << ht->Size() << endl;
		cout << "Czas wykonania: " << time << endl;

		const int m = pow(10, 4);
		int hits = 0;
		t1 = clock();
		for (int i = 0; i < m; i++)
		{
			if(ht->Exists(RandomInt())); // wyszukiwanie wg losowego klucza
				hits++;
		}
		t2 = clock();

		cout << "Hits: " << hits << endl;
		cout << "Czas wykonania: " << time << endl;

		ht->Clear(); // czyszczenie tablicy mieszajacej
	}
	
	delete ht;
}