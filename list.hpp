#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <string>

class List {
    class Node;

    public:
        List();
        ~List();
        bool is_empty() const;
        void front();
        inline unsigned int size() const;
        void push_front(const int& a, const int& b);
        void pop_front();
        void display();
        int show_x(int d) const;
        int show_y(int d) const;
        void show_back();
        void push_back(const int& a, const int& b);
        void pop_back();


        private:
        unsigned int size_;
        Node *head_;
        Node *tail_;

};

inline unsigned int List::size() const {return size_;}

class List::Node {
    public:
       Node(const int& a, const int& b, Node* next = 0, Node* prev = 0);

    private:
        friend class List;
        unsigned int x_,y_;
        Node*           next_;
        Node*           prev_;
};

#endif //_LIST_HPP_
