#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "Graph.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Array.h"
using std::back_inserter;
using namespace std;

class Shortest
{
private:
	stack<string> direction_;
	double time_;
	int distance_;
public:
	Shortest();
	stack<string> GetDirection();
	double GetTime();
	double GetDistance();
	void SetDirection(stack<string> direction);
	void SetTime(double time);
	void SetDistance(int distance);
};

Shortest::Shortest()
{
	time_ = 0;
	distance_ = 0;
}

double Shortest::GetDistance()
{
	return distance_;
}

stack<string> Shortest::GetDirection()
{
	return direction_;
}

double Shortest::GetTime()
{
	return time_;
}

void Shortest::SetDirection(stack<string> direction)
{
	direction_ = direction;
}

void Shortest::SetTime(double time)
{
	time_ = time;
}

void Shortest::SetDistance(int distance)
{
	distance_ = distance;
}



class Dijkstra 
{
private:
	Graph<string, string> dijkstra_;
	template <class T>
	void split_(const string & line, char delimiter, T result);
	vector<string> split_(const string & line, const char delimiter);
public:
	void Build(string filename);
	Graph<string, string> & GetGraph() { return dijkstra_; };
	Shortest ShortestPath(string origin, string destination);
};

template <class T>
inline void Dijkstra::split_(const string & line, char delimiter, T result)
{
	stringstream stream;
	stream.str(line);
	string item;
	while (getline(stream, item, delimiter))
		*(result++) = item;
}

vector<string> Dijkstra::split_(const string & line, const char delimiter)
{
	vector<string> elements;
	split_(line, delimiter, back_inserter(elements));
	return elements;
}

void Dijkstra::Build(string filename)
{
	ifstream myFile;
	myFile.open(filename);
	string line;
	if (myFile.is_open())
	{
		getline(myFile, line);
		while (!myFile.eof())
		{
			auto strings = split_(line, ',');
			string start = strings[0];
			string dest = strings[1];
			string arc_data = strings[2];
			int miles = atoi(strings[3].c_str());
			auto start_vertex = dijkstra_.GetVertex(start);
			auto dest_vertex = dijkstra_.GetVertex(dest);
			if (!start_vertex)
			{
				dijkstra_.InsertVertex(start);
				start_vertex = dijkstra_.GetVertex(start);
			}
			if (!dest_vertex)
			{
				dijkstra_.InsertVertex(dest);
				dest_vertex = dijkstra_.GetVertex(dest);
			}
			dijkstra_.InsertArc(start, dest, arc_data, miles);
			getline(myFile, line);
		}
	}
	else
		throw Exception("File did not open");
}

Shortest Dijkstra::ShortestPath(string origin, string destination)
{
	int start = -1;
	int end = -1;
	int min_index = 0;
	int min_distance = -1;
	size_t size = dijkstra_.GetVertices().size();

	Array<Vertex<string, string>> vertices(size);
	Array<int> distances(size);
	for (int i = 0; i < size; i++)
		distances[i] = -1;

	Array<double> time(size);
	Array<int> predecessor(size);
	for (int i = 0; i < size; i++)
	{
		predecessor[i] = -1;
		distances[i] = -1;
	}

	Array<string> roads(size);

	int k = 0;
	for (auto v : dijkstra_.GetVertices())
		vertices[k++] = *&v;

	for (int i = 0; i < size; i++)
	{
		if (vertices[i].GetData() == origin)
			start = i;
		if (vertices[i].GetData() == destination)
			end = i;
	}
	if (start == -1 || end == -1)
		throw Exception("Error.");

	time[start] = 0;
	distances[start] = 0;

	for (int i = 0; i < size && !vertices[end].Processed(); i++)
	{
		for (auto v = 0; v < size; v++)
			if (!vertices[v].Processed() && distances[v] != -1 && (min_distance == -1 || distances[v] < min_distance))
			{
				min_distance = distances[v];
				min_index = v;
			}

		auto arcs = vertices[min_index].GetInEdges();
		for (auto edges : vertices[min_index].GetOutEdges())
			arcs.emplace_back(edges);
		for (auto arc : arcs)
		{
			int arc_index = 0;
			for (int j = 0; j < size; j++)
			{
				if (arc.GetDest()->GetData() == vertices[j].GetData())
					arc_index = j;
			}
			int total_distance = distances[min_index] + arc.GetWeight();
			if (total_distance < distances[arc_index] || distances[arc_index] == -1)
			{
				distances[arc_index] = total_distance;
				predecessor[arc_index] = min_index;
				roads[arc_index] = arc.GetData();

				if (roads[arc_index] == "I-5")
					time[arc_index] = (time[min_index]) + (arc.GetWeight() / 65.0);
				else
					time[arc_index] = (time[min_index]) + (arc.GetWeight() / 55.0);
			}
		}
		vertices[min_index].SetProcessed(true);
		min_distance = -1;
	}

	int predecessor_index = end;
	stack<string> directions;

	while (predecessor_index != -1)
	{
		if (!roads[predecessor_index].empty())
		{
			if (directions.empty())
				directions.push(roads[predecessor_index]);
			else if (roads[predecessor_index] != directions.top())
				directions.push(roads[predecessor_index]);
		}
		predecessor_index = predecessor[predecessor_index];
	}

	Shortest path;
	path.SetDirection(directions);
	path.SetTime(time[end]);
	path.SetDistance(distances[end]);
	return path;
}
#endif 

