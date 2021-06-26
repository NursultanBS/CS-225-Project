#pragma once

#include <iterator>
#include <set>
#include <vector>
#include "../structs/nodestep.hpp"
#include "../graphs/graph.h"


using namespace std;

class Traversal {
    public: 
    // ****************Inner Iterator class******************************
        class Iterator: iterator<forward_iterator_tag, NodeStep> {
            public:
                Iterator();
                Iterator(int n);
                Iterator(Traversal* traversal, NodeStep& start);
                Iterator & operator++();
                NodeStep operator*();
                bool operator!=(const Iterator &other);
                bool canMove(const NodeStep& ns, int limit=-1) const;
            private:
                Traversal* traversal_;
                set<string> visited_;
                NodeStep current_;

        };
    // ****************End of Inner Iterator class************************
    // Public Traversal Field continue
        virtual Iterator begin() = 0;

        virtual Iterator end() = 0;

        virtual void add(const NodeStep & t) = 0;

        virtual NodeStep pop() = 0;

        virtual NodeStep peek() const = 0;

        virtual bool empty() const = 0; 

        virtual set<string>& getSet(const string& key) const = 0;

        virtual bool contains(const string& key) const = 0;
    private:
        NodeStep start_;

};