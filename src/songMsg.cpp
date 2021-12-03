#include <string>

#include "songMsg.h"

using json = nlohmann::json;
using namespace std;

string songMsg(json j, int& song, int& songLast) {
   /* Same number pull prevention */
   while (song == songLast) {
      song = rand() % j.size();
   }
   songLast = song;
   
   /* Gets titme, artist, and URL from .json */
   string title = j[song].at("title");
   string artist = j[song].at("artist");
   string url = j[song].at("url");

   /* Creates string from .json info */
   string msg = "**Title:** " + title +
   "\n**Artist:** " + artist +
   "\n**URL:** " + url;
   
   return msg;
}
