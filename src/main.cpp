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

      stringstream ss(event.msg->content);
      string command;
      ss >> command;
      
      // !ping
      // A test command that returns a single message
      if (command == "!ping") {
         bot.message_create(dpp::message(event.msg->channel_id, "Pong!"));
      }
   });
   
   // /campus
   // Sends an image of the campus via campus webcam
   bot.on_interaction_create([&bot](const dpp::interaction_create_t & event) {
      if (event.command.type == dpp::it_application_command) {
         dpp::command_interaction cmd_data = get<dpp::command_interaction>(event.command.data);
         /* Check which command they ran */
         if (cmd_data.name == "campus") {
            
            const string webcam = "http://69.91.192.220/netcam.jpg";
            /* Reply to the command. There is an overloaded version of this
            * call that accepts a dpp::message so you can send embeds.
            */
            event.reply(dpp::ir_channel_message_with_source, fmt::format(webcam));
         }
      }
   });

   bot.on_ready([&bot](const dpp::ready_t & event) {

      dpp::slashcommand newcommand;
      /* Create a new global command on ready event */
      newcommand.set_name("campus")
         .set_description("Sends an image of the UW Bothell campus in real time.")
         .set_application_id(bot.me.id)
      );

      /* Register the command */
      bot.global_command_create(newcommand);
   });

   /* Start bot */
   bot.start(false);
   return 0;
}