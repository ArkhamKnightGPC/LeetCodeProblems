import scala.collection.mutable

object Solution {
    def isIsomorphic(s: String, t: String): Boolean = {
        val ns = s.length
        val nt = t.length
        if(ns != nt)return false

        val mapping = mutable.Map[Char, Char]()
        var taken = Set[Char]()

        var ret = true
        for(i <- 0 to ns-1){
            val cs = s(i)
            val mapped_cs = if(mapping.contains(cs)) mapping(cs) else null
            val ct = t(i)
            //3 fail cases
            if(mapped_cs != null){
                if(mapped_cs != ct){//case 1: cs already mapped and different
                    ret = false
                }
            }else{
                if(cs != ct){
                    if(!taken.contains(ct)){
                        mapping(cs) = ct
                        taken = taken + ct
                    }else{// case 2: cs not mapped, needs mapping but char is taken
                        ret = false
                    }
                }else{
                    if(taken.contains(cs))ret = false //case 3: cs needs to be mapped onto itself, already taken
                    mapping(cs) = cs
                    taken = taken + cs
                }
            }
        }
        return ret
    }
}