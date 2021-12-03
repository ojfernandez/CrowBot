#include <string>

#include "crowMsg.h"

using json = nlohmann::json;
using namespace std;

dpp::embed crowMsg(json& j, int& fact, int& factLast, int& img, int& imgLast) {
   /* Same number pull prevention */
   /*
   while (fact == factLast || img == imgLast) {
      fact = rand() % j.at("facts").size();
      img = rand() % j.at("imgs").size();
   }
   factLast = fact;
   imgLast = img;
   */

   fact = 0;
   factLast = 0;

   /* Gets fact and URL from .json */
   string crowFact = j.at("facts")[fact].at("fact");
   string crowImg = j.at("imgs")[img].at("url");

   /* Creates an embed */
   dpp::embed crowEmbed = dpp::embed().
   set_color(0x4b2e83).
   set_title("Crow Fact!").
   set_description(crowFact).
   set_image(crowImg).
   set_timestamp(time(0));
   
   return crowEmbed;
}
