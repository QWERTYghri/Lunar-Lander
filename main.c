/* The fact I find the GNU coding standard readable shows that I'm probably an idiot and you shouldn't trust me */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Definitions */

#define INPUTBUF 100
#define FUELMAX  200
#define SPEEDST  20
#define STARTFT  500
#define MAXFTSP  20	/* Feet start for plot */
#define FT_PFTD  25	/* Plot space conversion */
#define MAX_IN   500
#define MIN_IN   0
/* Strings */

#define GOODLUCK   "\n\n G O O D   L U C K ! ! !\n\n"
#define TOPBAR     "\nSEC  FEET  SPEED  FUEL\n"
#define TOPFORMAT  "\n\n %d   %.1f   %.1f   %.1f"
#define THROTTLE   "\nThrottle : "
#define ENDGAME    "\n**** CONTACT ****\nTOUCHDOWN : %d\n LANDING V = %f ft/s\nFuel remaining : %f\n"
#define FAIL       "\n**** CRASHED ****\n"
#define WIN        "\n**** LANDED *****\n"
#define MISSION    "\n\n*** ANOTHER MISSION? **** : "


/* Functions */

int
inputVal (void)
{
	char buffer[INPUTBUF];

	fgets (buffer, INPUTBUF, stdin);

	return  atoi (buffer);
}

int
initGame (void)
{
	int seconds = 0;
	float feet = STARTFT, speed = SPEEDST, fuel = FUELMAX;
	int input;

	puts (GOODLUCK);		/* Print the GOOD LUCK DEF || then print TOPBAR and calls other funcs */
	puts (TOPBAR);

	/* Game loop */

	while (feet > 0)
	{
		puts (THROTTLE);
		input = inputVal ();	/* Get input from functions */

		/* Edit vals */

        	speed = feet / input;		/* Speed is given by feet / seconds */
		seconds++;			/* Inc second */
		feet -= speed;			/* Subtract current ft by the speed */
		fuel -= ((float ) input / 2);    /* Fuel is subtracted by input val divided by two */
		
		/* Output stuff */

		printf (TOPFORMAT, seconds, feet, speed, fuel);
		

		if (input > MAX_IN || input < MIN_IN)
		{
			puts (FAIL);
			return -1;
		}
		else if (fuel <= 0)
		{
			puts (FAIL);
			return 0;
		}
	}

	printf (ENDGAME, seconds, speed, fuel);

	if (speed < 10 || speed < 0 ||)
	{
		puts (WIN);
	}
	else
	{
		puts (FAIL);
	}
	
	puts (MISSION);

	return 0;
}



int
main (void)
{
	char buf[INPUTBUF];

	while (1)
	{
		if (initGame () == 0)
		{
			printf (MISSION);
			if (strcmp (fgets (buf, INPUTBUF, stdin), "yes") == 0)
			{
				initGame ();
			}
			else if (strcmp (fgets (buf, INPUTBUF, stdin), "no") == 0)
			{
				break;
			}
		}
		else
		{
			initGame ();
		}
	}

	
	return 0;
}
