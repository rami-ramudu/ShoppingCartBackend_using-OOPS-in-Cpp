//Product(1)<----->(1)Item(N)<---->Cart(1)
//the above mapping illustrates the relationship between the classes

//classes for product,item,cart
#include<bits/stdc++.h>
using namespace std;
class Item;
class Cart;
class Product
{
     int id;
     string name;
     float price;

     public:
     Product(){}
     Product(int id,string name,float prices)
     {
         this->id=id;
         price=prices;
         this->name=name;
     }

     string DisplayProduct()
     {
        return this->name+" : Rs "+to_string(price)+"\n";
     }

     char getShortName()
     {
         return tolower(this->name[0]);
     }

    //this declaration says that Item class is a friend
    //class to the Product class and that it can use the
    //private data members to the Item class
     friend class Item;
     friend class Cart;
};


class Item
{
  //the item class keeps track of the products and their corresponding
  //quantities
  //for that purpose we need to define an object of the product class
  //along with a variable called quantity
   Product product; //const means that the object cannot
  //be changed
  int quantity;
  public:
  Item(){}
  
  //create an initialisation list of the incoming 
  //product object and quantity
  Item(Product p,int quant):product(p),quantity(quant){}

  float getItemPrice()
  {
      return quantity*product.price;
  }

  string getItemInfo()
  {
      float ans=quantity*product.price;
      return to_string(quantity)+" X "+product.name+" --->RS "+to_string(ans)+"\n";
  }

  //indicate the item class that Cart is the friend of the
  //item class
  friend class Cart;

};

class Cart
{
    //here we are going to store an unordered_map 
    //1.where we will be able to check if the cart is empty
    //2.add items to the cart
    //also find the current_total of the cart
   
   //here integer is the product id
   //which uniquely identifies a certain product
    unordered_map<int,Item>items;
    

    public:
    Cart(){}
    void addProduct(Product product)
    {
        //if it's a new item that'been added to the cart
        if(items.count(product.id)==0)
        {
            Item newItem(product,1);
            items[product.id]=newItem;
        }
        //or it means that the item was already present
        else{
           items[product.id].quantity++;
        }
    }


   //get the current total of the cart
   float getTotal()
   {
     //the method that returns the current total of the cart
     float total(0);
     for(auto itemPair:items)
        {
            auto item=itemPair.second;
            total+=item.getItemPrice();
        }
        return total;
   }

    //view the cart
    string Viewcart()
    {
        if(items.empty()) return "Cart is empty!\n";
        float cart_total=this->getTotal();
        string itemizedList;
        for(auto itemPair:items)
        {
            auto item=itemPair.second;
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList+"\nTotal Amount Payable: "+to_string(cart_total)+"\n Happy Shopping\n";
    }
    bool isEmpty()
    {
        return (items.empty());
    }

};