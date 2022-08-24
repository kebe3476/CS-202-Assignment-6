/*
CS 202 Assignment 6

Name: Keith Beauvais, 5005338658, CS 202 Assignment 6
*/
#include "americanCoinType.h"
#include <iostream>


using namespace std;

/* operator<< - friend function used to display/print data

	*/
ostream &operator<<(ostream& output, const coinsBox& coins){
  output <<coins.name<<" "<<"Penny = " <<coins.penny<<";  "<<"Nickel = " <<coins.nickel<<";  ";
  output <<"Dime = " <<coins.dime<<";  "<<"Quarter = " <<coins.quarter<<";  ";
  output <<"Fifty Centpiece = " <<coins.fifty_centpiece<<";  "<<"cents = " <<coins.getTotalAmountinCent()<<";  ";
  output <<"Dollars = " << coins.getTotalAmountinDollars()<<";  "<<"Address = " <<(void*)coins.name<<endl;

  return output;
}
/* operator>> - friend function used to read in data

	*/
istream &operator>>(istream& in, coinsBox& coins){
  coinsBox sum;
    sum = coins;

    cout<<"Insert Coins to CoinBox1"<<endl;
    cout<<"Penny : "<<endl;
    in >> coins.penny;
    cout<<"Nickel : "<<endl;
    in >> coins.nickel;
    cout<<"Dime : "<<endl;
    in >> coins.dime;
    cout<<"Quarter : "<<endl;
    in >> coins.quarter;
    cout<<"Fifty Centpiece : "<<endl;
    in >> coins.fifty_centpiece;

    coins = coins + sum;
    return in;
}
/*
Getters for the private members
*/
int coinsBox::getPennyCount() const{
  return penny;
}
int coinsBox::getNickelCount() const{
  return nickel;
}
int coinsBox::getDimeCount() const{
  return dime;
}
int coinsBox::getQuarterCount() const{
  return quarter;
}
int coinsBox::getFiftycentpieceCount() const{
  return fifty_centpiece;
}
double coinsBox::getTotalAmountinCent() const{
  double cent;

  cent = penny +(nickel*5)+(dime *10)+(quarter*25)+(fifty_centpiece*50);
  return cent;
}
double coinsBox::getTotalAmountinDollars() const{
  double centTotal, dollarAmount;

  centTotal = getTotalAmountinCent();
  dollarAmount=(centTotal/100);

  return dollarAmount;
}
/*
Setters for the private members
*/
void coinsBox::setPennyCount(int pen){
  penny = pen;
}
void coinsBox::setNickelCount(int nick){
  nickel=nick;
}
void coinsBox::setDimeCount(int dime){
  this -> dime = dime;
}
void coinsBox::setQuarterCount(int quart){
  quarter = quart;
}
void coinsBox::setFiftycentpieceCount(int fiddy){
  fifty_centpiece = fiddy;
}
void coinsBox::setName(string boxName){
  for(int i = 0; i <boxName.length(); i++){
    name[i] = boxName[i];
  }
}

//Overload the arithmetic operators

/* operator+ - Adds two numbers represented as object (coinBox1+coinBox2)

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns the sum of each custom type.
	*/
coinsBox coinsBox::operator+ (const coinsBox& rhs) const{
  coinsBox sum;

  sum.penny= this->penny + rhs.penny;
  sum.nickel= this->nickel + rhs.nickel;
  sum.dime= this->dime + rhs.dime;
  sum.quarter= this->quarter + rhs.quarter;
  sum.fifty_centpiece= this->fifty_centpiece + rhs.fifty_centpiece;

  return sum;
}
/* operator- - Subtracts two numbers represented as object (coinBox1-coinBox2)

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns the difference of each custom type.
	*/
coinsBox coinsBox::operator- (const coinsBox& rhs) const{

  coinsBox difference;

  difference.penny= this->penny - rhs.penny;
  difference.nickel= this->nickel - rhs.nickel;
  difference.dime= this->dime - rhs.dime;
  difference.quarter= this->quarter - rhs.quarter;
  difference.fifty_centpiece= this->fifty_centpiece - rhs.fifty_centpiece;

  return difference;
}
/* operator* - Multiplies two numbers represented as coinsBox object
(coinBox1*coinBox2)

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns the product of each custom type.
	*/
coinsBox coinsBox::operator* (const coinsBox& rhs) const{
  coinsBox product;

  product.penny= this->penny * rhs.penny;
  product.nickel= this->nickel * rhs.nickel;
  product.dime= this->dime * rhs.dime;
  product.quarter= this->quarter * rhs.quarter;
  product.fifty_centpiece= this->fifty_centpiece * rhs.fifty_centpiece;

  return product;
}
/* operator-= - Subtracts coinBox1 from CoinBox2 and the result is assigned to
coinBox2. (coinBox2 -= coinBox1)

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns the difference of coins1 and 2 unless it is less than 0
  of each custom type.
	*/
// assignment operator
coinsBox& coinsBox::operator-=(const coinsBox & rhs){
  coinsBox difference;

  this->penny = this->penny - rhs.penny;
  this->nickel = this->nickel - rhs.nickel;
  this->dime = this->dime - rhs.dime;
  this->quarter = this->quarter - rhs.quarter;
  this->fifty_centpiece = this->fifty_centpiece - rhs.fifty_centpiece;

  if(this->penny < 0 || this->nickel < 0 || this->dime < 0 ||
  this->quarter < 0 || this->fifty_centpiece < 0){
    setPennyCount(0);
    setNickelCount(0);
    setDimeCount(0);
    setQuarterCount(0);
    setFiftycentpieceCount(0);
  }
	return *this;
}
/* operator++ -  It increments all the 5 members by 1 individually.

	return value - returns the pointer *this of the incremented object.
	*/
//Overload the increment and decrement operators
coinsBox& coinsBox::operator++(){

  setPennyCount(++penny);
  setNickelCount(++nickel);
  setDimeCount(++dime);
  setQuarterCount(++quarter);
  setFiftycentpieceCount(++fifty_centpiece);

  return *this;
}    //pre-increment
/* operator++ -  It increments all the 5 members by 1 individually.

	return value - returns the pointer *this of the incremented object.
	*/
coinsBox& coinsBox::operator++(int){

  penny++;
  nickel++;
  dime++;
  quarter++;
  fifty_centpiece++;

  return *this;
} //post-increment
/* operator-- - It decrements all the 5 members by 1 individually

	return value - returns the pointer *this of the decremented object.
	*/
coinsBox& coinsBox::operator--(){

  setPennyCount(--penny);
  setNickelCount(--nickel);
  setDimeCount(--dime);
  setQuarterCount(--quarter);
  setFiftycentpieceCount(--fifty_centpiece);

  return *this;
}   //pre-decrement
/* operator-- - It decrements all the 5 members by 1 individually

	return value - returns the pointer *this of the decremented object.
	*/
coinsBox& coinsBox::operator--(int){

  penny--;
  nickel--;
  dime--;
  quarter--;
  fifty_centpiece--;

  return *this;
} //post-decrement

//Overload the default assignment operator
/* operator= - assignes passed value in to the class value. c
(coinBox2 = coinBox1)

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns the Copied contents of coinBox1 to coinBox2
  of each custom type.
	*/
coinsBox& coinsBox::operator=(const coinsBox & rhs){
  if (this != &rhs)
	{
		this->penny = rhs.penny;
    this->nickel = rhs.nickel;
    this->dime = rhs.dime;
    this->quarter = rhs.quarter;
    this->fifty_centpiece = rhs.fifty_centpiece;

	}
	return *this;
}

//Overload the relational operators
/* operator== - Compare two coinsBox objects if they are equal. (compare: if
      (coinBox1 == coinBox2))

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator==(const coinsBox& rhs) const{
  return ((this ->penny == rhs.penny)&&(this->nickel == rhs.nickel)&&
  (this ->dime == rhs.dime) && (this ->quarter == rhs.quarter)&&
  (this ->fifty_centpiece == rhs.fifty_centpiece));
}
/* operator!= - Compare two coinsBox objects if they are not equal. (compare:
      if (coinBox1 != coinBox2))

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator!=(const coinsBox& rhs) const{
  return !((this ->penny == rhs.penny)&&(this->nickel == rhs.nickel)&&
  (this ->dime == rhs.dime) && (this ->quarter == rhs.quarter)&&
  (this ->fifty_centpiece == rhs.fifty_centpiece));
}
/* operator<= - Compare if coinBox1 <= coinBox2

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator<=(const coinsBox& rhs) const{
  return(((this ->penny == rhs.penny)&&(this->nickel == rhs.nickel)&&
  (this ->dime == rhs.dime) && (this ->quarter == rhs.quarter)&&
  (this ->fifty_centpiece == rhs.fifty_centpiece))

  ||

  ((this ->penny < rhs.penny)&&(this->nickel < rhs.nickel)&&
  (this ->dime < rhs.dime) && (this ->quarter < rhs.quarter)&&
  (this ->fifty_centpiece < rhs.fifty_centpiece)));
}
/* operator< - Compare if coinBox1 < coinBox2

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator<(const coinsBox& rhs) const{
  return ((this ->penny < rhs.penny)&&(this->nickel < rhs.nickel)&&
  (this ->dime < rhs.dime) && (this ->quarter < rhs.quarter)&&
  (this ->fifty_centpiece < rhs.fifty_centpiece));
}
/* operator>= -  Compare if coinBox1 >= coinBox2

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator>=(const coinsBox& rhs) const{
  return(((this ->penny == rhs.penny)&&(this->nickel == rhs.nickel)&&
  (this ->dime == rhs.dime) && (this ->quarter == rhs.quarter)&&
  (this ->fifty_centpiece == rhs.fifty_centpiece))

  ||

  ((this ->penny > rhs.penny)&&(this->nickel > rhs.nickel)&&
  (this ->dime > rhs.dime) && (this ->quarter > rhs.quarter)&&
  (this ->fifty_centpiece > rhs.fifty_centpiece)));
}
/* operator> -  Compare if coinBox1 > coinBox2

	const coinsBox& rhs - passes in the right hand side of the equation

	return value - returns a true or false statement.
	*/
bool coinsBox::operator>(const coinsBox& rhs) const{
  return ((this ->penny > rhs.penny)&&(this->nickel > rhs.nickel)&&
  (this ->dime > rhs.dime) && (this ->quarter > rhs.quarter)&&
  (this ->fifty_centpiece > rhs.fifty_centpiece));
}

//Constructors

coinsBox::coinsBox(){
   setPennyCount(0);
   setNickelCount(0);
   setDimeCount(0);
   setQuarterCount(0);
   setFiftycentpieceCount(0);
   name = new char[LEN];
}
coinsBox::coinsBox(int _penny, int _nickel, int _dime, int _quarter, int _fifty_centpiece, char _name[LEN]){
  setPennyCount(_penny);
  setNickelCount(_nickel);
  setDimeCount(_dime);
  setQuarterCount(_quarter);
  setFiftycentpieceCount(_fifty_centpiece);

  name = new char[LEN];
  for(int i =0; i<LEN;i++){
    name[i]=_name[i];
  }
}
coinsBox::~coinsBox(){
  if(name != NULL){
    delete [] name;
  }
}
