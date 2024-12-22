#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include "cum_uS.h"

static void headerCumulativesFile(FILE* file, cumlog_params_for_uS_t* logs, int32_t no_cumulative, int32_t no_cumulatives);

#define MAX_STRING_SIZE	(uint16_t)0xFFFF

cumlog_params_for_uS_t cumlog_params_for_uS =
{
    // .structure.nor_first_byte_page = 0xFF, //uint8_t
    // .structure.remain_SOH = 0xFF, //uint8_t
    // .structure.working_time_DCh = 0xFFFF, //uint16_t
    // .structure.working_time_Ch = 0xFFFF, //uint16_t
    // .structure.cycle_total = 0xFFFF, //uint16_t
    // .structure.discharged_Ah = 0xFFFFFFFF, //uint32_t
    // .structure.number_of_deep_discharge = 0xFFFFFFFF, //uint32_t
    // .structure.regenerated_Ah = 0xFFFFFFFF, //uint32_t
    // .structure.discharged_Wh = 0xFFFFFFFF, //uint32_t
    // .structure.regenerated_Wh = 0xFFFFFFFF, //uint32_t
    // .structure.charged_Ah = 0xFFFFFFFF, //uint32_t
    // .structure.charged_Wh = 0xFFFFFFFF, //uint32_t
    // .structure.standby_Ah = 0xFFFFFFFF, //uint32_t
    // .structure.standby_Wh = 0xFFFFFFFF, //uint32_t 
    // .structure.discharged_Ah_in_charge = 0xFFFFFFFF, //uint32_t 
    // .structure.discharged_Wh_in_charge = 0xFFFFFFFF, //uint32_t 
    // .structure.service_temperature = 0xFFFF, //int16_t 
    // .structure.st_discharge_time = 0xFFFF, //uint16_t
    // .structure.st_discharge_avg = 0xFFFF, //int16_t
    // .structure.st_charge_time = 0xFFFF, //uint16_t
    // .structure.st_charge_avg = 0xFFFF, //int16_t
    // .structure.st_standby_time = 0xFFFF, //uint16_t
    // .structure.st_standby_avg = 0xFFFF, //int16_t 
    // .structure.last_charge_date = 0xFFFFFFFF, //uint32_t
    // .structure.last_complete_charge_date = 0xFFFFFFFF, //uint32_t
    // .structure.number_of_complete_charge = 0xFFFF, //uint16_t
    // .structure.remain_SOH_raw = 0xFFFFFFFF, //uint32_t
    // .structure.build_number = 0xFFFF, //uint16_t   

    .structure.nor_first_byte_page = 1, //uint8_t
    .structure.remain_SOH = 2, //uint8_t
    .structure.working_time_DCh = 3, //uint16_t
    .structure.working_time_Ch = 4, //uint16_t
    .structure.cycle_total = 5, //uint16_t
    .structure.discharged_Ah = 6, //uint32_t
    .structure.number_of_deep_discharge = 7, //uint32_t
    .structure.regenerated_Ah = 8, //uint32_t
    .structure.discharged_Wh = 9, //uint32_t
    .structure.regenerated_Wh = 10, //uint32_t
    .structure.charged_Ah = 11, //uint32_t
    .structure.charged_Wh = 12, //uint32_t
    .structure.standby_Ah = 13, //uint32_t
    .structure.standby_Wh = 14, //uint32_t 
    .structure.discharged_Ah_in_charge = 15, //uint32_t 
    .structure.discharged_Wh_in_charge = 16, //uint32_t 
    .structure.service_temperature = 17, //int16_t 
    .structure.st_discharge_time = 18, //uint16_t
    .structure.st_discharge_avg = 19, //int16_t
    .structure.st_charge_time = 20, //uint16_t
    .structure.st_charge_avg = 21, //int16_t
    .structure.st_standby_time = 22, //uint16_t
    .structure.st_standby_avg = 23, //int16_t 
    .structure.last_charge_date = 24, //uint32_t
    .structure.last_complete_charge_date = 25, //uint32_t
    .structure.number_of_complete_charge = 26, //uint16_t
    .structure.remain_SOH_raw = 27, //uint32_t
    .structure.build_number = 28, //uint16_t     
};

void main (void)
{
    FILE* log_file = fopen("log_uS.txt", "w");
    headerCumulativesFile(log_file, &cumlog_params_for_uS, 89, 88);
    fclose(log_file);

    printf("Hello world!!!!");

}

static void headerCumulativesFile(FILE* file, cumlog_params_for_uS_t* logs, int32_t tot_no_cumulatives, int32_t index_no_cumulative)
{
    char string[MAX_STRING_SIZE];
    
    snprintf(string, MAX_STRING_SIZE, "Tot number cumulatives logs saved: %d\n", tot_no_cumulatives);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "Current number cumulative log: %d\n", index_no_cumulative);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "Nor first byte page\tWorking Time [h]\tCycle Total\tDischarged Ah\tRegen Ah\tDischarged Wh\tRegen Wh\tCharged Ah\tCharged Wh\tNumber of Deep Disch\tRemain SOH\tStandby Ah\tStandby Wh\tDischarged Ah in Charge\tDischarged Wh in Charge\tService Temperature [°C]\tS.T. Discharge Time [h]\tS.T. Discharge Avg [°C]\tS.T. Recharge Time [h]\tS.T. Recharge Avg [°C]\tS.T. Standby Time [h]\tS.T. Standby Avg [°C]\tLast Charge Time/Date\tLast Complete Charge Time/Date\tNum of Complete Charges\tRemain SOH (raw)\tDisch A*s for SOH Recover\tRecovered SOH (raw)\tBuild Number\n");
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",
    logs->structure.nor_first_byte_page,
    logs->structure.working_time_DCh + logs->structure.working_time_Ch,
    logs->structure.cycle_total,	
    logs->structure.discharged_Ah,
    logs->structure.regenerated_Ah,	
    logs->structure.discharged_Wh,
    logs->structure.regenerated_Wh,	
    logs->structure.charged_Ah,
    logs->structure.charged_Wh,
    logs->structure.number_of_deep_discharge,
    logs->structure.remain_SOH,
    logs->structure.standby_Ah,	
    logs->structure.standby_Wh,
    logs->structure.discharged_Ah_in_charge,
    logs->structure.discharged_Wh_in_charge,
    logs->structure.service_temperature,
    logs->structure.st_discharge_time,	
    logs->structure.st_discharge_avg,
    logs->structure.st_charge_time,	
    logs->structure.st_charge_avg,	
    logs->structure.st_standby_time,	
    logs->structure.st_standby_avg,	
    logs->structure.last_charge_date,	
    logs->structure.last_complete_charge_date,	
    logs->structure.number_of_complete_charge,
    logs->structure.remain_SOH_raw,	
    logs->structure.remain_SOH_raw,	
    logs->structure.build_number);

    
 /*    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "nor_first_byte_page\t%3d\n", logs->structure.nor_first_byte_page);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "remain_SOH\t%d\n", logs->structure.remain_SOH );
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "working_time_DCh\t%d\n", logs->structure.working_time_DCh);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "working_time_Ch\t%d\n", logs->structure.working_time_Ch);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "cycle_total\t%d\n", logs->structure.cycle_total);   
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "discharged_Ah\t%d\n", logs->structure.discharged_Ah);   
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "number_of_deep_discharge\t%d\n", logs->structure.number_of_deep_discharge);   
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "regenerated_Ah\t%d\n", logs->structure.regenerated_Ah);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "discharged_Wh\t%d\n", logs->structure.discharged_Wh);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "regenerated_Wh\t%d\n", logs->structure.regenerated_Wh);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "charged_Ah\t%d\n", logs->structure.charged_Ah);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "charged_Wh\t%d\n", logs->structure.charged_Wh);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "standby_Ah\t%d\n", logs->structure.standby_Ah);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "standby_Wh\t%d\n", logs->structure.standby_Wh);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "discharged_Ah_in_charge\t%d\n", logs->structure.discharged_Ah_in_charge);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "discharged_Wh_in_charge\t%d\n", logs->structure.discharged_Wh_in_charge);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "service_temperature\t%d\n", logs->structure.service_temperature);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_discharge_time\t%d\n", logs->structure.st_discharge_time);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_discharge_avg\t%d\n", logs->structure.st_discharge_avg);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_charge_time\t%d\n", logs->structure.st_charge_time);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_charge_avg\t%d\n", logs->structure.st_charge_avg);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_standby_time\t%d\n", logs->structure.st_standby_time);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "st_standby_avg\t%d\n", logs->structure.st_standby_avg);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "last_charge_date\t%d\n", logs->structure.last_charge_date);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "last_complete_charge_date\t%d\n", logs->structure.last_complete_charge_date);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "number_of_complete_charge\t%d\n", logs->structure.number_of_complete_charge);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "remain_SOH_raw\t%d\n", logs->structure.remain_SOH_raw);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "build_number\t%d\n", logs->structure.build_number);
    snprintf(string + strlen(string), MAX_STRING_SIZE - strlen(string), "\n"); */
   
   fprintf(file, string);
}
