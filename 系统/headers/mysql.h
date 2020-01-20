#ifndef MYSQL_H
#define MYSQL_H
#include <iostream>
#include <string>
#include <mysql/mysql.h>
using namespace std;

#define HOST     "localhost"
#define USER     "root"
#define PASSWORD  123456
#define DATABASE "CameraImage"
#define TABLE    "info"

//将要插入数据库的信息结构体
typedef struct INFO
{
	int id;
	char *name;
	char *sex;
	char *address;

}info;

class MysqlOperation
{
	private:
		MysqlOperation();
		MYSQL mysql;       //句柄
		MYSQL_ROW row;     //row[i]可用于输出该行第i个字段的数据
		MYSQL_RES *result; //用于定义一个存储数据库检索信息结果的对象
		MYSQL_FIELD *field;//用于定义一个存储字段信息的对象。如field->name存储对应字段名称
	public:
		static MysqlOperation* instance;     //用于单例模式中构造
		static MysqlOperation* getinstance();//用于单例模式
		//连接数据库
		void ConnectToMysql(string host,string user,string password,string database);
		//关闭数据库 断开连接
		void CloseMysql();
		//向数据库插入数据
		void InsertValues(info values);
		//从数据库删除数据
		void DeleteValues();
		//从数据库显示数据
		void ShowValues();
		//析构
		~MysqlOperation();
};


#endif
