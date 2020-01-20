#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define SIZE 1024

int mIsStop = 0;

#if 0

int main(int argc, char *argv[]) {
	char buf[SIZE];
	if(0 != mkfifo("file.txt", 0777)) {
		perror("mkfifo error");
		return -1;
	}
	int fd = open("file.txt", O_WRONLY);
	if(fd < 0) {
		perror("open error");
		return -1;
	}
	
	while(!mIsStop) {
		printf("please input data:");
		scanf("%s", buf);
		getchar();

		if(write(fd, buf, strlen(buf) + 1) < 0) {
			perror("write error");
			return -1;
		}
		printf("write success ...\n");
	}

	close(fd);

	return 0;
}

#endif

void  hangle(int sig)
{
        printf("rec  sig:%d\n",sig);
}
int main()
{
        signal(SIGPIPE,hangle);
        int fd,ret;
        char buff[128];
        //创建管道
        printf("mkfifo.....\n");
        ret=mkfifo("./file",0777);
        printf("mkfifo  over.......\n");
        if(ret<0)
        {
                if(errno != EEXIST)
                {
                        printf("create  fifo failed...errno=%d\n",errno);
                        return -1;
                }
        }
        // 打开
        printf("open.....\n");
        fd = open("./file",O_WRONLY);
        printf("open over....\n");
        if(fd<0)
        {
                perror("open");
        }
 
        //写
        while(1)
        {
				printf("please input data:");
                fgets(buff,sizeof(buff),stdin);
                printf("write.....\n");
                ret = write(fd,buff,strlen(buff));
                printf("write over.....\n");
                if(ret<0)
                {
                        perror("write");
                        break;
                }
                printf("write success\n");
        }
        //关闭
        close(fd);
        return 0;
}

