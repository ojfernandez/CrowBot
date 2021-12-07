#include "getBan.h"

using namespace std;

dpp::ban getBan(dpp::message& m) {
   dpp::ban offender;
   
   offender.user_id = m.msg.mentions[0].first.id;
   offender.reason = "The ban hammer has spoken!";
   
   return offender;
}
