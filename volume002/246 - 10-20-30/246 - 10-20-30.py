def check(piles, card_list):
	while(True):
		if (len(piles) < 3):
			break

		if ((piles[0] + piles[1] + piles[-1]) % 10 == 0):
			card_list.extend((piles[0], piles[1], piles[-1]))
			del((piles[0], piles[0], piles[-1]))
		elif ((piles[0] + piles[-2] + piles[-1]) % 10 == 0):
			card_list.extend((piles[0], piles[-2], piles[-1]))
			del((piles[0], piles[-1], piles[-1]))
		elif ((piles[-3] + piles[-2] + piles[-1]) % 10 == 0):
			card_list.extend((piles[-3], piles[-2], piles[-1]))
			del((piles[-1], piles[-1], piles[-1]))
		else:
			break

def output_piles(piles):
	for i in range(7):
		print("piles " + str(i) + ": " + str(piles[i]))

def append_list(piles, card_list):
	temp = []
	for i in range(7):
		for j in range(len(piles[i])):
			temp.append(piles[i][j])
		temp.append(-1)
	for i in range(len(card_list)):
		temp.append(card_list[i])

	return temp


end = False
fo = open("test.txt", "w")
while(True):
	card_list = [int(x) for x in input().split()]
	if (card_list[0] == 0):
		break
	while(len(card_list) < 52):
		card_list += [int(x) for x in input().split()]

	piles = [[] for i in range(7)]
	for i in range(7):
		piles[i].append(card_list[i])
	del(card_list[0:7])

	for i in range(7):
		piles[i].append(card_list[i])
	del(card_list[0:7])

	count = 14

	record = []
	combine_list = append_list(piles, card_list)
	record.append((combine_list))

	test_count = 1
	end = False
	while(end == False):
		for i in range(7):

			if (len(piles[i]) == 0):
				continue
			else:
				piles[i].append(card_list[0])
				del(card_list[0])
				if (len(piles[i]) >= 3):
					check(piles[i], card_list)
				count += 1

				combine_list = append_list(piles, card_list)
				if (len(card_list) == 52):
					end = True
					fo.write("Win : " + str(count) + "\n")
					#print("Win : %d" % count)
					break
				elif (len(card_list) == 0):
					end = True
					fo.write("Loss: " + str(count) + "\n")
					#print("Loss : %d" % count)
					break
				elif (combine_list in record):
					end = True
					fo.write("Draw: " + str(count) + "\n")
					#print("Draw : %d" % count)
					#print(record.index(temp))
					break
				else:
					record.append((combine_list))








