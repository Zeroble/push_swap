import random
lst = list(range(500))
f = open("./test_cases.sh", mode='w')
for i in range(0, 500):
    random.shuffle(lst)
    f.write("../push_swap {} | wc -l\n".format(str(lst).replace('[','').replace(']','').replace(',','')))
