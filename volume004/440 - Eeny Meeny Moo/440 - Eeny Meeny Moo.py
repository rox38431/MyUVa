all_m = [0] * 51
for i in range(3, 51):
	j = 1
	while(True):
		j += 1
		#initial
		is_killed = [0] * i

		#start to kill use j
		is_killed[0] = 1
		next_kill = 0
		kill_count = 1
		while(True):
			#print("+++" + str(next_kill))
			count_to_death = 0
			while(count_to_death < j):
				next_kill = (next_kill + 1) % i
				if (is_killed[next_kill] == 0):
					#print(next_kill, is_killed[next_kill])
					count_to_death += 1
			if (next_kill == 1):
				#print("break")
				break
			else:
				#print("stay")
				is_killed[next_kill] = 1
				kill_count += 1
		if (kill_count == i - 1):
			all_m[i] = j
			break

while(True):
	num = int(input())
	if (num == 0):
		break
	else:
		print(all_m[num])
