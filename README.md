# push_swap
95/100
틀린 부분
1. 파싱 시 "+" 또는 "-"만 넣었을 때 통과됨

개선안
1. atoi 오버플로우 두번이면 맞는 문제
2. split push후 a스택에 3개 이상 남아있어도 simple sort로 넘겨버려서 비효율적인 문제
3. ra + rrb, rra + rb 가 최적의 조합일 때 고려
