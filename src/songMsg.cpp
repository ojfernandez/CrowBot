#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

string crowMsg(const json j, int& song, int& songLast) {

   /* Same number pull prevention */
   while (song == songLast) {
      song = rand()%j.size();
   }
   songLast = song;
   
   /* Gets titme, artist, and URL from .json */
   string title = songDB[songRand]["title"];
   string artist = songDB[songRand]["artist"];
   string url = songDB[songRand]["url"];

   /* Creates string from .json info */
   string songMsg = "**Title:** " + title +
   "\n**Artist:** " + artist +
   "\n**URL:** " + url;
   
   return songMsg;
}