rm -rf personalinfo
mkdir personalinfo
cd personalinfo
eosio-cpp -abigen ../personalinfo.cpp -o personalinfo.wasm -I ./