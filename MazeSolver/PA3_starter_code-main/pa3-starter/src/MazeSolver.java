/* Class to implement a Maze solver */

public abstract class MazeSolver {
	
	public static Square solve(Maze maze, SearchWorklist wl) {
		wl.add(maze.start);
		maze.start.visit();
		while (!wl.isEmpty()) {
			Square curr = wl.remove();
			if (curr == maze.finish) {
				return curr;
			}	//the if statements check each neighbor in the order: North, South, East West
			if(curr.getRow() > 0 && !maze.contents[curr.getRow()-1][curr.getCol()].getIsWall() && maze.contents[curr.getRow()-1][curr.getCol()].isVisited() == false) {
					maze.contents[curr.getRow()-1][curr.getCol()].visit();
					maze.contents[curr.getRow()-1][curr.getCol()].setPrevious(curr);
					wl.add(maze.contents[curr.getRow()-1][curr.getCol()]);
				}if(curr.getRow() < maze.rows-1 && !maze.contents[curr.getRow()+1][curr.getCol()].getIsWall()&& maze.contents[curr.getRow()+1][curr.getCol()].isVisited() == false) {
					maze.contents[curr.getRow()+1][curr.getCol()].visit();
					maze.contents[curr.getRow()+1][curr.getCol()].setPrevious(curr);
					wl.add(maze.contents[curr.getRow()+1][curr.getCol()]);
				}if(curr.getCol() < maze.cols-1 && !maze.contents[curr.getRow()][curr.getCol()+1].getIsWall()&& maze.contents[curr.getRow()][curr.getCol()+1].isVisited() == false) {
					maze.contents[curr.getRow()][curr.getCol()+1].visit();
					maze.contents[curr.getRow()][curr.getCol()+1].setPrevious(curr);
					wl.add(maze.contents[curr.getRow()][curr.getCol()+1]);
				}if(curr.getCol()> 0 && !maze.contents[curr.getRow()][curr.getCol()-1].getIsWall()&& maze.contents[curr.getRow()][curr.getCol()-1].isVisited() == false) {
					maze.contents[curr.getRow()][curr.getCol()-1].visit();
					maze.contents[curr.getRow()][curr.getCol()-1].setPrevious(curr);
					wl.add(maze.contents[curr.getRow()][curr.getCol()-1]);
				}
			}
		
		return null;
	}

}
