#include <iostream>
#include "Tv.h"
using std::cout;

bool Tv::volup()
{
	if(volumn < MaxVal)
       {
++volumn;
return true;
     }
return false;
}

bool Tv::voldown()
{
if(volumn > MinVal)
{
--volumn;
return true;
}
return false;
}

void Tv::channelup()
{
if(channel < maxchannel)
{++channel;}
else
channel = 1;
}

void Tv::channeldown()
{
if(channel > 1)
--channel;
else
channel = maxchannel;
}

void Tv::settings() const
{
cout << "Tv is " << (state==On? "On":"off") << "\n";
if(state == On)
{
cout << "volumn: " << volumn << "\n";
cout << "channel: " << channel << "\n";
cout << "mode: " << mode << "\n";
cout << "input: " << mode << "\n";
}
}

