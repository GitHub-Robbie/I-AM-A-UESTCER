
public class VarArgs {

	public static int sum(boolean b, int... args){
		int s = 0;
		for(int i : args)
			s+=i;
		return s;
	}
	public static void main(String... args) {
		System.out.println(sum(true));
		System.out.println(sum(true,1));
		System.out.println(sum(false, 1, 2));
		System.out.println(sum(true, 1, 2, 3));
	}

}
