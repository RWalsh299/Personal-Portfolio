import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * @param <K> The type of the keys of this BST. They need to be comparable by nature of the BST
 * "K extends Comparable" means that BST will only compile with classes that implement Comparable
 * interface. This is because our BST sorts entries by key. Therefore keys must be comparable.
 * @param <V> The type of the values of this BST. 
 */
public class BST<K extends Comparable<? super K>, V> implements DefaultMap<K, V> {
	int size = 0;
	Node<K,V> root;
	
	public BST() {
		this.root = null;
		this.size = 0;
	}
	
	public BST(Node<K,V> root) {
		this.root = root;
		this.size += 1;
	}

	@Override
	public boolean put(K key, V value) throws IllegalArgumentException {
		Node<K,V> newNode = new Node<K, V>(key, value, null, null);
		if (newNode.key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		if (this.root == null) {
			this.root = newNode;
			this.size += 1;
			return true;
		}else{
			Node<K,V> pointer = root;
			Node<K,V> parent;
			while(true) {
				parent = pointer;
				if(parent.getKey().compareTo(key) == 0) {return false;}
				if(parent.getKey().compareTo(key) > 0) {
					pointer = pointer.left;
					if(pointer == null) {
						parent.left = newNode;
						this.size += 1;
						return true;
					}
					if(pointer.getKey().compareTo(key) == 0) {
						return false;
					}
				}else {
					if (parent.getKey().compareTo(key) < 0) {
						pointer = pointer.right;
						if(pointer == null) {
							parent.right = newNode;
							this.size += 1;
							return true;
						}
						if(pointer.getKey().compareTo(key) == 0) {
							return false;
						}
					}
				}
			}	
		}
	}

	@Override
	public boolean replace(K key, V newValue) throws IllegalArgumentException {
		Node pointer = this.root;
		Node parent;
		if(key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		//if(newValue == null) {return true;}
		if(this.root.key == key) {
			this.root.setValue(newValue);
			return true;
		}
		while(pointer.left != null && pointer.right != null){
			parent = pointer;
			if(parent.getKey().compareTo(key) > 0) {
				pointer = pointer.left;
				if(pointer.getKey().compareTo(key) == 0) {
					pointer.setValue(newValue);
					return true;
				}
			}else {
				if(parent.getKey().compareTo(key) < 0) {
					pointer = pointer.right;
					if(pointer.getKey().compareTo(key) == 0) {
						pointer.setValue(newValue);
						return true;
					}
				}
			}
		}
		return false;
	}
	//need to check for children then move right child up
	@Override
	public boolean remove(K key) throws IllegalArgumentException {
		Node pointer = this.root;
		Node parent = pointer;
		if(key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		while(true){
			parent = pointer;
			if(this.root.key == key) {
				if(this.root.left == null && this.root.right == null){
					this.root = null;
					this.size -= 1;
					return true;
				}
				if(this.root.right != null) {
					this.root = this.root.right;
					this.size -= 1;
					return true;
				}
				if (this.root.left != null) {
					this.root = this.root.left;
					this.size -= 1;
					return true;
				}
			}
			if(parent.getKey().compareTo(key) > 0) {
				pointer = pointer.left;
				if(pointer == null) {return false;}
				if(pointer.getKey().compareTo(key) == 0) {
					if(pointer.right != null) {
						parent.left = pointer.right;
					}
					if(pointer.left != null && pointer.right == null) {
						parent.left = pointer.left;
					}else if(pointer.left != null) {
						parent.left.left = pointer.left;
					}
					if(pointer.left == null && pointer.right == null) {
						parent.left = null;
					}
					this.size -= 1;
					return true;
				}
			}else{
				if(parent.getKey().compareTo(key) < 0) {
					pointer = pointer.right;
					if(pointer == null) {return false;}
					if(pointer.getKey().compareTo(key) == 0) {
						if(pointer.right != null) {
							parent.left = pointer.right;
						}
						if(pointer.left != null && pointer.right == null) {
							parent.left = pointer.left;
						}else if(pointer.left != null) {
							parent.left.left = pointer.left;
						}
						if(pointer.left == null && pointer.right == null) {
							parent.right = null;
						}
						this.size -= 1;
						return true;
					}
					
				}
			}
			
		}
	}

	@Override
	public void set(K key, V value) throws IllegalArgumentException {
		Node<K,V> newNode = new Node<K, V>(key, value, null, null);
		if (newNode.key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		if (this.root == null) {
			this.root = newNode;
			this.size += 1;
			return;
		}else{
			Node<K,V> pointer = root;
			Node<K,V> parent;
			while(true) {
				parent = pointer;
				if(parent.getKey().compareTo(key) == 0) {
					parent.setValue(value);
					return;
				}
				if(parent.getKey().compareTo(key) > 0) {
					pointer = pointer.left;
					if(pointer == null) {
						parent.left = newNode;
						this.size += 1;
						return;
					}
					if(pointer.getKey().compareTo(key) == 0) {
						pointer.setValue(value);
						return;
					}
				}else {
					if (parent.getKey().compareTo(key) < 0) {
						pointer = pointer.right;
						if(pointer == null) {
							parent.right = newNode;
							this.size += 1;
							return;
						}
						if(pointer.getKey().compareTo(key) == 0) {
							pointer.setValue(value);
							return;
						}
					}
				}
			}	
		}
		
	}

	@Override
	public V get(K key) throws IllegalArgumentException {
		Node pointer = this.root;
		Node parent;
		if(key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		if(this.root == null) {return null;}
		if(this.root.key == key) {return this.root.val;}
		while(pointer.right != null && pointer.left != null){
			parent = pointer;
			if(parent.getKey().compareTo(key) > 0) {
				pointer = pointer.left;
				if(pointer.getKey().compareTo(key) == 0) {
					return (V) pointer.getValue();
				}
			}else{
				if(parent.getKey().compareTo(key) < 0) {
					pointer = pointer.right;
					if(pointer.getKey().compareTo(key) == 0) {
						return (V) pointer.getValue();
					}
					
				}
			}
		}
		return null;
	}

	@Override
	public int size() {
		return this.size;
	}

	@Override
	public boolean isEmpty() {
		if (this.root == null || this.size() == 0) {
			return true;
		}else {return false;}
	}

	@Override
	public boolean containsKey(K key) throws IllegalArgumentException {
		Node pointer = this.root;
		Node parent;
		if(key == null) {throw new IllegalArgumentException("KEY IS NULL");}
		//if(this.root == null && root.left == null && root.right == null) {return false;}
		if(this.root.getKey().compareTo(key) == 0) {return true;}
		while(pointer.right != null || pointer.left != null){
			parent = pointer;
			if(parent.getKey().compareTo(key) > 0) {
				pointer = pointer.left;
				if(pointer.getKey().compareTo(key) == 0) {
					return true;
				}
			}else{
				if(parent.getKey().compareTo(key) < 0) {
					pointer = pointer.right;
					if(pointer.getKey().compareTo(key) == 0) {
						return true;
					}
				}
			}
		}return false;
	}

	// Keys must be in ascending sorted order
	// You CANNOT use Collections.sort() or any other sorting implementations
	// You must do inorder traversal of the tree
	@Override
	public List<K> keys() {
		// TODO Auto-generated method stub
		if(this.size == 0) { 
			List<K> emptyList = new ArrayList<K>();
			return  emptyList;
		}
		else {
			List<K> tempList = new ArrayList<K>(this.size);
			List<K> keyList = keys(this.root, tempList);
			return keyList;
		}
	}
	
	@SuppressWarnings("unchecked")
	public List<K> keys(Node pointer, List<K> keyList){
		if(pointer != null) {
			keys(pointer.left, keyList);
			keyList.add((K) pointer.key);
			keys(pointer.right, keyList);
		}
		return keyList;
	}
	
	private static class Node<K extends Comparable<? super K>, V> implements DefaultMap.Entry<K, V> {
		K key;
		V val;
		Node<K,V> left = null;
		Node<K,V> right = null;
		
		public Node(K key, V val, Node<K,V> left, Node<K,V> right) {
			this.key = key;
			this.val = val;
			this.left = left;
			this.right = right;
		}

		@Override
		public K getKey() {
			return this.key;
		}

		@Override
		public V getValue() {
			return this.val;
		}

		@Override
		public void setValue(V value) {
			this.val = value;
			
		}
		
		
	}
	 
}