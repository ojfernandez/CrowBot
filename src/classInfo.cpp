#include "classInfo.h"

using namespace std;

dpp::embed classInfo(string courseID) {
	
	for (auto & c: courseID) c = toupper(c);
	
	dpp::embed courseInfo = dpp::embed().
		set_color(0x4b2e83).
      		set_title("Course Information for " + courseID).
      		set_url("https://myplan.uw.edu/course/#/courses/" + courseID).
      		set_author("University of Washington Bothell", "https://www.uwb.edu/", "https://www.uwb.edu/uwbothell/media/brand-assets/Logos/w-logo/Web-W-Logo-Purple.png").
      		set_thumbnail("https://www.uwb.edu/uwbothell/media/brand-assets/Logos/stacked-w/stacked-encode-w-uw-bothell.png").
      		set_timestamp(time(0));
      			
	return courseInfo;
}
