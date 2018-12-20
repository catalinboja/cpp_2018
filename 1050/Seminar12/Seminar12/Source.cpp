#include <iostream>
#include <string>

using namespace std;

class InsufficientFundsException: public exception{
public:
	InsufficientFundsException(string msg):exception(msg.data()) {
	}
};

class IllegalTransferException : public exception {

};

class Account {
public:
	virtual void Deposit(double amount) = 0;
	virtual void Withdraw(double amount) = 0;
	virtual void Transfer(Account* destination, double amount) = 0;
	virtual double getBalance() = 0;
	virtual void getDescription() {
		cout << endl << "NOTHING";
	}
};

class BankAccount : public Account {
protected:
	string IBAN;
	double balance;
public:
	//override one of the virtual pure methods
	double getBalance() {
		return this->balance;
	}
	//override another one
	void Deposit(double amount) {
		if (amount <= 0)
			throw new IllegalTransferException();
		this->balance += amount;
	}

	void getDescription() {
		cout << endl << "GENERIC account with balance = " << this->balance;
	}

};

class CurrentAccount : public BankAccount {
	static double MAX_CREDIT;
public:
	CurrentAccount(string IBAN) {
		this->balance = CurrentAccount::MAX_CREDIT;
		this->IBAN = IBAN;
	}

	//override Withdraw
	void Withdraw(double amount) {
		if (amount <= 0)
			throw IllegalTransferException();
		if (this->balance - amount < 0)
			throw new InsufficientFundsException("Credit limit reached");
		this->balance -= amount;
	}

	void Transfer(Account* destination, double amount) {
		//check if the source is same with destination
		if (this == destination)
			throw new IllegalTransferException();
		if (destination == NULL)
			throw new IllegalTransferException();
		this->Withdraw(amount);
		destination->Deposit(amount);
	}

	void getDescription() {
		cout << endl << "CREDIT account with balance = " << this->balance;
	}
};

double CurrentAccount::MAX_CREDIT = 10000;

class SavingsAccount : public BankAccount {
	static double MIN_BALANCE;

public:
	SavingsAccount(string IBAN, double amount) {
		if (amount < SavingsAccount::MIN_BALANCE)
			throw InsufficientFundsException("You need to deposit at least 100");
		this->IBAN = IBAN;
		this->balance = amount;
	}

	//override Withdraw
	void Withdraw(double amount) {
		if (amount <= 0)
			throw IllegalTransferException();
		if (this->balance - amount < SavingsAccount::MIN_BALANCE)
			throw new InsufficientFundsException("You are out of money");
		this->balance -= amount;
	}

	void Transfer(Account* destination, double amount) {
		//check if the source is same with destination
		if (this == destination)
			throw new IllegalTransferException();
		if (destination == NULL)
			throw new IllegalTransferException();
		this->Withdraw(amount);
		destination->Deposit(amount);
	}

	void getDescription() {
		cout << endl << "DEPOSIT account with balance = " << this->balance;
	}
};

double SavingsAccount::MIN_BALANCE = 100;


int main() {
	//Account account;
	//using an abstract class as a pointer/reference type
	Account *aAccount;

	//is abstract because of its parent
	//BankAccount bankAccount;

	SavingsAccount deposit1("MyBank01", 200);
	SavingsAccount deposit2("MyBank02", 2000);
	
	CurrentAccount credit1("VirtualBank01");
	CurrentAccount credit2("VirtualBank01");

	credit2.Transfer(&deposit2, 500);

	cout << endl << "Deposit 2 balance is " << deposit2.getBalance();
	cout << endl << "Credit 2 balance is " << credit2.getBalance();

	Account* accounts[4];
	accounts[0] = &deposit1;
	accounts[1] = &credit1;
	accounts[2] = &deposit2;
	accounts[3] = &credit2;

	for (int i = 0; i < 4; i++)
		accounts[i]->getDescription();

}