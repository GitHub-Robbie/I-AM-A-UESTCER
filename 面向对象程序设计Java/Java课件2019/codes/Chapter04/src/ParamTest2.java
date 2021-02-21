class DAT {
	int x, y;

	static void setData(int a, int b) {
		a = 10;
		b = 20;
	}

	static void setRefer1(DAT p) {
		p.x = 10;
		p.y = 20;
	}

	void setRefer2(DAT p) {
		p = new DAT();
		p.x = 100;
		p.y = 200;
	}
}

public class ParamTest2 {
	
	public static void main(String[] args) {
		int a = 1, b = 2;
		DAT p = new DAT();

		DAT.setData(a, b);
		System.out.println(a + ":" + b);

		System.out.println(p.x + ":" + p.y);
		DAT.setRefer1(p);
		System.out.println(p.x + ":" + p.y);

		System.out.println(p.x + ":" + p.y);
		p.setRefer2(p);
		System.out.println(p.x + ":" + p.y);
	}
}
