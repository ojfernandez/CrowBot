#include <string>

#include "helpMsg.h"

using json = nlohmann::json;
using namespace std;

string helpMsg(const json j) {
   string msg = "";
   string commDesc[2] = { "" };

   /* Loops through .json file and adds them to msg */
   /* Last line is added with no \n */
   for (int i = 0; i < j.size() - 1; i++) {
      commDesc[0] = j[i].at("comm");
      commDesc[1] = j[i].at("desc");
      msg += (commDesc[0] + " - " + commDesc[1] + "\n");
   }
   commDesc[0] = j[j.size() - 1].at("comm");
   commDesc[1] = j[j.size() - 1].at("desc");
   msg += (commDesc[0] + " - " + commDesc[1]);
   
   return msg;
}
