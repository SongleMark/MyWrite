#include <iostream>
#include <string>
#include <mysql/mysql.h>
using namespace std;

class MysqlDB 
{
	private:
		MYSQL mysql;       //mysql标记对应某个数据库
		MYSQL_ROW row;     //row[i]可用于输出该行第i个字段的数据
		MYSQL_RES *result; //用于定义一个存储数据库检索信息结果的对象。
		MYSQL_FIELD *field;//用于定义一个存储字段信息的对象。如field->name存储对应字段名称

	public:
		MysqlDB() 
		{
			//用于初始化一个MYSQL对象，来连接mysql服务端。
			if( mysql_init( &mysql ) == NULL ) 
			{
				cout << "init error, line: " << __LINE__ << endl;
				exit(-1);
			}
		}
		~MysqlDB() 
		{
			mysql_close( &mysql );
		}
		void connect( string host, string user, string passwd,  string database ) 
		{
			//用于连接数据库
			if( !mysql_real_connect( &mysql, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0 ) ) 
			{
				cout << "connect error, line: " << __LINE__ << endl;
				exit(-1);
			}
		}
		void add();
		void print();
		bool TableIsExist();
};

void MysqlDB::add() {
	string id, name, sex, birthday;
	string sql = "CREATE TABLE IF NOT EXIST stuinfo(id char(10) , name varchar(32) , sex varchar(12), birthday char(12));)";
	mysql_query( &mysql, sql.c_str() );
	do {
		cout << "请输入学生信息:\n";

		cin >> id >> name >> sex >> birthday;
		string sql = "insert into stuinfo values('" + id + "', '" + name + 
			"', '" + sex + "', '" + birthday + "');";

		//用于执行mysql命令。其参数应使用c风格字符串。
		mysql_query( &mysql, sql.c_str() );
		cout << "是否继续（y/n）: ";
		cin >> id;
	} while( id == "y" );
}

void MysqlDB::print() {

	// string sql = "select * from info where name = '" + name + "';";  //要有''
	string sqll = "CREATE TABLE IF NOT EXISTS stuinfo(id char(10) , name varchar(32) , sex varchar(12), birthday char(12));)";
	mysql_query( &mysql, sqll.c_str() );
	string sql = "select * from stuinfo;";
	mysql_query( &mysql, sql.c_str() );

	//用于获取mysql操作的检索结果。
	result = mysql_store_result( &mysql );
	if( !result ) {
		cout << "result error, line : " << __LINE__ << endl;
		return ;
	}

	int num;
	//用于获取结果集的字段数。
	num = mysql_num_fields( result );  //返回字段个数
	for( int i = 0; i < num; i++ ) {
		field = mysql_fetch_field_direct( result, i );  //返回字段类型
		cout << field->name << "\t\t";  //输出字段名
	}
	cout << endl;
	
	//用于获取结果集的行数。
	while( row = mysql_fetch_row( result ), row ) {
		for( int i = 0; i < num; i++ ) {
			cout << row[i] << "\t\t";
		}
		cout << endl;
	}
}

bool MysqlDB::TableIsExist(string sql)
{
	if(0 == mysql_query(&mysql , sql.c_str()))
	{
		return true;
	}
}

int main() {
	MysqlDB db;
	db.connect( "localhost", "root", "123456", "student" ); 

	db.print();
	db.add();
	db.print();

	return 0;
}

