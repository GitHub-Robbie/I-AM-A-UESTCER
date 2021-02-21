package lambda;

import java.util.Arrays;
import java.util.List;

public class LambdaTest3 {
	public static void main(String[] args) {
		// Prior Java 8 :
		List features1 = Arrays.asList("Lambdas", "Default Method", "Stream API", "Date and Time API");
//		for (String feature : features1) {
//			System.out.println(feature);
//		}

		// In Java 8:
		List features2 = Arrays.asList("Lambdas", "Default Method", "Stream API", "Date and Time API");
		features2.forEach(n -> System.out.println(n));

		// Even better use Method reference feature of Java 8
		// method reference is denoted by :: (double colon) operator
		// looks similar to score resolution operator of C++
		features2.forEach(System.out::println);
	}
}
