#include "Reservation.h"
#include "Application.h"


int main(void){
    Time time = Time_New(13,7,1997);
    Time_Set_Day(&time, 21);
    puts(Time_ToString(time));
    return 0;
}