#ifndef SETTINGDB_H
#define SETTINGDB_H

#include <string>
#include <dpp/nlohmann/json.hpp>

nlohmann::json settingDB(const std::string, bool&);

#endif