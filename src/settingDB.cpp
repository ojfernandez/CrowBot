#include <fstream>
#include <string>

#include "settingDB.h"

using json = nlohmann::json;
using namespace std;

nlohmann::json settingDB(const string path, bool& open) {
   json j;
   ifstream db(path);
   
   /* Check if stream is open, parses into json if open */
   if (db.is_open()) {
      open = true;
      db >> j;
   }
   open = false;
   return j;
}
