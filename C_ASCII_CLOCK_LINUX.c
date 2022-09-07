#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define COLON 10;

char a[11][13][24] = 

{{{"      xx xx xx  xx     "},
  {"    xx xx xx xx xx xx  "},
  {"  xx xx          xx xx "},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {" xx xx            xx xx"},
  {"  xx xx          xx xx "},
  {"    xx xx xx xx xx xx  "},
  {"     xx xx xx xx xx    "},},

 {{"            xx xx      "},
  {"         xx xx xx      "},
  {"      xx xx xx xx      "},
  {" xx xx xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"       xx  xx  xx      "},
  {"  xx xx xx xx xx xx xx "},
  {"  xx xx xx xx xx xx xx "},},
 
 {{"    xx xx xx xx        "},
  {"  xx xx    xx xx       "},
  {" xx xx    xx xx        "},
  {"xx xx    xx xx         "},
  {"xx xx   xx xx          "},
  {"       xx xx           "},
  {"      xx xx            "},
  {"     xx xx             "},
  {"    xx xx              "},
  {"   xx xx               "},
  {"  xx xx                "},
  {" xx xx xx xx xx xx xx  "},
  {"xx xx xx xx xx xx xx xx"},},

 {{"  xx xx xx xx xx xx    "},
  {" xx xx xx xx xx xx xx  "},
  {"               xx xx xx"},
  {"                  xx xx"},
  {"                  xx xx"},
  {"               xx xx xx"},
  {"            xx xx xx   "}, 
  {"               xx xx xx"}, 
  {"                  xx xx"},
  {"               xx xx xx"},
  {"              xx xx xx "},
  {" xx xx xx xx xx xx xx  "}, 
  {"  xx xx xx xx xx xx    "},},

 {{"             xx xx xx  "},
  {"            xx  xx  xx "},
  {"          xx xx  xx xx "},
  {"         xx xx   xx xx "},
  {"       xx xx     xx xx "},
  {"      xx xx      xx xx "},
  {"    xx xx        xx xx "}, 
  {"  xx xx          xx xx "}, 
  {"xx xx xx xx xx xx xx xx"},
  {"xx xx xx xx xx xx xx xx"},
  {"                 xx xx "},
  {"                 xx xx "}, 
  {"                 xx xx "},},

 {{"   xx xx xx xx xx xx xx"},           
  {"xx xx xx xx xx xx xx   "},         
  {"xx xx                  "},                
  {"xx xx                  "},               
  {"xx xx                  "},                
  {" xx xx xx xx xx xx xx  "},     
  {"   xx xx xx xx xx xx xx"},       
  {"                  xx xx"},   
  {"                  xx xx"}, 
  {"                  xx xx"},
  {"                  xx xx"},   
  {"xx xx xx xx xx xx xx xx"}, 
  {" xx xx xx xx xx xx xx  "},},

 {{"          xx xx xx xx  "},
  {"      xx xx xx xx      "},
  {"    xx xx xx xx        "},
  {"   xx xx               "},
  {"  xx xx                "},
  {" xx xx                 "},
  {" xx xx xx xx xx xx     "},
  {"xx xx           xx xx  "}, 
  {"xx xx             xx xx"},
  {"xx xx             xx xx"},
  {"xx xx             xx xx"},
  {" xx xx           xx xx "},
  {"  xx xx xx xx xx xx    "},},

 {{"xx xx xx xx xx xx xx   "},
  {"xx xx xx xx xx  xx     "},
  {"           xx  xx      "},
  {"          xx  xx       "},
  {"         xx  xx        "},
  {"        xx  xx         "},
  {"       xx  xx          "},
  {"      xx  xx           "},
  {"     xx  xx            "},
  {"    xx  xx             "},
  {"   xx  xx              "},
  {"  xx  xx               "},
  {" xx  xx                "},},

 {{"    xx xx xx xx xx     "},
  {"  xx xx        xx xx   "},
  {" xx xx          xx xx  "},
  {" xx xx          xx xx  "},
  {"  xx xx        xx xx   "},
  {"   xx xx      xx xx    "},
  {"     xx xx xx xx       "},
  {"   xx xx      xx xx    "},
  {"  xx xx        xx xx   "},
  {" xx xx          xx xx  "},
  {" xx xx          xx xx  "},
  {"  xx xx        xx xx   "},
  {"    xx xx xx xx xx     "},},

 {{"    xx xx xx xx xx     "},
  {"  xx xx xx xx xx xx    "},
  {" xx xx           xx xx "},
  {" xx xx           xx xx "},
  {" xx xx           xx xx "},
  {" xx xx           xx xx "},
  {"  xx xx xx xx xx xx xx "},
  {"   xx xx xx xx    xx   "},
  {"            xx   xx    "},
  {"           xx   xx     "},
  {"          xx   xx      "},
  {"         xx   xx       "},
  {"        xx   xx        "},},
  
 {{"                       "},
  {"                       "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"                       "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"       xx xx xx        "},
  {"                       "},
  {"                       "},},};

// y = clock digit we want to output

void clockOutput(int firstHourDigit, int secondHourDigit, int firstMinuteDigit, int secondMinuteDigit, int firstSecondDigit, int secondSecondDigit){
	
	int printDigit = 0;
	bool previousWasFirst = false;

	for(int x = 0; x < 13; ++x){
		for(int y = 0; y < 5; ++y){
			switch (y){
				case 0:
					printDigit = firstHourDigit;
				break;

				case 1:
					printDigit = secondHourDigit;
				break;

				case 2:
					printDigit = COLON;
				break;

				case 3:
					printDigit = firstMinuteDigit;
				break;

				case 4:
					printDigit = secondMinuteDigit;
				break;
			}
			for(int z = 0; z < 23; ++z){
				if((a[printDigit][x][z]) == 'x'){
					if(previousWasFirst == true){
						putchar(secondSecondDigit + '0');
						previousWasFirst = false;
						continue;
					}
					putchar(firstSecondDigit + '0');
					previousWasFirst = true;
					continue;
				}
				putchar(a[printDigit][x][z]);
			}
		}
		putchar('\n');
	}
}

int main(){

	int firstHourDigit = 0;
	int secondHourDigit = 0;
	int firstMinuteDigit = 0;
	int secondMinuteDigit = 0;
	int firstSecondDigit = 0;
	int secondSecondDigit = 0;

	// Clock loop
	while(1){
		// Gather time info for use with clock
		time_t rawtime;
		struct tm *info;
 
		time(&rawtime);
		info = localtime(&rawtime);

		// Converting digits to usable format
		secondHourDigit = ((info->tm_hour)%10);
		firstHourDigit = (((info->tm_hour)-secondHourDigit)/10);
		secondMinuteDigit = ((info->tm_min)%10);
		firstMinuteDigit = (((info->tm_min)-secondMinuteDigit)/10);
		secondSecondDigit = ((info->tm_sec)%10);
		firstSecondDigit = (((info->tm_sec)-secondSecondDigit)/10);

		system("clear");

		clockOutput(firstHourDigit, secondHourDigit, firstMinuteDigit, secondMinuteDigit, firstSecondDigit, secondSecondDigit);
		//printf("DEBUG - Time: %2d:%02d:%2d",info->tm_hour, info->tm_min, info->tm_sec);
		//printf(" DEBUG - Time: %d%d:%d%d:%d%d",firstHourDigit, secondHourDigit, firstMinuteDigit, secondHourDigit, firstSecondDigit, secondSecondDigit);

		// because of the slow draw time (on windows, i suspect the linux port will suck less) sleep isnt one full second to accound for drawing lag
		system("sleep 1");
	}

	return 0;
}
