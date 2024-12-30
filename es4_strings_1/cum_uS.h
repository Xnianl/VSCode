/*
 * file cum_uS.h
 *
 *  Created on: Dec 5 , 2024
 *      Author: midac
 */

#ifndef CUM_US_H_
#define CUM_US_H_

#include <stdint.h>

typedef union
{
	uint8_t buffer;
	struct
	{
		uint8_t nor_first_byte_page;
		uint8_t remain_SOH;
		uint16_t working_time_DCh;
		uint16_t working_time_Ch;
		uint16_t cycle_total;
		uint32_t discharged_Ah;
		uint32_t number_of_deep_discharge;
		uint32_t regenerated_Ah;
		uint32_t discharged_Wh;
		uint32_t regenerated_Wh;
		uint32_t charged_Ah;
		uint32_t charged_Wh;
		uint32_t standby_Ah;
		uint32_t standby_Wh;
		uint32_t discharged_Ah_in_charge;
		uint32_t discharged_Wh_in_charge;
		int16_t service_temperature;
		uint16_t st_discharge_time;
		int16_t st_discharge_avg;
		uint16_t st_charge_time;
		int16_t st_charge_avg;
		uint16_t st_standby_time;
		int16_t st_standby_avg;
		uint32_t last_charge_date;
		uint32_t last_complete_charge_date;
		uint16_t number_of_complete_charge;
		uint32_t remain_SOH_raw;
		uint16_t build_number;
	} structure;
}cumlog_params_for_uS_t;

#endif /* CUM_US_H_ */
