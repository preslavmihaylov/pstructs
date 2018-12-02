SRC_DIR=./src
INC_DIR=$(abspath ./include)

CC=g++
INCLUDES=-I. -I$(INC_DIR)
CFLAGS=-g -O2 -Wall -Wextra -Werror -Wno-unused-function \
       -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG\
       $(INCLUDES) $(OPTFLAGS)

export CC
export CFLAGS
export INCLUDES

PROJECTS=$(SRC_DIR)/stack \
         $(SRC_DIR)/queue

all: tests

rebuild: clean all

tests: tests_run

tests_build:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i test; \
	done

tests_run: tests_build
	@for i in $(PROJECTS); do \
		echo "TESTING $$i"; \
		./$$i/tests/tests.exe; \
	done

target_src:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i target; \
	done

clean_src:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i clean; \
	done

