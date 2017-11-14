/*****
	Create a list based graph representation.

	It will need to support the following operations:
	Ask the user how many points there are.
	Ask the user to label those points, ie "A", "B", "C"...
	Define the graph as an array of linked lists based on the number of points that holds labels. The node type would support the label and weight.
	Repeatedly ask the user to define edges between two points with the weight of the edge. Add these edges to the list.
	Have a list method that will list out all of the edges in the graph with their weights.
*****/

#include <iostream>
#include <string>

using namespace std;

class Node
{
	public:
		Node() : weight(0), label(""), next_link(0), prev_link(0) { }
		//~ Node();		//class destructor still missing
		Node(int & v, std::string & n) : weight(v), label(n), next_link(0), prev_link(0) { }
		Node * next_link;
		Node * prev_link;
		
		int weight;
		std::string label;
};

class List
{
	public:
		List() : head(0), tail(0), lsize(0) { }
		void add_vertex(int & w, std::string & l);
		bool empty() {return ((head == 0) && (tail == 0)); }
		void print_matrix() {std::cout << "Printing Matrix" << endl; }
		
		Node * head;
		Node * tail;
		int lsize;
};

void List::add_vertex(int & w, std::string & l)
{
	Node * N = new Node(w, l);
	if(empty())
	{
		std::cout << "adding head and tail" << endl;
		head = tail = N;
	}
	else
	{
		//head->next_link = N;
		//N->prev_link = head;
		//N->next_link = tail;
		//tail->prev_link = N;
		//head = N;
		std::cout << "adding new point " << l << " " << w << endl;
		N->prev_link = tail; // tail->prev_link;
		tail->next_link = N;
		tail = N;
		//N->next_link = tail;
		//tail->prev_link->next_link = N;
		//tail->prev_link = N;
	}
	lsize++;
}

int main()
{
	int nodes = 0, weight = 0;
	std::string label = "";
	
	std::cout << "-----List Based Graph Representation-----" << endl;
	std::cout << "How many nodes does your graph contain?:" << endl;
	std::cin >> nodes;
	
	//create array of lists
	List* am = new List[nodes];
	
	//add labels to list, weight defaults to 0
	for(int i = 0; i < nodes; i++)
	{
		std::cout << "Enter a label for node " << i << " of your graph:" << endl;
		std::cin >> label;
		for(int j = 0; j < nodes; j++) am[i].add_vertex(weight, label);
	}
	
	List matrix;
	weight = 0;
	std::string name = "test";
	for(int i = 1; i <= 3; i++)
	{
		weight = i;
		matrix.add_vertex(weight, name);
		matrix.print_matrix();
	}
	return 0;
}
