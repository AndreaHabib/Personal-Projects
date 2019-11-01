#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<windows.h>
#include <cstdlib>
#include <cctype>
using namespace std;
enum month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec };
struct date {
	int day, month, year;
};
struct task {
	string title;
	string detail;
	date day;
	int priority = -1;
	bool finished = false;
	bool overdue = false;
};
int counter = 0;
int MAX = 100;
task* list= new task[MAX];
SYSTEMTIME a;
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
int main() {
	getData();
	string loop = "y";
	while (loop == "y" || loop == "Y" || loop == "Yes" || loop == "YES" || loop == "yes" || loop == "yES" || loop == "YeS") {
		system("CLS");
		cout << "Welcome to the TO-DO list" << flush << endl;
		cout << "Please choose one of ther following:" << endl;
		cout << "1. Add a new task" << endl;
		cout << "2. Mark task as done" << endl;
		cout << "3. Edit any task" << endl;
		cout << "4. Delete any task" << endl;
		cout << "5. Display all tasks" << endl;
		cout << "6. Display all done tasks" << endl;
		cout << "7. Display all overdue tasks" << endl;
		cout << "8. Display all tasks that needs to be done today" << endl;
		cout << "9. Search for specific task (using Title, Task Number, date" << endl;
		int choice = 5;
		do {
			if (isdigit(choice))
				cout << "Not a number!" << endl;
			if (!cin.fail() && choice > 9 || choice < 1) {
				cout << "Please enter a number between 1 and 9!" << endl;
			}
			cout << "Enter the number of task: ";
			cin >> choice;
		} while (isdigit(choice) && !cin.fail() && choice > 9 || choice < 1);
		switch (choice) {
		case 1:
			addTask();
			break;
		case 2:
			taskDone();
			break;
		case 3:
			edit();
			break;
		case 4:
			Delete();
			break;
		case 5:
			displayAll();
			break;
		case 6:
			displayDone();
			break;
		case 7:
			displayOverdue();
			break;
		case 8:
			displayDueToday();
			break;
		case 9:
			search();
			break;
		default:
			exit(1);
		}
		do
		{
			if (!cin.fail() && loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" && 
				loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
				loop != "nO" && loop != "N") {
				system("CLS");
				cout << "Please enter Yes or No!" << endl << flush;
			}
			cout << "Would you like to choose another task?" << endl;
			cin >> loop;
		} while (!cin.fail() && loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" &&
			loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
			loop != "nO" && loop != "N");
		
	}
	outData();
	system("PAUSE");
	return 0;
}
void addTask() {
	counter++;
	for (int taskNum = counter - 1; taskNum < counter; taskNum++) {
		system("CLS");
		cout << "Please enter a new task" << flush << endl;
		cout << "Title: ";
		cin.ignore();
		getline(cin, list[taskNum].title);
		cout << "Details: ";
		getline(cin, list[taskNum].detail);
		cout << "Due date: (MM/DD/YYYY)" << endl;
		cin >> list[taskNum].day.month;
		cin >> list[taskNum].day.day;
		cin >> list[taskNum].day.year;
		while (list[taskNum].priority > 9 || list[taskNum].priority < 0) {
			cout << "Priority: (Enter a number between 0 and 9 --> 0 least importance and 9 most importance) ";
			cin >> list[taskNum].priority;
			if (list[taskNum].priority > 9 || list[taskNum].priority < 0) {
				cout << "Please enter a number between 0 and 9!" << endl;
			}
		}
	}
}
void taskDone() {
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
void edit() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		string loop = "y";
		while (loop == "y" || loop == "Y" || loop == "Yes" || loop == "YES" || loop == "yes" || loop == "yES" || loop == "YeS") {

			int taskNum = counter;
			do { // REMEMBER!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				if (isdigit(taskNum)) {
					cout << "Not a number!" << endl;
				}
				if (!cin.fail() && taskNum > counter || taskNum < counter) {
					cout << "Task number not found! Please enter a number till " << counter << "!" << endl;
				}
				system("CLS");
				cout << "Enter task number you want to edit: " << flush << endl;
				cin >> taskNum;
			} while (!isdigit(taskNum) && !cin.fail() && taskNum > counter || taskNum < counter);
			cout << "Which part would you like to edit?" << endl;
			cout << "1. Title\n" << "2. Details\n" << "3. Date\n" << "4. Priority" << endl;
			int part;
			cin >> part;
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
				cout << "New Due date: (MM/DD/YYYY)" << endl;
				cin >> list[taskNum - 1].day.month;
				cin >> list[taskNum - 1].day.day;
				cin >> list[taskNum - 1].day.year;
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
void Delete() { //swapping and deleting last row, but data is still saved in the next location in array
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		cout << "Please choose task you want to delete" << flush << endl;
		int taskNum;
		cin >> taskNum;
		for (int i = taskNum; i < counter; i++) {
			task temp;
			temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
		}
		counter--;
	}
}
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
				cout << "No tasks done!" << endl;
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
		cout << "Please enter number 1 to 3: " << endl;
		cout << "1. Title\n" << "2. Number\n" << "3. Date\n" << endl;
		cin >> search;
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
			cout << list[taskNum].priority << endl;

		}
		if (taskNum == counter - 1) {
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
		cout << list[taskNum - 1].priority << endl;
	}
	if(taskNum > counter) {
		cout << "TASK NUMBER INVALID!!" << endl;
	}
}
void dateSearch() {
	system("CLS");
	cout << flush;
	int day, month, year, taskNum = 0;
	cout << "Please enter the date of task you are searching for" << endl;
	cin >> day >> month >> year;
	for (int taskNum = 0; taskNum < counter; taskNum++) {
		if (day == list[taskNum].day.day && month == list[taskNum].day.month && year == list[taskNum].day.year) {
			cout << "TASK FOUND!!" << endl;
			cout << "Title: " << list[taskNum].title << endl;
			cout << "Details: " << list[taskNum].detail << endl;
			cout << "Due date: " << '(' << list[taskNum].day.month << '/' << list[taskNum].day.day << '/' << list[taskNum].day.year << ')' << endl;
			cout << list[taskNum].priority << endl;
			break;
		}
		// {
		//	cout << "TASK NOT FOUND!!" << endl;
		//}
	}
}
int getData() {
	ifstream inData, taskData;
	inData.open("todo.txt");
	taskData.open("tasknumber.txt");
	taskData >> counter;
	if (counter == 0) {
		cout << "No tasks active" << endl;
	}
	else {
		if (!inData) {
			exit(1);
		} //adding while(!EOF) - title doesn't get read in for first task only
		//but doesn't read title of second task
		for (int taskNum = 0; taskNum < counter; taskNum++) {
			getline(inData, list[taskNum].title);
			getline(inData, list[taskNum].detail);
			inData >> list[taskNum].day.month;
			inData >> list[taskNum].day.day;
			inData >> list[taskNum].day.year;
			inData >> list[taskNum].priority;
			inData >> list[taskNum].finished;
			inData >> list[taskNum].overdue;
			inData.ignore();
		}
		inData.close();
		taskData.close();
	}
	return counter;
}
void outData() {
	ofstream saveData, taskData;
	saveData.open("todo.txt");
	taskData.open("tasknumber.txt");
	taskData << counter;
	for (int taskNum = 0; taskNum < counter; taskNum++) {
		saveData << list[taskNum].title << endl;
		saveData << list[taskNum].detail << endl;
		saveData << list[taskNum].day.month << ' ' << list[taskNum].day.day << ' ' << list[taskNum].day.year << ' ';
		saveData << list[taskNum].priority << ' ';
		saveData << list[taskNum].finished << ' ';
		saveData << list[taskNum].overdue << endl;
	}
	saveData.close();
	taskData.close();
}