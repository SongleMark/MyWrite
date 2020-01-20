#include "../headeers/mysql.h"

MysqlOPeration *MysqlOperation::instance = nullptr;

MysqlOPeration::MysqlOperation()
{
}

MysqlOperation::~MysqlOperation()
{
	CloseMysql();
}

MysqlOperation *MysqlOPeration::getinstance()
{
	if(instance == nullptr)
	{
		instance = new MysqlOperation();
	}

	return instance;
}

//初始化数据库并连接
void MysqlOperation::ConnectMysql(string host,string user,string password,string database)
{
	if( mysql_init(&mysql) == NULL )
	{
		cout << "init mysql error in  " << __LINE__ <<endl;
		exit(-1);
	}

	if( !mysql_real_connect(host.c_str(),user.c_str(),password.c_str(),database.c_str()),0,NULL,0 )
	{
		cout << "connect mysql failed " << endl;
		exit(-1);
	}
}

//断开与数据库的连接
void MysqlOperation::CloseMysql()
{
	bool ret = mysql_close(&mysql);
	if(ret)
	{
		cout << "close mysql success ";
	}
	else
	{
		cout << "close mysql failed" ;
	}

	return ;
}

//向数据库中插入数据
/*
typedef struct INFO
{
	int id;
	char *name;
	char *sex;
	char *birthday;
}info;该结构体为插入数据库中的数据
*/
void MysqlOperation::InsertValues(info values)
{
	string sql = "INSERT INTO info values('" + values.id + "' , '" + values.name + "','"+values.sex + "','"+values.birthday+"');";

	bool ret = mysql_query(&mysql , sql.c_str());
	if(!ret)
	{
		cout << "insert values error!!!" << endl;
		return ;
	}
}

//删除数据库中的数据
void MysqlOperation::DeleteValues()
{
}

//
