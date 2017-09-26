#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int Day;
    int Month;
    int Year;
}Time;

char* Time_ToString(Time time){
    char* TimeString = malloc(sizeof(char) * 15);
    char Bridge[8];

    sprintf(Bridge, "%.2d/", time.Day);
    strcpy(TimeString, Bridge);
    sprintf(Bridge, "%.2d/", time.Month);
    strcat(TimeString, Bridge);
    sprintf(Bridge, "%.4d", time.Year);
    strcat(TimeString, Bridge);

    return TimeString;
}

int Time_ToDays(Time time){
    return (time.Year * 365) + ((time.Month) * 30) + time.Day;
}

int Time_Check(Time time){
    if(time.Month < 1 || time.Month > 12)   return 0;
	if(time.Day < 1 || time.Day > 31) 	    return 0;
	if(time.Year < 0) 				        return 0;

	if (time.Month==4||time.Month==6||time.Month==9||time.Month==11)
		if(time.Day > 30) return 0;
    if(((time.Year % 4 == 0) && (time.Year % 100 != 0)) || (time.Year % 400 == 0)){
		if(time.Month == 2)
			if(time.Day > 29) return 0;
	}
	else if(time.Month == 2)
		if(time.Day > 28) return 0;

	return 1;
}

int Time_Compare(Time Time1, Time Time2)
{
    if(Time1.Year == Time2.Year)
    {
        if(Time1.Month == Time2.Month)
        {
            if(Time1.Day == Time2.Day)      return  0;
            else if(Time1.Day > Time2.Day)  return  1;
            else if(Time1.Day < Time2.Day)  return -1;
        }
        else if(Time1.Month > Time2.Month)  return  1;
        else if(Time1.Month < Time2.Month)  return -1;
    }
    else if(Time1.Year > Time2.Year)        return  1;
    else if(Time1.Year < Time2.Year)        return -1;
    return 0;
}

void Time_Copy(Time *time1, Time time2){
    time1->Day = time2.Day;
    time1->Month = time2.Month;
    time1->Year = time2.Year;
}

Time Time_New(int Day, int Month, int Year){
    Time time = {Day, Month, Year};
    return time;
}

Time Time_Null(){
    Time time = {0, 0, 0};
    return time;
}

//-------------------Setters and Getters---------------------

void Time_Set_Day(Time * time, int Day){
    time->Day = Day;
}

void Time_Set_Month(Time * time, int Month){
    time->Month = Month;
}

void Time_Set_Year(Time * time, int Year){
    time->Year = Year;
}

int Time_Get_Day(Time * time){
    return time->Day;
}

int Time_Get_Month(Time * time){
    return time->Month;
}

int Time_Get_Year(Time * time){
    return time->Year;
}

//--------------------------Others---------------------------
int Time_DaysBetween(Time t1, Time t2){
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};
    
    int lp1 = (t1.Month <= 2) 
                ? (t1.Year-1)/4 - (t1.Year-1)/100 + (t1.Year-1)/400
                : t1.Year/4 - t1.Year/100 + t1.Year/400;

    int lp2 = (t2.Month <= 2) 
                ? (t2.Year-1)/4 - (t2.Year-1)/100 + (t2.Year-1)/400
                : t2.Year/4 - t2.Year/100 + t2.Year/400;
 
    long int n1 = t1.Year*365 + t1.Day;
    for (int i=0; i<t1.Month - 1; i++)
        n1 += monthDays[i];
    
    n1 += lp1;

    long int n2 = t2.Year*365 + t2.Day;
    for (int i=0; i<t2.Month - 1; i++)
        n2 += monthDays[i];
    
    n2 += lp2;
    return (n2 - n1);
}

#endif /* TIME_H */