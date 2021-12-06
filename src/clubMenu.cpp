#include "clubMenu.h"

#include <iostream>

using json = nlohmann::json;
using namespace std;

void clubMenu(const json& j, dpp::message& m) {

   m.add_component(
      dpp::component().add_component(
         dpp::component().set_type(dpp::cot_selectmenu).
         set_placeholder("Clubs @ UWB").
	 add_select_option(dpp::select_option("Club", "Discord Link", "Club desc.")).
         set_id("ClubMenu")
      )
   );

   cout << "Menu made" << endl;
/*
   for (int i = 0; i < j.size(); i++) {
      cout << "Option " << i << endl;
      m.add_component(
         dpp::component().add_component(
            dpp::component().set_type(dpp::cot_selectmenu).
            add_select_option(dpp::select_option(j[i]["club"], j[i]["link"], j[i]["desc"]))
         )
      );
   }
   */
}
