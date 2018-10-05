// Author: Sean Davis

#ifndef TIME_H
#define	TIME_H

typedef struct
{
  short hour;
  short minute;
}  Time;

bool lessThan(Time *time1, Time *time2);
void print(Time *time);
void read(Time *time);


#endif	// TIME_H 

