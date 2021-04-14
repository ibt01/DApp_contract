rm -rf educationblk
mkdir educationblk
cd educationblk
eosio-cpp -abigen ../educationblk.cpp -o educationblk.wasm -I ./