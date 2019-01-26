SRC_DIR=./src
INC_DIR=$(abspath ./include)

CC=g++
INCLUDES=-I. -I$(INC_DIR)
CFLAGS=-g -O2 -std=c++11 -Wall -Wextra -Werror -Wno-unused-function \
       -Wno-unused-parameter -Wno-address -rdynamic -DNDEBUG \
       -fprofile-arcs -ftest-coverage \
       $(INCLUDES) $(OPTFLAGS)

export CC
export CFLAGS
export INCLUDES

PROJECTS=$(SRC_DIR)/stack \
         $(SRC_DIR)/queue \
         $(SRC_DIR)/min_heap \
         $(SRC_DIR)/max_heap

EXIT_CODE=0

.PHONY: coverage detailed_coverage

all: tests

rebuild: clean all

tests:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i test || EXIT_CODE=$$?; \
	done; \
	exit $$EXIT_CODE;

mem_check:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i mem_check || EXIT_CODE=$$?; \
	done; \
	exit $$EXIT_CODE;

coverage: build
	gcovr -e ".*tests/.*" -o coverage/report_raw.txt || true
	cat coverage/report_raw.txt
	@./check_cov.sh

detailed_coverage: build
	gcovr -e ".*tests/.*" --html --html-details -o coverage/report.html
	gcovr -e ".*tests/.*" -o coverage/report_raw.txt
	cat coverage/report_raw.txt
	@./check_cov.sh

clean: clean_src

clean_src:
	@for i in $(PROJECTS); do \
		$(MAKE) -C $$i clean; \
	done

build:
	@rm coverage/* || true
	mkdir coverage || true

