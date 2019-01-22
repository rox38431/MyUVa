root: 	min(row, col)
knight:	roof(row / 2) * roof(col / 2) + ((row - roof(row / 2)) * floor(col / 2))
Queen: 	min(row, col)
King:	roof(row / 2) * roof(col / 2)