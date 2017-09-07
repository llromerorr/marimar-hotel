#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int day;
    int month;
    int year;
}Time;

char* TimeToString(Time time){
    char* TimeString = malloc(sizeof(char) * 15);
    char Bridge[8];

    sprintf(Bridge, "%d/", time.day);
    strcpy(TimeString, Bridge);
    sprintf(Bridge, "%d/", time.month);
    strcat(TimeString, Bridge);
    sprintf(Bridge, "%d", time.year);
    strcat(TimeString, Bridge);

    return TimeString;
}

int CheckTime(Time time){
    if(time.month < 1 || time.month > 12)   return 0;
	if(time.day < 1 || time.day > 31) 	    return 0;
	if(time.year < 0) 				        return 0;

	if (time.month==4||time.month==6||time.month==9||time.month==11)
		if(time.day > 30) return 0;
    if((time.year % 4 == 0) && (time.year % 100 != 0) || (time.year % 400 == 0)){
		if(time.month == 2)
			if(time.day > 29) return 0;
	}
	else if(time.month == 2)
		if(time.day > 28) return 0;

	return 1;
}

int CompareTime(Time Time1, Time Time2)
{
    if(Time1.year == Time2.year)
    {
        if(Time1.month == Time2.month)
        {
            if(Time1.day == Time2.day)      return  0;
            else if(Time1.day > Time2.day)  return  1;
            else if(Time1.day < Time2.day)  return -1;
        }
        else if(Time1.month > Time2.month)  return  1;
        else if(Time1.month < Time2.month)  return -1;
    }
    else if(Time1.year > Time2.year)        return  1;
    else if(Time1.year < Time2.year)        return -1;
}

Time ReturnTime(int day, int month, int year){
    Time time = {day, month, year};
    return time;
}

Time NullTime(){
    Time time = {0, 0, 0};
    return time;
}