#include <iostream>
#include <string>

using namespace std;

class InsufficientFundsException: public exception {

};

class IllegalTransferException : public exception {
public:
	IllegalTransferException(string msg): exception(msg.data()) {
	}
};

class Account {
public:
	virtual void Deposit(double amount) = 0;
	virtual void Withdraw(double amount) = 0;
	virtual double getBalance() = 0;
	virtual void Transfer(double amount, Account* destination) = 0;
};

class BankAccount : public Account {
protected:
	double balance = 0;
	string iban;

public:
	double getBalance() {
		return this->balance;
	}

	void Deposit(double amount) {
		if (amount > 0)
			this->balance += amount;
		else
			throw new IllegalTransferException("Received a value <=0");
	}

	BankAccount(string iban, double balance) {
		this->iban = iban;
		this->Deposit(balance);
	}
};

class CurrentAccount: public BankAccount {

private:
	static double MAX_CREDIT;
public:
	CurrentAccount(string iban) : BankAccount(iban, MAX_CREDIT) {

	}

	void Withdraw(double amount) {
		if(amount <= 0)
			throw new IllegalTransferException("Zero or negative value");
		if (this->balance - amount < 0)
			throw new InsufficientFundsException();
		this->balance -= amount;
	}

	void Transfer(double amount, Account* destination){
		if (this == destination)
			throw new IllegalTransferException("Same accounts");
		//alternative: you should check the ibans
		//CurrentAccount* destAccount = (CurrentAccount*)destination;
		//if(this->iban._Equal(destAccount->iban.data()))
		//	throw new IllegalTransferException("Same accounts");

		this->Withdraw(amount);
		destination->Deposit(amount);
	}
};
double CurrentAccount::MAX_CREDIT = 5000;

class SavingsAccount : public BankAccount {
	static double MIN_BALANCE;
public:
	SavingsAccount(string iban, double amount) : BankAccount(iban,amount) {
		if (amount < MIN_BALANCE)
			throw new InsufficientFundsException();
	}

	void Withdraw(double amount) {
		if (amount <= 0)
			throw new IllegalTransferException("Zero or negative value");
		if (this->balance - amount < MIN_BALANCE)
			throw new InsufficientFundsException();
		this->balance -= amount;
	}

	void Transfer(double amount, Account* destination) {
		if (this == destination)
			throw new IllegalTransferException("Same accounts");
		//alternative: you should check the ibans
		this->Withdraw(amount);
		destination->Deposit(amount);
	}
};

double SavingsAccount::MIN_BALANCE = 100;

int main() {
	//Account account;
	//BankAccount bankAccount;

	//use the abstract class as a reference/pointer type
	Account *pAccount;

	CurrentAccount credit1("MYBank00001");
	CurrentAccount credit2("MYBank00002");

	SavingsAccount deposit1("MyBankD0001", 500);
	SavingsAccount deposit2("MyBankD0001", 1000);

	Account* accounts[4];
	accounts[0] = &credit1;
	accounts[1] = &credit2;
	accounts[2] = &deposit1;
	accounts[3] = &deposit2;

	credit1.Transfer(500, &deposit1);

	for (int i = 0; i < 4; i++)
	{
		cout << endl << "The account value is " << accounts[i]->getBalance();
	}
}