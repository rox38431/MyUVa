def roof(a):
	integer_part = int(a)
	if (a - integer_part != 0):
		return int(a) + 1
	else:
		return int(a)

def floor(a):
	return int(a)


#f = open('output.txt', 'w')
cases = int(input())
while(cases > 0):
	input_list = input().split()

	if (len(input_list) != 3):
		continue

	chess_type = input_list[0]
	row = int(input_list[1])
	col = int(input_list[2])

	ans = 0
	if(chess_type == 'r'):
		ans = min(row, col)
	elif (chess_type == 'k'):
		ans = roof(row / 2) * roof(col / 2) + ((row - roof(row / 2)) * floor(col / 2))
	elif (chess_type == 'Q'):
		ans = min(row, col)
	elif (chess_type == 'K'):
		ans = roof(row / 2) * roof(col / 2)

	print("%.0f" % ans)
	#f.write("%.0f" % ans)
	#f.write("\n")
	cases -= 1