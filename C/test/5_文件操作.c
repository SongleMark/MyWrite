#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct info {
	int num;
	char name[32];
	char buf[32];
} INFO;

int main(int argc, char *argv[]) {
	int fd = open("test.txt", O_RDWR | O_CREAT | 00700);
	if(fd < 0) {
		perror("open error");
		return -1;
	}
	FILE *fp = fopen("test1.txt", "r+b");
	if(NULL == fp) {
		perror("fopen error");
		return -1;
	}

	//char buf[32];
	//sprintf(buf, "hello, world!!!");
	INFO _mWrite = {10001, "Jack", "this is a buf"};
	//_mWrite.num = 10001;
	//sprintf(_mWrite.name, "Jack");
	//sprintf(_mWrite.buf, "this is a buf ...");
	

	int result = write(fd, &_mWrite, sizeof(INFO));
	if(result < 0) {
		perror("write error");
		return -1;
	}

	result = fwrite(&_mWrite, sizeof(INFO), 1, fp);
	if(result < 0) {
		perror("fwrite error");
		return -1;
	}

	INFO _mRead;
	result = read(fd, &_mRead, sizeof(INFO));
	if(result < 0) {
		perror("read error");
		return -1;
	}
	printf("read num = %d, read name = %s, read buf = %s\n",_mRead.num, _mRead.name, _mRead.buf);
	
	result = fread(&_mRead, sizeof(INFO), 1, fp);
	if(result < 0) {
		perror("fread error");
		return -1;
	}
	printf("fread num = %d, fread name = %s, fread buf = %s\n",_mRead.num, _mRead.name, _mRead.buf);


	close(fd);
	fclose(fp);
	return 0;
}

