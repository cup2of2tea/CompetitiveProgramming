import com.sun.xml.internal.fastinfoset.util.StringArray
 
fun main(args: Array<String>) {
    var n = readLine()!!.split(' ').get(0).toInt()
    for(i in 0..n-1){
        var arr = readLine()!!.split(' ').map(String::toInt);
        var res = false;
        for(c in 0..arr[0])
            for(c2 in 0..arr[1])
                if(c*c2 == arr[2]) {
                    res = true;
                    break;
                }
                else if(c*c2 > arr[2]){
                    break;
                }
 
 
        println(if(res)"Yes" else "No")
    }
}