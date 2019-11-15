#ifndef FEATRUES_H
#define FEATURES_H

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<windows.h>
#include<cstdlib>
#include<cctype>
#include<time.h>
#include<dos.h>
#include<ctime>
#include<conio.h>
using namespace std;
//enum month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec };
struct date {
	int day{}, month{}, year{};
};
class task {
public:
	void expandTasks();
	void addTask();
	void taskDone();
	void edit();
	void Delete();
	void displayAll();
	void displayDone();
	void displayOverdue();
	void displayDueToday();
	void search();
	void stringSearch();
	void numberSearch();
	void dateSearch();
	void outData();
	int getData();
private:
	string title;
	string detail;
	date day;
	int priority = -1;
	bool finished = false;
	bool overdue = false;
};
#endif // !FEATRUES_H
