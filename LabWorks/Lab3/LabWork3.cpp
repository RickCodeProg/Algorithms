#include <iostream>
#include "vector.h"
#include "queue.h"
#include <fstream>
using namespace std;

void BFS(int** matrix, int start, int V)
{
	ofstream out("output.txt");
	int* found = new int[V];
	for (int i = 0; i < V; i++)
	{
		found[i] = 0;
	}
	Queue* queue;
	queue = queue_create();
	queue_insert(queue, start);
	while (!queue_empty(queue))
	{
		int st = queue_get(queue);
		queue_remove(queue);
		for (int i = 0; i < V; i++)
		{
			if ((matrix[st][i] == 1) && (found[i] == 0) && (i != start))
			{
				found[i] = found[st] + 1;
				queue_insert(queue, i);
			}
		}
	}
	for (int i = 0; i < V; i++)
	{
		out << found[i] << '\n';
	}
	queue_delete(queue);
	delete[] found;
}




int main()
{
	int V;
	ifstream file("input.txt");
	if (!file.is_open())
	{
		cout << "Error" << '\n';
	}
	file >> V;
	int** matrix = new int* [V];
	for (int i = 0; i < V; i++)
	{
		matrix[i] = new int[V];
	}
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	BFS(matrix, 0, V);


	for (int i = 0; i < V; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}
