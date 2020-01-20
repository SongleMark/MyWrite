#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	time_t tm = time(NULL);
	srand((unsigned int)tm);
	
	for(int i = 0; i < 10 ; i ++) {

		int num = rand()%10;
		printf("第%d次, rand num = %d\n", i+1, num);
	}

	return 0;
}
