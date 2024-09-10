#include "Account.hpp"

int	Account:: _nbAccounts = 0;
int	Account:: _totalAmount = 0;
int	Account:: _totalNbDeposits = 0;
int	Account:: _totalNbWithdrawals = 0;

int	Account:: getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account:: getTotalAmount( void )
{
	return _totalAmount;
}

int	Account:: getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account:: getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

Account:: Account( int initial_deposit)
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}
void	Account:: displayAccountsInfos( void )
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);
	int total;

	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " acounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account:: displayStatus( void ) const
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);

	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account:: makeDeposit( int deposit )
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);

	this->_nbDeposits ++;
	this->_totalNbDeposits++;
	this->_amount += deposit;
	this->_totalAmount += deposit;

	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit
	<< ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account:: makeWithdrawal( int withdrawal )
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);


	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " index:" << _accountIndex << ";p_amount:" << _amount ;
	if(_amount < withdrawal)
		std::cout << ";withdrawal:refused\n";
	else
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
		this->_totalAmount -= withdrawal;
		std::cout << ";withdrawal:"<< withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std:: endl;
	}
	return 0;
}