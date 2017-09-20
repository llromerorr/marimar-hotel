#include "headers/Reservation.h"
#include "headers/Charge.h"
#include "headers/Application.h"

int main(void){

    while(Application_Menu_Main());
    
    Reservation_Memory_Clear();
    Charge_Memory_Clear();
    return EXIT_SUCCESS;
}