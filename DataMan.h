#ifndef DATAMAN_H_INCLUDED
#define DATAMAN_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

	

struct user
{
	int id;
	char name[20];
	char Lname[20];
	char password[20];
	float balance;
};

void adduser();
int numOfuser();
user* UserDataInStruct();
void UpdateUserData(user* Client);

void writeATMcash(float);
float readATMcash();

void writeTransaction(int id,char name[],char Lname[],char desc[],int id2=0,char name2[]="",char Lname2="");




using namespace std;

int numOfuser()
{
	ifstream read;
	read.open("userDataBase.txt");
	
	char* useless = new char[1000];
	int counter=0; 
	while(!read.eof())
	{
		read.getline(useless,100,'\n');
		counter++;
	}
	
	read.close();
	delete [] useless;	
	return counter-1;	
}

user* UserDataInStruct()
{
	
	int size = numOfuser();

	ifstream read;
	read.open("userDataBase.txt");
	const int size2 = size;
	user* Client = new user[size2];
	
	for(int i = 0; i<size; i++)
	{
		read>>Client[i].id;
		read>>Client[i].name;
		read>>Client[i].Lname;
		read>>Client[i].password;
		read>>Client[i].balance;
	}

	read.close();

	return Client;	
}

//END OF MAIN FUCNTION



void adduser()
{
	
	string name;
	string Lname;
	string password;
	float balance;
	int id = numOfuser();
	
	cout<<"FirstName-> ";
	cin>>name;
	cout<<"LastName->";
	cin>>Lname;
	cout<<"Password-> ";
	cin>>password;
	cout<<"balance-> ";
	cin>>balance;

	
	ofstream write;

	write.open("userDataBase.txt",ios::app);
	write<<"1000"<<id<<" "<<name<<" "<<Lname<<" "<<password<<" "<<balance<<"\n";
	write.close();
	
}



void UpdateUserData(user* Client)
{
	int size = numOfuser();
	//user* Client = UsertDataInStruct();
	
	ofstream write;	
	write.open("userDataBase.txt");
	write.clear();
	
	
	
	for(int i = 0; i<size; i++)
	{
		write<<Client[i].id<<" ";
		write<<Client[i].name<<" ";
		write<<Client[i].Lname<<" ";
		write<<Client[i].password<<" ";
		write<<Client[i].balance<<" ";
		write<<"\n";
	}
	
	write.close();
	
}

void writeTransaction(int id,char name[],char Lname[],char desc[],int id2=0,char name2[]="",char Lname2[]="")
{
	
	ofstream write;	
	write.open("TransactionData.txt",ios::app);
	
	time_t now = time(0);
	char* Date = ctime(&now);

	write<<"\nDate: "<<Date<<"ID of user: "<<id<<"; Name of user: "<<name<<" "<<Lname
		  <<"; Type Of description: "<<desc<<"; ID of second user: "<<id2
		  <<"; Name of second user: "<<name2<<"\n";
	write.close();

}


void writeATMcash(float cash)
{
	ofstream write;	
	write.open("ATMdata.txt");
	write<<cash;
	write.close();
}

float readATMcash()
{
	float cash;
	ifstream read;	
	read.open("ATMdata.txt");
	read>>cash;
	
	read.close();
	return cash;
}
#endif

