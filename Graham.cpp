#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


using namespace std;
struct Point
{
	float x;
	float y;
	float alfa;
};

int det(Point a, Point b, Point c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - c.x*b.y - a.x*c.y - b.x*a.y;
}

int zakret(vector<Point> S, Point c) {
	Point b = S.at(S.size() - 1);
	Point a = S.at(S.size() - 2);

	if (det(a, b, c) > 0) //Lewo
		return 0;
	else if (det(a, b, c) < 0) //prawo
		return 1;
}

void alfa(vector<Point> points) {
	float d,x,y;


	for (int i = 0; i < points.size(); i++) {
		x = points[i].x;
		y = points[i].y;

		d = abs(x) + abs(y);


		if ((x >= 0) && (y >= 0))
			points[i].alfa = y / d;
		else if ((x < 0) && (y >= 0))
			points[i].alfa = 2 - y / d;
		else if ((x < 0) && (y < 0))
			points[i].alfa = 2 + abs(y) / d;
		else if ((x >= 0) && (y < 0))
			points[i].alfa = 4 - abs(y) / d;
	}
}

vector<Point> Graham(vector<Point> points) {
	alfa(points);

	for (int i = 0; i < points.size(); i++) {
		for (int j = 1; j < points.size(); j++) {
			if (points[j].alfa < points[j - 1].alfa) {
				swap(points[j], points[j - 1]);
			}
		}
	}

	vector<Point> result;
	for (int i = 0; i < points.size(); i++) {
		if (result.size() > 2) {
			while (zakret(result, points[i]) == 1)
				result.pop_back();
			result.push_back(points[i]);
		}
		else
			result.push_back(points[i]);
	}
	return result;
}

void show(vector<Point> points) {
	for (int i = 0; i < points.size(); i++) {
		cout << "(" << points[i].x << ", " << points[i].y << ") "<<endl;
	}
	cout << "Suma punktow : " << points.size()<<endl;
}

void main(void) {
	vector<Point> points;
	ifstream inFile;
	float x,y;

	inFile.open("points1.txt");
	if (!inFile) {
		cout << "unable to open" << endl;
		exit(1);
	}
	inFile.ignore(numeric_limits<streamsize>::max(), '\n');

	Point p;
	while (!inFile.eof()) {

		inFile >> p.x >> p.y;
		points.push_back(p);
		//cout << x << " " << y<<endl;
	}

	vector<Point> circut = Graham(points);
	cout<<"Punkty tworzace wypukla otoczke: "<<endl;
	show(circut);
}