#include <stdio.h>
#include "Reservation.h"

int main(void){
    Reservation_File_Load();
    Reservation_Show_All();
    printf("RQ: %d\n", ReservationQuantity);
    return 0;
}