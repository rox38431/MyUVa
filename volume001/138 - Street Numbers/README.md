# IDEA 

假設目前　programmer　住在號碼為　x　的房子，且最後一間房子的號碼為　y　<br>，
則　　sum(1,...,x-1)　=　sum(x+1,...,y)
　=>　(x*(x-1))/2　=　((y+x+1)*y-x)/2
　=>　x^2-x　=　xy-x^2+y-x+y^2-xy
　=>　2x^2　=　y^2+y
　=>　y^2+y-2x^2　=　0
　=>　y = (-1+sqrt(1+8x^2))/2　　(or x　=　sqrt((y^2+y)/2))