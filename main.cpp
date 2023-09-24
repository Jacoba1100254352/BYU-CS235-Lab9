#include <iostream>
#include <ctime>
#include <random>
#include <array>

#include <set>
#include <unordered_set>
#include "LinkedList.h"
#include "BST.h"
#include "AVL.h"

string resizedBuffer(unsigned, const string&);

using namespace std;

int main() {
    for (int i = 0; i < 2; i++) // Insert Remove
        for (int j = 0; j < 2; j++) { // Random Ordered
            const int NUM_TYPES = 5;
            const int NUM_IT = 3; // Changes number of N's
            const int BASE_N = 10; // Changes the number N starts at
            clock_t timing;
            clock_t times[NUM_IT][NUM_TYPES + 1] = {0};


            ///   Use random library to effectively randomize the values   ///
            std::random_device rd;
            std::mt19937 mt(rd());
            std::uniform_real_distribution<> dist(numeric_limits<int>::min(), numeric_limits<int>::max()); // Random number between numeric_limits<int>::min() and numeric_limits<int>::max() (exclusive numeric_limits<int>::max() + 1)


            // select one of the following implementations of a set by declaring the variable s to be of that type
            for (int col = 0; col < NUM_TYPES; col++) {
                set<int> s = {0};
                unordered_set<int> us = {0};
                LinkedList<int> ll;
                BST b;
                AVL a;

                for (int row = 0; row < NUM_IT; row++) { // Increase N each time
                    times[row][0] = BASE_N * static_cast<int>(pow(10, row)); // Equivalent to N

                    ///   For removes, automatically insert first, then time   ///
                    if (i == 1) {
                        //cout << "Inserting before starting remove" << endl;
                        for (int k = 0; k < times[row][0]; k++) {
                            int num = (j == 0) ? static_cast<int>(dist(mt))
                                               : k;    // this is for random data.  To get ordered data, change it to: num = i;
                            if (col == 0) s.insert(num);
                            else if (col == 1) us.insert(num);
                            else if (col == 2)
                                ll.insertHead(num); // for your LinkedList set, you can change it to s.insertHead(num)
                            else if (col == 3) b.add(num);
                            else a.add(num);
                        }
                    }

                    ///   TIMING   ///
                    //(i == 0) ? cout << "Starting insert" << endl : cout << "Starting remove" << endl;
                    timing = clock();

                    for (int k = 0; k < times[row][0]; k++) {
                        if (i == 0) {
                            ///   Can change the (j == 0) condition to analyze different circumstances   ///
                            int num = (j == 0) ? static_cast<int>(dist(mt)) : k;    // this is for random data.  To get ordered data, change it to: num = i;
                            if (col == 0) s.insert(num);
                            else if (col == 1) us.insert(num);
                            else if (col == 2) ll.insertHead(num); // for your LinkedList set, you can change it to s.insertHead(num)
                            else if (col == 3) b.add(num);
                            else a.add(num);
                        } else {
                            ///   Can change the (j == 0) condition to analyze different circumstances   ///
                            int num = (j == 0) ? static_cast<int>(dist(mt)) : k;    // this is for random data.  To get ordered data, change it to: num = i;
                            if (col == 0) s.erase(num);
                            else if (col == 1) us.erase(num);
                            else if (col == 2) ll.remove(num); // for your LinkedList, BST, and AVL sets, you'll need to change this to s.remove(num);
                            else if (col == 3) b.remove(num);
                            else a.remove(num);
                        }
                    }

                    timing = clock() - timing;


                    ///   Clear after the insert   ///  NOTE: sets and unordered sets are already cleared
                    if (i == 0) {
                        //cout << "Clearing..." << endl;
                        for (int k = 0; k < times[row][0]; k++)
                            (col == 2) ? ll.clear() : (col == 3) ? b.clear() : a.clear();  // The bst clear and the avl clear are recursive, is that bad?
                    }

                    //string currentType = (col == 0) ? "set" : (col == 1) ? "unordered set" : (col == 2) ? "linked list" : (col == 3) ? "bst" : "avl"; \
                    (i == 0) ? cout << "time required to insert " << times[row][0] << " integers into the " << currentType << ": " << ((double) timing / CLOCKS_PER_SEC) << endl : \
                               cout << "time required to remove " << times[row][0] << " integers from the " << currentType << ": " << ((double) timing / CLOCKS_PER_SEC) << endl;
                    times[row][col + 1] = timing;
                }
            }

            ///   Print Timing Table   ///
            (i == 0) ? cout << "\nRandom" : cout << "\nOrdered";
            (i == 0) ? cout << " insert" : cout << " remove";
            const unsigned BUFFER_LEN = 18;
            string buffer(BUFFER_LEN, ' ');
            string output = "\n" + resizedBuffer(BUFFER_LEN, "  N") + resizedBuffer(BUFFER_LEN, "set") +
                            resizedBuffer(BUFFER_LEN, "unordered_set")
                            + resizedBuffer(BUFFER_LEN, "Linked List") + resizedBuffer(BUFFER_LEN, "BST") +
                            resizedBuffer(BUFFER_LEN, "AVL") + "\n";

            for (auto &time: times) {
                for (unsigned long t: time) {
                    output += resizedBuffer(BUFFER_LEN, to_string(t));
                }
                output += "\n";
            }
            cout << output << endl;
        }

    return 0;
}

string resizedBuffer(const unsigned LENGTH, const string& text)
{
    string buffer(LENGTH - text.size(),' ');
    return text + buffer;
}
