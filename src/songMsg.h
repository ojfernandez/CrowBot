#ifndef SONGMSG_H
#define SONGMSG_H

#include <string>
#include <dpp/nlohmann/json.hpp>

string songMsg(const nlohmann::json, int&, int&);

#endif