#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>
#include <vector>
#include <string>

using namespace eosio;
using namespace std;

class [[eosio::contract("personalinfo")]] personalinfo : public contract {
   public:
      using contract::contract;


   [[eosio::action]] void saveperson(uint64_t id, string person);


   struct [[eosio::table]]  personqueue {
      uint64_t id;
      std::string person;
      uint64_t createTime;
      uint64_t primary_key() const { return id; }
   };


private:
   uint64_t get_currenttime_s();

   typedef eosio::multi_index< "personqueues"_n, personqueue > personqueues;
};