#include "type.h"


#define		PUBLIC
#define		PRIVATE			static






PUBLIC void get_type(Mytype* mytype)
{
	printf("how do you want a type ? :\n"
		"(0)int\n"
		"(1)double\n"
		"(2)name\n"
		"(3)date\n");
	scanf("%d", &(mytype->w_type));

	switch (mytype->w_type)
	{
	case INT: {
		int x;
		printf("enter your int number: \n");
		scanf("%d", &x);
		mytype->int_t = x;
		break;
	}
	case DOUBLE:
	{
		double x;
		printf("enter your double value :\n");
		scanf("%lf", &x);
		mytype->double_t = x;
		break;
	}

	case NAME:
	{
		char name[20];
		printf("enter your name : \n");
		scanf("%s", name);
		strcpy(mytype->name_t, name);
		break;
	};

	case DATE:
	{
		char date[20];
		printf("enter your date :\n");
		scanf("%s", date);
		set_date_str(&(mytype->date_t), date);
		break;
	}
	};
	return mytype;
};

PUBLIC void write_type(Mytype* mytype)
{
	switch (mytype->w_type)
	{
	case INT:
		printf("your int value : %d", mytype->int_t);
		break;
	case DOUBLE:
		printf("your double value : %lf", mytype->double_t);
		break;


	case NAME:
		printf("your name : %s", mytype->name_t);
		break;

	case DATE:
		printf("your date : ");
		print_date(&(mytype->date_t));
		break;
	};
};