# idea:
1. 假設輸入大小為 n 的矩陣，令為 matrix[1..n][1..n]
2. 先求在矩陣中 (1, 1) 到 (a, b) 所成之長方形和，並存到陣列 sum[a][b] 中，其中 1 <= a、b <= n
3. 再求 (x1, y1) 到 (x2, y2) 在矩陣中之長方形和，求法為 sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]
   ，並在過程中記錄最大的

