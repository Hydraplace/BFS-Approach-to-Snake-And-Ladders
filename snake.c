#include<iostream>
#include<queue>
#include<string.h>
#include<time.h>
#include <cstdlib>
#define MAX_NUM 6
using namespace std;
struct queueEntry
{
    int v;     // Vertex number
    int dist;  // Distance of this vertex from source
};
int getMinDiceThrows(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    queue<queueEntry> q;
 
    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0, 0};  // distance of 0't vertex is also 0
    q.push(s);  // Enqueue 0'th vertex
 
    // Do a BFS starting from vertex at index 0
    queueEntry qe;  // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry
 
        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;
 
        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
 
                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
 
    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return qe.dist;
}
 
// Driver program to test methods of graph class

int randomfunc(int &score)
{
int random;
random=rand()%MAX_NUM;
cout<<"your number is "<<random<<endl;
score=random+score;
switch(score)
{
case 98 :score=28;
     cout<<"you ran into a snake!"<<endl;

    break;
case 95 :score=24;
cout<<"you ran into a snake!"<<endl;

break;
case 92 :score=51;
cout<<"you ran into a snake!"<<endl;

break;
case 83 :score=19;
cout<<"you ran into a snake!"<<endl;

break;
case 73 :score=1;
cout<<"you ran into a snake!"<<endl;

break;
case 69 :score=33;
cout<<"you ran into a snake!"<<endl;

break;
case 64 :score=36;
cout<<"you ran into a snake!"<<endl;

break;
case 59 :score=17;
cout<<"you ran into a snake!"<<endl;

break;
case 55 :score=7;
cout<<"you ran into a snake!"<<endl;

break;
case 52 :score=11;
cout<<"you ran into a snake!"<<endl;

break;
case 48 :score=9;
cout<<"you ran into a snake!"<<endl;

break;
case 46 :score=5;
cout<<"you ran into a snake!"<<endl;

break;
case 44 :score=22;
cout<<"you ran into a snake!"<<endl;

break;
case 8 :score=26;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 21 :score=82;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 43 :score=77;
 cout<<"luckyyy boy u got ladder"<<endl;

break;
case 50 :score=91;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 54 :score=93;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 62 :score=96;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 66 :score=87;
cout<<"luckyyy boy u got ladder"<<endl;

break;
case 80 :score=100;
cout<<"luckyyy boy u got ladder"<<endl;

}
return score;
}

int main()
{
int v;
cout<<"Press 1 to play game and 2 for calculating the shortest path: ";
cin>>v;
if(v==1){
int p1_score=0,p2_score=0;
cout<<endl;
cout<<endl;
cout<<"========================================"<<endl;
cout<<endl;
cout<<"\t\t\t\t SNAKE AND LADDER GAME \t\t\t\t"<<endl;
cout<<endl;
cout<<"========================================"<<endl;
cout<<endl;

int i;
string player1,player2;

srand(time(0));

cout<<"enter the name of  player 1"<<endl;
cin>>player1;
cout<<"enter the name of the player 2 "<<endl;
cin>>player2;
cout<<"the position of player1 and player2 is 0 initially"<<endl;

while(p1_score<100 && p2_score<100)
{

cout<<player1<<" It is your turn press any key to play "<<endl;
cin.get();
randomfunc(p1_score);
cout<<"your score is "<<p1_score<<endl;
cout<<player2<<"it is your turn press any key to play"<<endl;
cin.get();
randomfunc(p2_score);
cout<<"your score is "<<p2_score<<endl;

}
if(p1_score>p2_score)
{
cout<<player1<<"is the winner"<<endl;
}
if(p2_score>p1_score)
{
cout<<player2<<"is the winner"<<endl;
}
if(p1_score==p2_score)
{
cout<<"match is draw"<<endl;
}
}
else if(v==2)
{
	int N = 100;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
 
    // Ladders
    moves[8] = 26;
    moves[21] = 82;
    moves[43] = 77;
    moves[50] = 91;
    moves[54] = 93;
    moves[62] = 96;
    moves[66] = 87;
    moves[80] = 100;
 
    // Snakes
    moves[98] = 28;
    moves[95] = 17;
    moves[83] = 19;
    moves[73] = 22;
    moves[69] = 28;
    moves[44] = 24;
    moves[39] = 19;
    moves[25] = 1;
    moves[52] = 11;
 
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
    
}
else
{
	cout<<"ERROR..!!";
}
}
