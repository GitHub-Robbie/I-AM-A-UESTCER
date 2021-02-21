package clone;

public class CloneTest
{
   public static void main(String[] args)
   {
      try
      {
         Employee original = new Employee("John Q. Public", 50000);
         original.setHireDay(2000, 10, 10);
         
         Employee copy = original.clone();
         
         copy.raiseSalary(10);
         copy.setHireDay(2018, 12, 31);// 如果不深拷贝会影响原来的对象
         
         System.out.println("original=" + original);
         System.out.println("copy    =" + copy);
      }
      catch (CloneNotSupportedException e)
      {
         e.printStackTrace();
      }
      
      //数组克隆
      int[] a = {1, 2, 3, 4, 5};
      int[] b = a.clone();
      b[4] = 10;
      System.out.println("a[4]: " + a[4]);
      System.out.println("b[4]: " + b[4]);
   }
}