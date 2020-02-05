#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+66;
char s[AX];
char tmp[105];

typedef struct Trie_Node{
    struct Trie_Node* next[26];
    int num;
    bool exist;
}TrieNode,*Trie;

int res ;

Trie_Node* Trie_createroot(){
    Trie_Node* root = new Trie_Node();
    root -> num = 0 ;
    root -> exist = false ;
    memset( root -> next , 0 , sizeof( root -> next ) );
    return root;
}

void Trie_insert( Trie node , char *p ){
    while( *p ){
        if( node -> next[*p-'a'] == NULL ){
            node -> next[*p-'a'] = Trie_createroot();
        }
        node = node -> next[*p-'a'];
        ++p;
    }
    node -> exist = true;
    node -> num ++;
}

int Trie_serach( Trie node , char *p ){
    while( *p ){
        node = node -> next[*p-'a'];
        if( node == NULL ){
            return 0;
        }
        if( node -> exist ) res += node -> num; 
        p++;
    }
    return true;
}
void Trie_del(Trie root){
    for( int i = 0 ; i < 26 ; i++ ){
        if( root -> next[i] != NULL)
            Trie_del( root -> next[i] );
    }
    free(root);
}
int main(){
    int T;
    scanf("%d",&T);
    int n ;
    while( T-- ){
        res = 0 ;
        Trie root = Trie_createroot();
        scanf("%s",s);
        scanf("%d",&n);
        for( int i = 0 ; i < n ; i++ ){
            scanf("%s",tmp);
            Trie_insert( root , tmp );
        }
        for( int i = 0 ; s[i] ; i++ ){
            Trie_serach( root , s + i );
        }
        printf("%d\n",res);
        Trie_del(root);
    }
    return 0 ;
}