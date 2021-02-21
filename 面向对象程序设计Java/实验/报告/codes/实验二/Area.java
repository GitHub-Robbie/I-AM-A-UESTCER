//yuanhaonan
package pkg;

public class Area {
	public static void main(String[] args) {
		Triangle1 tri = new Triangle1(5, 2);
		Rectangle rec = new Rectangle(5, 2);
		System.out.println("Triangle Area = " + tri.coutArea(tri.getBase(), tri.getHeight()));
		System.out.println("Rectangle Area = " + rec.coutArea(rec.getBase(), rec.getHeight()));
	}
}

class Triangle1 {
	public int base;
	public int height;
	public float area;

	public int getBase() {
		return this.base;
	}

	public int getHeight() {
		return this.height;
	}

	public Triangle1(int base, int height) {
		this.base = base;
		this.height = height;
	}

	public float coutArea(int base, int height) {
		return (float) (base * height * 0.5);
	}
}

class Rectangle {
	public int base;
	public int height;
	public float area;

	public int getBase() {
		return this.base;
	}

	public int getHeight() {
		return this.height;
	}

	public Rectangle(int base, int height) {
		this.base = base;
		this.height = height;
	}

	public float coutArea(int base, int height) {
		return (float) (base * height);
	}
}