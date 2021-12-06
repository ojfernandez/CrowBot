#include "clubMenu.h"

#include <iostream>

using json = nlohmann::json;
using namespace std;

void clubMenu(const json& j, dpp::message& m) {

   // Unfortuately needs to be hardcoded rn
   // Seems to be possible to be varied, needs more research
   m.add_component(
      dpp::component().add_component(
         dpp::component().set_type(dpp::cot_selectmenu).
         set_placeholder("Clubs @ UWB").
	      add_select_option(dpp::select_option("ACM@UWB", "https://discord.gg/p94BdasxXm", "")).
         add_select_option(dpp::select_option("Husky Game Dev", "https://discord.gg/qghnHGZ", "A club dedicated to the practice of game dev.")).
         add_select_option(dpp::select_option("Husky Gaming Club", "https://discord.gg/hgc", "The main HUB of gaming at UWB")).
         add_select_option(dpp::select_option("Bothell Beats", "https://discord.gg/y6Yuybm2bK", "The Music Prod. Club @ UW Bothell (Unofficial)")).
         add_select_option(dpp::select_option("CS @ UWB", "https://discord.gg/feaXtKUfQj", "Computer Science @ UW Bothell")).
         add_select_option(dpp::select_option("UW Discord Directory", "https://discord.gg/HYQhXXJyny", "")).
         set_id("ClubMenu")
      )
   );

   // Test to see if menu can be adjusted based on database size
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


