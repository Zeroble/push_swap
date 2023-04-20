python ./case_generater.py
sh ./test_cases.sh | awk '
  NR%2==1 {
    sum += $1
    count++
    if (min == "" || $1 < min) min = $1
    if (max == "" || $1 > max) max = $1
  }
  NR%2==0 {
    if ($1 == "OK") ok_count++
    else if ($1 == "KO") ko_count++
  }
  END {
    printf("평균: %.2f\n", sum/count)
    printf("최소값: %d\n", min)
    printf("최대값: %d\n", max)
    printf("OK: %d\n", ok_count)
    printf("KO: %d\n", ko_count)
  }
'
