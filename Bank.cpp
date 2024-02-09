#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <cmath>
#include <cstdlib>
#pragma warning(disable : 4996)
using namespace std;

void displayDateTime(const std::tm* tPtr);

struct payBillNode
{
	string billType;
	long billInvoiceNumber;
	long double billAmount;
	payBillNode *next;
	payBillNode *prev;
};

class billPaymentQueue
{
private:
	payBillNode *front;
	payBillNode *rear;
public:
	billPaymentQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue()
	{
		payBillNode *temp = new payBillNode();
		char confirmation;

		cout << "\tKindly write down your bill type from the following: Electricity, Gas, Internet -> ";
		cin >> temp->billType;
		cout << "\tKindly write down the 10 digit Invoice Number -> ";
		cin >> temp->billInvoiceNumber;
		cout << "\tKindly write down the bill amount -> ";
		cin >> temp->billAmount;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Type : " << temp->billType << endl;
		cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\tPress 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (isEmpty())
			{
				temp->prev = NULL;
				front = rear = temp;
				cout << "\tTransaction Completed, Bill payment in process." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\tTransaction Completed, Bill payment in process." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\tTransaction not Completed." << endl;
		}
		else
		{
			cout << "\tERROR ERROR ERROR!!! Wrong input entered, transaction failed!" << endl;
			temp = NULL;
		}

		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void dequeue()
	{
		payBillNode *temp = front;

		if (isEmpty())
		{
			cout << "\tBill Payment Queue is empty, nothing left to process" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}
		else if (front == rear)
		{
			cout <<"\tBill# " << temp->billInvoiceNumber << " has been paid" << endl;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
			cout << "\tBill# " << temp->billInvoiceNumber << " has been paid." << endl;
		}
		delete temp;
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayBillPaymentQueue()
	{
		payBillNode *temp = front;
		
		if (isEmpty())
		{
			cout << "\tBill Payment Queue is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ <<" ---------------"<< endl;
			cout << "\t\t\t\tBill Type : " << temp->billType << endl;
			cout << "\t\t\t\tBill Invoice# : " << temp->billInvoiceNumber << endl;
			cout << "\t\t\t\tBill Amount : " << temp->billAmount << endl;
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayFront()
	{
		payBillNode *temp = front;

		if (isEmpty())
		{
			cout << "\tBill Payment Queue is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		cout << "\t\t\t\t------------------------------" << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tBill Amount: " << temp->billAmount << endl;
		cout << "\t\t\t\tBill Invoice#: " << temp->billInvoiceNumber << endl;
		cout << "\t\t\t\tBill Type: " << temp->billType << endl;
		cout << "\t\t\t\t------------------------------" << endl << endl;
		// temp = temp->next;
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
};

struct withdrawDepositNode
{
	long accountNumber;
	long double cashAmount;
	bool withdrawCash;
	bool depositCash;
	withdrawDepositNode *next;
	withdrawDepositNode *prev;
};

class withdrawDepositQueue
{
private:
	withdrawDepositNode *front;
	withdrawDepositNode *rear;
public:
	withdrawDepositQueue()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		if (rear == NULL && front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void enqueue()
	{
		withdrawDepositNode *temp = new withdrawDepositNode();

		int opt = 0;
		string flag = "";

		cout << "\tKindly choose from the following two options: 1) Withdraw Cash (cheque) or 2) Deposit Cash -> ";
		cin >> opt;

		if (opt == 1)
		{
			temp->withdrawCash = true;
			temp->depositCash = false;
			flag = "Withdraw Cash";
		}
		else if (opt == 2)
		{
			temp->depositCash = true;
			temp->withdrawCash = false;
			flag = "Deposit Cash";
		}
		else
		{
			cout << "\tWrong option entered, press any key to return to menu." << endl;
			_getch();
			return;
		}

		char confirmation;

		cout << "\tKindly write down the 10 digit Account Number -> ";
		cin >> temp->accountNumber;
		cout << "\tKindly write down the cash amount -> ";
		cin >> temp->cashAmount;
		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t\tAccount#: " << temp->accountNumber << endl;
		cout << "\t\t\t\tCash: " << temp->cashAmount << endl;
		cout << "\t\t\t\tTransaction Type: " << flag << endl;
		cout << "\t\t\t\t----------" << endl;
		cout << "\tPress 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (isEmpty())
			{
				temp->prev = NULL;
				front = rear = temp;
				cout << "\tTransaction Completed." << endl;
			}
			else
			{
				temp->prev = rear;
				rear->next = temp;
				rear = temp;
				cout << "\tTransaction Completed." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\tTransaction not Completed." << endl;
		}
		else
		{
			cout << "\tERROR ERROR ERROR!!! Wrong input entered, transaction failed!" << endl;
			temp = NULL;
		}

		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();

	}
	void dequeue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\tWithdraw/Deposit Queue is empty, nothing left to process" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}
		else if (front == rear)
		{
			cout << "\t\t\t\t----------" << endl;
			cout << "\t" << temp->accountNumber << endl;
			cout << "\t" << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\tTransaction has been done." << endl;
			front = rear = NULL;
		}
		else
		{
			front = front->next;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t" << temp->accountNumber << endl;
			cout << "\t" << temp->cashAmount << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\tTransaction has been done." << endl;
		}
		delete temp;
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayWithdrawDepositQueue()
	{
		withdrawDepositNode *temp = front;

		if (isEmpty())
		{
			cout << "\tWithdraw/Deposit Payment Queue is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 0;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t" << temp->accountNumber << endl;
			cout << "\t" << temp->cashAmount << endl;
			cout << "\tWithdraw =" << temp->withdrawCash << endl;
			cout << "\tDeposit =" << temp->depositCash << endl;
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
};


struct newAccountNode
{
	string Name;
	string accountStatus;
	long long phoneNumber;
	long long CNIC;
	long double cash;
	string emailAddress;
	bool debitCard;
	int debitCardPin;
	string username;
	string password;
	long accountNumber;
	newAccountNode *next;
	newAccountNode *prev;
};

class bankAccountsDatabase
{
public:
	newAccountNode *head, *tail;

public:
	bankAccountsDatabase()
	{
		head = tail = NULL;
	}
	void insertNewAccount()
	{
		newAccountNode *temp = new newAccountNode();

		char confirmation;
		int debitCardOpt = 0;
		int chequeBookOpt = 0;
		time_t t = time(NULL);
		tm* tPtr = localtime(&t);

		cout << "\tKindly write down your  Name -> ";
		cin >> temp->Name;
		cout << "\tKindly write down your Email Address -> ";
		cin >> temp->emailAddress;
		cout << "\tKindly write down your Phone Number -> ";
		cin >> temp->phoneNumber;
		cout << "\tKindly write down your CNIC -> ";
		cin >> temp->CNIC;
		cout << "\tDo you want to get a Debit Card: write Yes(1) or No(0)-> ";
		cin >> debitCardOpt;

		if (debitCardOpt == 1)
		{
			temp->debitCard = true;
			cout << "\tKindly write down your Debit Card PIN (4 Digits) -> ";
			cin >> temp->debitCardPin;
		}
		else if (debitCardOpt == 0)
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\tDebit card is set as No(0)" << endl;
		}
		else
		{
			temp->debitCard = false;
			temp->debitCardPin = 0;
			cout << "\tInvalid Option entered, debit card is set as No(N)" << endl;
		}

	TYPEAGAINUSNM:cout << "\tKindly write down your desired Username(NO Space Allowed) -> ";
		cin >> temp->username;

		if (checkUsernameClash(temp->username))
		{
			cout << "\tUsername has already been taken.!" << endl;
			goto TYPEAGAINUSNM;
		}

		cout << "\tKindly write down your desired Password(NO Space Allowed) -> ";
		cin >> temp->password;

		system("cls");

		displayDateTime(tPtr);

		cout<< " Horizon Union Bank Ltd.  #" << endl;
		cout<< "\t\t" << endl;
		cout<< "\t\t" << endl;

		cout << "\t\t\t\t----------" << endl;
		cout << "\t\t\t Name: " << temp->Name << endl;
		cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
		cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
		cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
		cout << "\t-------------" << endl;
		cout << "\t\t\t\tUsername: " << temp->username << endl;
		cout << "\t\t\t\tPassword: " << temp->password << endl;
		cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl;
		cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
		cout << "\tPress 'Y' to confirm, or 'N' to exit" << endl;
		cout << "\t", cin >> confirmation;
		temp->next = NULL;

		if (confirmation == 'y' || confirmation == 'Y')
		{
			if (head == NULL)
			{
				temp->prev = NULL;
				temp->cash = 900000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				head = tail = temp;
				cout << "\tAccount Details Completed, in process now." << endl;
			}
			else
			{
				temp->cash = 900000;
				temp->accountStatus = "In Process";
				temp->accountNumber = 0;
				temp->prev = tail;
				tail->next = temp;
				tail = temp;
				cout << "\tAccount Details Completed, in process now." << endl;
			}
		}
		else if (confirmation == 'n' || confirmation == 'N')
		{
			temp = NULL;
			cout << "\tAccount not Completed." << endl;
		}
		else
		{
			cout << "\tERROR ERROR ERROR!!! Wrong input entered, account opening failed!" << endl;
			temp = NULL;
		}

		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void viewAccountsToBeProcessed()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\tAccount Database is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t Name: " << temp->Name << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t-------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			}
			temp = temp->next;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void processAccounts()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\tAccount Database is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;
		int opt;

		while (temp != NULL)
		{
			if (temp->accountStatus == "In Process")
			{
				cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
				cout << "\t\t\t\t----------" << endl;
				cout << "\t\t\t Name: " << temp->Name << endl;
				cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
				cout << "\t-------------" << endl;
				cout << "\t\t\t\tUsername: " << temp->username << endl;
				cout << "\t\t\t\tPassword: " << temp->password << endl;
				cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
				cout << "\tDo you want to process this account or not? Yes(1) No(0)" << endl;
				cin >> opt;

				if (opt == 1)
				{
					temp->accountStatus = "Completed";
					temp->accountNumber = generateAccountNumber();
				}
				else if (opt == 0)
				{
					temp->accountStatus == "Declined";
				}
				else
				{
					cout << "\tWrong option entered, account not completed nor declined." << endl;
				}
			}		
			temp = temp->next;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	
	int countNodes()
	{
		int count = 0;

		if (head == NULL)
		{
			return count;
		}
		else
		{
			newAccountNode *temp = head;

			while (temp != NULL)
			{
				if (temp->accountStatus == "Completed")
				{
					count++;
				}
				temp = temp->next;	
			}
			return count;
		}
	}
	long generateAccountNumber()
	{
		long accNumber = 1007750 + countNodes() ;

		return accNumber;
	}
	void deleteAccount(long accountNum)
	{
		newAccountNode *temp = head;
		newAccountNode *findAndDelete;

		if (head == NULL)
		{
			cout << "\t\t\t\tAccount Database is empty, nothing is available to delete!!!!" << endl;
		}
		else if (head->accountNumber == accountNum)
		{
			head = head->next;
			findAndDelete = temp;
			temp = NULL;
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}

		int flag = 0;

		while (temp != NULL)
		{
			temp = temp->next;
			if (temp->accountNumber == accountNum)
			{
				findAndDelete = temp;
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				flag = 1;
			}
		}

		if (flag == 0)
		{
			cout << "\t\t\t\tAccount not found in database !!!!" << endl;
		}
		else if (flag == 1)
		{
			delete findAndDelete;
			cout << "\t\t\t\tAccount found in database and successfully deleted !!!!" << endl;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	newAccountNode *checkIfAccountPresent(string usernm, string paswd)
	{
		newAccountNode *temp = NULL;
		if (head == NULL)
		{
			cout << "\t\t\t\tAccount not found in Database, because database is empty." << endl;
			return temp;
		}

		temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernm && temp->password == paswd && temp->accountStatus == "Completed")
			{
				cout << "\t\t\t\tAccount found in Database." << endl;
				return temp;
			}
			temp = temp->next;
		}
		cout << "\t\t\t\tAccount not found in Database." << endl;

		return temp;
	}
	bool checkATMCredentials(int pn, long accNum)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->debitCardPin == pn && temp->accountNumber == accNum && temp->accountStatus == "Completed")
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	bool checkUsernameClash(string usernameEnt)
	{
		if (head == NULL)
		{
			return false;
		}

		newAccountNode *temp = head;

		while (temp != NULL)
		{
			if (temp->username == usernameEnt)
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	void withDrawCash(string usernm, string paswd, long double amount)
	{
		newAccountNode *withDrawAcc = checkIfAccountPresent(usernm, paswd);

		if (withDrawAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (amount > withDrawAcc->cash)
			{
				cout << "\t\t\t\tAccount does not contain this much cash, transaction failed !!!!" << endl;
				cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
				_getch();
				return;
			}

			withDrawAcc->cash = withDrawAcc->cash - amount;
			cout << "\t\t\t\tTransaction successful!" << endl;
			cout << "\t\t\t\tRemaining Balance -> " << withDrawAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void changeATMpin(string usernm, string paswd, int oldPin, int newPin)
	{

		newAccountNode *changePinAcc = checkIfAccountPresent(usernm, paswd);

		if (changePinAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, transaction failed !!!!" << endl;
		}
		else
		{
			if (newPin > 9999 || changePinAcc->debitCardPin != oldPin)
			{
				cout << "\t\t\t\tNew PIN is not 4 digits or Old PIN is invalid, process failed!!!!" << endl;
				return;
			}

			changePinAcc->debitCardPin = newPin;
			cout << "\t\t\t\tProcess successful!" << endl;
			cout << "\t\t\t\tPin Updated " << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void balanceEnquiry(string usernm, string paswd)
	{
		newAccountNode *balanceEnquiryAcc = checkIfAccountPresent(usernm, paswd);

		if (balanceEnquiryAcc == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\tAccount# -> " << balanceEnquiryAcc->accountNumber << endl;
			cout << "\t\t\t\tBalance -> " << balanceEnquiryAcc->cash << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAccountDetails(string usernm, string paswd)
	{
		newAccountNode *accountDisplay = checkIfAccountPresent(usernm, paswd);
		if (accountDisplay == NULL)
		{
			cout << "\t\t\t\tAccount not found in database, process failed !!!!" << endl;
		}
		else
		{
			cout << "\t\t\t\t------------------------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount#: " << accountDisplay->accountNumber << endl;
			cout << "\t\t\t\tAccount Status: " << accountDisplay->accountStatus << endl;
			cout << "\t\t\t Name: " << accountDisplay->Name << endl;
			cout << "\t\t\t\tEmail Address: " << accountDisplay->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << accountDisplay->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << accountDisplay->phoneNumber << endl;
			cout << "\t\t\t\tCash: " << accountDisplay->cash << endl;
			cout << "\t-------------" << endl;
			cout << "\t\t\t\tUsername: " << accountDisplay->username << endl;
			cout << "\t\t\t\tPassword: " << accountDisplay->password << endl;
			cout << "\t\t\t\tDebit Card: " << accountDisplay->debitCard << endl;
			cout << "\t\t\t\tDebit Card PIN: " << accountDisplay->debitCardPin << endl;
			cout << "\t\t\t\t------------------------------" << endl << endl;
		}
		cout << "\t\t\t\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
	void displayAllAccounts()
	{
		newAccountNode *temp = head;

		if (head == NULL)
		{
			cout << "\tAccount Database is empty" << endl;
			cout << "\tPress any key to return to Bank Menu" << endl;
			_getch();
			return;
		}

		int count = 1;

		while (temp != NULL)
		{
			cout << "\t\t\t\t--------------- #" << count++ << " ---------------" << endl;
			cout << "\t\t\t\t----------" << endl;
			cout << "\t\t\t\tAccount Status: " << temp->accountStatus << endl;
			cout << "\t\t\t\tAccount Number: " << temp->accountNumber << endl;
			cout << "\t\t\t Name: " << temp->Name << endl;
			cout << "\t\t\t\tEmail Address: " << temp->emailAddress << endl;
			cout << "\t\t\t\tCNIC: " << temp->CNIC << endl;
			cout << "\t\t\t\tPhone#: " << temp->phoneNumber << endl;
			cout << "\t-------------" << endl;
			cout << "\t\t\t\tUsername: " << temp->username << endl;
			cout << "\t\t\t\tPassword: " << temp->password << endl;
			cout << "\t\t\t\tDebit Card: " << temp->debitCard << endl; 
			cout << "\t\t\t\tDebit Card PIN: " << temp->debitCardPin << endl;
			cout << "\t\t\t\t--------------- #" << count << " ---------------" << endl << endl;
			temp = temp->next;
		}
		cout << "\tPress any key to return to Bank Menu" << endl;
		_getch();
	}
};

class admin
{
private:
	const string username = "admin";
	const string password = "admin"; 
public:
	admin()
	{

	}
	string getUserName() const
	{
		return username;
	}
	string getPassWord() const
	{
		return password;
	}
	bool checkCredentials(string userNm, string passWd)
	{
		if (userNm == username && passWd == password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void startScreen(tm* tPtr);
void endScreen(tm* tPtr);
void bankEnterScreen(tm* tPtr, int &opt);
void screenBank(tm* tPtr, int &opt);
void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber);
void screenATMtwo(tm* tPtr, int &opt);
void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword);
void screenAdminTwo(tm* tPtr, int &opt);
void screenAdminAccountOpenings(tm* tPtr, int &opt);
void screenAdminBillPayments(tm* tPtr, int &opt);


int main()
{
	time_t t = time(NULL);
	tm* tPtr = localtime(&t);
	int bankEnterOption = 0;
	int optionInBankOne = 0;
	int optionInBankTwo = 0;
	int optionInATMone = 0;
	int optionInATMtwo = 0;
	int optionInAdmin = 0;
	int optionInAdminAccOpen = 0;
	int optionInAdminBillPaymt = 0;
	long userCardNumber = 0;
	int userCardPIN = 0;
	string accountViewUsnm = "";
	string accountViewPaswd = "";
	string adminUserName;
	string adminPassword;
	int flag = 0;
	admin administrator;
	long double withdrawCash = 0.00;
	int oldPinChange = 0;
	int newPinChange = 0;
	bankAccountsDatabase accDatabase;
	billPaymentQueue billPaymentLine;
	withdrawDepositQueue withDwDepstLine;
	string usnmATM = "";
	string pssdATM = "";

	startScreen(tPtr);
	system("cls");
	
BANKSCREEN:bankEnterScreen(tPtr, bankEnterOption);
	system("cls");
	switch (bankEnterOption)
	{
	case 1:
		INSIDEBANK:screenBank(tPtr, optionInBankOne);
		system("cls");

		displayDateTime(tPtr);
		switch (optionInBankOne)
		{
		case 1:
			billPaymentLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 2:
			withDwDepstLine.enqueue();
			system("cls");
			goto INSIDEBANK;
			break;
		case 3:
			accDatabase.insertNewAccount();
			system("cls");
			goto INSIDEBANK;
			break;
		case 4:
			cout << "Enter Username: ", cin >> accountViewUsnm, cout << endl;
			cout << "Enter Password: ", cin >> accountViewPaswd, cout << endl;
			accDatabase.displayAccountDetails(accountViewUsnm, accountViewPaswd);
			system("cls");
			goto INSIDEBANK;
			break;
		case 5:
			system("cls");
			goto BANKSCREEN;
			break;
		default:
			system("cls");
			displayDateTime(tPtr);
			cout << " Wrong Option Entered, press any key to go back to Main Menu "<< endl;
			_getch();
			system("cls");
			goto INSIDEBANK;
			break;
		}
		break;
	case 2:
		MAINATMSCREEN:screenATMone(tPtr, userCardNumber, userCardPIN);
		system("cls");

		if (accDatabase.checkATMCredentials(userCardPIN, userCardNumber))
		{
		ATMSCREEN:screenATMtwo(tPtr, optionInATMtwo);
			system("cls");
			displayDateTime(tPtr);
			switch (optionInATMtwo)
			{
			case 1:
				cout << "# Enter amount you wish to withdraw -> ", cin >> withdrawCash;
				cout << "# Enter your username -> ", cin >> usnmATM;
				cout << "# Enter your password -> ", cin >> pssdATM;
				accDatabase.withDrawCash(usnmATM, pssdATM, withdrawCash);
				system("cls");
				goto ATMSCREEN;
				break;
			case 2:
				cout << "# Enter your username -> ", cin >> usnmATM;
				cout << "# Enter your password -> ", cin >> pssdATM;
				accDatabase.balanceEnquiry(usnmATM, pssdATM);
				system("cls");
				goto ATMSCREEN;
				break;
			case 3:
				cout << "# Enter your username -> ", cin >> usnmATM;
				cout << "# Enter your password -> ", cin >> pssdATM;
				cout << "# Enter old pin -> ", cin >> oldPinChange;
				cout << "# Enter new pin (4 Digits) -> ", cin >> newPinChange;
				accDatabase.changeATMpin(usnmATM, pssdATM, oldPinChange, newPinChange);
				system("cls");
				goto ATMSCREEN;
				break;
			case 4:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				displayDateTime(tPtr);
				cout << " Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ATMSCREEN;
				break;
			}
		}
		else
		{
			displayDateTime(tPtr);
			cout << "# Invalid Credentials Added" << endl;
			cout << "Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 3:
		screenAdminOne(tPtr, adminUserName, adminPassword);
		system("cls");
		if (administrator.checkCredentials(adminUserName, adminPassword))
		{
			ADMINSCREEN:screenAdminTwo(tPtr, optionInAdmin);
			system("cls");

			switch (optionInAdmin)
			{
			case 1:
				ACCOPPSCREN:screenAdminAccountOpenings(tPtr, optionInAdminAccOpen);
				system("cls");
				displayDateTime(tPtr);
				switch (optionInAdminAccOpen)
				{
				case 1:
					accDatabase.viewAccountsToBeProcessed();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 2:
					accDatabase.processAccounts();
					system("cls");
					goto ACCOPPSCREN;
					break;
				case 3:
					accDatabase.displayAllAccounts();
					system("cls");
					goto ACCOPPSCREN;
				case 4:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					displayDateTime(tPtr);
					cout<< " Horizon Union Bank Ltd.  #" << endl;
					cout << " Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto ACCOPPSCREN;
					break;
				}
			case 2:
				BILLPAYSCREEN:screenAdminBillPayments(tPtr, optionInAdminBillPaymt);
				system("cls");
				displayDateTime(tPtr);
				switch (optionInAdminBillPaymt)
				{
				case 1:
					billPaymentLine.displayBillPaymentQueue();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 2:
					billPaymentLine.displayFront();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 3:
					billPaymentLine.dequeue();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				case 4:
					system("cls");
					goto ADMINSCREEN;
					break;
				default:
					system("cls");
					displayDateTime(tPtr);
					cout<< " Horizon Union Bank Ltd.  #" << endl;
					cout << " Wrong Option Entered, press any key to go back to Main Menu " << endl;
					_getch();
					system("cls");
					goto BILLPAYSCREEN;
					break;
				}
				break;
			case 3:
				system("cls");
				goto BANKSCREEN;
				break;
			default:
				system("cls");
				displayDateTime(tPtr);
				cout << " Wrong Option Entered, press any key to go back to Main Menu " << endl;
				_getch();
				system("cls");
				goto ADMINSCREEN;
				break;
			}
		}
		else
		{
			displayDateTime(tPtr);
			cout << "# Invalid Credentials Added" << endl;
			cout << "Press any key to return to Bank Menu" << endl;
			_getch();
			system("cls");
			goto BANKSCREEN;
		}
		break;
	case 4:
		system("cls");
		endScreen(tPtr);
		break;
	default:
		system("cls");
		displayDateTime(tPtr);
		cout << " Wrong Option Entered, press any key to go back to Main Menu " << endl;
		_getch();
		system("cls");
		goto BANKSCREEN;
		break;
	}

	cout << "", system("pause");
	return 0;
}

void startScreen(tm* tPtr)
{
	displayDateTime(tPtr);

	cout << "\tWelcome to Domain Bank\t"<< endl;
	cout << "\t ",system("pause");
}

void endScreen(tm* tPtr)
{
	displayDateTime(tPtr);
}

void bankEnterScreen(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);

	cout<< "Choose an option:\n" << endl;
	cout<< "1) Enter Bank\n" << endl;
	cout<< "2) Enter ATM\n" << endl;
	cout<< "3) Admin Login\n" << endl;
	cout<< "4) Exit\n" << endl;
	cout << "Enter Option:",cin>>opt,cout<<endl;
}

void screenBank(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);

	cout<< " Horizon Union Bank Ltd.  #" << endl;
	cout<< "     Welcome to Bank" << endl;

	cout<< "   Choose an option:\n" << endl;
	cout<< "    1) Pay Bills" << endl;
	cout<< "    2) Deposits/Cheques          #" << endl;
	cout<< "    3) Open up Account" << endl;
	cout<< "    4) View your Account  #" << endl;
	cout<< "    5) Exit\t" << endl;

	cout << "Enter Option: ", cin >> opt, cout << endl;
}

void screenATMone(tm* tPtr, long &userCardNumber, int &userPINnumber)
{
	displayDateTime(tPtr);

	cout<< "Enter Following Details:#" << endl;
	cout<< "    1) Account Number" << endl;
	cout<< "    2) Debit Card PIN          #" << endl;
	
	cout << "Enter Account Number: ", cin >> userCardNumber, cout << endl;
	cout << "Enter Debit Card PIN: ", cin >> userPINnumber, cout << endl;
}

void screenATMtwo(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);

	cout<< "   Choose an option:          #" << endl;
	cout<< "    1) Withdraw Cash" << endl;
	cout<< "    2) Balance Inquiry          #" << endl;
	cout<< "    3) Change Pin" << endl;
	cout<< "    4) Exit\t" << endl;
	
	cout << "Enter Option: ", cin >> opt, cout << endl;
}

void screenAdminOne(tm* tPtr, string &adminUserName, string &adminPassword)
{
	displayDateTime(tPtr);

	cout<< "Enter Following Details:\t\t         #" << endl;
	cout<< "    1) Username\t" << endl;
	cout<< "    2) Password\t          #" << endl;
	
	cout << "Enter Username: ", cin >> adminUserName, cout << endl;
	cout << "Enter Password: ", cin >> adminPassword, cout << endl;
}
void screenAdminTwo(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);
	
	cout<< "   Choose an option:          #" << endl;
	cout<< "    1) Process Account Openings  #" << endl;
	cout<< "    2) Process Bill Payments\t\t         #" << endl;
	cout<< "    3) Exit\t" << endl;

	cout << "Enter Option: ", cin >> opt, cout << endl;
}
void screenAdminAccountOpenings(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);

	cout<< "   Choose an option:          #" << endl;
	cout<< "    1) View Account Openings  #" << endl;
	cout<< "    2) Process Accounts          #" << endl;
	cout<< "    3) View Accounts in Database\t         #" << endl;
	cout<< "    4) Exit\t" << endl;
	
	cout << "Enter Option: ", cin >> opt, cout << endl;
}
void screenAdminBillPayments(tm* tPtr, int &opt)
{
	displayDateTime(tPtr);
	
	cout<< "   Choose an option:          #" << endl;
	cout<< "    1) View Bill Payments  #" << endl;
	cout<< "    2) View Bill Payment at Front\t         #" << endl;
	cout<< "    3) Process Bill Payment at Front\t         #" << endl;
	cout<< "    4) Exit\t" << endl;
	
	cout << "Enter Option: ", cin >> opt, cout << endl;
}

void displayDateTime(const std::tm* tPtr) {
    std::cout << "\n\n\nDate: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << std::endl;
    std::cout << "Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << std::endl;
}