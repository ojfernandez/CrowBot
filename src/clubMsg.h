#ifndef CLUBMSG_H
#define CLUBMSG_H

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

void clubMsg(const nlohmann::json&, dpp::message&);

#endif
