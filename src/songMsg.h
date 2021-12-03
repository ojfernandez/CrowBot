#ifndef SONGMSG_H
#define SONGMSG_H

#include <string>
#include <dpp/nlohmann/json.hpp>

std::string songMsg(nlohmann::json, int&, int&);

#endif
