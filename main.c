#include "Reservation.h"
#include "Charge.h"
#include "Application.h"


int main(void){
    Charge_File_Load();
    Charge_Show_All();
    Application_Pause();
    Charge ** p = Charge_Search_CIByPointer(12345678);

    Charge_Delete_ChargeByPointer(p[0]);
    puts("1 delete");

    Charge_Delete_ChargeByPointer(p[1]);
    puts("2 delete\n");

    Charge_Show_All();
    printf("Quantity: %d\n", ChargeQuantity);
    printf("first: %p ", Charge_FirstCharge);
    printf("last: %p ", Charge_LastCharge);
    printf("time: %s\n", Time_ToString(Charge_LastCharge->TimeCharge));
    Application_Pause();

    Charge_Delete_ChargeByPointer(p[2]);
    puts("3 delete");

    Charge_File_Save();
    puts("All is ok :D");
    return 0;
}