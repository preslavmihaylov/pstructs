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
         $(SRC_DIR)/queue \
         $(SRC_DIR)/min_heap \
         $(SRC_DIR)/max_heap

all: tests

rebuild: clean all

tests: tests_build

tests_build:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i test; \
	done

clean_src:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i clean; \
	done

clean: clean_src
