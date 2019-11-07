#include "FEATURES.h"
//THIS FILE CONTAINS THE MAIN, GET AND OUT DATA FUNCTIONS, AS WELL AS EXPANSION
int counter = 0;
int MAX = 100;
task* list = new task[MAX];
SYSTEMTIME a;
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
		cout << "9. Search for specific task (using Title, Task Number, date)" << endl;
		int choice = 11;
		while (!cin || choice > 10 || choice < 1) {
			cout << "Please enter a number between 1 and 9: ";
			cin >> choice;
			if (cin && choice > 10 || choice < 1) {
				cin.clear();
				cout << "Invalid! Please enter a valid number!" << endl;
				cin.ignore();
			}
		}
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
		loop = "k";
		while (loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" &&
			loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
			loop != "nO" && loop != "N") {
			cout << "Would you like to choose another task?" << endl;
			cin >> loop;
			if (loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" &&
				loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
				loop != "nO" && loop != "N") {
				cout << "Please enter Y or N!" << endl;
			}
		}

	}
	outData();
	system("PAUSE");
	return 0;
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
		/*if (counter > MAX) {
			expandTasks();
		}*/
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
//void expandTasks() {
//	
//}