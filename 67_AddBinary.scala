object Solution {

    object HalfAdder{
        def apply(a: Char, b: Char): (Char, Char) = {
            val s = if(a != b) '1' else '0'
            val cout = if (a == b & a == '1') '1' else '0'
            return (s, cout)
        }
    }

    object FullAdder{
        def apply(a: Char, b: Char, cin: Char): (Char, Char) = {
            val (s1, cout1) = HalfAdder(a, b)
            val (s2, cout2) = HalfAdder(s1, cin)
            val cout3 = if (cout1 == '1' | cout2 == '1') '1' else '0'
            return (s2, cout3)
        }
    }

    def addBinary(a: String, b: String): String = {
        val na = a.length
        val nb = b.length
        val n = math.max(na, nb)

        var ret: String = ""
        var cin = '0'
        for(i <- 0 to n-1) do {
            val ai = if(i < na) a(na-i-1) else '0'
            val bi = if(i < nb) b(nb-i-1) else '0'
            val (s, cout) = FullAdder(ai, bi, cin)
            ret = s.toString + ret
            cin = cout
        }
        if(cin == '1')ret = cin.toString + ret
        return ret
    }
}