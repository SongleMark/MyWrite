/*************************************************************************
	> File Name: test.cpp
	> Author: MaSongle
	> Mail  : 1830917719@qq.com
	> Created Time: 2019年12月11日 星期三 16时26分19秒
 ************************************************************************/

#include "logger.h"
#include <unistd.h>

int main() {
    while(1) {
        LOGD("SUCCESS", "this is a %s log", "normal");
        LOGE("FAILED", "this is a %s log", "unnormal");
        sleep(1);
    }
}
