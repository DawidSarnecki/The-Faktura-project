#include "Address.h"
#include <iostream>
using namespace std;

Address::Address(){
	this->number = "no_input";
	this->street = "no_input";
	this->postalCode = "no_input";
	this->city = "no_input";
}
Address::Address(string str, string numb, string post, string cit) {
	this->street = str;
	this->number = numb;
	this->postalCode = post;
	this->city = cit;
};

void Address::setNumber(string numb) { this->number = numb; }
void Address::setStreet(string str) { this->street = str; }
void Address::setPostalCode(string post) { this->postalCode = post; }
void Address::setCity(string cit){ this->city = cit; }

string Address::getStreet() { return this->street; }
string Address::getNumber() { return this->number; }
string Address::getPostalCode() { return this->postalCode; }
string Address::getCity() { return this->city; }
string Address::getAddress() {
	string address_data;
	address_data = this->getStreet() + ' ' + this->getNumber()
		+ "; " + this->getPostalCode() + ' '+ this->getCity();
	return address_data;
}


