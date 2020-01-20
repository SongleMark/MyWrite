#include <stdio.h>

int main(int argc, char *argv[]) {
	int a = 4;
	printf("fistly, a = %d\n", a);
	a += (a ++); // a = a + a + 1 = 9
	printf("after a+=(a++), a = %d\n", a);
	
	a = 4;
	a += (++ a); // a = a + 1 = 5, a = a + a = 10
	printf("after a+=(++a), a = %d\n", a);

	a = 4;
	//(++ a) += (a ++);
	//printf("after (++ a) += (a++), a = %d\n", a);

	return 0;
}
