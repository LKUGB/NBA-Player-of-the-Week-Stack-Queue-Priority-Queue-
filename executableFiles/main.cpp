#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <queue>
#include "Data.h"




using namespace std;

int main() {

    //define a stack, queue and a priority queue
    stack<Data> myStack;
    queue<Data> myQueue;
    priority_queue<Data> myPriorityQueue;

    ifstream inFS; //input file stream
    ofstream outFS; //output file stream
    inFS.open("../NBA_player_of_the_week.csv");

    //read file one at a time
    string line;
    cout << "Reading ../NBA_player_of_the_week.csv.." << endl;
    //skip the first line
    getline(inFS, line);
    while(getline(inFS, line)){
        //turn line into input string stream
        istringstream nba(line);
        string substring;
        int subInt;
        //read active season
        getline(nba, substring, ',');
        int activeSeason = stoi(substring);
        //read player's name
        getline(nba, substring, ',');
        string playerName = substring;
        //read team name
        getline(nba, substring, ',');
        string team = substring;
        //read seasons in league
        getline(nba, substring, ',');
        int seasonsInLeague = stoi(substring);

        //store the variables into the object of data class
        //declare Data object
        Data obj;
        obj.activeSeason = activeSeason;
        obj.playerName = playerName;
        obj.team = team;
        obj.seasonInLeague = seasonsInLeague;

        //push the object into the stack, queue and priority queue
        myStack.push(obj);
        myQueue.push(obj);
        myPriorityQueue.push(obj);
    }

    inFS.close();


    //open stack file
    outFS.open("../stacked.txt");
    while(!myStack.empty()){
        //print out the stack
        outFS << myStack.top() << endl;
        //pop the stack
        myStack.pop();
    }
    //close file
    outFS.close();

    //open queue file
    outFS.open("../queued.txt");
    while(!myQueue.empty()){
        //print out the queue
        outFS << myQueue.front() << endl;
        //pop the front element of the queue
        myQueue.pop();
    }
    //close file
    outFS.close();


    //open Sorted Linked List file
    outFS.open("../sorted.txt");
    while(!myPriorityQueue.empty()){
        //output the priority_queue into the file
        Data tempObj = myPriorityQueue.top();
        outFS << tempObj << endl;
        //pop the priorityQueue
        myPriorityQueue.pop();
    }
    //close file
    outFS.close();


    return 0;
}

