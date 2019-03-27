// Gurjot Singh Nijjar
// Chain is a type of dynamically allocated array, that can hold number values, strings, 
// and you can do about anything.

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <algorithm>
#include <sstream>
#include <string>

namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain() : array_(nullptr), size_(0) {
      // making sure your are allocating and activating
  }
// you are gonna copy everything from right hand side to the left hand side chain including size member functions

  // Copy-constructor.
  Chain(const Chain &rhs)
  {
      size_= rhs.size();
      array_ = new Object[size_];
      for (int i = 0; i < size_; i++ )
      {
          array_[i] = rhs.array_[i];
      }
  }

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Chain copy = rhs;
  // std::swap(*this, copy);
  // return *this;
  // }
  Chain& operator=(const Chain &rhs)
{
   Chain copy = rhs;
   std::swap(*this, copy);
   return *this;
   

}
  // Move-constructor.
  Chain(Chain &&rhs)
  {
      size_ = rhs.size_;
      array_ =  rhs.array_;
      rhs.size_ = 0; 
      rhs.array_ = nullptr;
  }

  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs)
{
	std::swap(array_, rhs.array_);
	std::swap(size_, rhs.size_);
	 rhs.size_ = 0; 
      rhs.array_ = nullptr;

}
  ~Chain() {
    delete[] array_;
    array_ = nullptr; 
  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) : size_(0) {
    size_ = size_ + 1;
    array_ = new Object[size_]{item};

  }

  // Read a chain from standard input.
  void ReadChain() {

    std::string line;
    getline(std::cin, line);
    line.erase(std::remove(line.begin(), line.end(), ':'), line.end());
    line.erase(std::remove(line.begin(), line.end(), '['), line.end());
    line.erase(std::remove(line.begin(), line.end(), ']'), line.end());
// removing punctuation whilst not removing any negative - signs to make sure an integer doesnt get altered

    std::stringstream stream(line);
     stream >> size_;
// streaming everything from the line array filled with objects
     array_ = new Object[size_];
     Object temp;

     for (int j = 0; stream >> temp; j++)
        {
            array_[j] = temp;
        }
  }

  size_t size() const { // Write something
      return size_;
  }

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const {
if (size_ < location || location < 0)
{
abort();
}
    return array_[location];
 }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) {
if (size_ < location || location < 0)
{
abort();
}
    return array_[location];
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
	Chain<Object> template1;
	template1.size_ = c1.size() + c2.size();
  	template1.array_ = new Object[template1.size_];
	for (int k = 0; k < c1.size(); k++)
	{
		template1.array_[k] = c1.array_[k];
	}
	for (int w = c1.size(), b = 0; w < template1.size_; w++)
	{
		template1.array_[w] = c2.array_[b];
		b++;
	}
	return template1; 
	
 }
// to handle the concatenations of items and a chain 
// adjusting for strings and integers 
 friend Chain operator+(const Chain &c1, const Object& item) {
	Chain<Object> template1;
	template1.size_ = c1.size() + 1;
  	template1.array_ = new Object[template1.size_];
	for (int k = 0; k < c1.size(); k++)
	{
		template1.array_[k] = c1.array_[k];
	}
      	template1.array_[c1.size()] = item;

	return template1; 
	
 }

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
    out << "[";
    for (int i = 0; i < a_chain.size_; i++){
    out << a_chain.array_[i] << " " ;
    }
   out << "]";
   return out;
 }

 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
