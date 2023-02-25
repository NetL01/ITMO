#n, m, k = input().split()
#masha = input()
sasha = input()

#s_letter = {}
#list = [x for x in sasha]
#for i in range(0, len(list)):
#    if list[i].isnumeric():
def decode(s):
    return "".join((map(lambda tup:  tup[0] * int(tup[1]), zip(s[0:len(s):2], s[1:len(s):2]))))

print(decode(sasha))
