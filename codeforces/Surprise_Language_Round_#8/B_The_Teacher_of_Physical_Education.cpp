import com.sun.xml.internal.fastinfoset.util.StringArray
 
fun main(args: Array<String>) {
    val n = readLine()!!.split(' ').get(0).toInt();
    val map = hashMapOf<Int, Array<String> >()
    for(i in 0..n-1) {
        val arr = readLine()!!.split(' ');
 
        val lol = arr.get(1).toInt();
        map.put(lol, (if (map[lol] == null) emptyArray() else map[lol])!!.plus(arr.get(0)));
    }
    for(i in 0..1000)
        if(map[i] != null)
            for (j in map[i]!!)
                println(j)
 
 
}