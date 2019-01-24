import math

def bubble_sort(W):
	for i in range(len(W) - 1):
		for j in range(0, len(W) - i - 1):
			if (W[j] > W[j + 1]):
				temp = W[j + 1]
				W[j + 1] = W[j]
				W[j] = temp

while (True):
	try:
		input_line = input()
	except:
		break
	input_word = input_line.split()

	W = []
	for i in range(len(input_word)):
		num = 0
		for j in range(len(input_word[i])):
			num += (ord(input_word[i][j]) - 96) * math.pow(32, (len(input_word[i]) - j - 1))
		W.append(int(num))

	bubble_sort(W)

	C = W[0]
	n = len(W)
	end = False
	while(end == False):
		for i in range(len(W)):
			jump_out = False
			for j in range(i + 1, len(W)):
				if ( (int(C / W[i]) %  n) == (int(C / W[j]) % n) ):
					jump_out = True
					C = int(min((int(C / W[i]) + 1) * W[i], (int(C / W[j]) + 1) * W[j]))
			if (jump_out == True):
				break
		if (jump_out == False):
			end = True

	print(input_line)
	print(C)
	print()
