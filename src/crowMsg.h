#ifndef CROWMSG_H
#define CROWMSG_H

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

dpp::embed crowMsg(nlohmann::json&, int&, int&, int&, int&);

#endif
