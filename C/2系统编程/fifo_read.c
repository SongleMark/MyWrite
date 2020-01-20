#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

const int SIZE = 1024;
int mIsStop = 0;

void RecvSignal(int sig) {
	printf("recv signal = %d\n", sig);
}

int main(int argc, char *argv[]) {
	char buf[SIZE];
	signal(SIGPIPE, RecvSignal);
	if(mkfifo("./file", 0777) < 0) {
		perror("mkfifo error");
		return -1;
	}
	int fd = open("./file", O_RDONLY);
	if(fd < 0) {
		perror("open error");
		return -1;
	}

	while(!mIsStop) {
		if(read(fd, buf, 1024) <= 0) {
			perror("read error or fifo broken");
			break;
		}
		printf("read buf = %s\n", buf);
	}
	close(fd);

	return 0;
}
