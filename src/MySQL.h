#pragma once

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "Log.h"

class MySQL
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	sql::Statement* stmt;
	std::string database;
public:
	~MySQL();
	void Init(char* db, char* username, char* password);
	void Execute(std::vector<std::string> statements);
};

