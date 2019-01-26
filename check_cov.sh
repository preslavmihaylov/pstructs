#!/bin/bash

TARGET_PERCENT=90
TOTAL_PERCENT=$(cat coverage/report_raw.txt | grep TOTAL.* | awk '{print $4}')
TOTAL_PERCENT=${TOTAL_PERCENT::-1}
EXIT_CODE=0

if [ "$TOTAL_PERCENT" -gt $TARGET_PERCENT ]; then
    echo "PASSED: Coverage Test"
    EXIT_CODE=0
else
    echo "FAILED: Coverage Test"
    EXIT_CODE=1
fi

echo "Expected more than $TARGET_PERCENT%. Got $TOTAL_PERCENT%"
exit $EXIT_CODE
