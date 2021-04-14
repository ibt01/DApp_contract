#include "personalinfo.hpp"
#include "utils.hpp"
#include <math.h> 

const static string SPLITTER = "|";

void personalinfo::saveperson(uint64_t id, string person)
{
    require_auth( get_self());

    personqueues hs(get_self(), _self.value);
    auto iths = hs.find(id);
    check(iths==hs.end(), "id already in cache now");
      hs.emplace( _self, [&](auto& a) {
      a.id = id;
      a.person=person;
      a.createTime=get_currenttime_s();
    });
}


uint64_t personalinfo::get_currenttime_s() {
    return static_cast<uint64_t>(current_time_point().sec_since_epoch());
}
