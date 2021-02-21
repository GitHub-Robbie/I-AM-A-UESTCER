import java.util.ArrayList;

public class AutoBoxing {
	public static void main(String[] args){
		ArrayList<Integer> al = new ArrayList<>();
		al.add(3);//autoboxing
		al.add(Integer.valueOf(4));
		
		int n1 = al.get(0);//unboxing
		int n2 = al.get(1).intValue();
		
		System.out.println("n1: " + n1 + ", n2: " + n2);
	}
}
