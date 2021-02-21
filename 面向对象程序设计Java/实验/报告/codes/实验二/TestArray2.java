//yuanhaonan
package pkg;

import java.util.*;

class ArraySort {
	public int[] sim;
	void setOrder() {
		Arrays.sort(sim);
		System.out.println(Arrays.toString(sim));
	}
	public ArraySort(int n) {
		sim=new int[n];
		for (int i = 0; i < n; i++) {
			int e = (int) (Math.random() * 100);
			sim[i] = e;
		}
	}
}

public class TestArray2 {
	public static void main(String[] args) {
		ArraySort array =new ArraySort(10);
		array.setOrder();
	}
}
