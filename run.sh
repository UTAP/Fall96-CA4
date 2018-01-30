#!/bin/bash

OUTPUT_DIR=output
TEST_CASE_DIR=testcase

# defining colors
RED="\033[0;31m"
GREEN="\033[0;32m"
NC='\033[0m' # No Color

MAINS=(main.cpp main-with-extra-players.cpp main-with-penalty.cpp main-with-inaquate-teams.cpp main-bigger-testcase.cpp)
counter=1
if [[ -d $OUTPUT_DIR ]]; then
	rm -rf $OUTPUT_DIR
fi
mkdir $OUTPUT_DIR
for file in ${MAINS[*]}; do
	yes | cp -i $file "main.cpp"
	make clean && make && ./${1} > $OUTPUT_DIR/out_$counter
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

echo "=========================="
echo -e "${GREEN}passed${NC}: $accepted_test_cases\t${RED}failed${NC}: $wrong_test_cases"
