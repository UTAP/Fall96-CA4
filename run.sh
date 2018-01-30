#!/bin/bash

if [[ $# == 0 ]]; then
    echo -e "usage:\t ${0} code_dir [exe_name]"
    exit 0
fi

OUTPUT_DIR=output
TEST_CASE_DIR=testcase
MAINS_DIR=mains
CODE_DIR="${1}"
EXE="./a.out"
DIFFTOOL="sdiff -sWiw 60"
if [[ $# > 1 ]]; then
	EXE=./${2}
fi

# defining colors
RED="\033[0;31m"
GREEN="\033[0;32m"
CYAN="\033[0;36m"
NC='\033[0m' # No Color

MAINS=(main.cpp main-with-extra-players.cpp main-with-penalty.cpp main-with-inaquate-teams.cpp main-bigger-testcase.cpp)
counter=1
accepted_test_cases=0
wrong_test_cases=0

pushd "$CODE_DIR"
if [[ -d $OUTPUT_DIR ]]; then
	rm -rf $OUTPUT_DIR
fi
mkdir $OUTPUT_DIR
make clean
rm *.o
make || exit 1
$EXE &> /dev/null || {
	echo -e "${RED}$EXE Not Found.${NC}"
	exit 1
}
popd

for file in ${MAINS[*]}; do
	echo -e "\n${CYAN}Testcase $counter ($file)${NC}"
	cp -f $MAINS_DIR/$file "$CODE_DIR"/main.cpp
	pushd "$CODE_DIR"
	make || {
		echo -e "${RED}Make Failure${NC}"
		((wrong_test_cases++))
		popd
		continue
	}
	$EXE > $OUTPUT_DIR/out_$counter
	popd
	if diff -wi "$CODE_DIR"/$OUTPUT_DIR/out_$counter $TEST_CASE_DIR/out_$counter > /dev/null; then
		echo -e "${GREEN}Accepted${NC}"
		((accepted_test_cases++))
	else
		echo -e "${RED}Wrong Answer${NC}"
		((wrong_test_cases++))
		$DIFFTOOL "$CODE_DIR"/$OUTPUT_DIR/out_$counter $TEST_CASE_DIR/out_$counter
	fi
	((counter++))
done

echo -e "\n${CYAN}==========================${NC}"
echo -e "${GREEN}passed${NC}: $accepted_test_cases\t${RED}failed${NC}: $wrong_test_cases"
