#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "circular_queue.h"

#define ORDER_TERM 15  // unit: sec

#define CHBG 0  // CHeeseBurGer as 0
#define BGBG 1  // BulGogiBurger as 1
#define DBBG 2  // DoubleBurger as 2

#define CH_TERM 12  // unit: sec
#define BG_TERM 15
#define DB_TERM 24

int main() {
	int progress = 0;
	int ch_order = 0, bg_order = 0, db_order = 0;
	
	Queue q;
	
	QueueInit(&q);
	srand(time(NULL));  // use time as func' srand's seed
	
	for (int sec = 0; sec < 3600; sec++) {
		if (sec % ORDER_TERM == 0) {  // TRUE once every 15 seconds
			switch(rand() % 3) {  // choose menu(burger) randomly
				case CHBG:
					Enqueue(&q, CH_TERM);
					ch_order++;
					break;
				case BGBG:
					Enqueue(&q, BG_TERM);
					bg_order++;
					break;
				case DBBG:
					Enqueue(&q, DB_TERM);
					db_order++;
					break;
			}
		}
		
		if (progress <= 0 && !IsQueueEmpty(&q))
			progress = Dequeue(&q);
		
		progress--;
	}
	
	printf("[ SIMULATION REPORT ]\n"); //17
	printf("- Cheese burger:    %5d\n", ch_order);
	printf("- Bulgogi burger:   %5d\n", bg_order);
	printf("- Double burger:    %5d\n", db_order);
	printf("* Waiting room size:%5d\n", QUE_LEN);
}