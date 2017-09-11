#define _CRT_SECURE_NO_WARNINGS
#ifndef DATE_H  
#define DATE_H  
#pragma once
#include <ctime>
#include <iostream>
using namespace std;


class Date
{
private:
	int day;
	int month;
	int year;
	//int weekd;

public:
	Date();

	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void menuData();

	int getDay();
	int getMonth();
	int getYear();
	string getDateStamp();
};
#endif 