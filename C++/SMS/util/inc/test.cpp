/*************************************************************************
	> File Name: test.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年11月20日 星期三 17时56分40秒
 ************************************************************************/

#include "logger.h"
#include <unistd.h>

int main() {
    const char *tag = "Main";
    while(1) {
        LOGD(tag, "hello, world");
        sleep(1);
        LOGD(tag, "my name is %s, I'm %d years old, my hometown is %s", "masongle", 23, "安徽安庆");
        LOGE(tag, "THIS IS ERROR MESSAGE !!!");
    }
    return 0;
}
