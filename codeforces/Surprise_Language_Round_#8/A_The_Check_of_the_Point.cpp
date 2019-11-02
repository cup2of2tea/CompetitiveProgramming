fun main(args: Array<String>) {
    val (a, x, y) = readLine()!!.split(' ').map(String::toInt)
 
    println(if(x > 0 && y > 0 && x < a && y < a) 0 else if (((x == 0 || x == a) && y <= a && y >= 0) || ((y == 0 || y == a) && x <= a && x >= 0) ) 1 else 2)
}