import random
lst = list(range(500))
f = open("./test_cases.sh", mode='w')
# for i in range(0, 50):
#     random.shuffle(lst)
#     f.write("./a.out {} | wc -l\n".format(str(lst).replace('[','').replace(']','').replace(',','')))

for i in range(0, 50):
    random.shuffle(lst)
    f.write("./a.out {} | tail -1\n".format(str(lst).replace('[','').replace(']','').replace(',','')))
