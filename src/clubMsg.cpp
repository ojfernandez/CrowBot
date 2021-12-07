#include <string>

#include "clubMsg.h"

using namespace std;

string clubMsg(const dpp::select_click_t& e) {

   return e.values[0];
}
