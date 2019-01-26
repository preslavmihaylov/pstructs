INC_DIR=../../include
TESTS_DIR=./tests

CC=g++
INCLUDES ?= -I. -I$(INC_DIR)
CFLAGS ?= -g -O2 -std=c++11 -Wall -Wextra -Werror -Wno-unused-function \
          -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
          $(INCLUDES) $(OPTFLAGS)
TESTS_LIBS=-lcppunit

TESTS_SOURCES=$(shell find $(TESTS_DIR) -name '*.cpp')
TESTS_OBJECTS=$(TESTS_SOURCES:%.cpp=%.o)
TESTS_TARGET=$(TESTS_DIR)/tests.exe

all: test

rebuild: clean all

test: $(TESTS_TARGET)
	./tests/tests.exe

mem_check: $(TESTS_TARGET)
	valgrind --leak-check=yes --tool=memcheck ./tests/tests.exe

$(TESTS_DIR)/%.o: $(TESTS_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TESTS_TARGET): $(TESTS_OBJECTS)
	$(CC) $(CFLAGS) $< -o $@ $(TESTS_LIBS)

clean:
	rm -rf $(TESTS_TARGET) || true
	rm -rf $(TESTS_OBJECTS) || true

