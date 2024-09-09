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
	// for (int i = 0; i <= 7 ; i++)
	// {

	// }
	std::cout << "[" << now_tm->tm_year + 1900 << "0" << now_tm->tm_mon + 1 << "0" << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]"
	<< " acounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}