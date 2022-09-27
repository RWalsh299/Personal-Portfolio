import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

import org.junit.*;

public class BSTTest {
	
	/* TODO: Add your own tests */
	@Test
	public void basicPutContainsTest() {
		BST tree = new BST();
		tree.put(5, 100);
		tree.put(10, 200);
		tree.put(2, 50);
		assertEquals(true, tree.containsKey(2));
		assertEquals(true, tree.containsKey(10));
		assertEquals(true, tree.containsKey(5));
	}
	@Test
	public void PutContainsTest() {
		BST tree = new BST();
		tree.put(5, 100);
		tree.put(10, 200);
		tree.put(2, 50);
		tree.put(3, 100);
		tree.put(15, 200);
		tree.put(1, 50);
		assertEquals(true, tree.containsKey(2));
		assertEquals(true, tree.containsKey(10));
		assertEquals(true, tree.containsKey(5));
		assertEquals(true, tree.containsKey(3));
		assertEquals(true, tree.containsKey(1));
		assertEquals(false, tree.containsKey(20));
		assertEquals(false, tree.containsKey(4));
		assertEquals(false, tree.containsKey(25));
	}
	@Test
	public void basicSetGetTest() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		assertEquals(50, tree.get(2));
		assertEquals(200, tree.get(10));
		assertEquals(100, tree.get(5));
	}
	@Test
	public void SetGetTest() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		tree.set(5, 150);
		tree.set(10, 250);
		tree.set(5, 20);
		assertEquals(20, tree.get(5));
		assertEquals(250, tree.get(10));
		assertEquals(50, tree.get(2));
	}
	@Test
	public void basicReturnKeysSizeTest() {
		BST tree = new BST();
		tree.put(5, 100);
		tree.put(10, 200);
		tree.put(2, 50);
		List<Integer> ans = new ArrayList<Integer>(tree.size);
		ans.add(2);
		ans.add(5);
		ans.add(10);
		List<Integer> castAns = new ArrayList<Integer>(tree.size);
		castAns = tree.keys();
		assertEquals(ans, castAns);
	}
	@Test
	public void ReturnKeysSizeTest() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		tree.set(1, 50);
		tree.set(4, 50);
		tree.set(15, 50);
		tree.remove(1);
		tree.remove(15);
		List<Integer> ans = new ArrayList<Integer>(tree.size);
		ans.add(2);
		ans.add(4);
		ans.add(5);
		ans.add(10);
		List<Integer> castAns = new ArrayList<Integer>(tree.size);
		
		castAns = tree.keys();
		assertEquals(ans, castAns);
	}
	@Test
	public void basicReplaceIsEmptyTest() {
		BST emptytree = new BST();
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		assertEquals(true, emptytree.isEmpty());
		assertEquals(false, tree.isEmpty());
	}
	@Test
	public void ReplaceIsEmptyTest() {
		BST emptytree = new BST();
		BST tree = new BST();
		emptytree.set(5, 100);
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		emptytree.remove(5);
		assertEquals(true, emptytree.isEmpty());
		assertEquals(false, tree.isEmpty());
		
		tree.replace(5, 500);
		tree.replace(10, 250);
		assertEquals(500, tree.get(5));
		assertEquals(250, tree.get(10));
	}
	@Test
	public void basicRemoveTest() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);

		assertEquals(true, tree.remove(2));
		assertEquals(true, tree.remove(10));
		assertEquals(true, tree.remove(5));
	}
	@Test
	public void RemoveTest() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(2, 50);

		assertEquals(true, tree.remove(2));
		//System.out.print(tree.keys());
		assertEquals(false, tree.remove(10));
		
		BST tree2 = new BST();
		tree2.set(5, 100);
		tree2.set(10, 50);
		tree2.set(15, 50);

		assertEquals(true, tree2.remove(15));
		//System.out.print(tree2.keys());
		assertEquals(true, tree2.remove(10));
		//System.out.print(tree2.keys());
		assertEquals(false, tree2.remove(2));
		
		BST tree3 = new BST();
		tree3.set(5, 100);
		tree3.set(4, 50);
		tree3.set(3, 50);

		assertEquals(true, tree3.remove(3));
		//System.out.print(tree3.keys());
		assertEquals(true, tree3.remove(4));
		//System.out.print(tree3.keys());
		assertEquals(false, tree3.remove(2));
	}
	@Test
	public void Test() {
		BST tree = new BST();
		tree.set(5, 100);
		tree.set(10, 200);
		tree.set(2, 50);
		tree.set(1, 50);
		assertEquals(true, tree.containsKey(2));
		assertEquals(true, tree.containsKey(10));
		assertEquals(true, tree.containsKey(5));
		assertEquals(true, tree.containsKey(1));
	}
	@Test
	public void removeDeepLeafNodeTest() {
		BST tree = new BST();
		tree.set(10, 100);
		tree.set(7, 200);
		tree.set(15, 200);
		tree.set(4, 200);
		tree.set(8, 200);
		
		assertEquals(true, tree.remove(7));
		System.out.print(tree.keys());
	}
	@Test
	public void removeonlyLeftLeafNodeTest() {
		BST tree = new BST();
		tree.set(10, 100);
		tree.set(7, 200);
		tree.set(4, 200);
		tree.set(8, 200);
		
		assertEquals(true, tree.remove(7));
		System.out.print(tree.keys());
	}
	@Test
	public void removeOneLeftLeafNodeTest() {
		BST tree = new BST();
		tree.set(10, 100);
		tree.set(4, 200);
		
		assertEquals(true, tree.remove(4));
		System.out.print(tree.keys());
	}
	@Test
	public void removeOneRightLeafNodeTest() {
		BST tree = new BST();
		tree.set(10, 100);
		tree.set(15, 200);
		
		assertEquals(true, tree.remove(15));
		System.out.print(tree.keys());
	}
	@Test
	public void removeLeftOnlySubLeafNodeTest() {
		BST tree = new BST();
		tree.set(10, 100);
		tree.set(8, 200);
		tree.set(6, 50);
		
		assertEquals(true, tree.remove(8));
		System.out.print(tree.keys());
	}
}