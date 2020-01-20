#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strlen(const char *str) {
	int length = 0;
	while('\0' != str[length]) {
		length ++;
	}

	return length;
}

void Strcpy(char *dest, const char *src) {
	int i = 0;
	while('\0' != src[i]) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}

void Strcat(char *dest, const char *src) {
	int i = 0;
	int j = 0;
	while('\0' != dest[i]) {
		i ++;
	}
	while('\0' != src[j]) {
		dest[i] = src[j];
		i ++;
		j ++;
	}
	dest[i] = '\0';
}

void ReverseString(char *str) {
	int i = 0;
	int len = Strlen(str);
	char temp;

	for(int j = len - 1; i < j ; i ++, j --) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void DeleteSpaceFromString(char *str) {
	int i = 0;
	while('\0' != str[i]) {
		if(' ' == str[i]) {
			for(int j = i ; j < Strlen(str) ; j ++) {
				str[j] = str[j + 1];
			}
			continue;
		}
		i ++;
	}
	
}

void MainInterFace() {
	system("clear");
	printf("\t\t\t1.Strlen()\n");
	printf("\t\t\t2.Strcpy()\n");
	printf("\t\t\t3.Strcat()\n");
	printf("\t\t\t4.ReverseString()\n");
	printf("\t\t\t5.DeleteSpaceFromString()\n");
	printf("\t\t\t0.quit()\n\n");
	printf("please select: ");
}

static int _mIsStop = 0;

int main(int argc, char *argv[]) {
	int sel;
	int len = 0;
	char src[32];
	while(!_mIsStop) {
		MainInterFace();
		scanf("%d", &sel);
		switch(sel) {
			case 1:
				printf("please input src:");
				scanf("%s", src);
				printf("strlen(src) = %d\n", Strlen(src));
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				printf("please input src:");
				scanf("%s", src);
				ReverseString(src);
				printf("after reverse src = %s\n", src);
				break;
			case 5:
				printf("please input src:");
				//scanf("%s", src);
				fgets(src, 32, stdin);
				getchar();
				DeleteSpaceFromString(src);
				printf("after delete space  src = %s\n", src);
				break;
			case 0:
			default:
				_mIsStop = 1;
		}
	}
	
	return 0;
}

