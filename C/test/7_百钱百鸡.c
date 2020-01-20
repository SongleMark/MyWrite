#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int Male   = 0;
	int FeMale = 0;
	int Child  = 0;
	for(int Male = 0; Male <= 100; Male ++) {
		for(int FeMale = 0; FeMale <= 100; FeMale ++) {
			for(int Child = 0; Child <= 100; Child ++) {
				if((5*Male + 3*FeMale + Child/3) == 100 && (Male + FeMale + Child) == 100 && (Child%3) == 0) {
					printf("Male = %d, FeMale = %d, Child = %d\n", Male, FeMale, Child);
				}
			}
		}
	}

	return 0;
}
