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

 void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
    std::tm* now_tm = std::localtime(&now);

	std::cout << "[" << now_tm->tm_year + 1900  << now_tm->tm_mon + 1  << now_tm->tm_mday 
	<< "_" << now_tm->tm_hour << now_tm->tm_min << now_tm->tm_sec << "]";
}

Account:: Account( int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += _amount;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}
void	Account:: displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " acounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account:: displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
	<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account:: makeDeposit( int deposit )
{
	_nbDeposits ++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit
	<< ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account:: makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount ;
	if(_amount < withdrawal)
		std::cout << ";withdrawal:refused\n";
	else
	{
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << ";withdrawal:"<< withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std:: endl;
	}
	return 0;
}

Account:: ~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std:: endl;
}
