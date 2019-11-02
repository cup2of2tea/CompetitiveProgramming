import com.sun.xml.internal.fastinfoset.util.StringArray
 
fun main(args: Array<String>) {
    var s = readLine()
    s = s!!.trim();
    var prec = "rien";
 
    for(i in 0..s.length-1) {
        if(s.get(i) == ' ') {
            if(prec!="spaceDot" && prec!="comma" && prec != "rien" && prec!="space" && (i == s.length-1 || s.get(i+1).isLetter() )){
                print(" ");
                prec = "space";
            }
 
        } else if(s.get(i) >= 'a' && s.get(i) <= 'z') {
            if(prec == "spaceDot" || prec =="rien") {
                print(s.get(i).toUpperCase())
            } else {
                print(s.get(i))
            }
            prec = "char";
        } else if(s.get(i) >= 'A' && s.get(i) <= 'Z') {
            if(prec == "spaceDot" || prec == "rien") {
                print(s.get(i))
            } else {
                print(s.get(i).toLowerCase())
            }
            prec = "char";
        } else if(s.get(i) == '.') {
            print(".");
            if(i != s.length-1){
                print(" ");
            }
            prec = "spaceDot";
        } else if(s.get(i) == ',') {
            print(",");
            if(i != s.length-1){
                print(" ");
            }
            prec = "comma";
        }
    }
}