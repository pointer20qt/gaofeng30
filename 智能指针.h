#pragma once
using namespace std;

template<class T>
class gfptr{
	Ref<T>* ref = nullptr;
public:
	
	gfptr() = default;
	~gfptr(){
		if (ref){
			ref->reduce();
		}
	}
	gfptr(T* newP){
		ref = new Ref<T>(newP);
	}
	gfptr(const gfptr& other){
		ref = other.ref;
		if (ref){
			ref->increase();
		}
	}
	gfptr(gfptr&& other){
		swap(ref, other.ref);
	}
	gfptr&& operator=(gfptr&& other){
		if (ref){
			ref->reduce;
		}
		ref = other.ref;
		other.ref = nullptr;
		return *this;
	}
	gfptr&& operator=(gfptr& other){
		if (ref){
			ref->reduce();
		}
		ref = other.ref;
		if (ref){
			ref->increase();
		}
		return *this;
	}
	void swap(gfptr& other){
		swap(ref, other.ref);
	}
	void reset(T* target = nullptr){
		if (ref){
			ref->reduce();
		}
		if (target != nullptr){
			ref = new Ref<T>(target);
		}
		else{
			ref = nullptr;
		}
	}
	T& operator*(){
		if (ref){
			return *ref->get();
		}
		else{
			return *(T*)nullptr;
		}
	}
	T* operator->(){
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	T* get(){
		if (ref){
			return ref->get();
		}
		else{
			return (T*)nullptr;
		}
	}
	int use_count(){
		if (ref){
			return ref->getCount();
		}
		else{
			return 0;
		}
	}
	bool unique(){
		if (ref){
			return ref->getCount() == 1;
		}
		else{
			return false;
		}
	}
	operator bool(){
		return ref != nullptr;
	}
	};

  template<class T>
  class Ref{

	  int count = 0;
	  T* object = nullptr;

  public:
	  Ref(T* target) :object(target){
		  ++count;
	  }
	  inline void increase(){
		  count++;
	  }
	  inline void reduce(){
		  count--;
		  if (count == 0){
			  delete object;
			  delete this;
		  }
	  }
	  T* get(){
		  return object;
	  }
	  int getCount(){
		  return count;
	  }
  };