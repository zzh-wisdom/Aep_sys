
#ifndef AEP_H
#define AEP_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include "hashtable.h"
#include <mutex>
#include "nvm_common2.h"
#include "test_common.h"
#include "random.h"
// #include "persistent_BPlusTree_Wrapper.h"
// #include "drnvm_BPlusTree_Wrapper.h"
#include "statistic.h"
#include <mutex>
#include "nvm_btree.h"
#include "dram_btree.h"
// #include "nvm_nvtree.h"

// #include "statistic.h"



#define CACHE0  "/pmem2/cache/daram0"
#define CACHE1  "/pmem2/cache/daram1"
#define CACHE2  "/pmem2/cache/daram2"
#define CACHE3  "/pmem2/cache/daram3"

#define PATH0      "/pmem0/datastruct/persistent"
#define VALUEPATH0 "/pmem0/datastruct/value_persistent"
#define PATH1      "/pmem1/datastruct/persistent"
#define VALUEPATH1 "/pmem1/datastruct/value_persistent"
#define PATH2      "/pmem2/datastruct/persistent"
#define VALUEPATH2 "/pmem2/datastruct/value_persistent"
#define PATH3      "/pmem3/datastruct/persistent"
#define VALUEPATH3 "/pmem3/datastruct/value_persistent"

using namespace std;

namespace rocksdb{
    class aepsystem{
 public:
    aepsystem();
    ~aepsystem();

    void Initialize();
    void End();
    void Print();

    void Insert(const string &key, const string &value);

    void Delete(const std::string& key);

    string Get(const std::string& key);

   int is_cache;
   int num_size;
   int cache_size;
    
 private:
    size_t KEY_SIZE = rocksdb::NVM_KeySize;         
    size_t VALUE_SIZE = rocksdb::NVM_ValueSize;
    size_t buf_size;        // initilized in parse_input()
   };
}

#endif
