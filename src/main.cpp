#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "settingDB.h"
#include "helpMsg.h"
#include "crowMsg.h"
#include "songMsg.h"
#include "clubMenu.h"
#include "clubMsg.h"
#include "campusMsg.h"
#include "classInfo.h"
#include "debug.h"

using json = nlohmann::json;
using namespace std;

/* Global constants */
const int DB = 4; // # of databases (.json)
const int FAIL = 3; // # of failed messages

/* Setup databases */
json database[DB]; // Array of databases
bool dbFound[DB] = { false }; // Array of bools represent if databases exist

/* Random variables and weights */
int crowRand = -1;
int crowLast = -1;
int crowImgRand = -1;
int crowImgLast = -1;
int songRand = -1;
int songLast = -1;

int main(int argc, char const *argv[]) {
   srand(time(0)); // Seed randomness

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
      if (event.severity > dpp::ll_trace) {
         std::cout << event.message << "\n";
      }
   });
   
   bot.on_ready([&bot](const dpp::ready_t &event) {
      
      /* Array of strings of the path to databases */
      string dbPath[DB] = {
        "../dataBases/comms.json",
        "../dataBases/crows.json",
	     "../dataBases/songs.json",
        "../dataBases/clubs.json"
      };
      
      /* Reading in .json files from dataBases folder */
      for (int i = 0; i < DB; i++) {
         database[i] = settingDB(dbPath[i], dbFound[i]);
      }
   });

   /* Use the on_message_create event to look for commands */
   bot.on_message_create([&bot](const dpp::message_create_t& event) {

      /* Reads messages from Discord */
      stringstream ss(event.msg.content);
      string command;
      ss >> command;

      string failed = "Cannot execute " + command + ". ";

      string reason[FAIL] = {
         "Database cannot be opened.",
	 "Command needs an extra parameter.",
	 "Do not have access to this command."
      };

      /* !help */
      /* A command which shows the different avaiable commands for the bot */
      /* Requires comms.json to be read */
      if (command == "!help") {
         if (dbFound[0]) {
         bot.message_create(dpp::message(event.msg.channel_id, helpMsg(database[0])));
         }
         else {
            bot.message_create(dpp::message(event.msg.channel_id, failed + reason[0]));
         }
      }

      /* !ping */
      /* A test command that returns a single message */
      if (command == "!ping") {
         bot.message_create(dpp::message(event.msg.channel_id, "Pong!"));
      }

      /* !inspire */
      /* A test command that returns a single insparational quote */
      if (command == "!inspire") {
         bot.message_create(dpp::message(event.msg.channel_id, "***SURPASS YOUR LIMITS***"));
      }

      /* !crowFact */
      /* Sends a random embedded crow fact */
      /* Requires crows.json to be read */
      if (command == "!crowFact") {
         if (dbFound[1]) {
            /* Creates an embed */
            dpp::embed crowEmbed = crowMsg(database[1], crowRand, crowLast, crowImgRand, crowImgLast);

            /* reply with the created embed */
            bot.message_create(dpp::message(event.msg.channel_id, crowEmbed).set_reference(event.msg.id));
         }
         else {
            bot.message_create(dpp::message(event.msg.channel_id, failed + reason[0]));
         }
      }

      /* !songSuggest */
      /* Sends a random song suggestion */
      /* Requires songs.json to be read */
      if (command == "!songSuggest") {	
         if (dbFound[2]) {
            bot.message_create(dpp::message(event.msg.channel_id, songMsg(database[2], songRand, songLast)));
         }
         else {
            bot.message_create(dpp::message(event.msg.channel_id, failed + reason[0]));
         }
      }

      /* !clubs */
      /* Sends a menu of clubs at UWB */
      /* Requires clubs.json to be read */
      if (command == "!clubs") {
         if (dbFound[3]) {
            dpp::message clubList(event.msg.channel_id, "**Clubs @ UWB**");
	    clubMenu(database[3], clubList);
            bot.message_create(clubList);
         }
         else {
            bot.message_create(dpp::message(event.msg.channel_id, failed + reason[0]));
         }
      }

      /* !campus */
      /* Sends an embedded image of the UWB campus grounds */
      if (command == "!campus") {
         /* reply with the created embed */
         bot.message_create(dpp::message(event.msg.channel_id, campusMsg()).set_reference(event.msg.id));
      }
      
      /* !classInfo */
      /* Gets information regarding UW Course */
      if (command == "!classInfo") {
      	string parameter;
      	ss >> parameter;
      	if (parameter == "") {
      		bot.message_create(dpp::message(event.msg.channel_id, failed + reason[1] + " Please specify a course. (e.g.\"!classInfo CSS360\"\)"));
	}
      	else {
      		bot.message_create(dpp::message(event.msg.channel_id, classInfo(parameter)).set_reference(event.msg.id));
	}
      }
     
      /* .debug <key>*/
      /* Sends a script of commands, calling itself for testing */
      /* A key is required for the test to work */
      if (command == ".debug") {
      	string key;
      	ss >> key;
      	string pass = "0GsdNb";
      	
      	if (key == pass) {
      		vector<string> commands;
      		debug(commands);
      		
      		bot.message_create(dpp::message(event.msg.channel_id, "**TESTING COMMANDS**"));
	      	sleep(1);
	      	
      		for (int i = 0; i < commands.size(); i++) {
      			bot.message_create(dpp::message(event.msg.channel_id, commands[i]));
      			sleep(1);
      		}
	      	
	      	bot.message_create(dpp::message(event.msg.channel_id, "**TESTING RESPONSES**"));
      	}
      	else {
      		bot.message_create(dpp::message(event.msg.channel_id, failed + reason[2]));
      	}
      	
      }
      sleep(2);
   });

   /* Use on_select_click for when a suer clicks your select menu */
   bot.on_select_click([&bot](const dpp::select_click_t& event) {
      if (event.custom_id == "ClubMenu") {
         event.reply(dpp::ir_channel_message_with_source, clubMsg(event));
      }
      else {
         /* Select clicks are still interactions and must be replied to in some form */
         /* This is needed to prevent the "this interaction has failed" message from Discord to the user. */
         event.reply(dpp::ir_channel_message_with_source, "You clicked " + event.custom_id + " and chose: " + event.values[0]);
      }
   });

   /* Start bot */
   bot.start(false);
   return 0;
}
