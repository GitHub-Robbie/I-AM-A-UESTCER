//yuanhaonan
package pkg2;

public class PillarTest {
	public static void main(String[] args) {
		Pillar pillar1 = new Pillar(3, 3.5, 4.5, 3.3);
		Pillar pillar2 = new Pillar(4, 3.5, 4.5, 3.3);
		System.out.println("V-cuboid = " + pillar1.getV());
		System.out.println("V-triangular prism = " + pillar2.getV());
	}
}

class Pillar {
	int n;
	double a, b, h;

	public Pillar(int n, double a, double b, double h) {
		this.n = n;
		this.a = a;
		this.b = b;
		this.h = h;
	}

	public double getV() {
		if (n == 3) {
			Triangle tri = new Triangle(n, a, b);
			return h * tri.getArea();
		} else if (n == 4) {
			Rectangle rec = new Rectangle(n, a, b);
			return h * rec.getArea();
		}
		return 0;
	}
}