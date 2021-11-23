#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>
#include <templatebot/templatebot.h>
#include <iomanip>
#include <sstream>

using json = nlohmann::json;
using namespace std;

int main(int argc, char const *argv[]) {
   json configdocument;
   ifstream configfile("../config.json");
   configfile >> configdocument;
   ifstream infile("songs.txt");
   bool songs = true;
   bool crowFacts = true;
   bool clubs = true;
   if (!infile) {
   	song = false;
	cout << "Can't read song file" << endl;
   }

   /* Setup the bot */
   dpp::cluster bot(configdocument["token"]);

	//create vector of song
	vector<string[3]> songSuggestions;
	

   /* Log event */
   bot.on_log([&bot](const dpp::log_t &event) {
      if (event.severity >= dpp::ll_debug) {
         cout << dpp::utility::current_date_time() << " [" << dpp::utility::loglevel(event.severity) << "] " << event.message << "\n";
      }
   });

   /* Use the on_message_create event to look for commands */
   bot.on_message_create([&bot](const dpp::message_create_t &event) {
      stringstream ss(event.msg->content);
      string command;
      ss >> command;
      
      // !ping
      // A test command that returns a single message
      if (command == "!ping") {
         bot.message_create(dpp::message(event.msg->channel_id, "Pong!"));
      }

      //!inspire
      // A test command that returns a single insirpartional quote
      if (command == "!inspire") {
            
            bot.message_create(dpp::message(event.msg->channel_id, "***SURPASS YOUR LIMITS***"));
      }
      
      if (command == "!crowFact") {
         vector<string> crowFacts = {"Young crows leave the nest after four weeks.", "Crows have around 250 different calls.", 
            "Crow eggs hatch after 20-40 days.", "Crows are COOL", "Crows are part of the family Corvidae.", "Crows are omnivores."};
         int max; 
         max = 5;
         srand(time(0));
         bot.message_create(dpp::message(event.msg->channel_id, crowFacts.at(rand()%max)));
      }

	if (command == ("!suggestSongs") {
	}
      
      // !campus
      // Sends an embedded image of the UWB campus grounds
      if (command == "!campus") {

      string webcam;
      int t = time(0);
      webcam = "http://69.91.192.220/nph-jpeg.cgi?" + to_string(t);

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
         bot.message_create(dpp::message(event.msg->channel_id, campusEmbed).set_reference(event.msg->id));
      }
   });

   /* Start bot */
   bot.start(false);
   return 0;
}
