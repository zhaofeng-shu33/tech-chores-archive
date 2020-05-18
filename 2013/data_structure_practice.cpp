#include <iostream>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <list>

using namespace std;

int MYINFINITY = INT_MAX;
struct Vertex
{
    string           name;   // Vertex name
    vector<Vertex *> adj;    // Adjacent vertices //用邻接表法 
    int              dist;   // Cost
    Vertex          *path;   // Previous vertex on shortest path
    Vertex(const string & nm ): name(nm)
      {reset();}
    void reset(){dist = MYINFINITY; path = NULL; }
};
typedef map<string,Vertex *> vmap;
typedef pair<string,Vertex *> vpair;

class Graph
{
  public:
    Graph( ) { }
    ~Graph( );
    void addEdge( const string & sourceName, const string & destName );
    void printPath( const string & destName ) const;
    void unweighted( const string & startName );
      
  private:
    Vertex * getVertex( const string & vertexName );
    void printPath( const Vertex & dest ) const;
    void clearAll( );

    vmap vertexMap;
    vector<Vertex *> allVertices;
};
void Graph::addEdge( const string & sourceName, const string & destName )
{
    Vertex * v = getVertex( sourceName );
    Vertex * w = getVertex( destName );
    v->adj.push_back( w );
}
Vertex * Graph::getVertex( const string & vertexName )
{
    vmap::iterator itr = vertexMap.find( vertexName );

    if( itr == vertexMap.end( ) )
    {
        Vertex *newv = new Vertex( vertexName );
        allVertices.push_back( newv );
        vertexMap.insert( vpair( vertexName, newv ) );
        return newv;
    }
    return (*itr).second;
}

int main( int argc, char *argv[ ] )
{
    Graph g;
    g.addEdge("C1","C2");
    g.addEdge("C1","C3");
    g.addEdge("C2","C3");
    
    system("pause");
    return 0;
}

