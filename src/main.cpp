#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <templatebot/templatebot.h>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>

using json = nlohmann::json;
using namespace std;

/* Setup databases */
json commDB; // Command list for !help
json songDB; // Song list for !song
json crowDB; // Crow facts for !crowFact
//json clubDB; // Club list for !clubs

/* Random variables and weights */
int crowRand = -1;
int crowLast = -1;
int crowImgRand = -1;
int crowImgLast = -1;
int songRand = -1;
int songLast = -1;

int main(int argc, char const *argv[]) {
	srand(time(0));

	json configdocument;
	ifstream configfile("../config.json");
	configfile >> configdocument;

	/* Reading in .json files from dataBases folder */
	ifstream db1("../dataBases/comms.json");
	db1 >> commDB;
	ifstream db2("../dataBases/songs.json");
	db2 >> songDB;
	ifstream db3("../dataBases/crows.json");
	db3 >> crowDB;
	//ifstream db4("../dataBases/clubs.json");
	//db4 >> clubDB;

   /* Setup the bot */
   dpp::cluster bot(configdocument["token"]);

   /* Log event */
   bot.on_log([&bot](const dpp::log_t &event) {
      if (event.severity >= dpp::ll_debug) {
         cout << dpp::utility::current_date_time() << " [" << dpp::utility::loglevel(event.severity) << "] " << event.message << "\n";
      }
   });

   /* Use the on_message_create event to look for commands */
   bot.on_message_create([&bot](const dpp::message_create_t &event) {

      stringstream ss(event.msg.content);
      string command;
      ss >> command;

      /* !help */
      /* A command which shows the different avaiable commands for the bot */
      /* Requires comms.json to be read */
      if (command == "!help" && commDB.size() > 0) {

	string commDesc[2] = { "" };
	string helpMsg = "";

	for (int i = 0; i < commDB.size() - 1; i++) {
		commDesc[0] = commDB[i]["comm"];
		commDesc[1] = commDB[i]["desc"];
		helpMsg += (commDesc[0] + " - " + commDesc[1] + "\n");
	}
	commDesc[0] = commDB[commDB.size() - 1]["comm"];
	commDesc[1] = commDB[commDB.size() - 1]["desc"];
	helpMsg += (commDesc[0] + " - " + commDesc[1]);

	bot.message_create(dpp::message(event.msg.channel_id, helpMsg));
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
      if (command == "!crowFact" && crowDB["facts"].size() > 0) {

	/* Same number pull prevention */
	while (crowRand == crowLast || crowImgRand == crowImgLast) {
		crowRand = rand()%crowDB["facts"].size();
		crowImgRand = rand()%crowDB["imgs"].size();
      	}
	      	crowLast = crowRand;
	      	crowImgLast = crowImgRand;

	      string crowFact = crowDB["facts"][crowRand]["fact"];
	      string crowImg = crowDB["imgs"][crowImgRand]["url"];

	      dpp::embed crowEmbed = dpp::embed().
		      set_color(0x4b2e83).
		      set_title("Crow Fact!").
		      set_description(crowFact).
		      set_image(crowImg).
		      set_timestamp(time(0));

         //bot.message_create(dpp::message(event.msg.channel_id, crowDB[crowRand]["fact"]));

	 /* reply with the created embed */
	 bot.message_create(dpp::message(event.msg.channel_id, crowEmbed).set_reference(event.msg.id));
      }

      /* !songSuggest */
      /* Sends a random song suggestion */
      /* Requires songs.json to be read */
	if (command == "!songSuggest" && songDB.size() > 0) {	

		/* Same number pull prevention */
		while (songRand == songLast) {
			songRand = rand()%songDB.size();
		}
		songLast = songRand;

		string title = songDB[songRand]["title"];
		string artist = songDB[songRand]["artist"];
		string url = songDB[songRand]["url"];

		string songMsg = "**Title:** " + title +
				 "\n**Artist:** " + artist +
				 "\n**URL:** " + url;

		bot.message_create(dpp::message(event.msg.channel_id, songMsg));
	}

      /* !campus */
      /* Sends an embedded image of the UWB campus grounds */
      if (command == "!campus") {

      int t = time(0);
      string webcam = "http://69.91.192.220/nph-jpeg.cgi?" + to_string(t);

         dpp::embed campusEmbed = dpp::embed().
	    set_color(0x4b2e83).
	    set_title("UWB Campus Live Image").
	    set_url("https://www.uwb.edu/about/webcam").
	    set_author("University of Washington Bothell", "https://www.uwb.edu/", "https://www.uwb.edu/uwbothell/media/brand-assets/Logos/w-logo/Web-W-Logo-Purple.png").
	    set_thumbnail("https://www.uwb.edu/uwbothell/media/brand-assets/Logos/stacked-w/stacked-encode-w-uw-bothell.png").
	    set_image(webcam).
	    set_footer(dpp::embed_footer().set_text(webcam)).
	    set_timestamp(time(0));

      	 /* reply with the created embed */
         bot.message_create(dpp::message(event.msg.channel_id, campusEmbed).set_reference(event.msg.id));
      }
   });

   /* Start bot */
   bot.start(false);
   return 0;
}
