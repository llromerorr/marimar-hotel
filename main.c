#include <stdio.h>
#include "List.h"

int main(void){
    for(int i = 1; i < 10;i++)
        NewReservation("none", "none", i, NullTime(), NullTime(), i);
    ShowAllReservation();
    //SaveReservation();
    return 0;
}