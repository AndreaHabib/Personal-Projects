#include "FEATURES.h"
//THIS FILE CONTAINS ALL THE FEATURES FROM 1 TO 4
extern int counter;
extern int MAX;
extern task* list;
extern SYSTEMTIME today;
void task::addTask() {
	int numOfDays{ 33 };
	GetLocalTime(&today);
	counter++;
	for (int taskNum = counter - 1; taskNum < counter; taskNum++) {
		system("CLS");
		cout << "Please enter a new task" << flush << endl;
		cout << "Title: ";
		cin.ignore();
		getline(cin, list[taskNum].title);
		cout << "Details: ";
		getline(cin, list[taskNum].detail);
		list[taskNum].day.day = 33;
		list[taskNum].day.year = 2018;
		list[taskNum].day.month = 13;
		while (list[taskNum].day.year < today.wYear || list[taskNum].day.month > 12 || list[taskNum].day.month < 1 || list[taskNum].day.day > numOfDays || list[taskNum].day.day < 1) {
			cout << "Due date: (MM/DD/YYYY)" << endl;
			cin >> list[taskNum].day.month;
			cin >> list[taskNum].day.day;
			cin >> list[taskNum].day.year;
			switch (list[taskNum].day.month) {
			case 1:
				numOfDays = 31;
				break;
			case 2:
				if ((list[taskNum].day.year % 4 == 0 && list[taskNum].day.year % 100 != 0) || list[taskNum].day.year % 400 == 0)
					numOfDays = 29;
				else numOfDays = 28;
				break;
			case 3:
				numOfDays = 31;
				break;
			case 4:
				numOfDays = 30;
				break;
			case 5:
				numOfDays = 31;
				break;
			case 6:
				numOfDays = 30;
				break;
			case 7:
				numOfDays = 31;
				break;
			case 8:
				numOfDays = 31;
				break;
			case 9:
				numOfDays = 30;
				break;
			case 10:
				numOfDays = 31;
				break;
			case 11:
				numOfDays = 30;
				break;
			case 12:
				numOfDays = 31;
				break;
			default:
				cout << "Invalid month!" << endl;
				break;
			}
			if (list[taskNum].day.day > numOfDays || list[taskNum].day.day < 1) {
				cin.clear();
				cout << "Invalid day for the month and year you entered!" << endl;
				cin.ignore();
			}
			if (list[taskNum].day.year < today.wYear) {
				cout << "Please enter a year within or after " << today.wYear << endl;
			}
		}
		while (list[taskNum].priority > 9 || list[taskNum].priority < 0) {
			cout << "Priority: (Enter a number between 0 and 9 --> 0 least importance and 9 most importance) ";
			cin >> list[taskNum].priority;
			if (list[taskNum].priority > 9 || list[taskNum].priority < 0) {
				cout << "Please enter a number between 0 and 9!" << endl;
			}
		}
	}
}
void task::taskDone() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		cout << "Enter task number to be done: " << flush << endl;
		int taskNum;
		cin >> taskNum;
		list[taskNum - 1].finished = true;
	}
}
void task::edit() {
	int part = 5;
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		string loop = "y";
		while (loop == "y" || loop == "Y" || loop == "Yes" || loop == "YES" || loop == "yes" || loop == "yES" || loop == "YeS") {

			int taskNum = counter + 1;
			while (!cin || taskNum > counter || taskNum < 1) {
				cout << "Please enter which task you would like edit: (from 1 to " << counter << ") ";
				cin >> taskNum;
				if (cin && taskNum > counter || taskNum < 1) {
					cin.clear();
					cout << "Task not found! Please enter a valid task!" << endl;
					cin.ignore();
				}
			}
			cout << "Which part would you like to edit?" << endl;
			cout << "1. Title\n" << "2. Details\n" << "3. Date\n" << "4. Priority" << endl;
			while (!cin || part > 4 || part < 1) {
				cout << "Please enter a number between 1 and 4: ";
				cin >> part;
				if (cin && part > 4 || part < 1) {
					cin.clear();
					cout << "Invalid! Please enter a valid number!" << endl;
					cin.ignore();
				}
			}
			switch (part) {
			case 1:
				cout << "New Title: ";
				cin.ignore();
				getline(cin, list[taskNum - 1].title);
				break;
			case 2:
				cout << "New Detials: ";
				cin.ignore();
				getline(cin, list[taskNum - 1].detail);
				break;
			case 3:
				int numOfDays;
				GetLocalTime(&today);
				list[taskNum - 1].day.day = 33;
				list[taskNum - 1].day.year = 2018;
				list[taskNum - 1].day.month = 13;
				while (list[taskNum - 1].day.year < today.wYear || list[taskNum - 1].day.month > 12 || list[taskNum - 1].day.month < 1 || list[taskNum - 1].day.day > numOfDays || list[taskNum - 1].day.day < 1) {
					cout << " New Due date: (MM/DD/YYYY)" << endl;
					cin >> list[taskNum - 1].day.month;
					cin >> list[taskNum - 1].day.day;
					cin >> list[taskNum - 1].day.year;
					switch (list[taskNum - 1].day.month) {
					case 1:
						numOfDays = 31;
						break;
					case 2:
						if ((list[taskNum - 1].day.year % 4 == 0 && list[taskNum - 1].day.year % 100 != 0) || list[taskNum - 1].day.year % 400 == 0)
							numOfDays = 29;
						else numOfDays = 28;
						break;
					case 3:
						numOfDays = 31;
						break;
					case 4:
						numOfDays = 30;
						break;
					case 5:
						numOfDays = 31;
						break;
					case 6:
						numOfDays = 30;
						break;
					case 7:
						numOfDays = 31;
						break;
					case 8:
						numOfDays = 31;
						break;
					case 9:
						numOfDays = 30;
						break;
					case 10:
						numOfDays = 31;
						break;
					case 11:
						numOfDays = 30;
						break;
					case 12:
						numOfDays = 31;
						break;
					default:
						cout << "Invalid month!" << endl;
						break;
					}
					if (list[taskNum - 1].day.day > numOfDays || list[taskNum - 1].day.day < 1) {
						cin.clear();
						cout << "Invalid day for the month and year you entered!" << endl;
						cin.ignore();
					}
					if (list[taskNum - 1].day.year < today.wYear) {
						cout << "Please enter a year within or after " << today.wYear << endl;
					}
				}
				break;
			case 4:
				while (list[taskNum - 1].priority > 9 || list[taskNum - 1].priority < 0) {
					cout << " New Priority: (Enter a number between 0 and 9 --> 0 least importance and 9 most importance) ";
					cin >> list[taskNum - 1].priority;
					if (list[taskNum - 1].priority > 9 || list[taskNum - 1].priority < 0) {
						cout << "Please enter a number between 0 and 9!" << endl;
					}
				}
			}
			cout << "Would you like to make more edits?" << endl;
			cin >> loop;
		}
	}
}
void task::Delete() { //swapping and deleting last row, but data is still saved in the next location in array
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		cout << "Please choose task you want to delete" << flush << endl;
		int taskNum;
		cin >> taskNum;
		if (taskNum > counter) {
			cout << "Task not found!" << endl;
		}
		else {
			for (int i = taskNum; i < counter; i++) {
				task temp;
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
			}
			counter--;
		}
	}
}