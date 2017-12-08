#!/bin/bash

OUTPUT_DIR=output
TEST_CASE_DIR=testcase

# defining colors
RED="\033[0;31m"
GREEN="\033[0;32m"
NC='\033[0m' # No Color

MAINS=(main.cpp main-with-extra-players.cpp main-with-penalty.cpp main-with-inaquate-teams.cpp main-bigger-testcase.cpp)
counter=1
for file in ${MAINS[*]}; do
	mkdir $OUTPUT_DIR
	yes | cp -i $file "main.cpp"
	make clean && make && ./a.out > $OUTPUT_DIR/out_$counter
	echo Testcase $counter is running:
	if diff $OUTPUT_DIR/out_$counter $TEST_CASE_DIR/out_$counter > /dev/null; then
		echo -e "${GREEN}Accepted${NC}"
		((accepted_test_cases++))
	else
		echo -e "${RED}Wrong Answer${NC}"
		((wrong_test_cases++))
	fi

	((counter++))
done
