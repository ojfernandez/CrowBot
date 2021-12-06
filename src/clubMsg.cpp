#include <string>

#include "clubMsg.h"

using json = nlohmann::json;
using namespace std;

void clubMenu(const json& j, dpp::message& m) {

   m.add_component(
      dpp::component().add_component(
         dpp::component().set_type(dpp::cot_selectmenu).
         set_placeholder("Clubs @ UWB").
         for (int i = 0; i < j.size(); i++) {
             add_select_option(dpp::select_option(j[i]["club"], j[i]["link"], j[i]"desc").
         }
         set_id("clubMenu")
      )
   );
}

string clubMsg(const const dpp::select_click_t& e) {

   return "From " + e.custom_id + ": " + e.values[0];
}