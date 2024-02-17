#include <iostream>

#include "bricks/dflags/dflags.h"

// NOTE(dkorolev): Make sure to `export CURRENT_WITH_LEVELDB=true; make clean` if the next line fails to build.
#include "leveldb/db.h"

DEFINE_string(db, "./testdb", "The path to LevelDB to use.");
DEFINE_string(key, "key", "The key to populate.");
DEFINE_string(value, "value", "The value to populate.");

int main(int argc, char** argv) {
  ParseDFlags(&argc, &argv);

  leveldb::DB* db;
  leveldb::Options options;

  leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

  if (db) {
    std::cout << "DB opened." << std::endl;
    if (db->Put(leveldb::WriteOptions(), FLAGS_key, FLAGS_value).ok()) {
      std::cout << "Record added." << std::endl;
    } else {
      std::cout << "Failed to add the record." << std::endl;
    }
    delete db;
  } else {
    std::cout << "Failed to open the DB." << std::endl;
  }
}
