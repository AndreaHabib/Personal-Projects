#include "FEATURES.h"
//THIS FILE CONTAINS THE MAIN, GET AND OUT DATA FUNCTIONS, AS WELL AS EXPANSION
int counter = 0;
int MAX = 100;
task* list = new task[MAX];
SYSTEMTIME today;
void loading();
int main() {
	loading();
	task call;
	call.getData();
	string loop = "y";
	int choice = 1;
	while ((loop == "y" || loop == "Y" || loop == "Yes" || loop == "YES" || loop == "yes" || loop == "yES" || loop == "YeS") && choice != -1) {
		system("CLS");
		cout << "***************************************************************" << endl;
		cout << "* Welcome to the TO-DO list" << setw(36) << "*" << flush << endl;
		if (counter == 0) {
			cout << "* There are no tasks active!" << setw(35) << "*" << endl;
		}
		else if (counter == 1) {
			cout << "* You currently have " << counter << " active task." << setw(28) << "*" << endl;
		}
		else if(counter > 10) {
			cout << "* You currently have " << counter << " active tasks." << setw(26) << "*" << endl;
		}
		else {
			cout << "* You currently have " << counter << " active tasks." << setw(27) << "*" << endl;
		}
		cout << "* Please choose one of ther following:"  << setw(25) << "*" << endl;
		cout << "* 1. Add a new task" << setw(44) << "*" << endl;
		cout << "* 2. Mark task as done" << setw(41) << "*" << endl;
		cout << "* 3. Edit any task" << setw(45) << "*" << endl;
		cout << "* 4. Delete any task" << setw(43) << "*" << endl;
		cout << "* 5. Display all tasks" << setw(41) << "*" << endl;
		cout << "* 6. Display all done tasks" << setw(36) << "*" << endl;
		cout << "* 7. Display all overdue tasks" << setw(33) << "*" << endl;
		cout << "* 8. Display all tasks that needs to be done today" << setw(13) << "*" << endl;
		cout << "* 9. Search for specific task (using Title, Task Number, date)*" << endl;
		cout << "***************************************************************" << endl;
		int choice = 11;
		while (!cin || choice > 10 || choice < 1 && choice != -1) {
			cout << "Please enter a number between 1 and 9: (-1 to exit) ";
			cin >> choice;
			if (cin && choice > 10 || choice < 1 && choice != -1) {
				cin.clear();
				cout << "Invalid! Please enter a valid number!" << endl;
				cin.ignore();
			}
		}
		switch (choice) {
		case 1:
			call.addTask();
			break;
		case 2:
			call.taskDone();
			break;
		case 3:
			call.edit();
			break;
		case 4:
			call.Delete();
			break;
		case 5:
			call.displayAll();
			break;
		case 6:
			call.displayDone();
			break;
		case 7:
			call.displayOverdue();
			break;
		case 8:
			call.displayDueToday();
			break;
		case 9:
			call.search();
			break;
		case -1:
			break;
		default:
			cout << "Error! Invalid Number!" << endl;
		}
		loop = "k";
		while (loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" &&
			loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
			loop != "nO" && loop != "N" && choice != -1) {
			cout << "Would you like to choose another task?" << endl;
			cin >> loop;
			if (loop != "y" && loop != "n" && loop != "Y" && loop != "Yes" &&
				loop != "YES" && loop != "yes" && loop != "yES" && loop != "YeS" && loop != "No" && loop != "NO" &&
				loop != "nO" && loop != "N") {
				cout << "Please enter Y or N!" << endl;
			}
		}
	}
	call.outData();
	for (int j = 0; j < 3; j++) {
		cout << "\rExiting   \rExiting";
		for (int i = 0; i < 3; i++) {
			cout << ".";
			Sleep(200);
		}
	}
	system("CLS");
	cout << flush;
	system("PAUSE");
	return 0;
}
int task::getData() {
	task call;
	ifstream inData, taskData;
	inData.open("todo.txt");
	taskData.open("tasknumber.txt");
	taskData >> counter;
	if (!inData) {
		exit(1);
	} //adding while(!EOF) - title doesn't get read in for first task only
	//but doesn't read title of second task
	if (counter > MAX) {
		call.expandTasks();
	}
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
	return counter;
}
void task::outData() {
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
void task::expandTasks() {
	int newSize = 2 * MAX;
	task* newList = new task[newSize];
	for (int i = 0; i < MAX; i++) {
		newList[i] = list[i];
	}
	delete[] list;
	list = newList;
	MAX = newSize;
}
void loading() {
	system("color 0F");
	cout << right << setw(113) << " " << "Please wait! Loading!" << endl;
	char a = 177, b = 219;
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
		cout << a;
	cout << "\r";
	cout << "\t\t\t\t";
	for (int i = 0; i <= 15; i++)
	{
		cout << b;
		Sleep(50);
	}

	system("CLS");
	//cout << "\n\n\n\t\t\t\tTO-DO LIST\n\n\t\t\t";
	//cout << "\n\n\t\t\tPRESS ENTER TO CONTINUE\n\n\t\t\t";
	cout << right << setw(200) << " " << "TO-DO LIST\n\n" << endl;
	cout << right << setw(113) << " " << "PRESS ENTER TO CONTINUE" << endl;
	_getch();
}
