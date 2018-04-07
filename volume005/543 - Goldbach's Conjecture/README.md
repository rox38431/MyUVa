# IDEA
1. 先建立質數表 prime[1..1000001]，若 i 為質數，則 prime[i] = true，否則 prime[i] = false
2. 暴力法，若輸入為 x，則令 i = 3 開始，判斷 i 與 x - i 是否皆為質數，若是則輸出解，否則 i += 2 (想一下即可知 i 不可能為偶數)
3. 若 i 已大於等於 x ，則找不到兩質數相加為 x，輸出 Goldbach's conjecture is wrong.
---

快數建立 prime table：
	
	bool prime[1000001];

	for (int i = 0; i < 1000001; i++)
		prime[i] = true;

	for (int i = 2; i < 1000001 / 2; i++) 
		for (int j = i + i; j < 1000001; j++)
			prime[j] = false;