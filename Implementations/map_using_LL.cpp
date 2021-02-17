#include<string> 
#include<iostream>
using namespace std;
template <typename V>
class mapNode{
	string key;
	V value;
	mapNode* next;
	mapNode(string key, V value){
		this->key=key;
		this->value=V;
		next=NULL;
	}
	~mapNode(){
		delete next;
	}
};

template <typename V>
class mymap{
	mapNode<V>** buckets;
	int count;
	int numBuckets;
	public:
	mymap(){
		count=0;
		numBuckets=5;
		buckets = new mapNode<V>*[numBuckets];
		for(int i=0;i<numBuckets;i++){
			buckets[i]=NULL;
		}
	}
	~mymap(){
		for(int i=0;i<numBuckets;i++){
			delete buckets[i];
		}
		delete [] buckets;
	}
	int size(){
		return count;
	}

	private:
		getBucketIndex(string key){
			int HashCode=0;
			currentCoeff = 1;
			for(int i=key.length()-1;i>=0;i--){
				HashCode+=key[i]*currentCoeff;
				HashCode=HashCode%numBuckets;
				currentCoeff*=37;
				currentCoeff=currentCoeff%numBuckets;
			}
			return HashCode%numBuckets;
		}
	public:
	void insert(string key, V value){
		BucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[BucketIndex];
		while(head!=NULL){
		if(head->key==key){
			head->value= value;
			return;
		}
		head=head->next;
	}
	head = buckets[BucketIndex];
	mapNode<V>* node = new mapNode<V>(key, value);
	node->next = head;
	buckets[BucketIndex] = node;
	count++;
}
	V remove(string key){
		BucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[BucketIndex];
		mapNode<V>* prev=NULL;
		while(head!=NULL){
			if(head->key==key){
				if(prev==NULL){
					buckets[BucketIndex] = head->next;
				}
				else
				prev->next=head->next;
				V value=head->value;
				head->next = NULL;
				delete head;
				count--;
				return value;
			}
			prev=head;
			head=head->next;
		}
		return 0;
	}
	
	V getValue(string key){
		BucketIndex = getBucketIndex(key);
		mapNode<V>* head = buckets[BucketIndex];
		while(head!=NULL){
			if(head->key==key)
			return head->value;
			head = head->next;
		}
		return 0;
	}

};

