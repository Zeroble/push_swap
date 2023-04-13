python ./case_generater.py
sh ./test_cases.sh | awk 'BEGIN {sum=0; count=0; min=999999; max=-999999} {sum+=$1; count++; if($1<min) min=$1; if($1>max) max=$1} END {print "평균:", sum/count; print "최소값:", min; print "최대값:", max}'
