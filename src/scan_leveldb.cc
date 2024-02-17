#include <iostream>

#include "bricks/dflags/dflags.h"

// NOTE(dkorolev): Make sure to `export CURRENT_WITH_LEVELDB=true; make clean` if the next line fails to build.
#include "leveldb/db.h"

DEFINE_string(db, "./testdb", "The path to LevelDB to use.");

int main(int argc, char** argv) {
  ParseDFlags(&argc, &argv);

  leveldb::DB* db;
  leveldb::Options options;

  leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);

  if (db) {
    std::cout << "DB opened." << std::endl;

    leveldb::Iterator* cit = db->NewIterator(leveldb::ReadOptions());
    for (cit->SeekToFirst(); cit->Valid(); cit->Next()) {
      std::cout << cit->key().ToString() << ": "  << cit->value().ToString() << std::endl;
    }
    if (cit->status().ok()) {
      std::cout << "Scan succeeded." << std::endl;
    } else {
      std::cout << "Scan failed." << std::endl;
    }
    delete cit;
    delete db;
  } else {
    std::cout << "Failed to open the DB." << std::endl;
  }
}
