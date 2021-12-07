#include "clubMsg.h"

#include <string>

using namespace std;

string clubMsg(const dpp::select_click_t& e) {

   return e.values[0];
}
