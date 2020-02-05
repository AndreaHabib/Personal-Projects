#include "FEATURES.h"
//THIS FILE CONTAINS ALL THE FEATURES THAT MANIPULATE A TASK
extern int counter;
extern int MAX;
extern task* list;
extern SYSTEMTIME today;
void task::addTask() {
	int mm, dd, yyyy;
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
			list[taskNum].day.day = dd;
			list[taskNum].day.year = yyyy;
			list[taskNum].day.month = mm;
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
				cout << "Invalid month!\n";
				numOfDays = list[taskNum - 1].day.day;
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
		cout << flush;
		int taskNum = counter;
		int end = 0, count = 0;
		for (int i = 0; i < counter; i++) {
			if (!list[i].finished) {
				cout << "Task " << i + 1 << ". " << list[i].title << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "All tasks are done!" << endl;
			end = -1;
		}
		while (end != -1 && taskNum != -1) {
			cout << "Enter task number to be done: (-1 to exit) " << endl;
			cin >> taskNum;
			switch (taskNum) {
			case -1:
				break;
			}
			if (list[taskNum - 1].finished) {
				cout << "Already done!" << endl;
			}
			else if(taskNum != -1) {
				cout << "Marked as Done!" << endl;
				list[taskNum - 1].finished = true;
				list[taskNum - 1].overdue = false;
				end = -1;
			}
		}
	}
}
void task::edit() {
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {
		system("CLS");
		string loop = "y";
		int end = 0;
		while (loop == "y" || loop == "Y" || loop == "Yes" || loop == "YES" || loop == "yes" || loop == "yES" || loop == "YeS" && end != -1) {
			int taskNum = counter + 1;
			for (int i = 0; i < counter; i++) {
				cout << "Task " << i + 1 << ". " << list[i].title << endl;
			}
			while (!cin || taskNum > counter || taskNum < 1 && taskNum != -1) {
				cout << flush;
				cout << "Please enter which task you would like edit: (from 1 to " << counter << ") (-1 to exit) ";
				cin >> taskNum;
				if (cin && taskNum > counter || taskNum < 1 && taskNum != -1) {
					cin.clear();
					cout << "Task not found! Please enter a valid task!" << endl;
					cin.ignore();
				}
			}
			loop = 'n';
			if (taskNum != -1) {
				cout << "Which part would you like to edit?" << endl;
				cout << "1. Title\n" << "2. Details\n" << "3. Date\n" << "4. Priority" << endl;
				int part = 5;
				while (!cin || part > 4 || part < 1 && part != -1) {
					cout << "Please enter a number between 1 and 4: (-1 to exit) ";
					cin >> part;
					if (cin && part > 4 || part < 1 && part != -1) {
						cin.clear();
						cout << "Invalid! Please enter a valid number!" << endl;
						cin.ignore();
					}
				}
				switch (part) {
				case -1:
					break;
				case 1:
					cout << "Old Title: " << list[taskNum - 1].title << endl;
					cout << "New Title: ";
					cin.ignore();
					getline(cin, list[taskNum - 1].title);
					break;
				case 2:
					cout << "Old Details: " << list[taskNum - 1].detail << endl;
					cout << "New Detials: ";
					cin.ignore();
					getline(cin, list[taskNum - 1].detail);
					break;
				case 3:
					printf("Old Due date: %d/%d/%d \n", list[taskNum - 1].day.month, list[taskNum - 1].day.day, list[taskNum - 1].day.year);
					int mm, dd, yyyy;
					int numOfDays;
					GetLocalTime(&today);
					list[taskNum - 1].day.day = 33;
					list[taskNum - 1].day.year = 2018;
					list[taskNum - 1].day.month = 13;
					while (list[taskNum - 1].day.year < today.wYear || list[taskNum - 1].day.month > 12 || list[taskNum - 1].day.month < 1 || list[taskNum - 1].day.day > numOfDays || list[taskNum - 1].day.day < 1) {
						cout << "New Due date: (MM/DD/YYYY)" << endl;
						int i = 1;
						while (i != 3) {
							i = scanf_s("%d/%d/%d", &mm, &dd, &yyyy);
							if (i != 3) {
								cout << "Please enter in the correct format!" << endl;
								cout << "New Due date: (MM/DD/YYYY)" << endl;
								fflush(stdin);
								fseek(stdin, 0, SEEK_END);
							}
						}
						list[taskNum - 1].day.day = dd;
						list[taskNum - 1].day.year = yyyy;
						list[taskNum - 1].day.month = mm;
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
							numOfDays = list[taskNum - 1].day.day;
							//break;
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
}
void task::Delete() { //swapping and deleting last row, but data is still saved in the next location in array
	if (counter == 0) {
		cout << "No tasks found!" << endl;
	}
	else {

		system("CLS");
		cout << flush;
		int taskNum = 1;
		for (int i = 0; i < counter; i++) {
			cout << "Task " << i + 1 << ". " << list[i].title << endl;
		}
		while (taskNum != -1) {
		  cout << "Please choose task you want to delete: (-1 to exit) ";
		  cin >> taskNum;
		  if (taskNum != -1) {
			if (taskNum > counter || taskNum < 0 && taskNum != -1) {
				cout << "Task not found!" << endl;
			}
			else {
				for (int i = taskNum; i < counter; i++) {
					task temp;
					temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
				}
				cout << "Task " << taskNum << " Deleted!" << endl;
				counter--;
				break;
			}
		  }
		}
	}
}
