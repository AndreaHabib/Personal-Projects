#include "FEATURES.h"
//THIS FILE CONTAINS ALL THE FEATURES THAT DISPLAY TASKS
extern int counter;
extern int MAX;
extern task* list;
extern SYSTEMTIME today;
void task::displayAll() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			cout << "Task " << taskNum + 1 << flush << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
			cout << "Priority: " << list[taskNum].priority << endl;
			cout << "----------------------------" << endl;
		}
	}
}
void task::displayDone() {
	int count = 0;
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			if (list[taskNum].finished) {
				cout << "Task " << taskNum + 1 << endl;
				cout << "Task: " << list[taskNum].title << endl;
				cout << "Details: " << list[taskNum].detail << endl;
				printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
				cout << "Priority: " << list[taskNum].priority << endl;
				cout << "----------------------------" << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "No tasks done!" << endl;
		}
	}
}
void task::displayOverdue() {
	bool found = false;
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		GetLocalTime(&today);
		cout << flush;
		int taskNum = 0;
		for (taskNum = 0; taskNum < counter; taskNum++) {
			if (!(list[taskNum].finished) && ((today.wDay > list[taskNum].day.day) && (today.wMonth == list[taskNum].day.month) && (today.wYear == list[taskNum].day.year))
				|| ((today.wMonth > list[taskNum].day.month) && (today.wYear == list[taskNum].day.year)) || (today.wYear > list[taskNum].day.year)) {
				list[taskNum].overdue = true;
				cout << "Task " << taskNum + 1 << endl;
				cout << "Task " << list[taskNum].title << endl;
				cout << "Details: " << list[taskNum].detail << endl;
				printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
				cout << "Priority: " << list[taskNum].priority << endl;
				cout << "----------------------------" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "NO TASKS ARE OVERDUE!" << endl;
		}
	}
}
void task::displayDueToday() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		GetLocalTime(&today);
		system("CLS");
		cout << flush;
		bool found = false;
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			if ((!(list[taskNum].finished)) && (today.wDay == list[taskNum].day.day) && (today.wMonth == list[taskNum].day.month) && (today.wYear == list[taskNum].day.year)) {
				cout << "Task " << taskNum + 1 << endl;
				cout << "Task: " << list[taskNum].title << endl;
				cout << "Details: " << list[taskNum].detail << endl;
				printf("Due date: %d/%d/%d \n", list[taskNum].day.month, list[taskNum].day.day, list[taskNum].day.year);
				cout << "Priority: " << list[taskNum].priority << endl;
				cout << "----------------------------" << endl;
				found = true;
			}
		}
		if (!found) {
			cout << "No tasks due today!" << endl;
		}
	}
}
