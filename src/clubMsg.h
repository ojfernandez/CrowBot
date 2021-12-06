#ifndef CLUBMSG_H
#define CLUBMSG_H

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

dpp::message clubMsg(const nlohmann::json&, dpp::message&);

#endif