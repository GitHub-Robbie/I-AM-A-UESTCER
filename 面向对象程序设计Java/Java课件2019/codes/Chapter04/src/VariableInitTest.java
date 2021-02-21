class VariableInit {
	int x = 10;
	int y = 20;
	
	int m, n;

	public VariableInit(int a, int b) {
		x = a;
		y = b;
	}
	
	{
		m = 10; n = 20;
	}
}

public class VariableInitTest {
	public static void main(String[] args) {
		VariableInit vi = new VariableInit(100, 200);
		System.out.println("The object vi's value is (" + vi.x + ", " + vi.y + ")");
		System.out.println("The object vi's value is (" + vi.m + ", " + vi.n + ")");
	}
}
