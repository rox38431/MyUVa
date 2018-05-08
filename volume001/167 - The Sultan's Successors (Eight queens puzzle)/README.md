# IDEA 

先求出八后可放的位置組合(有92種)，八后的組和可利用　decision tree　結合遞迴之方式求解，<br>
再將求得的皇后擺放方式存到二維陣列，之後再根據輸入的棋盤一一測試此92種組合中最大的解。<br>

程式中right_down矩陣是表示某斜下方向是否已有擺放皇后，right_up矩陣式表示某斜上方向是否已有擺放皇后，<br>
right矩陣表示某列上是否已有矩陣。<br>

![index_explain](https://github.com/rox38431/MyUVa/blob/master/volume001/167%20-%20The%20Sultan's%20Successors%20(Eight%20queens%20puzzle)/queen.PNG)
