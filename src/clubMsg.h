#ifndef CLUBMSG_H
#define CLUBMSG_H

#include <string>
#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

void clubMenu(const nlohmann::json&, dpp::message&);
std::string clubMsg(const dpp::select_click_t&)

#endif
