#include "prescription.hpp"
#include "utils.hpp"
#include <math.h> 

const static string SPLITTER = "|";

void prescription::saveprescr(uint64_t id, string prescr)
{
    require_auth( get_self());

    prescrqueues hs(get_self(), _self.value);
    auto iths = hs.find(id);
    check(iths==hs.end(), "id already in cache now");
      hs.emplace( _self, [&](auto& a) {
      a.id = id;
      a.prescr=prescr;
      a.createTime=get_currenttime_s();
    });
}

void prescription::useprescr(uint64_t id)
{
    require_auth( get_self());
    prescrqueues hs(get_self(), _self.value);
    auto iths = hs.find(id);
    check(iths!=hs.end(), "id not in cache now");
    hs.erase(iths);
}

uint64_t prescription::get_currenttime_s() {
    return static_cast<uint64_t>(current_time_point().sec_since_epoch());
}
