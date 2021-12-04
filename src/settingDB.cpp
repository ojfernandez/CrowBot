#include <fstream>
#include <string>

#include "settingDB.h"

#include <iostream>

using json = nlohmann::json;
using namespace std;

nlohmann::json settingDB(const string path, bool& open) {
   json j;
   ifstream db(path);
   cout << path << " : ";
   
   /* Check if stream is open, parses into json if open */
   if (db.is_open()) {
      open = true;
      cout << " opened." << endl;
      db >> j;
   }
   else {
      open = false;
      cout << " failed." << endl;
   }
   return j;
}
