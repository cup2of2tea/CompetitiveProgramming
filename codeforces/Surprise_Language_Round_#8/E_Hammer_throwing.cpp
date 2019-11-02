import com.sun.xml.internal.fastinfoset.util.StringArray
 
fun main(args: Array<String>) {
    var n = readLine()!!.split(' ').get(0).toInt()
    var arr = readLine()!!.split(' ').map(String::toInt);
    var res = arrayOfNulls<Int>(n)
    for(i in 0..n-1){
        var bla = arr.get(i)
        var j = 0;
        while(bla > 0 || res[j] != null) {
            if(res[j] == null) bla = bla - 1;
            j++;
        }
        res[j] = i+1;
    }
    for(ele in res) {
        print(ele)
        print(" ")
    }
}