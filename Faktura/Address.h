#ifndef ADDRESS_H  
#define ADDRESS_H 
#pragma once
#include <iostream>
using namespace std;

class Address
{
private:
	string street;
	string number;
	string postalCode;
	string city;
public:
	Address();
	Address(string str, string numb, string post, string cit);

	void setNumber(string numb);
	void setStreet(string str);
	void setPostalCode(string post);
	void setCity(string cit);
	
	string getStreet();
	string getNumber();
	string getPostalCode();
	string getCity();
	string getAddress();
};
#endif 
