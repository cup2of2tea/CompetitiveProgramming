import java.util.*
 
fun main() {
    val sc = Scanner(System.`in`)
	
	val trash = sc.nextInt()
	
	val s = sc.next()
	var twoGrams: MutableMap<String, Int> = mutableMapOf()
 
    var best = 0
    var res = ""
 
	for (i in 1..(s.length-1)) {
	    var sub = s.subSequence(i-1,i+1).toString()
	    var z = twoGrams.getOrDefault(sub,0)
	    twoGrams.put(sub,z+1)
	    if(z+1 > best) {
	        best = z + 1;
	        res = sub;
	    }
	}
	println(res)
}