/**
 * TempConverFor.java
 */
class TempConverFor {
	public static void main(String args[]) {
		int fahr, cels;
		System.out.println("Celsius\tFahrenheit\n");
		for (cels = 0; cels <= 30; cels += 1) {
			fahr = cels * 9 / 5 + 32;
			System.out.println(cels + "\t" + fahr);
		}
	}
}
