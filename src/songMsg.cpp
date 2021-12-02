#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

string songMsg(const json j, int& song, int& songLast) {
   /* Same number pull prevention */
   while (song == songLast) {
      song = rand()%j.size();
   }
   songLast = song;
   
   /* Gets titme, artist, and URL from .json */
   string title = j[song]["title"];
   string artist = j[song]["artist"];
   string url = j[song]["url"];

   /* Creates string from .json info */
   string msg = "**Title:** " + title +
   "\n**Artist:** " + artist +
   "\n**URL:** " + url;
   
   return msg;
}
