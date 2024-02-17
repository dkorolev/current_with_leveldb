# `current_with_leveldb`

To run:

```
export CURRENT_WITH_LEVELDB=true
make
```

To run from scratch:

```
mkdir -p clean/with/subdirs
cd clean/with/subdirs
git clone https://github.com/dkorolev/current_with_leveldb
export CURRENT_WITH_LEVELDB=true
make
./.current/create_leveldb
./.current/scan_leveldb
./.current/populate_leveldb
./.current/scan_leveldb
./.current/populate_leveldb --key foo --value bar
./.current/scan_leveldb
```

The Makefile is originally grabbed from:

```
wget https://raw.githubusercontent.com/C5T/Current/stable/cmake/Makefile
```

For the time being, I've changed the repo & branch name for LevelDB support.

**TODO(dkorolev):** This will be unnecessary once the respective PR into C5T/Current is merged.
