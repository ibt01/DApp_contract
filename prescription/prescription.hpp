#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>
#include <vector>
#include <string>

using namespace eosio;
using namespace std;

class [[eosio::contract("prescription")]] prescription : public contract {
   public:
      using contract::contract;


   [[eosio::action]] void saveprescr(uint64_t id, string prescr);
   [[eosio::action]] void useprescr(uint64_t id);

   struct [[eosio::table]]  prescrqueue {
      uint64_t id;
      std::string prescr;
      uint64_t createTime;
      uint64_t primary_key() const { return id; }
   };


private:
   uint64_t get_currenttime_s();

   typedef eosio::multi_index< "prescrqueues"_n, prescrqueue > prescrqueues;
};