CC = clang
CXXFLAGS = -std=c++14 -lc++ -g

test: bitset_test
	./bitset_test

bitset_test: src/bitset_test.cc bitset.hpp
	$(CC) $(CXXFLAGS) src/bitset_test.cc -o bitset_test

clean:
	rm -rf bitset_test *.dSYM