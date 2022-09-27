import java.util.ArrayList;

/*
 * Write your JUnit tests here
 * Use the formatMaze() method to get nicer JUnit output
 */

import org.junit.Test;
import static org.junit.Assert.*;

public class TestSolvers {

	/* Helper method to compare two mazes */
	public void checkMaze(SearchWorklist wl, Maze startMaze, String[] expected) {
		Square s = MazeSolver.solve(startMaze, wl);
		if(expected == null) { assertNull(s); }
		else {
			ArrayList<Square> sp = startMaze.storePath();
			String actualStr = formatMaze(startMaze.showSolution(sp));
			String expectedStr = formatMaze(expected);
			assertEquals(expectedStr, actualStr);
		}
	}	

	/* Helper method to format String[] output as String */
	public String formatMaze(String[] arr) {
		String result = "";
		for (String s: arr)
			result += "\n"+s;
		return (result+"\n");
	}

	/* Add your own Worklist tests below */

	/* ************** HINT ******************** 
	 * Use the helper methods to create simple
	 * tests that are easier to debug. 
	 */

	@Test
	public void basicStackTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "__F_",
	            "S##_",
	            "____"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
	            "#___",
	            "__F*",
	            "S##*",
	            "****"};
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void basicQueueTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "__F_",
	            "S##_",
	            "____"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = { 
	            "#___",
	            "**F_",
	            "S##_",
	            "____"};
		checkMaze(qWL ,m ,queueAns);
	}
	
	@Test
	public void stackDeadEndTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "__F_",
	            "S##_",
	            "___#"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
	            "#___",
	            "**F_",
	            "S##_",
	            "___#"};
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void queueDeadEndTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "_#F_",
	            "S##_",
	            "____"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = { 
	            "#___",
	            "_#F*",
	            "S##*",
	            "****"};
		checkMaze(qWL ,m ,queueAns);
	}
	
	@Test
	public void stackNoPathTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "_#F_",
	            "S##_",
	            "___#"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = null;
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void queueNoPathTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "_#F_",
	            "S##_",
	            "___#"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = null;
		checkMaze(qWL,m ,queueAns);
	}
	
	@Test
	public void oneStepStackTest() {
		Maze m = new Maze(new String[] {
				"#___",
	            "____",
	            "_SF_",
	            "____"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
				"#___",
	            "____",
	            "*SF*",
	            "****"};
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void oneStepQueueTest() {
		Maze m = new Maze(new String[] {
				"#___",
	            "____",
	            "_SF_",
	            "____"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = { 
				"#___",
	            "_*__",
	            "_SF_",
	            "_*__"};
		checkMaze(qWL ,m ,queueAns);
	}
	
	@Test
	public void noWallStackTest() {
		Maze m = new Maze(new String[] {
	            "___F",
	            "____",
	            "S___",
	            "____"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
				"___F",
	            "___*",
	            "S***",
	            "____"};
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void noWallQueueTest() {
		Maze m = new Maze(new String[] {
	            "___F",
	            "____",
	            "S___",
	            "____"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = { 
				"***F",
	            "*___",
	            "S___",
	            "____"};
		checkMaze(qWL,m ,queueAns);
	}
	
	@Test
	public void manyWallStackTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "F_#_",
	            "###_",
	            "S___"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
				"#***",
	            "F*#*",
	            "###*",
	            "S***"};
		checkMaze(sWL,m ,stackAns);
	}
	
	@Test
	public void manyWallQueueTest() {
		Maze m = new Maze(new String[] {
	            "#___",
	            "F_#_",
	            "###_",
	            "S___"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] queueAns = { 
				"#***",
	            "F*#*",
	            "###*",
	            "S***"};
		checkMaze(qWL,m ,queueAns);
	}
	
	@Test
	public void CornersStackTest() {
		Maze m = new Maze(new String[] {
	            "F__#",
	            "_#__",
	            "__#_",
	            "#__S"
	        });
		StackWorklist sWL = new StackWorklist();
		String[] stackAns = { 
				"F__#",
	            "*#__",
	            "**#_",
	            "#**S"};
		checkMaze(sWL,m ,stackAns);
		
		Maze m2 = new Maze(new String[] {
	            "___F",
	            "_#__",
	            "__#_",
	            "S__#"
	        });
		StackWorklist sWL2 = new StackWorklist();
		String[] stackAns2 = { 
				"***F",
	            "*#__",
	            "*_#_",
	            "S__#"};
		checkMaze(sWL2,m2 ,stackAns2);
		
		Maze m3 = new Maze(new String[] {
	            "___S",
	            "_#__",
	            "__#_",
	            "F__#"
	        });
		StackWorklist sWL3 = new StackWorklist();
		String[] stackAns3 = { 
				"***S",
	            "*#__",
	            "*_#_",
	            "F__#"};
		checkMaze(sWL3,m3 ,stackAns3);
		
		Maze m4 = new Maze(new String[] {
	            "S__#",
	            "_#__",
	            "__#_",
	            "#__F"
	        });
		StackWorklist sWL4 = new StackWorklist();
		String[] stackAns4 = { 
				"S**#",
	            "_#**",
	            "__#*",
	            "#__F"};
		checkMaze(sWL4,m4 ,stackAns4);
	}
	
	@Test
	public void CornersQueueTest() {
		Maze m = new Maze(new String[] {
	            "F__#",
	            "_#__",
	            "__#_",
	            "#__S"
	        });
		QueueWorklist qWL = new QueueWorklist();
		String[] QueueAns = { 
				"F**#",
	            "_#**",
	            "__#*",
	            "#__S"};
		checkMaze(qWL,m ,QueueAns);
		
		Maze m2 = new Maze(new String[] {
	            "___F",
	            "_#__",
	            "__#_",
	            "S__#"
	        });
		
		QueueWorklist qWL2 = new QueueWorklist();
		String[] QueueAns2 = { 
				"***F",
	            "*#__",
	            "*_#_",
	            "S__#"};
		checkMaze(qWL2,m2 ,QueueAns2);
		
		Maze m3 = new Maze(new String[] {
	            "___S",
	            "_#__",
	            "__#_",
	            "F__#"
	        });
		QueueWorklist qWL3 = new QueueWorklist();
		String[] QueueAns3 = { 
				"***S",
	            "*#__",
	            "*_#_",
	            "F__#"};
		checkMaze(qWL3,m3 ,QueueAns3);
		
		Maze m4 = new Maze(new String[] {
	            "S__#",
	            "_#__",
	            "__#_",
	            "#__F"
	        });
		QueueWorklist qWL4 = new QueueWorklist();
		String[] QueueAns4 = { 
				"S__#",
	            "*#__",
	            "**#_",
	            "#**F"};
		checkMaze(qWL4,m4 ,QueueAns4);
	}
	
}



