
interface One{
   int MAX_INT = 100;
   void setData(int a, int b);
   int getMax();
}
class Int implements One{
   int x, y;
   public void setData(int a, int b){
      x = a;
      y = b;
   }
   public int getMax(){
      return x>y?x:y;
   }
}
public class TestInt{
   public static void main(String[] args){
      Int i = new Int();
      i.setData(10,50);
      System.out.println("Return max value = "+i.getMax());
   }
}
