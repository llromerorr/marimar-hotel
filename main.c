#include "headers/Reservation.h"
#include "headers/Charge.h"
#include "headers/Application.h"
#include "headers/Room.h"

int main(void){
    /*
    Application_Menu_Welcome();

    while(Application_Menu_Main());
    
    Reservation_Memory_Clear();
    Charge_Memory_Clear();
    */
    
    int * p = Room_Search_Free_ByAllPointer();
    for(int i = 0; p[i]; i++)
        printf("%d ", p[i]);
    Console_Pause();
    return EXIT_SUCCESS;
}