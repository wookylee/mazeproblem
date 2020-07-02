
#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACKS 1000000
#define MAX_SIZE 20


typedef struct {
	int row;
	int col;
	int dir;
}element;
typedef struct stack *stackPointer;
typedef struct stack {
	element data;
	stackPointer link;
};
stackPointer top[MAX_STACKS];

void push(int i, element item)
{
	stackPointer temp;
	temp = (stackPointer)malloc(sizeof(*temp));
	temp->data = item;
	temp->link = top[i];
	top[i] = temp;
	
}

element pop(int i)
{
	stackPointer temp = top[i];			
	element item;
	if (!temp) {
		printf("unsolvable");
			exit();
	}
	item = temp->data;
	top[i] = temp->link;
	free(temp);
	return item;
}



int solvemaze(element a, element b, int maze[MAX_SIZE][MAX_SIZE])
{
	element temp;
	
	temp = a;	
	int i = 0;
	int visited[MAX_SIZE][MAX_SIZE];

	for (int x = 0; x < b.row + 2; x++) {					//implement the visited maze
		for (int y = 0; y < b.col + 2; y++) {
			visited[x][y] = maze[x][y];
		}
	}

	
	push(i, temp);
	
	while (1) {												//a search algorithm to search 8 ways around the current node
		element next;
		
		temp = pop(i);
		int x = temp.row;
		int y = temp.col;
		int d = temp.dir;
		temp.dir = temp.dir + 1;
		push(i, temp);
		

		if (x == b.row && y == b.col) 
			return i;
		
		if (d == 0) {
			if ((x + 1) >= 0 && y >= 0 && (x + 1) <= (b.row + 1) && y <= (b.col + 1) && maze[x + 1][y] == 0 && visited[x + 1][y] == 0) {
				visited[x + 1][y] = 1;
				next.row = x + 1;
				next.col = y;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 1) {
			if ((x + 1) >= 0 && (y - 1) >= 0 && (x + 1) <= (b.row + 1) && (y - 1) <= (b.col + 1) && maze[x + 1][y - 1] == 0 && visited[x + 1][y - 1] == 0) {
				visited[x + 1][y - 1] = 1;
				next.row = x + 1;
				next.col = y - 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 2) {
			if (x >= 0 && (y - 1) >= 0 && x <= (b.row + 1) && (y - 1) <= (b.col + 1) && maze[x][y - 1] == 0 && visited[x][y - 1] == 0) {
				visited[x][y - 1] = 1;
				next.row = x;
				next.col = y - 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 3) {
			if ((x - 1) >= 0 && (y - 1) >= 0 && (x - 1) <= (b.row + 1) && (y - 1) <= (b.col + 1) && maze[x - 1][y - 1] == 0 && visited[x - 1][y - 1] == 0) {
				visited[x - 1][y - 1] = 1;
				next.row = x - 1;
				next.col = y - 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 4) {
			if ((x - 1) >= 0 && y >= 0 && (x - 1) <= (b.row + 1) && y <= (b.col + 1) && maze[x - 1][y] == 0 && visited[x - 1][y] == 0) {
				visited[x - 1][y] = 1;
				next.row = x - 1;
				next.col = y;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 5) {
			if ((x - 1) >= 0 && (y + 1) >= 0 && (x - 1) <= (b.row + 1) && (y + 1) <= (b.col + 1) && maze[x - 1][y + 1] == 0 && visited[x - 1][y + 1] == 0) {
				visited[x - 1][y + 1] = 1;
				next.row = x - 1;
				next.col = y + 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 6) {
			if (x >= 0 && (y + 1) >= 0 && x <= (b.row + 1) && (y + 1) <= (b.col + 1) && maze[x][y + 1] == 0 && visited[x][y + 1] == 0) {
				visited[x][y + 1] = 1;
				next.row = x;
				next.col = y + 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else if (d == 7) {
			if ((x + 1) >= 0 && (y + 1) >= 0 && (x + 1) <= (b.row + 1) && (y + 1) <= (b.col + 1) && maze[x + 1][y + 1] == 0 && visited[x + 1][y + 1] == 0) {
				visited[x + 1][y + 1] = 1;
				next.row = x + 1;
				next.col = y + 1;
				next.dir = 0;
				i++;
				push(i, next);
			}
		}
		else{									//if there is no place to go backtrack using pop
			visited[x][y] = 1;
				pop(i);
				i--;
		}
		
	}
	
}

int main(void)
{
	int x, y, z, w;
	int x_results[50];
	int y_results[50];
	FILE *fpin;
	FILE *fpout;
	int maze[20][20];
	int numbers[MAX_SIZE];
	int length;
	element start;
	element end;
	element result;


	fpin = fopen("c:\\mazeproblem\\input.txt", "r");
	
	if (fpin == NULL){
		printf("file does not exist\n");
		return 0;
	}
	
	fscanf_s(fpin, "%d %d %d %d", &x, &y, &z, &w);				//get the input file
	while (feof(fpin) == 0){
		for (int i = 1; i <= z; i++) {
			for (int j = 1; j <= w; j++) {
				fscanf_s(fpin, "%d", &maze[i][j]);
			}
		}
	}
	
	for (int i = 0; i <= z + 1; i++) {							//make a maze with walls of 1 around it to make it easier to search
		maze[i][0] = 1;
		maze[i][w + 1] = 1;
	}
	for (int i = 0; i <= w + 1; i++) {
		maze[0][i] = 1;
		maze[z + 1][i] = 1;
	}
	start.row = x;
	start.col = y;
	start.dir = 0;
	end.row = z;
	end.col = w;
	
	length = solvemaze(start, end, maze);									// the solve function that gives top[i]

	for (int i = length; i >= 0; i--) {
		result = pop(i);
		x_results[i] = result.row;
		y_results[i] = result.col;
	}
	fpout = fopen("c:\\mazeproblem\\output.txt", "w");						//output to  txt file
	for (int i = 0; i <= length; i++) {
		fprintf(fpout,"%d %d\n", x_results[i], y_results[i]);
	}
	fclose(fpin);
	fclose(fpout);

	return 0;

}