//yuanhaonan
package pkg;

public class Point {
	private int x;
	private int y;

	public void setX(int x) {
		this.x = x;
	}

	public void setY(int y) {
		this.y = y;
	}

	public Point() { // constructor
		this.x = 0;
		this.y = 0;
	}

	public Point getPoint() {
		return this;
	}

	public void movePoint(int x, int y) {
		this.x = x;
		this.y = y;
	}

	public String toString() {
		return "[X=" + x + ", Y=" + y + "]";
	}

	public static void main(String[] args) {
		Point point = new Point();
		System.out.println(point);
		point.movePoint(10, 20);
		System.out.println(point);
	}
}
