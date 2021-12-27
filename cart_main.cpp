#include<bits/stdc++.h>
#include"model.h"
using namespace std;
//global array of products
vector<Product>allProducts=
{
   Product(1,"Chocolates",190),
   Product(100,"Lipsticks",250),
   Product(82,"Fashion Clothing(for Women)",1000),
   Product(23,"Apples",200),
   Product(59,"T-Shirts and Hoodies",2000),
   Product(28,"Watches",2000),
   Product(100,"Stationary and Student Essentials",500),
   Product(12,"Munchies",10),
   Product(102,"Hand Sanitisers",100),
   Product(84,"Personal Care Products",600),
   Product(21,"Groceries",800),
   Product(10,"Ice cream Cakes",100),
};

Product* chooseProduct()
{
    string productList;
    cout<<"The Available Products are\n";
    for(auto product:allProducts)
    {
        productList.append(product.DisplayProduct());
    }
    cout<<productList<<"\n";
    cout<<"---------------------------------------------------------------\n";
    char ch;
    cout<<"Type in the first character of the product to add to the cart\n";
    cin>>ch;
    char choice=tolower(ch);
    //iterating all over the products and finding out
    //which product is matching the choice entered by the user
    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].getShortName()==choice)
        {
            return &allProducts[i];
        }
    }
    cout<<"Product Not Found!"<<endl;
    cout<<"We hope so to add it very soon "<<endl;
    return NULL;
}

bool checkout(Cart &cart)
{
   if(cart.isEmpty()) return false;
   float total=cart.getTotal();

   cout<<"Please do pay in cash!!\nDue to the Pandemic, ";
   cout<<"we are currently not accepting any other payment options \n";
   

   cout<<"Please do enter the amount you are paying(in Rs): ";
   float paid;
   cin>>paid;

   if(paid>=total)
   {
       if(paid>total)
       cout<<"Here is the change :"<<paid-total<<"\n";
       
       cout<<"Checkout and Payment Processing is successful!\n";
       cout<<"We hope you enjoyed shopping with us!!!\n";
       cout<<"Happy Shopping!!!\n";
       return true;
   }

   cout<<"Not enough cash to Process the payment\n!!";
   cout<<"Please do pay the required amount\n";
   return false;
}
int main()
{
    char ch;
    Cart cart;
    while(1)
    {
    cout<<"Select an action to perform \n1.(a)dd to the cart\n2.(v)iew the cart\n3.(c)heckout\n";
        cin>>ch;
        char action=tolower(ch);
        if(action=='a')
        {
           //view all the available products
           //Choose the products
           //add the products to the cart
          
           Product *product=chooseProduct();
           if(product)
           {
               cout<<"Added to the Cart "<<product->DisplayProduct()<<endl;
           }

           //actually adding the product to the cart
           cart.addProduct(*product);

        }
        else if(action=='v')
        {
            cout<<"------------------------------------------------------\n";
            cout<<cart.Viewcart()<<endl;
            cout<<"--------------------------------------------------------\n";


        }
        else if(action=='c')
        {
           cart.Viewcart();
           if(checkout(cart))
           {
               break;
           }
        }
    }
    return 0;
}