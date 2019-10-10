#ifndef __RTC_H
#define __RTC_H

//#define CCR_EN	0
//#define CCR_RESET	1

enum ccr_bits
{
	CCR_EN = 0, CCR_RESET = 1
};

typedef struct rtc 
{
	int sec, minute, hour;
	int day, month, year;
	int day_of_week, day_of_year;
}rtc_t;

void rtc_init(void);
void rtc_set(rtc_t *tm);
void rtc_get(rtc_t *tm);

#endif


