#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <sstream>
#include <iostream>

using json = nlohmann::json;
using namespace std;

const int DATABASES = 4;

int main(int argc, char const *argv[]) {
   srand(time(0));

   json configdocument;
   ifstream configfile("../config.json");
   configfile >> configdocument;

   /* Setup the bot */
   dpp::cluster bot(configdocument["token"]);

   /* Log event */
   bot.on_log([&bot](const dpp::log_t &event) {
      if (event.severity >= dpp::ll_debug) {
         cout << dpp::utility::current_date_time() << " [" << dpp::utility::loglevel(event.severity) << "] " << event.message << "\n";
      }
   });
   
   bot.on_ready([&bot](const dpp::ready_t &event)) {
      /* Setup databases */
      json commDB; // Command list for !help
      json songDB; // Song list for !song
      json crowDB; // Crow facts for !crowFact
      json clubDB; // Club list for !clubs
      
      bool dbFound[DATABASES] = { false }; // Array of bools represent if databases exist
      
      /* Random variables and weights */
      int crowRand = -1;
      int crowLast = -1;
      int crowImgRand = -1;
      int crowImgLast = -1;
      int songRand = -1;
      int songLast = -1;
      
      /* Reading in .json files from dataBases folder */
      ifstream db1("../dataBases/comms.json");
      if (db1.is_open()) {
         db1 >> commDB;
         dbFound[0] = true;
      }
      
      ifstream db2("../dataBases/songs.json");
      if (db2.is_open()) {
         db2 >> songDB;
         dbFound[1] = true;
      }
      
      ifstream db3("../dataBases/crows.json");
      if (db3.is_open()) {
         db3 >> crowDB;
         dbFound[2] = true;
      }
      
      ifstream db4("../dataBases/clubs.json");
      if (db4.is_open()) {
         db4 >> clubDB;
         dbFound[3] = true;
      }
   }

   /* Use the on_message_create event to look for commands */
   bot.on_message_create([&bot](const dpp::message_create_t &event) {

      string failed = " not found. Database failed to open.";
      
      /* Reads messages from Discord */
      stringstream ss(event.msg.content);
      string command;
      ss >> command;

      /* !help */
      /* A command which shows the different avaiable commands for the bot */
      /* Requires comms.json to be read */
      if (command == "!help") {
      	 if (dbFound[0]) {
            bot.message_create(dpp::message(event.msg.channel_id, helpMsg(commDB)));
	 }
	 else {
	    bot.message_create(dpp::message(event.msg.channel_id, (command + failed));
	 }
      }

      /* !ping */
      /* A test command that returns a single message */
      if (command == "!ping") {
         bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
      }

      /* !inspire */
      /* A test command that returns a single insirpartional quote */
      if (command == "!inspire") {
         bot.message_create(dpp::message(event.msg.channel_id, "***SURPASS YOUR LIMITS***"));
      }

      /* !crowFact */
      /* Sends a random crow fact */
      /* Requires crows.json to be read */
      if (command == "!crowFact" && dbFound[1]) {
	 if (dbFound[1]) {
            /* Creates an embed */
            dpp::embed crowEmbed = crowMsg(crowDB, crowRand, crowLast, crowImg, crowImgLast);

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, crowEmbed).set_reference(event.msg.id));
	 }
	 else {
	    bot.message_create(dpp::message(event.msg.channel_id, (command + failed));
	 }
     }

      /* !songSuggest */
      /* Sends a random song suggestion */
      /* Requires songs.json to be read */
      if (command == "!songSuggest") {
         if (dbFound[2]) {      
            bot.message_create(dpp::message(event.msg.channel_id, songMsg(songDB, songRand, songLast)));
      	 }
	 else {
	    bot.message_create(dpp::message(event.msg.channel_id, (command + failed));
	 }
      }

      /* !campus */
      /* Sends an embedded image of the UWB campus grounds */
      if (command == "!campus") {
         /* reply with the created embed */
         bot.message_create(dpp::message(event.msg.channel_id, campusMsg()).set_reference(event.msg.id));
      }
   });

   /* Start bot */
   bot.start(false);
   return 0;
}
