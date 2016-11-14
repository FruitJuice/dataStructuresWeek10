// dataStructuresWeek10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"

int getMonth();			//Returns a random number between 1 and 12
int getDay(int month);	//Returns a random date relevant to the month
int getYear();			//Returns a random year between 2013 and 2016
double getBalance();	//Returns a random number between -5000 and 5000

void printCustomer(struct customer customerX);	//Prints out customer data


//Structure definitions
typedef struct Date
{
	int day, month, year;
}date;

struct customer
{
	char name[50];			//String of the customers full name	
	int accountNumber;		//Customer account number starting with 10000
	double balance;			//Customer balance ranging from -5000 to 5000
	date lastTrans;	//Date of last transaction
};



int main()
{
	int i;
	struct customer customers[10];
	srand((unsigned)time(NULL));
	char names[10][50] = { "Dana Brown", "Liana Wolfe", "Christop Mays", "Chloe Duran","Spencer Thomas","Kyson Hill","Lucy Villegas","Jamiya Murray","Jaylon Gray","Valentina Love" };
	printf("Name \t\t\tAccount Number \tBalance \tDate of Last Transaction\n\n");
	for(i = 0; i < 10; i++)
	{
		strcpy_s(customers[i].name, names[i]);
		customers[i].accountNumber = 10000 + i;
		customers[i].balance = getBalance();
		customers[i].lastTrans.month = getMonth();
		customers[i].lastTrans.year = getYear();
		customers[i].lastTrans.day = getDay(customers[i].lastTrans.month);
		printCustomer(customers[i]);
	}
	return 0;
}


//Functions 

int getMonth()
{
	int randNum;
	randNum = rand() % 12 + 1;
	return randNum;
}

int getDay(int month)
{
	int day, max = 31;;
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		max = 30;

	}

	if((month == 2))
	{
		max = 28;
	}
	day = rand() % max + 1;

	return day;
}

int getYear()
{
	int year;
	year = rand() % (2016 + 1 - 2013) + 2013;
	return year;
}


double getBalance()
{
	double balance = 0;
	int sign;
	sign = rand() % 2;
	balance = rand() % 5000+1;
	if (sign == 0)
	{
		balance *= -1;
	}
	return balance;
}

void printCustomer(struct customer customerX)
{
	printf("%s \t\t%d \t\t%.2lf     \t%d/%d/%d\n", customerX.name, customerX.accountNumber, customerX.balance, customerX.lastTrans.day, customerX.lastTrans.month, customerX.lastTrans.year);
}

