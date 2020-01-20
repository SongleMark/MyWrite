#include <iostream>
#include <mysql/mysql.h>
#include <cstdio>
#define UTF8 "utf8"

using namespace std;

MYSQL *mMysql;     /*数据库句柄   */
MYSQL_RES *mResult;/*结果集       */
MYSQL_ROW mRow;    /*返回上一个结果*/
char *mDatabase = (char *)"TCP";   /*数据库名称   */
char *mUser = (char *)"root";       /*用户名      */
char *mPassword = (char *)"123456";   /*密码        */
char *mHostname = (char *)"localhost";   /*数据库地址   */

int main()
{
	mMysql = mysql_init(NULL);
	if(NULL == mMysql)
	{
		//LOG(TAG, "mysql_init error ...");
		cout << "mysql init error ..." << endl;
		return false;
	}
	cout << "mysql init success ..." << endl;
	//连接数据库
	if(!mysql_real_connect(mMysql, mHostname, mUser, mPassword, mDatabase, 0, NULL, 0))
	{
		//LOG(TAG, "connect mysql error may not has the database...");
		cout << "connect mysql error...";
		mysql_error(mMysql);
		return false;
	}
	cout << "mysql connect success ..." << endl;
	//设置数据库字符集
	mysql_set_character_set(mMysql, UTF8);

	int result = 0;
	//如果不存在regist表则创建该表
	const char *sql_creat = "CREATE TABLE IF NOT EXISTS regist(id int, name char(32), tel bigint);";
	//LOG(TAG, sql_creat);
	cout << sql_creat << endl;
	result = mysql_query(mMysql, sql_creat); //mysql执行语句
	if(result < 0)
	{
		//LOG(TAG, "create table error ...");
		cout << "create table error ..." << endl;
		return false;
	}
	//向表中插入数据
	char sql_insert[66];
	int id = 10001;
	char *name = (char *)"masongle";
	int64_t telphone = 18726193943;
	sprintf(sql_insert, "INSERT INTO regist values(%d, '%s', %ld);", id, name, telphone);
	//LOG(TAG, sql_insert);
	cout << sql_insert << endl;
	result = mysql_query(mMysql, sql_insert);
	if(result < 0)
	{
		//LOG(TAG, "insert values failed ...");
		cout << "insert values failed ..." << endl;
		return false;
	}

	//读取数据
	

	return 0;
}
