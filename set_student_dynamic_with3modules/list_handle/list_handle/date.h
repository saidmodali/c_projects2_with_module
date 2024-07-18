#ifndef DATE_H
#define	DATE_H


typedef struct Date {
	int m_day;
	int m_month;
	int m_year;
}Date;



Date* set_date(Date* ptr, int day, int month, int year);
Date* set_date_today(Date* ptr);
Date* set_date_str(Date* ptr, const char* str);
Date* set_date_random(Date* ptr);
void set_day(Date* ptr, int day);
void set_month(Date* ptr, int month);
void set_year(Date* ptr, int year);
int is_valid_date(int day, int month, int year);


// input-output function :

void print_date(const Date* ptr);
void scan_date(Date* ptr);

// get-functions

int get_year(const Date* ptr);
int get_month_day(const Date* ptr);
int get_month(const Date* ptr);
int get_week_day(int d, int month, int year);
int get_year_day(const Date* ptr);






#endif