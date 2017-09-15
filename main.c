#include "Reservation.h"
#include "Charge.h"
#include "Application.h"


int main(void){
    Charge_New_Null();
    Charge_New_Null();
    Charge_New_Null();
    Charge_New_Null();
    Charge_New_Null();
    Charge_Set_CI(3, 26729561);
    Charge * p = Charge_Search_CI(26729561);
    p->Cost = 999;
    Charge_Show_All();
    return 0;
}