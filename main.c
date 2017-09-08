#include <stdio.h>
#include "List.h"

int main(void){
    for(int i = 1; i < 10;i++)
        NewReservation("none", "none", i, NullTime(), NullTime(), i);
    for(int i = 1; i < 10;i++)
        DeleteReservation(1);
    ShowAllReservation();
    return 0;
}