package main

func main() {
	
	n := 0
	x := 0
	y := 0
	grid := [][]string{}

  
	nextMove(n, x, y, grid);
	
}

func nextMove(n, c, r, int, grid [][]string){
	var i, j, up, left int
	short princess[2];
  
	/* find the princess */
	for (i = 0; i < n; ++i) {
	  for (j = 0; j < n; ++j) {
		if (grid[i][j] == 'p') {
		  princess[0] = i;
		  princess[1] = j;
		}
	  }
	}
  
	if ((up = princess[0] - r) < 0) {
	  printf("UP\n");
	  return;
	} else if (up > 0) {
	  printf("DOWN\n");
	  return;
	}
  
  
	if ((left = princess[1] - c) < 0) {
	  printf("LEFT\n");
	  return;
	} else if (left > 0) {
	  printf("RIGHT\n");
	  return;
	}
  }