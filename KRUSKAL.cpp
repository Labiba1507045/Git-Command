#include<bits/stdc++.h>

using namespace std;
int parent[1000];
vector< pair< int , pair< int,int > > >edges;
int find_set(int x)
{
    if(parent[x]==x)
        return x;
    else return find_set(parent[x]);
}
void unite(int x,int y)
{
    int fx=find_set(x);
    int fy=find_set(y);
    parent[fy]=fx;
}
int main()
{
    int totalnode,totaledge,node1,node2,weight;
    cin>>totalnode>>totaledge;
    for(int i=1;i<=totalnode;i++)
    {
        parent[i]=i; //initialize the parent of all nodes with itself;
    }
    for(int i=0;i<totaledge;i++)
    {
        cin>>node1>>node2>>weight;
        edges.push_back(make_pair(weight,make_pair(node1,node2))); //1 2 7 (7,(1,2)) (weight,(node1,node2)) pair akare vector e edge rakhtesi
    }
    sort(edges.begin(),edges.end()); //weight wise sort krtese
    int mst_edge=0,mst_weight=0,edge_count=0;
    while(mst_edge<totalnode-1 || edge_count<totaledge) //total conncted edge node theke alwys ek kom hbe & total edge er theke beshi hoit parbe na
    {
        node1= edges[edge_count].second.first;
        node2= edges[edge_count].second.second;
        weight= edges[edge_count].first;
        if(find_set(node1)!=find_set(node2)) //checking node 2tar parent dif kina, dif hoile duitr parent same kore cnct krbo
        {
            cout<<node1<<" "<<node2<<" "<<weight<<endl;
            unite(node1,node2); //parent same krtesi
            mst_edge++;
            mst_weight +=weight;
        }
        edge_count++;
    }
    cout<<"Minimum Cost = "<<mst_weight<<endl;
}

