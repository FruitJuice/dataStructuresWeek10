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
struct date
{
	int day, month, year;
};

struct customer
{
	char name[50];			//String of the customers full name	
	int accountNumber;		//Customer account number starting with 10000
	double balance;			//Customer balance ranging from -5000 to 5000
	struct date lastTrans;	//Date of last transaction
};



int main()
{
	int i;
	int factor = 1;
	struct customer customers[10];
	char names[10][50] = { "Dana Brown", "Liana Wolfe", "Christop Mays", "Chloe Duran","Spencer Thomas","Kyson Hill","Lucy Villegas","Jamiya Murray","Jaylon Gray","Valentina Love" };
	printf("Name \t\t\tAccount Number \tBalance \tDate of Last Transaction\n\n");
	for(i = 0; i < 10; i++)
	{
		srand(factor*time(NULL));//Generates a new seed for each customers[i] by multiplying by an increasing number
		strcpy_s(customers[i].name, names[i]);
		customers[i].accountNumber = 10000 + i;
		customers[i].balance = getBalance();
		customers[i].lastTrans.month = getMonth();
		customers[i].lastTrans.year = getYear();
		customers[i].lastTrans.day = getDay(customers[i].lastTrans.month);
		printCustomer(customers[i]);
		factor++; // Increases the number by which seed is multiplied
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
	int day;
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		day = rand() % 31 + 1;
	}

	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		day = rand() % 30 + 1;

	}

	if((month == 2))
	{
		day = rand() % 28 + 1;
	}
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

