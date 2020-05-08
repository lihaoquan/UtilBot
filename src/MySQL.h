#pragma once

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class MySQL
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
public:
	~MySQL();
	void Init();
	void Execute();
};

