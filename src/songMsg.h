#ifndef SONGMSG_H
#define SONGMSG_H

#include <string>
#include <dpp/nlohmann/json.hpp>

std::string songMsg(const nlohmann::json, int&, int&);

#endif
