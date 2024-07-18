#include "date.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>



#define		PRIVATE			static					
#define		PUBLIC			
#define		YEAR_BASE		1900
#define		is_leap_year(x)				(((x) % 4 == 0) && (x % 400 == 0 || x % 100 != 0)) 
#define		RANDOM_YEAR_MAX				2024
#define		RANDOM_YEAR_MIN				1900



Date* set_function(Date* ptr, int day, int month, int year);
int is_valid_date(int day, int month, int year);




PRIVATE const int day_tabs[][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30},
	{0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30}
};



PUBLIC Date* set_date(Date* ptr, int day, int month, int year)
{
	return set_function(ptr, day, month, year);

}


PUBLIC Date* set_date_today(Date* ptr)
{
	time_t timer = time(NULL);
	struct tm* t_ptr = localtime(&timer);
	set_date(ptr, t_ptr->tm_mday, t_ptr->tm_mon + 1, t_ptr->tm_year + 1900);
	return ptr;

}


PUBLIC Date* set_date_str(Date* ptr, const char* str)
{
	ptr->m_day = atoi(str);
	ptr->m_month = atoi(str + 3);
	ptr->m_year = atoi(str + 6);
	return ptr;
}


PUBLIC Date* set_date_random(Date* ptr)
{
	ptr->m_month = (rand() % 11) + 1; ;
	ptr->m_year = rand() % (RANDOM_YEAR_MAX - RANDOM_YEAR_MIN + 1) + RANDOM_YEAR_MIN;
	ptr->m_day = rand() % day_tabs[is_leap_year(ptr->m_year)][ptr->m_month] + 1;
	return ptr;

}





PUBLIC void set_day(Date* ptr, int day)
{
	ptr->m_day = day;
}


PUBLIC void set_month(Date* ptr, int month)
{
	(ptr->m_month) = month;
}


PUBLIC void set_year(Date* ptr, int year)
{
	ptr->m_year = year;


}


PRIVATE	int is_valid_date(int day, int month, int year)
{
	return (year >= YEAR_BASE) && (month > 0 && month < 13) && (day > 0 && day <= day_tabs[is_leap_year(year)][month]);

}

PRIVATE Date* set_function(Date* ptr, int day, int month, int year)
{
	if (!is_valid_date(day, month, year))
		abort();
	ptr->m_day = day;
	ptr->m_month = month;
	ptr->m_year = year;
	return ptr;
}

// input-output function :

PUBLIC void print_date(const Date* ptr)
{
	const char* days[] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",

	};

	const char* months[] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"

	};

	(void)printf("%s/%s/%d", days[get_week_day(ptr->m_day, ptr->m_month, ptr->m_year)], months[ptr->m_month], ptr->m_year);

};


PUBLIC void scan_date(Date* ptr)
{
	printf("please enter the day : ");
	scanf("%d", &(ptr->m_day));
	printf("enter the month : ");
	scanf("%d", &(ptr->m_month));
	printf("enter the year : ");
	scanf("%d", &(ptr->m_year));

}

PUBLIC int get_year(const Date* ptr)
{
	return (ptr->m_year);

}
PUBLIC int get_month_day(const Date* ptr)
{
	return (ptr->m_day);
}

PUBLIC int get_month(const Date* ptr)
{
	return (ptr->m_month);

}

PUBLIC int get_week_day(int d, int m, int y)
{
	return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;

}

PUBLIC int get_year_day(const Date* ptr)
{
	int cnt = 0;
	for (int i = 0; i < ptr->m_month - 1; ++i)
		cnt += day_tabs[is_leap_year(ptr->m_year)][i + 1];
	cnt += ptr->m_day;
	return cnt;

}


