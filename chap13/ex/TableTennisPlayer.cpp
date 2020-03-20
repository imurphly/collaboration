#include "TableTennisPlayer.h"
#include <iostream>

//formatting stuff
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass
Brass::Brass(const string& fn, long num, double fd): fullname(fn), accNum(num), fund(fd) {}
void Brass::Deposite(double fd)
{
if(fd < 0)
std::cout << "negative deposite not allowed.\n";
else
fund += fd;
}

void Brass::Withdraw(double fd)
{
format initialState = setFormat();
precis prec = std::cout.precision(2);

if(fd < 0)
std::cout << "negative withdraw is not allowed.\n";
else if(fund >= fd)
fund -=fd;
else
std::cout << "Withdraw exceeds your balance.\n";
restore(initialState, prec);
}

std::ostream& operator<<(std::ostream& os, const Brass& bs)
{
std::cout << bs.fullname << " has account: " << bs.accNum << ", balance: " << bs.fund << std::endl;
}

//BrassPlus
BrassPlus::BrassPlus(const string& fn, long num, double fd, double ml, double rt, double ok): Brass(fn, num, fd), maxLoan(ml), rate(rt), owesBank(ok) {}

BrassPlus::BrassPlus(const Brass& bs, double ml, double rt, double ok): Brass(bs), maxLoan(ml), rate(rt), owesBank(ok) {}

std::ostream& operator<<(std::ostream& os, const BrassPlus& bs)
{
const Brass& bs1 = bs;
std::cout << bs1 << "maxLoan: " << bs.maxLoan << ", rate: " << bs.rate << ", owes to bank: " << bs.owesBank << std::endl;
}


void BrassPlus::Withdraw(double fd)
{
double fund = Balance();
format initialState = setFormat();
precis prec = std::cout.precision(2);

if(fund < fd)
 {
 if(fund+maxLoan-owesBank > fd)
{
double advance = fd - fund;
owesBank += advance*(1.0 + rate);
std::cout << "bank advance: $" << advance << std::endl;
std::cout << "Finance charge: $" << advance*rate << std::endl;
Deposite(advance);
Brass::Withdraw(fd); 
}
else
std::cout << "Your withdraw is arrived to maximun.";
//restore(initialState, prec);
 }
else
Brass::Withdraw(fd);
restore(initialState, prec);
}

void BrassPlus::ResetMax(double ml)
{maxLoan = ml;}
void BrassPlus::ResetRate(double rt)
{rate = rt;}
void BrassPlus::ResetOwe()
{owesBank = 0;}

format setFormat()
{return std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);}

void restore(format f, precis p)
{
std::cout.setf(f, std::ios_base::floatfield);
std::cout.precision(2);
}

//RatedPlayer
RatedPlayer::RatedPlayer(unsigned int r, const string& fn, const string& ln, bool ht):TableTennisPlayer(fn, ln, ht), rating(r) {}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer& tp):TableTennisPlayer(tp), rating(r){}
std::ostream& operator<<(std::ostream& os, const RatedPlayer& rp) 
{
const TableTennisPlayer& tp = rp;
std::cout << tp << "Rating: " << rp.rating << std::endl;
}


//TableTennisPlayer
TableTennisPlayer::TableTennisPlayer(const string& fn, const string& ln, bool ht): firstname(fn), lastname(ln), hasTable(ht){}
void TableTennisPlayer::Name() const {std::cout << lastname << ", " << firstname << std::endl;}
std::ostream& operator<<(std::ostream& os, const TableTennisPlayer& tp) 
{
std::cout << tp.lastname << ", " << tp.firstname;
if(tp.HasTable())
std::cout << " has a table. \n";
else
std::cout << " hasn't a table. \n";
}
