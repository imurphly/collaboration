#ifndef _TABLE_TENNIS_PLAYER_H
#define _TABLE_TENNIS_PLAYER_H
#include <string>
using std::string;

//记录会员的姓名和是否有球桌
class TableTennisPlayer
{
private:
string firstname;
string lastname;
bool hasTable;
public:
TableTennisPlayer(const string& fn = "no name", const string& ln = "no name", bool ht = false);
void Name() const;
bool HasTable() const {return hasTable;}
void ResetTable(bool v) {hasTable = v;}
friend std::ostream& operator<<(std::ostream& os, const TableTennisPlayer& tp);
};

class RatedPlayer: public TableTennisPlayer
{
private:
unsigned int rating;
public:
RatedPlayer(unsigned int r = 0, const string& fn = "no name", const string& ln = "no name", bool ht = false);
RatedPlayer(unsigned int r, const TableTennisPlayer& tp);
unsigned int Rating() const {return rating;}
void ResetRating(unsigned int r) {rating = r;}
friend std::ostream& operator<<(std::ostream& os, const RatedPlayer& tp);
};

class Brass
{
private:
string fullname;
long accNum;
double fund;
public:
Brass(const string& fn= "no name", long num = 0, double fd = 0.0);
void Deposite(double fd);
virtual void Withdraw(double fd);
friend std::ostream& operator<<(std::ostream& os, const Brass& bs);
double Balance() const {return fund;}
virtual ~Brass() {}
};

class BrassPlus: public Brass
{
private:
double maxLoan;
double rate;
double owesBank;
public:
BrassPlus(const string& fn= "no name", long num = 0, double fd = 0.0, double ml = 500.0, double rt = 0.11125, double ok = 0.0);
BrassPlus(const Brass& bs, double ml = 500.0, double rt = 0.11125, double ok = 0.0);
virtual void Withdraw(double fd);
friend std::ostream& operator<<(std::ostream& os, const BrassPlus& bs);
void ResetMax(double ml);
void ResetRate(double rt);
void ResetOwe();
};
#endif
