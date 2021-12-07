#include "getBan.h"

using namespace std;

dpp::ban getBan(const dpp::message_create_t m) {
   dpp::ban offender;
   
   offender.user_id = m.mentions[0].first.id;
   offender.reason = "The ban hammer has spoken!";
   
   return offender;
}
