package pack1;

public class Original2 {
	private int nPrivate = 1;
	int nDefault = 2;
	protected int nProtected = 3;
	protected static int nProtected_static = 9;
	public int nPublic = 4;

	void access() {
		System.out.println("** 在类中, 可以访问的成员: **");
		System.out.println("   Private member = " + nPrivate);
		System.out.println("   Default member = " + nDefault);
		System.out.println("   Protected member = " + nProtected);
		System.out.println("   Public member = " + nPublic);
	}
}
