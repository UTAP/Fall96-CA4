#!/bin/bash

OUTPUT_DIR=output
TEST_CASE_DIR=testcase
MAINS_DIR=mains

# defining colors
RED="\033[0;31m"
GREEN="\033[0;32m"
CYAN="\033[0;36m"
NC='\033[0m' # No Color

MAINS=(main.cpp main-with-extra-players.cpp main-with-penalty.cpp main-with-inaquate-teams.cpp main-bigger-testcase.cpp)
counter=1
if [[ -d $OUTPUT_DIR ]]; then
	rm -rf $OUTPUT_DIR
fi
mkdir $OUTPUT_DIR
accepted_test_cases=0
wrong_test_cases=0
for file in ${MAINS[*]}; do
	echo -e "${CYAN}Testcase $counter ($file)${NC}"
	cp -f $MAINS_DIR/$file "main.cpp"
	make && ./${1} > $OUTPUT_DIR/out_$counter
	if diff $OUTPUT_DIR/out_$counter $TEST_CASE_DIR/out_$counter > /dev/null; then
		echo -e "${GREEN}Accepted${NC}"
		((accepted_test_cases++))
	else
		echo -e "${RED}Wrong Answer${NC}"
		((wrong_test_cases++))
	fi
	((counter++))
	echo ""
done

echo -e "${CYAN}==========================${NC}"
echo -e "${GREEN}passed${NC}: $accepted_test_cases\t${RED}failed${NC}: $wrong_test_cases"
