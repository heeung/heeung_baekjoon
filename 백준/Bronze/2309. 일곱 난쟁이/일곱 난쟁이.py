lst = [0] * 9
flag = 0

for i in range(9):
    lst[i] = int(input())

lst.sort()
for j in range(8):
    if flag == 1:
        break
    k = j + 1
    while k < 9:
        lst_sub = lst[:]
        del lst_sub[k]
        del lst_sub[j]
        if sum(lst_sub) == 100:
            for a in range(7):
                print(lst_sub[a])
            flag = 1
            break
        k += 1