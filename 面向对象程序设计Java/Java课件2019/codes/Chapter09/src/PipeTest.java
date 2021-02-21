
/**
   PipeTest.java
*/
import java.io.*;
import java.util.Random;


class RunningAverage extends Thread {
	private DataInputStream in;
	double total = 0;
	long count = 0;

	public RunningAverage(InputStream i) {
		in = new DataInputStream(i);
	}

	public void run() {
		while (true) {
			try {
				double num = in.readDouble();
				total += num;
				count++;
				System.out.println(count + ": " + num + "\t avg = " + total / count);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}

class NumberGenerator extends Thread {
	private DataOutputStream out;
	private Random gen = new Random();
	private final long RANGE = 1000;

	public NumberGenerator(OutputStream o) {
		out = new DataOutputStream(o);
	}

	public void run() {
		while (true) {
			try {
				double num = gen.nextDouble() * RANGE;
				out.writeDouble(num);
				out.flush();
				sleep(1000);
			} catch (IOException e) {
				e.printStackTrace();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}

public class PipeTest {
	public static void main(String[] args) {
		try {
//			PipedOutputStream producer =  new PipedOutputStream(); 
//			PipedInputStream consumer = new PipedInputStream(producer); 
			
			// or
//			PipedInputStream consumer = new PipedInputStream(); 
//			PipedOutputStream producer =  new PipedOutputStream(consumer); 
			
			//or
			PipedInputStream consumer = new PipedInputStream(); 
			PipedOutputStream producer =  new PipedOutputStream(); 
			consumer.connect(producer);
			
			//or
//			PipedInputStream consumer = new PipedInputStream(); 
//			PipedOutputStream producer =  new PipedOutputStream(); 
//			producer.connect(consumer);

			RunningAverage avg = new RunningAverage(consumer);
			NumberGenerator gen = new NumberGenerator(producer);
			gen.start();
			avg.start();
			try {
				Thread.sleep(5000);
			} catch (InterruptedException e) {
			}
			gen.stop();
			avg.stop();
			producer.close();
			consumer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
