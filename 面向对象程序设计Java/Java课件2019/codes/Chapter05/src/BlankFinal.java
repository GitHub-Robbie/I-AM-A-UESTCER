import java.util.Random;

//: BlankFinal.java
// "Blank" final data members
class Poppet {
	private int i;

	Poppet(int ii) {
		i = ii;
	}
}

class BlankFinal {
	final int i = 0; // Initialized final
	
	final int j; // Blank final
//	static final int j; // Blank final cannot be static!!!
	final Poppet p; // Blank final handle
	// Blank finals MUST be initialized
	// in the constructor:

	BlankFinal() {
		j = 1; // Initialize blank final
		p = new Poppet(1);
	}

	BlankFinal(int x) {
		j = x; // Initialize blank final
		p = new Poppet(x);
	}

	public static void main(String[] args) {
		BlankFinal bf1 = new BlankFinal();
		BlankFinal bf11 = new BlankFinal();
		BlankFinal bf2 = new BlankFinal(8);
		BlankFinal bf22 = new BlankFinal(8);
		System.out.println("bf1: " + bf1.j);
		System.out.println("bf11: " + bf11.j);
		System.out.println("bf2: " + bf2.j);
		System.out.println("bf22: " + bf22.j);
	}
} /// :~