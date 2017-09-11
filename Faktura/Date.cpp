#include "Date.h"
#include <string>
#include <ctime>


Date::Date() {
	time_t t = time(NULL);
	tm* ltm = localtime(&t);// get time now
	 // set actual date
	this->day = ltm->tm_mday;
	this->month = 1 + ltm->tm_mon;
	this->year = 1900 + ltm->tm_year;
	//this->weekd = ltm ->tm_wday;
};

void Date::setDay(int d) { this->day = d; }
void Date::setMonth(int m) {this-> month = m; }
void Date::setYear(int y) { this->year = y; }

int Date::getDay() { return this->day; }
int Date::getMonth() { return this->month; }
int Date::getYear() { return this->year; }
string Date::getDateStamp() { 
	string stamp;
	stamp = to_string(this->day) +"-"+ to_string(this->month) +"-"
		+ to_string(this->year);
	return stamp;
	 }

void  Date::menuData() {
	int str;
	cout << " -> podaj dzien: ";
	cin >> str;
	setDay(str);
	cout << " -> podaj miesiac: ";
	cin >> str;
	setMonth(str);
	cout << " -> podaj rok: ";
	cin >> str;
	setYear(str);
	cout << "ustawiono date: " << getDateStamp() << endl;
}