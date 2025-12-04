#include "../import/Sistema.h"
#include <iostream>
#include <sqlite3.h>

std::vector<std::shared_ptr<User>> Sistema::getDoctorsList() const {
    std::vector<std::shared_ptr<User>> doctors;

    const char* sql =
        "SELECT ID, USERNAME, PASSWORD, NAME, EMAIL, SPECIALTY "
        "FROM USER WHERE ROLE = 'Doctor'";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) return doctors;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string specialty = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));

        doctors.push_back(std::make_shared<Doctor>(id, username, password, name, email, specialty));
    }

    sqlite3_finalize(stmt);
    return doctors;
}

std::vector<std::shared_ptr<User>> Sistema::getAllUsers() const {
    std::vector<std::shared_ptr<User>> users;

    const char* sql =
        "SELECT ID, USERNAME, PASSWORD, ROLE, NAME, EMAIL, SPECIALTY, TELEPHONE FROM USER";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) return users;

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        int id = sqlite3_column_int(stmt, 0);
        std::string username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        std::string password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        std::string role = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        std::string name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        std::string email = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        std::string specialty = sqlite3_column_text(stmt, 6)
                               ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))
                               : "";
        std::string telephone = sqlite3_column_text(stmt, 7)
                               ? reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7))
                               : "";

        if (role == "Doctor")
            users.push_back(std::make_shared<Doctor>(id, username, password, name, email, specialty));
        else if (role == "Patient")
            users.push_back(std::make_shared<Patient>(id, username, password, name, email, telephone));
        else if (role == "Administrator")
            users.push_back(std::make_shared<Admin>(id, username, password, name, email));
    }

    sqlite3_finalize(stmt);
    return users;
}

bool Sistema::assignScheduleToDoctor(int idDoctor, const std::string& day,
                                     const std::string& start, const std::string& end) 
{
    const char* sql = 
        "INSERT INTO SCHEDULE (ID_DOCTOR, DAY, START_TIME, END_TIME) VALUES (?, ?, ?, ?)";

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (rc != SQLITE_OK) return false;

    sqlite3_bind_int(stmt, 1, idDoctor);
    sqlite3_bind_text(stmt, 2, day.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, start.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, end.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return rc == SQLITE_DONE;
}
