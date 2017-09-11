#include "Company.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Company::Company() {
	
	this->companyName = " Nowa firma ";
	this->nip = "no_input_NIP";
	this->address = Address();
	this->personToInvoice = ".......................";
}
Company::Company(string cname){
	this->companyName = cname;
	this->nip = "no_input_NIP";
	this->address = Address();
	this->personToInvoice = ".......................";
}


void Company::setCompanyName(string cname) { this->companyName = cname; }

void Company::setNip(string n) { this->nip = n; }

void Company::setAddress(Address a) { this->address = a; }

void Company::setAddress(string str,string numb,string post,string cit) { 
	this->address = Address(str, numb, post, cit); 
}

void Company::setPerson(string per) { this->personToInvoice = per; }

string Company::getCompanyName() { return this->companyName; }

string Company::getNip() { return this->nip; }

string Company::getAddress() { return address.getAddress(); }

string Company::getPerson() { return this->personToInvoice; }


string Company::getInfo() {
	string info;
	info =
		"\n DANE FIRMY-----------------------\n : Nazwa: " +
		this->getCompanyName() +
		"\n : NIP: " + this->getNip() +
		"\n : Adres: " + this->getAddress() +
		"\n : Osoba upowazniona: " + this->getPerson() +
		"\n----------------------------------";
	return info;
}

string Company::getInfoInv() {
	string info;
	info =
		"\n ----------------------------------\n : Nazwa: " +
		this->getCompanyName() +
		"\n : NIP: " + this->getNip() +
		"\n : Adres: " + this->getAddress() +
		"\n ----------------------------------";
	return info;
}




