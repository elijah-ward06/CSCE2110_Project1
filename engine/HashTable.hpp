#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <iostream>
#include <string>
using namespace std;

template <typename V>
class HashTable{
private:
    struct Node{
        bool isIntKey;
        int intKey;
        string strKey;
        V value;
        Node* next;
    };

    Node** buckets;
    int numBuckets;
    int count;

    int hashInt(int key, int tableSize) const{
        long long sq=(long long)key*key;
        long long mid=(sq/100)%10000;
        return (int)(mid%tableSize);
    }

    int hashStr(const string& key, int tableSize) const{
        // adler32
        const unsigned int MOD=65521;
        unsigned int a=1, b=0;
        for (int i=0;i<(int)key.length();i++){
            a=(a+(unsigned char)key[i])%MOD;
            b=(b+a)%MOD;
        }
        unsigned int hash=(b<<16)|a;
        return (int)(hash%(unsigned int)tableSize);
    }

    void rehash(){
        int oldSize=numBuckets;
        Node** oldBuckets=buckets;

        numBuckets=oldSize*2;
        buckets=new Node*[numBuckets];
        for (int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
        count=0;

        for (int i=0;i<oldSize;i++){
            Node* cur=oldBuckets[i];
            while (cur!=NULL){
                Node* next=cur->next;
                int idx;
                if (cur->isIntKey)
                    idx=hashInt(cur->intKey, numBuckets);
                else
                    idx=hashStr(cur->strKey, numBuckets);
                cur->next=buckets[idx];
                buckets[idx]=cur;
                count++;
                cur=next;
            }
        }
        delete[] oldBuckets;
    }

public:
    HashTable(int size=16){
        numBuckets=size;
        count=0;
        buckets=new Node*[numBuckets];
        for (int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }

    ~HashTable(){
        clear();
        delete[] buckets;
    }

    //insert with int key
    void insert(int key, const V& value){
        if ((double)count/numBuckets>0.75) rehash();

        int idx=hashInt(key, numBuckets);
        Node* cur=buckets[idx];

        while (cur!=NULL){
            if (cur->isIntKey&&cur->intKey==key){
                cur->value=value;
                return;
            }
            cur=cur->next;
        }

        Node* n=new Node();
        n->isIntKey=true;
        n->intKey=key;
        n->strKey="";
        n->value=value;
        n->next=buckets[idx];
        buckets[idx]=n;
        count++;
    }

    //insert with string key
    void insert(const string& key, const V& value){
        if ((double)count/numBuckets>0.75) rehash();

        int idx=hashStr(key, numBuckets);
        Node* cur=buckets[idx];

        while (cur!=NULL){
            if (!cur->isIntKey&&cur->strKey==key){
                cur->value=value;
                return;
            }
            cur=cur->next;
        }

        Node* n=new Node();
        n->isIntKey=false;
        n->intKey=0;
        n->strKey=key;
        n->value=value;
        n->next=buckets[idx];
        buckets[idx]=n;
        count++;
    }

    V* find(int key){
        int idx=hashInt(key, numBuckets);
        Node* cur=buckets[idx];
        while (cur!=NULL){
            if (cur->isIntKey&&cur->intKey==key) return &cur->value;
            cur=cur->next;
        }
        return NULL;
    }

    V* find(const string& key){
        int idx=hashStr(key, numBuckets);
        Node* cur=buckets[idx];
        while (cur!=NULL){
            if (!cur->isIntKey&&cur->strKey==key) return &cur->value;
            cur=cur->next;
        }
        return NULL;
    }

    bool remove(int key){
        int idx=hashInt(key, numBuckets);
        Node* cur=buckets[idx];
        Node* prev=NULL;
        while (cur!=NULL){
            if (cur->isIntKey&&cur->intKey==key){
                if (prev!=NULL) prev->next=cur->next;
                else buckets[idx]=cur->next;
                delete cur;
                count--;
                return true;
            }
            prev=cur;
            cur=cur->next;
        }
        return false;
    }

    bool remove(const string& key){
        int idx=hashStr(key, numBuckets);
        Node* cur=buckets[idx];
        Node* prev=NULL;
        while (cur!=NULL){
            if (!cur->isIntKey&&cur->strKey==key){
                if (prev!=NULL) prev->next=cur->next;
                else buckets[idx]=cur->next;
                delete cur;
                count--;
                return true;
            }
            prev=cur;
            cur=cur->next;
        }
        return false;
    }

    int size() const{
        return count;
    }

    bool empty() const{
        return count==0;
    }

    void clear(){
        for (int i=0;i<numBuckets;i++){
            Node* cur=buckets[i];
            while (cur!=NULL){
                Node* next=cur->next;
                delete cur;
                cur=next;
            }
            buckets[i]=NULL;
        }
        count=0;
    }

    void display(){
        for (int i=0;i<numBuckets;i++){
            if (buckets[i]==NULL) continue;
            cout<<"Bucket "<<i<<": ";
            Node* cur=buckets[i];
            while (cur!=NULL){
                if (cur->isIntKey)
                    cout<<"("<<cur->intKey<<","<<cur->value<<") ";
                else
                    cout<<"("<<cur->strKey<<","<<cur->value<<") ";
                cur=cur->next;
            }
            cout<<"\n";
        }
    }
};

#endif
