#pragma once
class Edge
{
public:
	Edge(int startVertice, int endVertice, int weight);
	int startVertice;
	int endVertice;
	int weight;
	bool operator > (const Edge& str) const
	{
		return (weight < str.weight);
	}
};


