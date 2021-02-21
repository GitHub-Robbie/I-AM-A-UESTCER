

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Vector;
import java.util.Stack;
import java.util.HashMap;
import java.util.Hashtable;
import java.util.HashSet;
import java.util.TreeSet;
import java.util.Queue;
import java.util.Iterator;
import java.util.PriorityQueue;
/**
 * @author Switch_vov
 * @date 2015.10.30
 * @email q547550831@outlook.com
 *
 */
public class Collection {


	public static void main(String args[]){

		//List结构常用的集合类

		//ArrayList --- 实现了List接口，ArrayList是容量大小可变的数组的实现
		ArrayList al = new ArrayList();
		//将元素添加到al集合中的尾部
		String str1 = "a";
		al.add(str1);
		String str2 = "b";
		al.add(str2);
		//将元素添加到al集合中的指定位置
		String str3 = "c";
		al.add(0, str3);
		//可以添加重复元素
		al.add(str1);
		al.add(str2);
		//按下标移除元素
		al.remove(0);
		//按元素移除集合中指定元素，PS：如果该元素在集合中不止一个，移除的元素是正序第一个匹配到的元素
		al.remove(str2);
		//遍历输出
		for(int i = 0; i < al.size(); i++){
			//按下标获取元素,PS:因为get()方法返回的是Object类型的数据，所以要强制类型转换
			String tmp = (String)al.get(i);
			System.out.print(tmp + " ");
		}
		System.out.println();
		//擦除集合中所有元素
		al.removeAll(al);



		//LinkedList --- 实现的接口比较多，用的较多的是它的双端队列的特性
		LinkedList ll = new LinkedList();
		//上述ArrayList所使用的方法LinkedList都能使用
		//除此之外，还有以下这些

		//将元素添加到集合的首部
		ll.addFirst(str1);
		//将元素添加到集合的尾部
		ll.addLast(str2);
		ll.addLast(str3);
		ll.addLast(str1);
		ll.addLast(str2);
		ll.addLast(str3);
		ll.addLast(str1);
		//移除集合首部元素
		ll.removeFirst();
		ll.remove();
		//移除集合尾部元素
		ll.removeLast();
		//移除与指定元素相同的，从首部到尾部之间第一个元素
		ll.removeFirstOccurrence(str1);
		//移除与指定元素相同的，从首部到尾部之间最后一个元素
		ll.removeLastOccurrence(str2);
		//获取首部元素
		ll.getFirst();
		//获取尾部元素
		ll.getLast();
		//移除所有元素
		ll.removeAll(ll);



		//Vector --- Vector可以实现可增长的对象数组,Vector的大小可以根据需要增大或缩小，以适应创建 Vector后进行添加或移除项的操作。
		Vector v = new Vector();
		//上述ArrayList所使用的方法Vector都能使用
		//除此之外，还有以下这些
		//添加一个组件到向量向量末尾
		v.addElement(str1);
		v.addElement(str2);
		//返回向量当前的大小
		v.capacity();
		//判断向量是否为空
		v.isEmpty();
		//获取首部组件
		v.firstElement();
		//获取尾部组件
		v.lastElement();
		//扩大该向量的大小
		v.ensureCapacity(5);
		//移除指定位置的组件
		v.removeElementAt(0);
		//移除正序第一个与指定组件相同的组件
		v.removeElement(str1);
		//移除所有组件,并将向量大小设置为0
		v.removeAllElements();



		//Stack --- Stack表示栈结构。继承至 Vector。
		//它提供了push和 pop操作，以及取堆栈顶点的 peek方法、测试栈是否为空的empty方法、在栈中查找项并确定到栈顶距离的search方法。
		Stack s = new Stack();
		//压栈方法
		s.push(str1);
		s.push(str2);
		s.push(str3);
		//取栈顶元素方法
		s.peek();
		//出栈方法
		s.pop();
		//测试堆栈是否为空的方法
		s.empty();
		//在栈中查找项并确定到栈顶距离的方法，PS：返回值以1为栈顶基数，-1为未找到
		System.out.println(s.search(str1));





		//Map结构常用的集合类
		//HashMap --- 此实现假定哈希函数将元素适当地分布在各桶之间，其取出和存入的时间复杂度非常低，为常数级别，PS：不同存在相同键
		HashMap hm = new HashMap();
		//放入键值对
		int num1 = 1;
		hm.put(num1, str1);
		//如果键以存在，则替换该键值对
		hm.put(num1, str2);
		int num2 = 2;
		hm.put(num2, str2);
		int num3 = 3;
		hm.put(num3, str3);
		//通过键获取相应值
		hm.get(num1);
		//通过键判断集合是否存在该键值对
		hm.containsKey(num1);
		//通过值判断集合是否存在该键值对
		hm.containsValue(str1);

		//利用迭代器遍历集合中的所有键值对
		//keySet()返回此映射中所包含的键的Set视图
		//iterator()返回在此 set中的元素上进行迭代的迭代器
		Iterator it = hm.keySet().iterator();
		//hasNext()如果仍有元素可以迭代，则返回 true。
		while(it.hasNext()){
			//取出key
			//next()返回迭代的下一个元素。
			//toString()返回String类型数据，PS：这里不能强制类型转换成String
			int key = Integer.parseInt(it.next().toString());
			//通过key获取value
			String tmp = (String)hm.get(key);
			//输出value
			System.out.print(tmp + " ");
		}
		System.out.println();



		//HashTable --- Hashtable具有同步性，线程安全
		//HashTable在用法上和HashMap基本相似
		Hashtable ht = new Hashtable();
		//放入空值会报错
		//ht.put(null, null);
		//测试此哈希表是否没有键映射到值。
		ht.isEmpty();





		//Set结构常用的集合类
		//HashSet --- 以HashMap为底层
		//HashSet中无get方法，只能通过迭代器获取键
		HashSet hs = new HashSet();
		//添加键到集合尾部
		hs.add(str1);
		hs.add(str2);
		hs.add(str3);
		//自动去掉重复元素,PS：其实也是像HashMap一样，用新键覆盖旧键
		hs.add(str1);
		//返回包含全部键的Object类型数组
		Object[] o = hs.toArray();
		for(int i = 0; i < o.length; i++){
			System.out.print(o[i] + " ");
		}
		System.out.println();



		//TreeSet --- 使用元素的自然顺序对元素进行排序，PS:自然顺序是升序,或者根据创建 set时提供的 Comparator进行排序，具体取决于使用的构造方法
		TreeSet ts = new TreeSet();
		//添加键到集合
		ts.add(str1);
		ts.add(str2);
		ts.add(str3);
		//迭代器遍历
		for(it = ts.iterator(); it.hasNext();){
			String tmp = it.next().toString();
			System.out.print(tmp + " ");
		}
		System.out.println();
		//返回此 set 中小于等于给定元素的最大元素；如果不存在这样的元素，则返回 null。
		ts.floor(str2);
		//返回此 set 中大于等于给定元素的最小元素；如果不存在这样的元素，则返回 null。
		ts.ceiling(str2);
		//返回此 set 中严格小于给定元素的最大元素；如果不存在这样的元素，则返回 null。
		ts.lower(str2);
		//返回此 set 中严格大于给定元素的最小元素；如果不存在这样的元素，则返回 null。
		ts.higher(str2);
		//获取并移除第一个（最低）元素；如果此 set为空，则返回 null。
		ts.pollFirst();
		//获取并移除最后一个（最高）元素；如果此 set为空，则返回 null。
		ts.pollLast();
	}
}
