#include "classInfo.h"

using namespace std;

string classInfo(string courseID) {
	cpr::Url url = cpr::Url{"https://myplan.uw.edu/course/#/courses/" + courseID};
	//cpr::Response response = cpr::Get(url);
	//string page_content = response.text;
	
	//dpp::message courseinfo = dpp::message(event.msg.channel_id, page_content);
	
	return "pip";
}
