#ifndef GRAPH_H
#define GRAPH_H
#include "QDebug"
class Graph{//undirected graph without weight
public:
    int maxVertices;
    int numEdges;
    int numVertices;
    int getVertexPos(char vertex);
    Graph(int sz=5){
        graphData=new char[sz];
        numEdges=0;numVertices=0;
        adjoiningMatrix=new bool*[sz];
        for(int i=0;i<sz;i++){
            adjoiningMatrix[i]=new bool[sz];
            adjoiningMatrix[i][0]=0;
        }
    }

    char getValue(int i){
        return graphData[i];
    }
    int getDegree(int i){
        int degree=0;
        for(int j=0;j<numVertices;j++)
            (adjoiningMatrix[i][j])?(degree++):(degree+=0);
        return degree;
    }

    int getFirstNeighbor(int v);
    int getNextNeighbor(int v,int w);
    //Take the next neighbor of v starting from w.
    void insertVertex(char newVertex){
        graphData[numVertices++]=newVertex;
    }
    void insertEdge(int v1,int v2){
        adjoiningMatrix[v1][v2]=1;
        adjoiningMatrix[v2][v1]=1;

    }

    void removeVertex(int v);//also remove all the edges of v.
    void removeEdge(int v1,int v2);
    bool** adjoiningMatrix;
    char* graphData;
    void printAdjoiningMatrix(){
        for(int i=0;i<numVertices;i++){
            QString str="";
            for(int j=0;j<numVertices;j++){
                str.append(QString("%1 ").arg(adjoiningMatrix[i][j]));
            }
            qDebug()<<str;
        }
    }
};

#endif // GRAPH_H
