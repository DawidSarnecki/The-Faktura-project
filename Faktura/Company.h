#ifndef COMPANY_H  
#define COMPANY_H  
#pragma once
#include "Address.h"
#include <iostream>
using namespace std;
class Company
{
private:
	string companyName;
	string nip;
	Address address;
	string personToInvoice;
public:
	Company();
	Company(string cname);

	void setCompanyName(string cname);
	void setNip(string n);
	void setAddress(Address a);
	void setAddress(string str, string numb, string post, string cit);
	void setPerson(string person);

	string getCompanyName();
	string getNip();
	string getAddress();
	string getPerson();
	string getInfo();
	string getInfoInv();


};
#endif 