// License: The Unlicense (https://unlicense.org)

#include "pugixml.hpp"

#include <iostream>

auto main(int argc, char const* argv[]) -> int {
  if (2 == argc) {
    pugi::xml_document doc;
    if (!doc.load_file(argv[1])) return -1;
    pugi::xml_node activities = doc.child("TrainingCenterDatabase").child("Activities");

    for (pugi::xml_node activity : activities.children("Activity")) {
      pugi::xml_node lap = activity.child("Lap");
      pugi::xml_node track = lap.child("Track");
      for (pugi::xml_node track_point : track.children("Trackpoint")) {
        std::cout << track_point.child("Time").child_value() << std::endl;
      }
    }
  }
}
