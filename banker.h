#ifndef BANKER_H_INCLUDED
#define BANKER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iostream>
#include <cstring>

#include "DataMan.h"


bool isClient(int id,char pin[]);
int getIndex(int id);


void CoreWithdrow(user &customer,float ammount);
void CoreTransfer(user &customer,user &customer2, float amount);
void CorePinChange(user &customer,char newPin[]);

user* client = UserDataInStruct();
int size = numOfuser();

using namespace std;



bool isClient(int id,char pin[])
{
	
	
	bool B; 
	for(int i=0; i<size;i++)
	{
		B = (id == client[i].id) && !strcmp(pin,client[i].password); 
		if(B)
		{
			return true;
		}
	}
	
	return false;
	
}


int getIndex(int id)
{
	
	bool B; 
	for(int i=0; i<size;i++)
	{
		B = (id == client[i].id); 
		B = (id == client[i].id); 
		if(B)
		{
			return i;
		}
	}
	
	return 0;
}

void CoreWithdrow(user &customer,float ammount)
{
		float ATMcash = readATMcash();
		
		bool B = (ammount <= customer.balance ) && (ammount<=5000) && (ammount >= 50) && (ATMcash>=ammount);
		if(B)
			customer.balance -= ammount;
			//we might need to add else here
			
		writeATMcash(ATMcash-ammount);
		UpdateUserData(client);
}

void CoreTransfer(user &customer,user &customer2, float amount)
{
	bool B = (amount <= customer.balance ) && (amount<=5000) && (amount >= 50);
	
	if(B)
	{
		customer.balance -= amount;
		customer2.balance += amount;
	};
	UpdateUserData(client);
}

void CorePinChange(user &customer,char newPin[])
{
	strcpy(customer.password,newPin);
	UpdateUserData(client);	
}
#endif
