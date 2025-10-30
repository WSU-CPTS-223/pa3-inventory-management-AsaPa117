#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::string;
using std::stoi; 
using std::hash; 

class data
{
    private:
    int id; 
    string Uniq_Id,Product_Name,Brand_Name,Asin,Category,Upc_Ean_Code,List_Price,Selling_Price,
    Quantity,Model_Number,About_Product,Product_Specification,Technical_Details,Shipping_Weight,
    Product_Dimensions,Image,Variants,Sku,Product_Url,Stock,Product_Details,Dimensions,Color,Ingredients,Direction_To_Use,Is_Amazon_Seller,
    Size_Quantity_Variant,Product_Description; 

    int convert_id(const string& int_Id); 

    public: 
    //constructor
    data()
    {
        this->id = -1; //mean empty
        //Uniq_ID = ""; 

    } 
    //full constructor
    data(const string& uid, const string& pname, const string& bname, const string& asin,
        const string& cat, const string& upc, const string& lprice, const string& sprice,
        const string& qty, const string& model, const string& about, const string& spec,
        const string& tech, const string& shipW, const string& dim, const string& img,
        const string& var, const string& sku, const string& url, const string& stock,
        const string& pdetail, const string& dim2, const string& col, const string& ing,
        const string& dir, const string& seller, const string& sizeQ, const string& pdesc)
    {
         this->Uniq_Id = uid;
    this->id = convert_id(uid);

    this->Product_Name = pname;
    this->Brand_Name = bname;
    this->Asin = asin;
    this->Category = cat;
    this->Upc_Ean_Code = upc;
    this->List_Price = lprice;
    this->Selling_Price = sprice;
    this->Quantity = qty;
    this->Model_Number = model;
    this->About_Product = about;
    this->Product_Specification = spec;
    this->Technical_Details = tech;
    this->Shipping_Weight = shipW;
    this->Product_Dimensions = dim;
    this->Image = img;
    this->Variants = var;
    this->Sku = sku;
    this->Product_Url = url;
    this->Stock = stock;
    this->Product_Details = pdetail;
    this->Dimensions = dim2;
    this->Color = col;
    this->Ingredients = ing;
    this->Direction_To_Use = dir;
    this->Is_Amazon_Seller = seller;
    this->Size_Quantity_Variant = sizeQ;
    this->Product_Description = pdesc;
    }
   
int get_id();
    // getters
string getUniq_Id();
string getProduct_Name();
string getBrand_Name();
string getAsin();
string getCategory();
string getUpc_Ean_Code();
string getList_Price();
string getSelling_Price();
string getQuantity();
string getModel_Number();
string getAbout_Product();
string getProduct_Specification();
string getTechnical_Details();
string getShipping_Weight();
string getProduct_Dimensions();
string getImage();
string getVariants();
string getSku();
string getProduct_Url();
string getStock();
string getProduct_Details();
string getDimensions();
string getColor();
string getIngredients();
string getDirection_To_Use();
string getIs_Amazon_Seller();
string getSize_Quantity_Variant();
string getProduct_Description();

    // setters
void setUniq_Id(const string& s);
void setProduct_Name(const string& s);
void setBrand_Name(const string& s);
void setAsin(const string& s);
void setCategory(const string& s);
void setUpc_Ean_Code(const string& s);
void setList_Price(const string& s);
void setSelling_Price(const string& s);
void setQuantity(const string& s);
void setModel_Number(const string& s);
void setAbout_Product(const string& s);
void setProduct_Specification(const string& s);
void setTechnical_Details(const string& s);
void setShipping_Weight(const string& s);
void setProduct_Dimensions(const string& s);
void setImage(const string& s);
void setVariants(const string& s);
void setSku(const string& s);
void setProduct_Url(const string& s);
void setStock(const string& s);
void setProduct_Details(const string& s);
void setDimensions(const string& s);
void setColor(const string& s);
void setIngredients(const string& s);
void setDirection_To_Use(const string& s);
void setIs_Amazon_Seller(const string& s);
void setSize_Quantity_Variant(const string& s);
void setProduct_Description(const string& s);

void setData(data info); 

int isEmpty(); 
};

