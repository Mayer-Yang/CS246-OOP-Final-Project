#ifndef _SUBJECT_H_
#define _SUBJECT_H_
#include <vector>
#include <memory>
template <typename StateType> class Observer;

template <typename StateType> class Subject {
 	std::vector<std::shared_ptr<Observer<StateType>>> observers;
 	StateType state;
 protected:
 	void setState(StateType newS);
 public:
 	void attach(std::shared_ptr<Observer<StateType>> o);
 	void notifyObservers();
 	StateType getState() const;
};

template <typename StateType>
void Subject<StateType>::attach(std::shared_ptr<Observer<StateType>> o) {
 	observers.emplace_back(o);
}

template <typename StateType>
void Subject<StateType>::notifyObservers() {
 	for (auto &ob : observers) ob->notify(*this);
}

template <typename StateType>
void Subject<StateType>::setState(StateType newS) { state = newS; }

template <typename StateType>
StateType Subject<StateType>::getState() const { return state; }
#endif
