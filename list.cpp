#include "list.hpp"
#include <iostream>

using namespace std;

List::List() : size_(0), head_(0), tail_(0)
{

}

List::~List()
{
    while (head_ !=tail_)
    {
        pop_front();
    }
}

bool List::is_empty() const
{
    return size_ == 0;
}

void List::front()
{
    if(!is_empty()) {
        cout<<head_->x_;
        cout<<head_->y_;
    }
    throw std::string("List is empty!");
}

void List::push_front(const int& a, const int& b)
{

    Node *temp=head_;
    if(is_empty()) {
        head_ = new Node(a,b,0,0);
        tail_= head_;
    }
    else {
        head_ = new Node(a,b,head_,0);
        temp->prev_ = head_;
    }
    size_++;
}

void List::pop_front()
{
    if(is_empty()) {
        throw std::string("List is empty!");
    }

    Node* temp = head_;

    head_ = head_->next_;

    head_->prev_ = 0;

    delete temp;

    size_--;
}


void List::display()
{
    if (!is_empty())
    {
        Node *temp=head_;
        while(temp)
        {
            cout<<temp->x_<<" ";
            cout<<temp->y_<<endl;
            temp=temp->next_;
        }
    }
    else{cout<<"List is empty"<<endl;}

}

void List::show_back()
{
    if(!is_empty())
    {
        cout<<tail_->x_<< " ";
        cout<<tail_->y_<< endl;
    }
}

void List::push_back(const int& a, const int& b)
{
    if(is_empty())
    {
        head_ = new Node(a,b);
        tail_= head_;
    }
        else
        {
            tail_->next_ = new Node(a,b,0,tail_);
            tail_=tail_->next_;
        }
    size_++;


}

void List::pop_back()
{
    Node *rev;

    if(is_empty())
    {
       cout<<"List is empty";
    }
        else
        {
            if (head_ == tail_){pop_front();}
            else
            {
                rev=tail_;
                tail_ = tail_->prev_;
                delete rev;
                size_--;
            }
        }

}

int List::show_x(int d) const
{
    Node *smeg=head_;
    for(int z=1; z<d;z++)
    {
        smeg=smeg->next_;
    }
    return smeg->x_;
}

int List::show_y(int d) const
{
    Node *smeg=head_;
    for(int z=1; z<d;z++)
    {
        smeg=smeg->next_;
    }
    return smeg->y_;
}





//NODE CLASS IMPLEMENTATION:
List::Node::Node(const int& a, const int& b, Node* next, Node* prev)
{
    x_ = a;
    y_ = b;
    next_ = next;
    prev_ = prev;
}

