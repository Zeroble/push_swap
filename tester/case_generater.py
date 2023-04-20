import random

TEST_PARAMETERS = 5
TEST_CASES = 1000

lst = list(range(0, TEST_PARAMETERS))
f = open("./test_cases.sh", mode='w')
for i in range(0, TEST_CASES):
    random.shuffle(lst)
    # f.write("echo TEST {}\n".format(i))
    f.write("../push_swap {} | wc -l\n".format(str(lst).replace('[','').replace(']','').replace(',','')))
    f.write('ARG="{}"; ../push_swap $ARG | ../checker_Mac $ARG\n'.format(str(lst).replace('[','').replace(']','').replace(',','')))
