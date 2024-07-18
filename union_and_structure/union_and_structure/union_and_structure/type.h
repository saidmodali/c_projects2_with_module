#ifndef TYPE_H
#define	TYPE_H
#include "date.h"



#define			INT				0
#define			DOUBLE			1
#define			NAME			2
#define			DATE			3

typedef struct {
	int w_type;
	union {
		int int_t;
		double double_t;
		char name_t[20];
		Date date_t;
	};

}Mytype;


void get_type(Mytype* mytype);
void write_type(Mytype* mytype);














#endif 
