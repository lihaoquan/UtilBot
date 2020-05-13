/* Copyright 2008, 2010, Oracle and/or its affiliates. All rights reserved.

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; version 2 of the License.

There are special exceptions to the terms and conditions of the GPL
as it is applied to this software. View the full text of the
exception in file EXCEPTIONS-CONNECTOR-C++ in the directory of this
software distribution.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "MySQL.h"

MySQL::~MySQL()
{
    delete con;
}

void MySQL::Init(char* db, char* username, char* password)
{
    try {
        driver = get_driver_instance();
        database = db;
        con = driver->connect("tcp://127.0.0.1:3306", username, password);
    }
    catch (sql::SQLException& e) {
        CORE_ERROR("ERR: {0}", e.what());
        CORE_ERROR("(MySQL error code: {0}", e.getErrorCode());
    }
}

void MySQL::Execute(std::vector<std::string> statements) {

    con->setSchema(database.c_str());
    stmt = con->createStatement();

    try {

        sql::ResultSet* res;

        for (int i = 0; i < statements.size(); i++) {
            res = stmt->executeQuery(statements[i].c_str());
            CORE_INFO("SQL statement executed: {0}", statements[i]);

            CORE_INFO("SQL result count: {0}", res->rowsCount());

            if (res->rowsCount() > 0) {
                while (res->next()) {
                    CORE_INFO("SQL result: {0}", res->getInt(1));
                }
            }
            else {
                CORE_INFO("Statement yielded no results");
            }
        }
    } catch (sql::SQLException& e) {
        CORE_ERROR("ERR: {0}", e.what());
        CORE_ERROR("MySQL error code: {0}", e.getErrorCode());
    }

    delete stmt;
}