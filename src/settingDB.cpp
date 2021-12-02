#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;
using namespace std;

bool settingDB(const string path, json& j) {
   ifstream db(path);
   
   /* Check if stream is open, parses into json if open */
   if (db.is_open()) {
      db >> j;
      return true;
   }
   return false;
}
