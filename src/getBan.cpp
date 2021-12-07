#include "getBan.h"

using namespace std;

dpp::ban getBan(dpp::snowflake& s) {
   dpp::ban offender;
   
   offender.user_id = s.mentions[0].first.id;
   offender.reason = "The ban hammer has spoken!";
   
   return offender;
}
