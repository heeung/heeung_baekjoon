N = int(input())
house_list = list(map(int, input().split()))

house_list.sort(reverse=True)

cnt = 0
while house_list[0] > 0:
    house_list[0] -= 1
    if len(house_list) > 1:
        house_list[1] -= 1
    house_list.sort(reverse=True)
    cnt += 1

if cnt > 1440:
    print(-1)
else:
    print(cnt)