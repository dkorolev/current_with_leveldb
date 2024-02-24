#include <iostream>

#include "bricks/dflags/dflags.h"

// NOTE(dkorolev): Make sure to `export CURRENT_WITH_LEVELDB=true; make clean` if the next line fails to build.
#include "leveldb/db.h"

DEFINE_string(db, "./testdb", "The path to LevelDB to use.");

int main(int argc, char** argv) {
  ParseDFlags(&argc, &argv);

  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, FLAGS_db, &db);

  if (db) {
    std::cout << "DB opened/created." << std::endl;
    delete db;
    return 0;
  } else {
    std::cout << "Failed." << std::endl;
    return 1;
  }
}
