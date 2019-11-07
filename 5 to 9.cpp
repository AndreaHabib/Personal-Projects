#include "FEATURES.h"
//THIS FILE CONTAINS ALL THE FEATURES FROM 5 TO 9
extern int counter;
extern int MAX;
extern task* list;
extern SYSTEMTIME a;
void displayAll() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			cout << "Task " << taskNum + 1 << flush << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
			cout << "Priority: " << list[taskNum].priority << endl;
			cout << "----------------------------" << endl;
		}
	}
}
void displayDone() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			system("CLS");
			if (list[taskNum].finished) {
				cout << list[taskNum].title << flush << endl;
				cout << list[taskNum].detail << endl;
				cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
				cout << list[taskNum].priority << endl;
			}
			else {
				cout << "NO TASKS ARE DONE!" << endl;
			}
		}
	}
}
void displayOverdue() {
	bool found = false;
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		GetLocalTime(&a);
		cout << flush;
		int taskNum = 0;
		for (taskNum = 0; taskNum < counter; taskNum++) {
			if (!(list[taskNum].finished) && ((a.wDay > list[taskNum].day.day) && (a.wMonth == list[taskNum].day.month) && (a.wYear == list[taskNum].day.year))
				|| ((a.wMonth > list[taskNum].day.month) && (a.wYear == list[taskNum].day.year)) || (a.wYear > list[taskNum].day.year)) {
				list[taskNum].overdue = true;
				cout << list[taskNum].title << endl;
				cout << list[taskNum].detail << endl;
				cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
				cout << list[taskNum].priority << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "NO TASKS ARE OVERDUE!" << endl;
		}
	}
}
void displayDueToday() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		GetLocalTime(&a);
		system("CLS");
		cout << flush;
		bool found = false;
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			if ((!(list[taskNum].finished)) && (a.wDay == list[taskNum].day.day) && (a.wMonth == list[taskNum].day.month) && (a.wYear == list[taskNum].day.year)) {
				cout << list[taskNum].title << endl;
				cout << list[taskNum].detail << endl;
				cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
				cout << list[taskNum].priority << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "No tasks due today!" << endl;
		}
	}
}
void search() {
	int search;
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		cout << "Which element would you like to use to search?" << flush << endl;
		cout << "1. Title\n" << "2. Number\n" << "3. Date\n";
		search = 4;
		while (!cin || search > 3 || search < 1) {
			cout << "Please enter a number between 1 and 3: ";
			cin >> search;
			if (cin && search > 3 || search < 1) {
				cin.clear();
				cout << "Invalid! Please enter a valid number!" << endl;
				cin.ignore();
			}
		}
		switch (search) {
		case 1:
			stringSearch();
			break;
		case 2:
			numberSearch();
			break;
		case 3:
			dateSearch();
			break;
		}
	}
}
void stringSearch() {
	string search;
	system("CLS");
	cout << flush;
	cout << "Enter the title you are looking for" << endl;
	cin.ignore();
	getline(cin, search);
	for (int taskNum = 0; taskNum < counter; taskNum++) {
		if (list[taskNum].title.find(search, 0) != string::npos) {
			cout << "TASK FOUND!!" << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
			cout << "Priority: " << list[taskNum].priority << endl;

		}
		if (taskNum == counter) {
			cout << "TASK NOT FOUND!" << endl;
		}
	}
}
void numberSearch() {
	int taskNum;
	system("CLS");
	cout << flush;
	cout << "Please enter the number of task you are searching for" << endl;
	cin >> taskNum;
	if (taskNum == counter) {
		cout << "TASK FOUND!!" << endl;
		cout << "Title: " << list[taskNum - 1].title << endl;
		cout << "Details: " << list[taskNum - 1].detail << endl;
		cout << "Due date: " << '(' << list[taskNum - 1].day.month << '/' << list[taskNum - 1].day.day << '/' << list[taskNum - 1].day.year << ')' << endl;
		cout << "Priority: " << list[taskNum - 1].priority << endl;
	}
	if (taskNum > counter) {
		cout << "TASK NUMBER INVALID!!" << endl;
	}
}
void dateSearch() {
	system("CLS");
	cout << flush;
	bool found = false;
	int day, month, year, taskNum = 0;
	cout << "Please enter the date of task you are searching for" << endl;
	cin >> day >> month >> year;
	for (int taskNum = 0; taskNum < counter; taskNum++) {
		if (day == list[taskNum].day.day && month == list[taskNum].day.month && year == list[taskNum].day.year) {
			cout << "TASK FOUND!!" << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
			cout << "Priority: " << list[taskNum].priority << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Task was not found!" << endl;
	}
}