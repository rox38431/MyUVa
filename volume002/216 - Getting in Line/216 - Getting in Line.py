import math



temp_seq = [0] * 8
num = 0

def dfs(pre_node, visited, all_dis, temp_dis, min_dis, count, ans_seq):
    for i in range(num):
        if (visited[i] == 0):
            temp_dis = temp_dis + all_dis[pre_node][i]
            if (temp_dis < min_dis):
                visited[i] = 1
                temp_seq[count] = i
                min_dis = dfs(i, visited, all_dis, temp_dis, min_dis, count + 1, ans_seq)
                visited[i] = 0
            temp_dis = temp_dis - all_dis[pre_node][i]

    if (count == num):
        if (temp_dis < min_dis):
            min_dis = temp_dis
            ans_seq[:] = temp_seq[:]
    return min_dis


count = 1
while(True):
    num = int(input())
    if (num == 0):
        break
        
    arr = [[0 for x in range(2)] for y in range(num)] 
    for i in range(0, num):
        arr[i][:] = [int(x) for x in input().split()]

    all_dis = [[0 for x in range(num)] for y in range(num)] 
    for i in range(1, num):
        for j in range(0, i):
            all_dis[i][j] = math.sqrt(math.pow(arr[i][0] - arr[j][0], 2) + math.pow(arr[i][1] - arr[j][1], 2))
            all_dis[j][i] = all_dis[i][j]

    min_dis = 2147483646
    ans_seq = [0] * 8
    for i in range(num):
        visited = [0] * num
        visited[i] = 1
        temp_seq[0] = i
        min_dis = dfs(i, visited, all_dis, 0, min_dis, 1, ans_seq)

    print("**********************************************************")
    print("Network #" + str(count))
    count += 1
    ans = min_dis + (num - 1) * 16
    for i in range(1, num):
        pre, now = int(ans_seq[i - 1]), int(ans_seq[i])
        print("Cable requirement to connect ", end ="")
        print("(" + str(arr[pre][0]) + "," + str(arr[pre][1]) + ")", end ="")
        print(" to ", end = "")
        print("(" + str(arr[now][0]) + "," + str(arr[now][1]) + ")", end ="")
        print(" is %.2f feet."% (all_dis[pre][now] + 16))
    print("Number of feet of cable required is %.2f." % ans)




