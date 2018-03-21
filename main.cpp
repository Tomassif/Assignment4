
#include "Graph.hpp"
#include "Edge.hpp"
#include "BaseNode.hpp"
#include "Node.hpp"

using namespace std;
//luca tomassi passed by here.
void test1();
void test2();
//also here
//testing here
int main(){
    test1();
    return 0;
}
void test1(){
    BaseNode* a = new Node<int>(BaseNode::i,1);
    BaseNode* b = new Node<int>(BaseNode::i,2);
    BaseNode* c = new Node<int>(BaseNode::i,3);
    BaseNode* d = new Node<int>(BaseNode::i,4);
    BaseNode* e = new Node<int>(BaseNode::i,5);
    BaseNode* f = new Node<int>(BaseNode::i,6);
    Edge e1 = Edge(true,a,b);
    Edge e2 = Edge(true,a,d);
    Edge e3 = Edge(true,b,c);
    Edge e4 = Edge(true,b,d);
    Edge e5 = Edge(true,b,e);
    Edge e6 = Edge(true,c,d);
    Edge e7 = Edge(true,e,c);
    Edge e8 = Edge(true,f,c);
    Edge e9 = Edge(true,f,e);
    Edge e10 = Edge(true,d,a);
    Edge e11 = Edge(true,c,e);
    Graph g = Graph(true);
    g.addNode(a);
    g.addNode(b);
    g.addNode(c);
    g.addNode(d);
    g.addNode(e);
    g.addNode(f);
    g.addEdge(&e1);
    g.addEdge(&e11);
    g.addEdge(&e2);
    g.addEdge(&e3);
    g.addEdge(&e4);
    g.addEdge(&e5);
    g.addEdge(&e6);
    g.addEdge(&e7);
    g.addEdge(&e8);
    g.addEdge(&e9);
    g.addEdge(&e10);
    g.print();
    g.printPathFromNode(a);
    g.removeEdge(&e11);
    g.print();
    g.printPathFromNode(a);
    g.removeNode(a);
    g.printPathFromNode(a);
    g.setDirected(false);
    g.print();
    g.setDirected(true);
    g.print();
   // cout << g.valueContained<string>("abc", BaseNode::s) << endl;
}
void test2(){
    BaseNode* s = new Node<string>(BaseNode::st,"test");
    BaseNode* d = new Node<Graph>(BaseNode::g,Graph());
    BaseNode* a = new Node<BaseNode>(BaseNode::bN,BaseNode());
    BaseNode* i = new Node<int>(BaseNode::i,1123);
    BaseNode* b = new Node<bool>(BaseNode::b,false);
    BaseNode* q = new Node<int>(BaseNode::i,987654321);
    Edge ed1 = Edge(true, s, d);
    Edge ed4 = Edge(true, d, s);
    Edge ed2 = Edge(a, i);
    Edge ed3 = Edge(false, b, s);
    Graph g = Graph(true);
    g.addNode(s);
    g.addNode(d);
    g.addNode(a);
    g.addNode(i);
    g.addNode(b);
    g.addNode(q);
    g.addEdge(&ed1);
    g.addEdge(&ed2);
    g.addEdge(&ed3);
    g.addEdge(&ed4);
    g.print();
    cout << "EdgeCount: " << g.getEdgeCount() << endl;
}
