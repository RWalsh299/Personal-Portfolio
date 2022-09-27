import java.util.*;

/*
 * Class to implement SearchWorklist as a Stack and a Queue.
 * You can use any built-in Java collections for this class.
 */

class StackWorklist implements SearchWorklist {
	
	Stack<Square> workStack;
	StackWorklist(){
		workStack = new Stack<>();
	}
	
	@Override 
	public void add(Square c) {
		workStack.push(c);
	}

	@Override
	public Square remove() {
		return workStack.pop();
	}

	@Override
	public boolean isEmpty() {
		return workStack.isEmpty();
	}
	
}

class QueueWorklist implements SearchWorklist {
	
	Queue<Square> workQueue;
	QueueWorklist(){
		workQueue = new LinkedList<>();
	}
	
	@Override 
	public void add(Square c) {
		workQueue.add(c);
	}

	@Override
	public Square remove() {
		return workQueue.remove();
	}

	@Override
	public boolean isEmpty() {
		return workQueue.isEmpty();
	}
}

public interface SearchWorklist {
	void add(Square c);
	Square remove();
	boolean isEmpty();
}
