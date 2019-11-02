import com.sun.xml.internal.fastinfoset.util.StringArray
 
fun main(args: Array<String>) {
    var arr = readLine()!!.split(' ').map(String::toInt);
    var arr2 = readLine()!!.split(' ').map(String::toInt);
    arr = arr.takeLast(arr.size-1)
    arr2 = arr2.takeLast(arr2.size-1)
    val map = hashMapOf<Int,Boolean>();
    val map2 = hashMapOf<Int,Boolean>();
    for(ele in arr)
        map.put(ele,true)
    for(ele in arr2)
        map2.put(ele,true)
 
    var res = emptyArray<Int>()
 
    for(i in -1000..1000)
        if(map[i] != map2[i])
            res = res.plus(i)
 
    print(res.size)
    print(" ")
    for(ele in res){
        print(ele)
        print(" ")}
 
 
}