
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>//to get time from system
#include <conio.h>
#include <windows.h>//sleep & _kbhit()

using namespace std;

int counter;//to count how many reminds are wrriten

struct event //struct event to store time and date
{
	int day, month, year;
	int minute, hour;
};

struct remind {//struct remind to save remind into the [1000] array
	string text;
	string title;
	event date;
	event time;
}array_remind[1000];

void add_remind();
void edit_remind();
void _delete();
void save();
void open();
void report_reminds();
bool check_date(int d, int m, int y);
bool check_time(int minute, int hour);
void delete_all();
void search_by_title();
void exit();

int main() {

	system("color F9");//to change color of program 

	int choise, tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute, tmp_seccond;// temp variable to store value from user

	open();// to open amir_reminder.dat to read stored value

	while (_kbhit() == NULL) {

		int tmp_count = 0;

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

		// cout reminds that same date with system time
		for (int i = 0; i <= 999; i++) {
			if (array_remind[i].date.year == tmp_year && array_remind[i].date.month == tmp_month && array_remind[i].date.day == tmp_day) {

				cout << "\n ........remind [" << tmp_count << "]"

					<< "\n Date ( YY / MM / DD ) :"
					<< "   "
					<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

					<< "\n Time ( HH / MM ) :"
					<< "   "
					<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

					<< "\n title : " << array_remind[i].title
					<< "\n text : " << array_remind[i].text

					<< '\n';

				tmp_count++;
			}
		}

		cout << endl << "Press Any Key to continue..." << endl;
	}

	while (1) {

		system("cls");

		cout << "\n" << "______________________________________________" << endl;

		int tmp_count = 0;

		for (int i = 0; i <= 999; i++) {
			if (array_remind[i].date.year == tmp_year &&
				array_remind[i].date.month == tmp_month &&
				array_remind[i].date.day == tmp_day) {

				cout << "\n ........remind [" << tmp_count << "]"

					<< "\n Date ( YY / MM / DD ) :"
					<< "   "
					<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

					<< "\n Time ( HH / MM ) :"
					<< "   "
					<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

					<< "\n title : " << array_remind[i].title
					<< "\n text : " << array_remind[i].text

					<< '\n';

				tmp_count++;
			}
		}

		if (tmp_count == 0) { cout << "\nThere is no remind ...."; }

		cout << "\n" << "______________________________________________" << endl;

		cout << "\n 1) add \n 2) edit \n 3) delete \n 4) delete_all \n 5) search_by_title \n 6) report \n 7) exit \n";

		cin >> choise;

		switch (choise) {

		case 1:

			add_remind();

			break;

		case 2:

			edit_remind();

			break;

		case 3:

			_delete();

			break;

		case 4:

			delete_all();

			break;

		case 5:

			search_by_title();

			break;

		case 6:

			report_reminds();

			break;

		case 7:

			exit();

			break;

		}
	}

	return 0;
}

void add_remind() { // add remind to reminder

			 //temp variable to store value from the user(time & date)
	int tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute;
	//temp variable to store value from the user(title & text)
	string tmp_title, tmp_text;

	system("cls");

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

	// To open if date and time was same with remind in the RAM cout warrnings 
	for (int i = 0; i <= 999; i++) {
		if (array_remind[i].date.year == tmp_year &&
			array_remind[i].date.month == tmp_month &&
			array_remind[i].date.day == tmp_day &&
			array_remind[i].time.hour == tmp_hour
			&& array_remind[i].time.minute == tmp_minute) {

			cout << "\nThere Is The Remind That Same Date With This Remind" << endl;
			char bool_INPUT;
			cout << "Are You Sure To Write It ?(Y/N)" << endl;
			cin >> bool_INPUT;
			if (bool_INPUT == 'Y' || bool_INPUT == 'y')
			{
				break;
			}
			else
			{
				return;//return to main menue
			}

		}
	}

	//to store value of temp variable on array_remind 
	array_remind[counter].date.year = tmp_year;
	array_remind[counter].date.month = tmp_month;
	array_remind[counter].date.day = tmp_day;
	array_remind[counter].time.hour = tmp_hour;
	array_remind[counter].time.minute = tmp_minute;
	array_remind[counter].title = tmp_title;
	array_remind[counter].text = tmp_text;

	// to counter plus plus when the user cin value to tmp variables
	counter++;
}

void edit_remind() {

	int tmp_year, tmp_month, tmp_day, tmp_hour, tmp_minute, tmp_choise, tmp_count = 0, temp_array[1000];
	string tmp_text, tmp_title;

	//too get range of date to edit it
	system("cls");
	cout << "Please open Your Year of Remind : ";
	cin >> tmp_year;
	cout << "Please open Your Month of Remind : ";
	cin >> tmp_month;
	cout << "Please open Your Day of Remind : ";
	cin >> tmp_day;

	//too open if tis date that given from user same with store data remind
	for (int i = 0; i <= 999; i++) {
		if (array_remind[i].date.year == tmp_year && array_remind[i].date.month == tmp_month && array_remind[i].date.day == tmp_day) {
			cout << "\n ........remind [" << tmp_count << ']'

				<< "\n Date ( YY / MM / DD ) :"
				<< "   "
				<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

				<< "\n Time ( HH / MM ) :"
				<< "   "
				<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

				<< "\n title : " << array_remind[i].title
				<< "\n text : " << array_remind[i].text

				<< '\n';
			temp_array[tmp_count] = i;//too choise what the remind has been edited
			tmp_count++;
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

	//check if the time and date of remind has been same with new remind cout error
	for (int i = 0; i <= 999; i++) {
		if (i == temp_array[tmp_choise]) continue;
		if (array_remind[i].date.year == tmp_year &&
			array_remind[i].date.month == tmp_month &&
			array_remind[i].date.day == tmp_day &&
			array_remind[i].time.hour == tmp_hour &&
			array_remind[i].time.minute == tmp_minute) {

			cout << "\nThere Is The Remind That Same Date With This Remind" << endl;
			char bool_INPUT;
			cout << "Are You Sure To Write It ?(Y/N)" << endl;
			cin >> bool_INPUT;
			if (bool_INPUT == 'Y' || bool_INPUT == 'y')
			{
				break;
			}
			else
			{
				return;
			}
		}
	}

	array_remind[temp_array[tmp_choise]].date.year = tmp_year;
	array_remind[temp_array[tmp_choise]].date.month = tmp_month;
	array_remind[temp_array[tmp_choise]].date.day = tmp_day;
	array_remind[temp_array[tmp_choise]].time.hour = tmp_hour;
	array_remind[temp_array[tmp_choise]].time.minute = tmp_minute;
	array_remind[temp_array[tmp_choise]].title = tmp_title;
	array_remind[temp_array[tmp_choise]].text = tmp_text;
}

void _delete() {// to delet special record from file

	int tmp_year, tmp_month, tmp_day, tmp_choise, tmp_count = 0, temp_array[1000];

	system("cls");
	cout << "Please open Your Year of Remind : ";
	cin >> tmp_year;
	cout << "Please open Your Month of Remind : ";
	cin >> tmp_month;
	cout << "Please open Your Day of Remind : ";
	cin >> tmp_day;

	for (int i = 0; i <= 999; i++) {
		if (array_remind[i].date.year == tmp_year &&
			array_remind[i].date.month == tmp_month &&
			array_remind[i].date.day == tmp_day) {
			cout << "\n ........remind " << tmp_count

				<< "\n Date ( YY / MM / DD ) :"
				<< "   "
				<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

				<< "\n Time ( HH / MM ) :"
				<< "   "
				<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

				<< "\n title : " << array_remind[i].title
				<< "\n text : " << array_remind[i].text

				<< '\n';
			temp_array[tmp_count] = i;
			tmp_count++;
		}
	}

	cout << "\n choose one of the reminds ......";

	do
	{
		cin >> tmp_choise;
		cout << "wrong choise ....\a" << endl;
		cin.clear();
		cout << "\n choose one of the reminds ......";
	} while (!(tmp_choise >= 0 && tmp_choise <= tmp_count - 1));


	array_remind[temp_array[tmp_choise]].date.year = NULL;
	array_remind[temp_array[tmp_choise]].date.month = NULL;
	array_remind[temp_array[tmp_choise]].date.day = NULL;
	array_remind[temp_array[tmp_choise]].time.hour = NULL;
	array_remind[temp_array[tmp_choise]].time.minute = NULL;
	array_remind[temp_array[tmp_choise]].title = "";
	array_remind[temp_array[tmp_choise]].text = "";

	counter--;
}

void report_reminds() {
	int choise, tmp_count = 0, tmp_year_first, tmp_month_first, tmp_day_first, tmp_year_seccond, tmp_month_seccond, tmp_day_seccond;

	system("cls");

	cout << "\n 1) show reminds list with open Date\n 2) show All reminds list \n 3) save reminds " << endl << endl;
	cin >> choise;
	switch (choise) {
	case 1:

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
			for (int i = 0; i <= 999; i++) {
				if (array_remind[i].date.year == tmp_year_first &&
					array_remind[i].date.month == tmp_month_first &&
					array_remind[i].date.day == tmp_day_first) {

					cout << "\n ........remind " << tmp_count

						<< "\n Date ( YY / MM / DD ) :"
						<< "   "
						<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

						<< "\n Time ( HH / MM ) :"
						<< "   "
						<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

						<< "\n title : " << array_remind[i].title
						<< "\n text : " << array_remind[i].text

						<< '\n';
				}
			}

			tmp_day_first++;

			if (tmp_day_first > 31) { tmp_day_first = 1; tmp_month_first++; }
			if (tmp_month_first > 12) { tmp_month_first = 1; tmp_year_first++; }
		}
		cout << "\n Press any key to continue ....\n";
		_getch();
		break;

	case 2:

		for (int i = 0; i < counter; i++) {

			cout << "\n ........remind " << tmp_count

				<< "\n Date ( YY / MM / DD ) :"
				<< "   "
				<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

				<< "\n Time ( HH / MM ) :"
				<< "   "
				<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

				<< "\n title : " << array_remind[i].title
				<< "\n text : " << array_remind[i].text

				<< '\n';

			tmp_count++;
		}
		cout << "\n Press any key to continue ....\n";
		_getch();
		break;

	case 3:
		system("cls");
		save();
		cout << "\n All Reminds has been Saved";
		Sleep(1500);
		break;

	}


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

void search_by_title()//to search title in all records
{
	string tmp_title;
	int tmp_count = 0;
	system("cls");
	cout << "Please Enter your Title :";
	cin >> tmp_title;
	for (int i = 0; i <= 999; i++) {
		if (array_remind[i].title == tmp_title) {

			cout << "\n ........remind " << tmp_count

				<< "\n Date ( YY / MM / DD ) :"
				<< "   "
				<< array_remind[i].date.year << ":" << array_remind[i].date.month << ":" << array_remind[i].date.day

				<< "\n Time ( HH / MM ) :"
				<< "   "
				<< array_remind[i].time.hour << ":" << array_remind[i].time.minute

				<< "\n title : " << array_remind[i].title
				<< "\n text : " << array_remind[i].text

				<< '\n';

			tmp_count++;
		}
	}
	cout << "\n press any key to continue ....\n";
	_getch();

}
void open() {
	ifstream open("amir_reminder.dat");
	if (open) {
		open >> counter;
		for (int i = 0; i <= 999; i++) {
			open >> array_remind[i].date.year;
			open >> array_remind[i].date.month;
			open >> array_remind[i].date.day;
			open >> array_remind[i].time.hour;
			open >> array_remind[i].time.minute;
			open >> array_remind[i].title;
			open.ignore();
			getline(open, array_remind[i].text);
		}
		open.close();
	}
}

void save() {//to save all array reminds into the amir_reminder.dat

	ofstream output("amir_reminder.dat");
	if (output) {//check if file open successfully
		fstream output("amir_reminder.dat", ios::out);
		output << counter << endl;
		for (int i = 0; i <= 999; i++) {
			output << array_remind[i].date.year << endl;
			output << array_remind[i].date.month << endl;
			output << array_remind[i].date.day << endl;
			output << array_remind[i].time.hour << endl;
			output << array_remind[i].time.minute << endl;
			output << array_remind[i].title << endl;
			output << array_remind[i].text << endl;
		}
		output.close();
	}
}

void exit()//to exit from program 
{
	cout << "This Program Wrriten by Amir Mohseninia...";
	Sleep(3000);//set sleep to to show top sentence
	exit(0);
}


///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
///@@ (C) Copyright 1999-2019 by AMIR MOHSENINIA All Rights Reserved.      @@//
///@@     visit my github page : github.com/amircloner                     @@//
///@@              website : www.jimzy.ir                                  @@//
///@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///