#ifndef _TV_H 
#define _TV_H
#include <iostream>


enum {Off, On};
enum {MinVal, MaxVal = 20};
enum {Antenna, Cable};
enum {TV, DVD};

class Tv;

class Remote
{
friend class Tv;
public:
enum {Normal, Inter};
private:
int mode;
int inter;
public:
Remote(int m = TV, int inter = Inter): mode(m), inter(Inter) {}
bool volup(Tv& t);
bool voldown(Tv& t);
void onoff(Tv& t);
void channelup(Tv& t);
void channeldown(Tv& t);
void set_mode(Tv& t);
void set_input(Tv& t);
void set_chan(Tv& t, int c);
void show_mode() const {std::cout << "remote mode: " << mode << "\n";}
};

class Tv
{
friend void Remote::set_chan(Tv& t, int c);
private:
int state;
int volumn;
int maxchannel;
int channel;
int mode;
int input;
public:
Tv(int s = Off, int mc=125): state(s), volumn(5), maxchannel(mc), mode(Cable), input(TV) {}
~Tv() {}
void onoff() {state = (state==On)? Off: On;}
bool ison() const {return state==On;}
bool volup();
bool voldown();
void channelup();
void channeldown();
void set_mode() {mode = (mode==Antenna)? Cable: Antenna;}
void set_input() {input = (input == TV)? DVD: TV;}
void settings() const;
void SwitchRemote(Remote& r) {r.inter = (r.inter==Remote::Inter?Remote::Normal:Remote::Inter);}
};


inline bool Remote::volup(Tv& t) {return t.volup();}
inline bool Remote::voldown(Tv& t) {return t.voldown();}
inline void Remote::onoff(Tv& t) {t.onoff();}
inline void Remote::channelup(Tv& t) {t.channelup();}
inline void Remote::channeldown(Tv& t) {t.channeldown();}
inline void Remote::set_mode(Tv& t) {t.set_mode();}
inline void Remote::set_input(Tv& t) {t.set_input();}
inline void Remote::set_chan(Tv& t, int c) {t.channel = c;}

#endif
