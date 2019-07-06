#include <iostream>
#include <fstream>
#include <string>
#include <ctime>//to get time from system
#include <conio.h>
#include <windows.h>//sleep & _kbhit()

using namespace std;

struct event //struct event to store time and date
{
	int day, month, year;
	int minute, hour;
};

int counter;

struct node
{

	string text;
	string title;
	event date;
	event time;

	node *next;
};


bool check_date(int d, int m, int y);
bool check_time(int minute, int hour);
void delete_all();


class List
{
private:
	node *head, *tail;
public:
	List()
	{
		head = NULL;
		tail = NULL;
	}


	void add_remind(string text_tmp, string title_tmp, int date_day_tmp, int date_month_tmp, int date_year_tmp, int time_minute_tmp, int time_hour_tmp)// Create node and add it onto the linked list
	{
		counter++;
		node *temp = new node;

		temp->text = text_tmp;
		temp->title = title_tmp;
		temp->date.day = date_day_tmp;
		temp->date.month = date_month_tmp;
		temp->date.year = date_year_tmp;
		temp->time.minute = time_minute_tmp;
		temp->time.hour = time_hour_tmp;

		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
			temp = NULL;
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}

	}
	void display_all() // Prints out current trip
	{
		int tmp_count = 1;
		node *temp = new node;
		temp = head;

		while (temp != NULL)    // Loop through the list while the temporary node is not empty
		{
			cout << "\n ........remind " << tmp_count

				<< "\n Date ( YY / MM / DD ) :"
				<< "   "
				<< temp->date.year << ":"<< temp->date.month << ":" << temp->date.day

				<< "\n Time ( HH / MM ) :"
				<< "   "
				<< temp->time.hour << ":" << temp->time.minute

				<< "\n title : " << temp->title
				<< "\n text : " << temp->text

				<< '\n';

			++tmp_count;
			temp = temp->next;
		}
	}

	void delete_position(int pos)   // delete a stop by using the position in the list
	{
		node *current = new node;
		node *previous = new node;
		node *next = new node;
		current = head;
		for (int i = 1; i<pos; i++)   // Loop through the link list while the current node is not empty
		{
			if (current == NULL)
				return;
			previous = current;
			current = current->next;
		}
		next = current->next;
		previous->next = current->next;
		delete current;
	}

	void delete_head()  // delete head node
	{
		node *temp = new node;
		temp = head;
		head = head->next;
		delete temp;
	}

	void last_reminds()
	{

		system("color FC");//to change color of program 
		int tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute, tmp_seccond;

		while (_kbhit() == NULL) {

			//to get time from system
			time_t now = time(0);
			tm* ltm = localtime(&now);
			tmp_day = ltm->tm_mday;
			tmp_month = 1 + ltm->tm_mon;
			tmp_year = 1900 + ltm->tm_year;
			tmp_hour = ltm->tm_hour;
			tmp_minute = ltm->tm_min;
			tmp_seccond = ltm->tm_sec;

			system("cls");

			//show live time
			cout << endl << " Live Time ..." << endl;
			cout << endl << "  YY/MM/DD: " << tmp_year << ":" << tmp_month << ":" << tmp_day
				<< "  HH/MM/SS:  " << tmp_hour << ":" << tmp_minute << ":" << tmp_seccond << endl;

			cout << endl << "Your Today Remind ..." << endl;

			int tmp_count = 1;//?
			node *temp = new node;//?
			temp = head;

			// cout reminds that same date with system time
			while (temp != NULL) {
				if (temp->date.year == tmp_year &&
					temp->date.month == tmp_month &&
					temp->date.day == tmp_day) {

					cout << "\n ........remind " << tmp_count

						<< "\n Date ( YY / MM / DD ) :"
						<< "   "
						<< temp->date.year << ":" << temp->date.month << ":" << temp->date.day

						<< "\n Time ( HH / MM ) :"
						<< "   "
						<< temp->time.hour << ":" << temp->time.minute

						<< "\n title : " << temp->title
						<< "\n text : " << temp->text

						<< '\n';


					++tmp_count;
					temp = temp->next;
				}
			}

			cout << endl << "Press Any Key to continue..." << endl;
		}

	}
	//nastyplace
	//Lee Madison
	void open()
	{
		ifstream open("amir_reminder.dat");
		if (open) {
			open >> counter;
			for (int i = 0; i < counter; i++) {

				node *temp = new node;

				open >> temp->date.year;
				open >> temp->date.month;
				open >> temp->date.day;
				open >> temp->time.hour;
				open >> temp->time.minute;
				open >> temp->title;
				open.ignore();
				getline(open, temp->text);

				temp->next = NULL;
				if (head == NULL)
				{
					head = temp;
					tail = temp;
					temp = NULL;
				}
				else
				{
					tail->next = temp;
					tail = temp;
				}

			}
			open.close();
		}

	}

	void save() {//to save all array reminds into the amir_reminder.dat

		ofstream output("amir_reminder.dat");
		if (output) {//check if file open successfully
			fstream output("amir_reminder.dat", ios::out);

			output << counter << endl;

			//for (int i = 0; i <= counter; i++) {
			int tmp_count = 1;//?
			node *temp = new node;//?
			temp = head;

			while (temp != NULL) {

				output << temp->date.year << endl;
				output << temp->date.month << endl;
				output << temp->date.day << endl;
				output << temp->time.hour << endl;
				output << temp->time.minute << endl;
				output << temp->title << endl;
				output << temp->text << endl;

				++tmp_count;
				temp = temp->next;
			}
			output.close();
		}
	}

	void report()
	{
		////////////////////////////////////////////////////////////////////////////

		int choise, tmp_year_first, tmp_month_first, tmp_day_first, tmp_year_seccond, tmp_month_seccond, tmp_day_seccond;

		system("cls");

		cout << "\n 1) show reminds list with open Date\n 2) show All reminds list \n 3) save reminds " << endl << endl;
		cin >> choise;
		switch (choise) {
/*
		case 1:
		
		{

			cout << "Please Enter First Range Date Of Your Remind : (YY/MM/DD)" << endl;
			do {
				cin >> tmp_year_first;
				cin >> tmp_month_first;
				cin >> tmp_day_first;
				system("cls");
				cout << "wrong Date open ...." << endl;
				cin.clear();
				cout << "Please Enter  First Range Date Of Your Remind Again : (YY/MM/DD)" << endl;
			} while (check_date(tmp_day_first, tmp_month_first, tmp_year_first) == 0);

			system("cls");

			cout << "Please Enter Seccond Range Date Of Your Remind : (YY/MM/DD)" << endl;
			do {
				cin >> tmp_year_seccond;
				cin >> tmp_month_seccond;
				cin >> tmp_day_seccond;
				system("cls");
				cout << "wrong Date open ...." << endl;
				cin.clear();
				cout << "Please Enter seccond Range Date Of Your Remind Again : (YY/MM/DD)" << endl;
			} while (check_date(tmp_day_seccond, tmp_month_seccond, tmp_year_seccond) == 0);

			system("cls");

			while (tmp_year_first <= tmp_year_seccond) {

				int tmp_count = 1;//?
				node *temp = new node;//?
				temp = head;

				while (temp != NULL) {
					if (temp->date.year == tmp_year_first &&
						temp->date.month == tmp_month_first &&
						temp->date.day == tmp_day_first) {

						cout << "\n ........remind " << tmp_count

							<< "\n Date ( YY / MM / DD ) :"
							<< "   "
							<< temp->date.year << ":" << temp->date.month << ":" << temp->date.day

							<< "\n Time ( HH / MM ) :"
							<< "   "
							<< temp->time.hour << ":" << temp->time.minute

							<< "\n title : " << temp->title
							<< "\n text : " << temp->text

							<< '\n';


						++tmp_count;
						temp = temp->next;
					}
				}

				tmp_day_first++;

				if (tmp_day_first > 31) { tmp_day_first = 1; tmp_month_first++; }
				if (tmp_month_first > 12) { tmp_month_first = 1; tmp_year_first++; }
			}

			cout << "\n Press any key to continue ....\n";

			_getch();

		}
		
			break;
*/
		case 2:

			display_all();
			cout << "\n Press any key to continue ....\n";
			_getch();
			break;
		
		case 3:

			system("cls");
			save();
			cout << "\n All Reminds has been Saved";
			Sleep(1500);
			//break;

		}
		
		////////////////////////////////////////////////////////////////////////////
	}
	void edit_remind() 
	{
		///////////////////////////////////////////////////////////

		/*


		int tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute, tmp_choise, tmp_count = 0;
		int tmp_year_save, tmp_month_save, tmp_day_save, tmp_hour_save, tmp_minute_save;
		string tmp_text, tmp_title;
		string tmp_text_save, tmp_title_save;

		//too get range of date to edit it
		system("cls");
		cout << "Please open Your Year of Remind : ";
		cin >> tmp_year;
		cout << "Please open Your Month of Remind : ";
		cin >> tmp_month;
		cout << "Please open Your Day of Remind : ";
		cin >> tmp_day;

		int tmp_count = 1;//?
		node *temp = new node;//?
		temp = head;

		//too open if tis date that given from user same with store data remind
		while (temp != NULL) {
			if (temp->date.year == tmp_year &&
				temp->date.month == tmp_month &&
				temp->date.day == tmp_day) {

				cout << "\n ........remind " << tmp_count

					<< "\n Date ( YY / MM / DD ) :"
					<< "   "
					<< temp->date.year << ":" << temp->date.month << ":" << temp->date.day

					<< "\n Time ( HH / MM ) :"
					<< "   "
					<< temp->time.hour << ":" << temp->time.minute

					<< "\n title : " << temp->title
					<< "\n text : " << temp->text

					<< '\n';


				++tmp_count;
				temp = temp->next;
			}
		}

		cout << "\n choose one of the reminds ......";

		do//if we choose wrong number program say user eror
		{
			cin >> tmp_choise;
			cout << "wrong choise ....\a" << endl;
			cin.clear();
			cout << "\n choose one of the reminds ......";
		} while (!(tmp_choise >= 0 && tmp_choise <= tmp_count - 1));

		system("cls");

		//to get new date & time from user
		cout << "Please Enter NEW Date Of Your Remind : (YY/MM/DD)" << endl;
		do {

			cin >> tmp_year;
			cin >> tmp_month;
			cin >> tmp_day;
			system("cls");
			cout << "wrong Date open ....\a" << endl;
			cin.clear();
			cout << "Please Enter NEW Date Of Your Remind Again : (YY/MM/DD)" << endl;
		} while (check_date(tmp_day, tmp_month, tmp_year) == 0);

		system("cls");

		cout << "Please Enter NEW Time Of Your Remind : (HH/MM)" << endl;
		do {

			cin >> tmp_hour;
			cin >> tmp_minute;
			system("cls");
			cout << "wrong Time open ....\a" << endl;
			cin.clear();
			cout << "Please Enter NEW Time Of Your Remind Again : (HH/MM)" << endl;

		} while (check_time(tmp_minute, tmp_hour) == 0);
		system("cls");

		cout << "Please Enter Your NEW Title : " << endl;
		cin >> tmp_title;

		cout << "Please Enter Your NEW Remind : " << endl;
		cin.ignore();
		getline(cin, tmp_text);


		int tmp_count = 1;//?
		node *temp = new node;//?
		temp = head;

		//too open if tis date that given from user same with store data remind
		while (temp != NULL) {
			if (temp->date.year == tmp_year &&
				temp->date.month == tmp_month &&
				temp->date.day == tmp_day) {

				cout << "\n ........remind " << tmp_count

					<< "\n Date ( YY / MM / DD ) :"
					<< "   "
					<< temp->date.year << ":" << temp->date.month << ":" << temp->date.day

					<< "\n Time ( HH / MM ) :"
					<< "   "
					<< temp->time.hour << ":" << temp->time.minute

					<< "\n title : " << temp->title
					<< "\n text : " << temp->text

					<< '\n';


				++tmp_count;
				temp = temp->next;
			}
		}

		*/

		//////////////////////////////////////////////////////////
	}
	bool check_wrriten(int tmp_day, int tmp_month, int tmp_year, int tmp_minute, int tmp_hour)
	{

		int tmp_count = 1;//?
		node *temp = new node;//?
		temp = head;

		while (temp != NULL) {
			if (temp->date.year == tmp_year &&
				temp->date.month == tmp_month &&
				temp->date.day == tmp_day &&
				temp->time.hour == tmp_hour &&
				temp->time.minute == tmp_minute) {

				cout << "\nThere Is The Remind That Same Date With This Remind" << endl;
				char bool_INPUT;
				cout << "Are You Sure To Write It ?(Y/N)" << endl;
				cin >> bool_INPUT;
				if (bool_INPUT == 'Y' || bool_INPUT == 'y')
				{
					return 1;
				}
				else
				{
					return 0;//return to main menue
				}

			}
		}

	}

};



int main()
{
	List reminds; // create a reminds item for the List class
	int choice, position;
	string text;
	string title;
	event date;
	event time;

	reminds.open();
	cout << "\n" << "______________________________________________" << endl;
	reminds.last_reminds();
	cout << "\n" << "______________________________________________" << endl;

	while (1) {

		system("cls");


		cout << "\n What would you like to do?: " << endl;

		cout << " 1. Add A Remind" << endl;
		cout << " 2. Edit A Remind" << endl;
		cout << " 3. Remove A Remind" << endl;
		cout << " 4. Remove All" << endl;
		cout << " 5. Report" << endl;
		cout << " 6. Exit The Program" << endl;

		cin >> choice;

		switch (choice)
		{

		case 2:

			reminds.edit_remind();
			break;

		case 1: {

			system("cls");

			int tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute;
			string tmp_title, tmp_text;

			cout << "Please Enter Date Of Your Remind : (YY/MM/DD)" << endl;

			do {
				cin >> tmp_year;
				cin >> tmp_month;
				cin >> tmp_day;
				system("cls");
				cout << "wrong Date open ....\a" << endl;
				cin.clear();
				cout << "Please Enter Date Of Your Remind Again : (YY/MM/DD)" << endl;
			} while (check_date(tmp_day, tmp_month, tmp_year) == 0);

			system("cls");

			cout << "Please Enter Time Of Your Remind : (HH/MM)" << endl;

			do {
				cin >> tmp_hour;
				cin >> tmp_minute;
				system("cls");
				cout << "wrong Time open ....\a" << endl;
				cin.clear();
				cout << "Please Enter Time Of Your Remind Again : (HH/MM)" << endl;
			} while (check_time(tmp_minute, tmp_hour) == 0);

			system("cls");

			cout << "Please Enter Your Title : " << endl;
			cin >> tmp_title;

			cout << "Please Enter Your Remind : " << endl;
			cin.ignore();
			getline(cin, tmp_text);
           
			if (reminds.check_wrriten(tmp_day, tmp_month, tmp_year, tmp_minute, tmp_hour) == 0)
				break;

			reminds.add_remind(tmp_text, tmp_title, tmp_day, tmp_month, tmp_year, tmp_minute, tmp_hour); // create the contact in the linked list
			cout << endl;
		}
			break;

		case 3:

			system("cls");

			reminds.display_all();

			cout << "Enter the remind number of the contact you would like to remove: ";
			cin >> position;
			if (position == 1)
				reminds.delete_head();
			else
				reminds.delete_position(position); // delete contact from list
			break;

		case 4:

			delete_all();
			break;

		case 5:

			reminds.report();
			break;

		case 6:
			
			system("cls");
			cout << "This Program Wrriten by Amir Mohseninia...";
			Sleep(2000);//set sleep to to show top sentence
			exit(0);

			break;

		default:

			system("cls");
			cout << "\n" << choice << " is not an option. Please select a valid option." << endl;
			break;

		}
	}
	system("pause");
	return 0;
}

bool check_date(int d, int m, int y)
{
	if ((1 <= d && d <= 31) && (1 <= m && m <= 12) && (0 <= y && y <= 9999))
		return 1;
	else
		return 0;
}
bool check_time(int minute, int hour)
{
	if ((0 <= hour && hour <= 23) && (0 <= minute && minute <= 59))
		return 1;
	else
		return 0;
}

void delete_all() {//delete all records form amir_reminder.dat file
	system("cls");
	cout << "Are you sure ? (y/n)";
	char ch = _getch();

	if (ch == 'y' || ch == 'Y')
	{
		fstream _delete("amir_reminder.dat", ios::out);

		_delete.close();

		cout << "\n All items was deleted...\n";
		cout << "\n Press any key to continue ....\n";
		_getch();
	}
}

///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
///@@ (C) Copyright 1999-2019 by AMIR MOHSENINIA All Rights Reserved.      @@//
///@@     visit my github page : github.com/amircloner                     @@//
///@@              website : www.jimzy.ir                                  @@//
///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///