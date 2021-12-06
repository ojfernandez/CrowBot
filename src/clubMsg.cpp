#include <string>

#include "clubMsg.h"

using json = nlohmann::json;
using namespace std;

void clubMsg(const json& j, dpp::message& m) {

   m.add_component(
      dpp::compare().add_component(
         dpp::component().set_type(dpp::cot_selectmenu).
         set_placeholder("Pick something").
         add_select_option(dpp::select_option("label1","value1","description1").set_emoji(u8"😄")).
         add_select_option(dpp::select_option("label2","value2","description2").set_emoji(u8"🙂")).
         set_id("myselid");
      )
   );
}