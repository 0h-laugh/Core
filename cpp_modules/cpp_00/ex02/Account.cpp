// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Thu Nov 20 20:02:22 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"

#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	          << ";total:" << getTotalAmount()
	          << ";deposits:" << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0) {
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	int previous_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << previous_amount
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits
	          << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (_amount >= withdrawal) {
		int previous_amount = _amount;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "index:" << _accountIndex
		          << ";p_amount:" << previous_amount
		          << ";withdrawal:" << withdrawal
		          << ";amount:" << _amount
		          << ";nb_withdrawals:" << _nbWithdrawals
		          << std::endl;
		return true;
	} else {
		std::cout << "index:" << _accountIndex
		          << ";p_amount:" << _amount
		          << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm* localTime = std::localtime(&now);
	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
	std::cout << buffer << " ";
}
