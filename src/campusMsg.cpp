#include <dpp/dpp.h>
#include <dpp/nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

dpp::embed campusMsg() {
   
   /* URL for webcam with cache buster */
   string webcam = "http://69.91.192.220/nph-jpeg.cgi?" + to_string(time(0));

   /* Creates an embed */
   dpp::embed campusEmbed = dpp::embed().
      set_color(0x4b2e83).
      set_title("UWB Campus Live Image").
      set_url("https://www.uwb.edu/about/webcam").
      set_author("University of Washington Bothell", "https://www.uwb.edu/", "https://www.uwb.edu/uwbothell/media/brand-assets/Logos/w-logo/Web-W-Logo-Purple.png").
      set_thumbnail("https://www.uwb.edu/uwbothell/media/brand-assets/Logos/stacked-w/stacked-encode-w-uw-bothell.png").
      set_image(webcam).
      set_footer(dpp::embed_footer().set_text(webcam)).
      set_timestamp(time(0));

   return campusEmbed;
}