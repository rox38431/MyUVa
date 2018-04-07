# IDEA
1. 若輸入 n 個字，則建立一個矩陣 words[1..n, 1..n]
2. 若第 i 個字與第 j 個字相差一個 char，則 words[i, j] = 1，否則 words[i, j] = 1000 (作為無限)
3. 給兩個字，欲求最少轉換數，則對矩陣 words 執行 floyd-warshall algo，求兩點之間的 shortest path 得解

---

相當於求圖上兩點間的最少邊數，所以用 BFS 解更佳