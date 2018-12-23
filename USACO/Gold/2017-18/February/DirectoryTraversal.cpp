#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const long long MAXN = 100000;
struct Node{
    bool isFile;
    vector<Node*> children;
    long long nameLen;
    long long numLeaves;
    long long totalsubTreeLen;
    long long total;
};
long long n;
long long leaves;
Node nodes[MAXN];
void dfs1(Node* node){
    if(node->isFile){
        node->numLeaves = 1;
    }else{
        node->numLeaves = 0;
    }
    for(auto child: node->children){
        dfs1(child);
        node->numLeaves+=child->numLeaves;
        bool ok = true;
        if(child->isFile){
            ok = false;
        }
        node->totalsubTreeLen += child->totalsubTreeLen + child->numLeaves*(child->nameLen + (long long)ok);
    }
}
void dfs2(Node* node,long long parentlen){
    node->total = parentlen + node->totalsubTreeLen;
    long long toadd = 0;
    for(auto child:node->children){
        bool ok = true;
        if(child->isFile){
            ok = false;
        }
        toadd+=((child->totalsubTreeLen) + (child->numLeaves*(child->nameLen+(long long)ok)));
    }
    for(auto child:node->children){
        bool ok = true;
        if(child->isFile){
            ok = false;
        }
        dfs2(child,parentlen + toadd -
      (child->totalsubTreeLen + child->numLeaves * (child->nameLen + (child->isFile ? 0 : 1)))
      + 3 * (leaves - child->numLeaves));
    }
    
}
int main() {
    ifstream fin("dirtraverse.in");
    ofstream fout("dirtraverse.out");
	fin>>n;
	for(long long i=0;i<n;i++){
	    string s;
	    fin>>s;
	    nodes[i].nameLen = s.length();
	    long long numChildren;
	    fin>>numChildren;
	    if(numChildren == 0){
	        nodes[i].isFile = true;
	        leaves++;
	    }else{
	        nodes[i].isFile = false;
	    }
	    for(long long j=0;j<numChildren;j++){
	        long long child;
	        fin>>child;
	        nodes[i].children.push_back(&nodes[child-1]);
	    }
	}
	dfs1(&nodes[0]);
	dfs2(&nodes[0],0);
	long long ans = nodes[0].total;
	for(long long i=0;i<n;i++){
	    if(!nodes[i].isFile){
	        ans = min(ans,nodes[i].total);
	    }
	}
	fout<<ans<<endl;
}
