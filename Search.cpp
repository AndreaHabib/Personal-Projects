#include "FEATURES.h"
//THIS FILE CONTAINS ALL THE FEATURES TO SEARCH THROUGH THE TASKS
extern int counter;
extern int MAX;
extern task* list;
extern SYSTEMTIME today;
void task::search() {
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
void task::stringSearch() {
	string search;
	system("CLS");
	cout << flush;
	int count = 0;
	int taskNum;
	cout << "Enter the title you are looking for" << endl;
	cin.ignore();
	getline(cin, search);
	for (taskNum = 0; taskNum < counter; taskNum++) {
		if (list[taskNum].title.find(search, 0) != string::npos) {
			cout << "TASK FOUND!!" << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
			cout << "Priority: " << list[taskNum].priority << endl;
			cout << "----------------------------" << endl;
			count++;
		}
	}
	if (count == 0) {
		cout << "TASK NOT FOUND!" << endl;
	}
}
void task::numberSearch() {
	int taskNum;
	system("CLS");
	cout << flush;
	cout << "Please enter the number of task you are searching for: ";
	cin >> taskNum;
	if (taskNum <= counter) {
		cout << "TASK FOUND!!" << endl;
		cout << "Title: " << list[taskNum - 1].title << endl;
		cout << "Details: " << list[taskNum - 1].detail << endl;
		printf("Due date: %d/%d/%d \n", list[taskNum - 1].day.month, list[taskNum - 1].day.day, list[taskNum - 1].day.year);
		cout << "Priority: " << list[taskNum - 1].priority << endl;
		cout << "----------------------------" << endl;
	}
	if (taskNum > counter) {
		cout << "TASK NUMBER INVALID!!" << endl;
	}
}
void task::dateSearch() {
	system("CLS");
	cout << flush;
	int mm, dd, yyyy;
	bool found = false;
	int day, month, year, taskNum = 0;
	cout << "Please enter the date of task you are searching for" << endl;
	int i = 1;
	while (i != 3) {
		i = scanf_s("%d/%d/%d", &mm, &dd, &yyyy);
		if (i != 3) {
			cout << "Please enter in the correct format!" << endl;
			cout << "Due date: (MM/DD/YYYY)" << endl;
			fflush(stdin);
			fseek(stdin, 0, SEEK_END);
		}
	}
	day = dd;
	month = mm;
	year = yyyy;
	for (int taskNum = 0; taskNum < counter; taskNum++) {
		if (day == list[taskNum].day.day && month == list[taskNum].day.month && year == list[taskNum].day.year) {
			cout << "TASK FOUND!!" << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
			cout << "Priority: " << list[taskNum].priority << endl;
			cout << "----------------------------" << endl;
			found = true;
			break;
		}
	}
	if (!found) {
		cout << "Task was not found!" << endl;
	}
}
