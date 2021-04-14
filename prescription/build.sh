rm -rf prescription
mkdir prescription
cd prescription
eosio-cpp -abigen ../prescription.cpp -o prescription.wasm -I ./