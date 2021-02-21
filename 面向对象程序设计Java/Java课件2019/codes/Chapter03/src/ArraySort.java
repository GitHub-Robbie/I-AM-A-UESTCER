import java.util.*;

/**
 * This program demonstrates array manipulation.
 */
public class ArraySort
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      
      System.out.print("How many elements in the array? ");
      int n = in.nextInt();
      
      System.out.print("The biggest number in the array? ");
      int b = in.nextInt();
//      String sss = in.nextLine();
      
      int[] array = new int[n];

      for (int i = 0; i < array.length; i++)
      {
         // make a random index between 0 and m - 1
         int r = (int) (Math.random() * b);

         array[i] = r;
      }

      System.out.println("Before sorting the result: ");
//      for (int e : array)
//          System.out.println(e);
      
      System.out.println(Arrays.toString(array));
      
      // print the sorted array
      Arrays.sort(array);
      System.out.println("After sorting the result: ");
//      for (int e : array)
//         System.out.println(e);
      
      System.out.println(Arrays.toString(array));
      
      in.close();
   }
}
