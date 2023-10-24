#include<iostream>
using namespace std;
const int size = 5;
class CircularQueue{
	private:
		int items[size], front , rear;
		
		public:
			circularque(){
				front = -1;
				rear = -1;
			}
			
			bool isfull(){
				if (front!=0 && rear != size - 1)
				return true;
				if (front == rear +1)
				return true;
				
				return false;
			}
			
			bool isempty(){
				if (front == -1)
				return true;
				else
				return false;
			}
			
			void enqueue(int element){
				if (isfull()){
					cout<<"Queu is Full! "<<endl;
				}
				else{
					if (front == -1){
					front = 0;
				}
				
				rear = (rear + 1) % size;
				items[rear] = element;
				cout<<"Inserted "<<element<<endl;
				}
			}
			
			int dequeue(){
				int element;
				if (isempty()){
					cout<<"Que is empty"<<endl;
					return -1;
				}
				else{
					element = items[front];
					if (front == rear){
						front = -1;
						rear = -1;
					}
					else{
						front = (front + 1) % size;
					}
					return element;
				}
			}
			
			void display(){
				int i;
				if (isempty()){
					cout<<"Que is empty"<<endl;
				}
				else{
					cout<<"Front->"<<front<<endl;
					cout<<"Items->";
					for (i = front; i!= rear; i=(i+1)%size)
						cout<<items[i]<<" ";
						
						cout<<items[i];
						cout<<endl<<"Rear->"<<rear<<endl;
					
				}
			}
};

int main() {
CircularQueue q;
// Filling the circular queue
q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
// Trying to add one more element to demonstrate the queue is full
q.enqueue(6);
// Displaying the circular queue
q.display();
// Removing an element from the circular queue
q.dequeue();
// Adding a new element after removal
q.enqueue(7);
// Displaying the circular queue after deletion and addition
q.display();
return 0;

}
