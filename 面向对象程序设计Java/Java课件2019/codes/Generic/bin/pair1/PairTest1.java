package pair1;

/**
 * @version 1.01 2012-01-26
 * @author Cay Horstmann
 */

//compareTo()的返回值是整型,它是先比较对应字符的大小(ASCII码顺序),
//如果第一个字符和参数的第一个字符不等,结束比较,返回他们之间的差值,
//如果第一个字符和参数的第一个字符相等,则以第二个字符和参数的第二个字
//符做比较,以此类推,直至比较的字符或被比较的字符有一方全比较完,这时就
//比较字符的长度. 
//
//
//例: 
//String s1 = "abc"; 
//String s2 = "abcd"; 
//String s3 = "abcdfg"; 
//String s4 = "1bcdfg"; 
//String s5 = "cdfg"; 
//System.out.println( s1.compareTo(s2) ); // -1 (前面相等,s1长度小1) 
//System.out.println( s1.compareTo(s3) ); // -3 (前面相等,s1长度小3) 
//System.out.println( s1.compareTo(s4) ); // 48 ("a"的ASCII码是97,"1"的的ASCII码是49,所以返回48) 
//System.out.println( s1.compareTo(s5) ); // -2 ("a"的ASCII码是97,"c"的ASCII码是99,所以返回-2)
public class PairTest1
{
   public static void main(String[] args)
   {
      String[] words = { "Mary", "had", "a", "little", "lamb" };
      Pair<String> mm = ArrayAlg.minmax(words);
      System.out.println("min = " + mm.getFirst());
      System.out.println("max = " + mm.getSecond());
//      System.out.println("Mary".compareTo("little"));
   }
}

class ArrayAlg
{
   /**
    * Gets the minimum and maximum of an array of strings.
    * @param a an array of strings
    * @return a pair with the min and max value, or null if a is null or empty
    */
   public static Pair<String> minmax(String[] a)
   {
      if (a == null || a.length == 0) return null;
      String min = a[0];
      String max = a[0];
      for (int i = 1; i < a.length; i++)
      {
         if (min.compareTo(a[i]) > 0) min = a[i];
         if (max.compareTo(a[i]) < 0) max = a[i];
      }
      return new Pair<>(min, max);
   }
}
