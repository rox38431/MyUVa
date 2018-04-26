# IDEA 1

利用 dynamic programming 的概念，輸入矩陣大小 row 與 col 後，再將後續的輸入存至矩陣 matrix[1..row][1..col] 

令 len[1..row][1..col]為一二微陣列，其中 len[i][j] ，表示由矩陣中第 (i, j) 項走到最後一行之最小 path weight，

所以 len[i][j] = min{ len[(i + row - 1) % row][j + 1], len[i][j + 1], len[(i + 1) % row][j + 1]　}，

而 len[i][col - 1] = matrix[i][col - 1]。

如此可求得由第一航任一項走至最後一行之最小的 path weight，且也可藉由追蹤矩陣 len 得此 path。

---

# IDEA 2

1.　對於所有圖中的點 (i, j)，建立射向 ((i + row -1 ) % row, j + 1)、(i, j + 1) 與 ((i + 1) % row, j + 1) 的邊，

　　其中 edge weight 設為 matrix[i][j]。

2.　在矩陣的左右兩邊皆加入一點，分別令為 s 與 t，其中 s 與矩陣最左邊的所有點皆建立一條由 s 射出的邊，且 edge weight 都設為 0。

　　同樣的 t 與矩陣最右邊的所有點皆建立一條射向 t 的邊，而 t 與點 (i, col - 1) 相連的邊之 weight 設為 matrix[i][col - 1]。

3. 利用 bellman - ford algorithm，求由 s 到 t 之最短路徑即得解。
