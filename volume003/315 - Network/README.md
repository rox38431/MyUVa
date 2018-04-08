# IDEA： 即找出 cut point

1. 根據輸入利用 adjacency matrix 建立圖 G
2. for each v in G.V
　　令 G' = (G.V - v, G.E)
　　對 G' 上之任意點執行 DFS，看是否可拜訪到所有點
　　若無法拜訪到所有的點，則將 count 加一
3. 輸出 count

---

意外發現 UVa 會加我未初始化的陣列初始為 0
