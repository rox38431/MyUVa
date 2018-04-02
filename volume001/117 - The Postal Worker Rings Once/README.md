# idea:
1. 根據題目條件已知見出的圖一定具有 Euler Path
2. 所以可得
   if (若所有點之 degree 皆為偶數)
      ans = 所有 street 之 weight 總和
   else if (有兩點 degree 為奇數，另為 a 和 b )
      ans = 所有 street 之 weight 總和 + a 到 b 之最短路徑距離
