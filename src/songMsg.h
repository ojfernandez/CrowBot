#ifndef SONGMSG_H
#define SONGMSG_H

#include <dpp/nlohmann/json.hpp>
#include <string>

using namespace std;

string songMsg(const nlohmann::json&, int&, int&);

#endif
