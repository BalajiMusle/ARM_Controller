#include "LPC17xx.h"
#include "rtc.h"

void rtc_init(void)
{
	// disable rtc
	LPC_RTC->CCR = BV(CCR_RESET);
}

void rtc_set(rtc_t *tm)
{
	// disable rtc
	LPC_RTC->CCR = BV(CCR_RESET);
	// set values
	LPC_RTC->SEC = tm->sec;
	LPC_RTC->MIN = tm->minute;
	LPC_RTC->HOUR = tm->hour;
	LPC_RTC->DOM = tm->day;
	LPC_RTC->DOW = tm->day_of_week;
	LPC_RTC->DOY = tm->day_of_year;
	LPC_RTC->MONTH = tm->month;
	LPC_RTC->YEAR = tm->year;
	// enable clock
	LPC_RTC->CCR = BV(CCR_EN);
}
void rtc_get(rtc_t *tm)
{
	tm->sec = LPC_RTC->SEC;
	tm->minute = LPC_RTC->MIN;
	tm->hour = LPC_RTC->HOUR; 
	tm->day = LPC_RTC->DOM;
	tm->day_of_week = LPC_RTC->DOW; 
	tm->day_of_year = LPC_RTC->DOY;
	tm->month = LPC_RTC->MONTH;
	tm->year = LPC_RTC->YEAR;
}
