#include <stdio.h>
#include <time.h>

const char* days[] = {
	"sunday",
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday",

};

const char* mons[] = {
	"january",
	"february",
	"march",
	"april",
	"may",
	"june",
	"july",
	"august",
	"september",
	"october",
	"november",
	"december",

};



int main(void)
{
	time_t timer = time(NULL);
	struct tm* ptr = localtime(&timer);
	printf("%d hours, %d minutes, %d seconds, year : %d, month : %s, day : %s", ptr->tm_hour, ptr->tm_min, ptr->tm_sec, ptr->tm_year + 1900, mons[ptr->tm_mon], days[ptr->tm_wday]);
	return 0;



}