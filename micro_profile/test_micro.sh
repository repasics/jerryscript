TESTS_DIR="../tests/jerry"
RESULT_FILE="test_result.txt"
SNAPSHOT_FILE="./micro.snapshot"
HEADER_NAME="./include/micro-source.h"
INCLUDE_PATH=`realpath ./include`

COM_RUN="../build/bin/jerry-micro"

PASS=0
FAIL=0
SUM=0

rm -f $RESULT_FILE
touch $RESULT_FILE

#3rd run all the related tests
for entry in "$TESTS_DIR"/*
do
  ./micro.sh $entry -t
  $COM_RUN

  if [ $? -eq 0 ] ; then
    echo "PASS: "$entry >> test_rate.txt
    PASS=$((PASS+1))
  else
    FAIL=$((FAIL+1))
    echo "FAIL: "$entry >> test_rate.txt
  fi

  SUM=$((SUM+1))
done

echo "****************************"
echo "PASS: "$PASS
echo "FAIL: "$FAIL
echo "SUM: "$SUM
