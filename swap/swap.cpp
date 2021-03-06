#include "pch.h"
#include <iostream>

// Prototypes for the transaction functions
void normalTransaction(int amount, int account);
void hackedTransaction(int amount, int& account, int& account2);

// Main loop
int main()
{
	// Create variables that store the funds of the two accounts
	int terroristAccount = 10000;
	int joesAccount = 500;

	// Print the two account balances to the console
	std::cout << "Bank of Terror Account Balance: " << terroristAccount << std::endl;
	std::cout << "Bank of Joe Account Balance: " << joesAccount << std::endl;

	// Call the normal transaction function and print the balances showing no change
	normalTransaction(10000000, terroristAccount);
	std::cout << "Bank of Terror Account Balance: " << terroristAccount << std::endl;
	std::cout << "Bank of Joe Account Balance: " << joesAccount << std::endl;

	// Call the hacked transaction function and print the balances showing the swapped accounts
	hackedTransaction(10000000, terroristAccount, joesAccount);
	std::cout << "Bank of Terror Account Balance: " << terroristAccount << std::endl;
	std::cout << "Bank of Joe Account Balance: " << joesAccount << std::endl;
}

// Normal transaction function is pass by value and changes nothing
void normalTransaction(int amount, int account)
{
	// Create temporary variable for the balance
	int balance = amount;
	// Set the amount of money equal to the copy of the account variable
	amount = account;
	// Set the copy of the account variable equal to the temp balance variable
	account = balance;
}

// Hacked transaction function is pass by reference and changes the values
void hackedTransaction(int amount, int& account, int& account2)
{
	// Set the first accounts value equal to the second account
	account = account2;
	// Set the second accounts value equal to the transaction ammount
	account2 = amount;
}
