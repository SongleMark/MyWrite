#!/bin/bash

echo "学生管理系统\n"
echo "1.学生登录\n"
echo "2.教师登录\n"
echo "3.管理员登录\n"
echo "请输入选项:"
read VARIABLE

if test $VARIABLE -eq 1
then
	echo "学生登录"
elif test $VARIABLE -eq 2 
then
	echo "教师登录"
else
	echo "管理员登录"
fi
