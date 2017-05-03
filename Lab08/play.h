/**
*	@file : play.h
*	@author : Richard Aviles
*	@date : 2015.11.05
	Purpose:  
*/

#ifndef PLAY_H
#define PLAY_H
#include "play.h"
#include "Node.h"


template <typename T>

class play
{
public:
        play();
        play(const play<T>& other);
        bool isEmpty() const;
        bool add(T value);
        bool search(T value) const;
        
private:
        Node<T>* m_root;
        bool add(T value, Node<T>* subtree);
        bool search(T value, Node<T>* subtree) const;
    
    
};


#include "play.hpp"

#endif

