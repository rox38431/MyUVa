# IDEA:

**[使用 Dynamic Programming 的概念，第 1500 大的 ugly number，必為第 1 ~ 1499 中某個 ugly number 乘上 2 or 3 or 5 而得。]**

另矩陣 ugly 儲存 ugly numbers，ugly[A] 表示第 A 大之 ugly number。

欲求第 n 大之 ugly number，即ugly[n]，先求出 min_2, min_3, min_5

其中，
min_2 = min{ugly[1] * 2, ugly[2] * 2, ..., ugly[n-1] * 2}
min_3 = min{ugly[1] * 3, ugly[2] * 3, ..., ugly[n-1] * 3}
min_5 = min{ugly[1] * 5, ugly[2] * 5, ..., ugly[n-1] * 5}

，則ugly[n] = min{ min_2, min_3, min_5}
