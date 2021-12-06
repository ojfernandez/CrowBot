#include <string>

#include "clubMsg.h"

using namespace std;

string clubMsg(const dpp::select_click_t& e) {

   return "From " + e.custom_id + ": " + e.values[0];
}