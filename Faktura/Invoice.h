#ifndef INVOICE_H  
#define INVOICE_H 
#pragma once
#include "Date.h"
#include "Company.h"
#include "Table.h"

class Invoice 
{
	friend class Menu;
private:
	string number;
	Date invDate;
	Date sellDate;
	Date payDate;
	Company anySeller;
	Company anyBuyer;
	Table anytable;
	string payForm;
	double totalToPay;

public:
	Invoice();
	string getInfo();
	string getShortInfo();
	void setSeller(Company);
	void setBuyer(Company);

	void writeTofile();	

	~Invoice();
};
#endif

