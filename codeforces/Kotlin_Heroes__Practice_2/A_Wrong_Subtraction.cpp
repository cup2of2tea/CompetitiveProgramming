import java.util.*
 
fun main() {
    val sc = Scanner(System.`in`)
	
	var v = sc.nextInt()
	val it = sc.nextInt()
	
	for (i in 1..it) {
		if(v % 10 == 0) {
			v /= 10
		} else {
			v -= 1
		}
	}
	println(v)
}