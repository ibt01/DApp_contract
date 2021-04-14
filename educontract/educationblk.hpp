#pragma once

#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/system.hpp>
#include <eosio/crypto.hpp>
#include <vector>
#include <string>

using namespace eosio;
using namespace std;

class [[eosio::contract("educationblk")]] educationblk : public contract {
   public:
      using contract::contract;


   [[eosio::action]] void saveedu(uint64_t id, string hashfromserver);

   struct [[eosio::table]]  eduqueue {
      uint64_t id;
      std::string eduJson;
      uint64_t createTime;
      uint64_t primary_key() const { return id; }
   };


private:
   uint64_t get_currenttime_s();

   typedef eosio::multi_index< "eduqueues"_n, eduqueue > eduqueues;
};