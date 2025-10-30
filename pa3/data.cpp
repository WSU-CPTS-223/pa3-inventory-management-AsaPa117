#include "data.hpp"

int data::convert_id(const string& int_Id)
{
    hash<string> convert; 
    return (convert(int_Id)) ; 
}

//getter
string data::getUniq_Id() 
{ 
    return this->Uniq_Id; 
}
string data::getProduct_Name() {return this->Product_Name; }
string data::getBrand_Name() { return this->Brand_Name; }
string data::getAsin() { return this->Asin; }
string data::getCategory() { return this->Category; }
string data::getUpc_Ean_Code() { return this->Upc_Ean_Code; }
string data::getList_Price() { return this->List_Price; }
string data::getSelling_Price() { return this->Selling_Price; }
string data::getQuantity() { return this->Quantity; }
string data::getModel_Number() { return this->Model_Number; }
string data::getAbout_Product() { return this->About_Product; }
string data::getProduct_Specification() { return this->Product_Specification; }
string data::getTechnical_Details() { return this->Technical_Details; }
string data::getShipping_Weight() { return this->Shipping_Weight; }
string data::getProduct_Dimensions() { return this->Product_Dimensions; }
string data::getImage() { return this->Image; }
string data::getVariants() { return this->Variants; }
string data::getSku() { return this->Sku; }
string data::getProduct_Url() { return this->Product_Url; }
string data::getStock() { return this->Stock; }
string data::getProduct_Details() { return this->Product_Details; }
string data::getDimensions() { return this->Dimensions; }
string data::getColor() { return this->Color; }
string data::getIngredients() { return this->Ingredients; }
string data::getDirection_To_Use() { return this->Direction_To_Use; }
string data::getIs_Amazon_Seller() { return this->Is_Amazon_Seller; }
string data::getSize_Quantity_Variant() { return this->Size_Quantity_Variant; }
string data::getProduct_Description() { return this->Product_Description; }

// 
int data::get_id() 
{ 
    return this->id; 
}

//setter
void data::setUniq_Id(const string& s) 
{ 
    this->Uniq_Id = s; 
    this->id = convert_id(s); // keep id in sync
}

void data::setProduct_Name(const string& s) { this->Product_Name = s; }
void data::setBrand_Name(const string& s) { this->Brand_Name = s; }
void data::setAsin(const string& s) { this->Asin = s; }
void data::setCategory(const string& s) { this->Category = s; }
void data::setUpc_Ean_Code(const string& s) { this->Upc_Ean_Code = s; }
void data::setList_Price(const string& s) { this->List_Price = s; }
void data::setSelling_Price(const string& s) { this->Selling_Price = s; }
void data::setQuantity(const string& s) { this->Quantity = s; }
void data::setModel_Number(const string& s) { this->Model_Number = s; }
void data::setAbout_Product(const string& s) { this->About_Product = s; }
void data::setProduct_Specification(const string& s) { this->Product_Specification = s; }
void data::setTechnical_Details(const string& s) { this->Technical_Details = s; }
void data::setShipping_Weight(const string& s) { this->Shipping_Weight = s; }
void data::setProduct_Dimensions(const string& s) { this->Product_Dimensions = s; }
void data::setImage(const string& s) { this->Image = s; }
void data::setVariants(const string& s) { this->Variants = s; }
void data::setSku(const string& s) { this->Sku = s; }
void data::setProduct_Url(const string& s) { this->Product_Url = s; }
void data::setStock(const string& s) { this->Stock = s; }
void data::setProduct_Details(const string& s) { this->Product_Details = s; }
void data::setDimensions(const string& s) { this->Dimensions = s; }
void data::setColor(const string& s) { this->Color = s; }
void data::setIngredients(const string& s) { this->Ingredients = s; }
void data::setDirection_To_Use(const string& s) { this->Direction_To_Use = s; }
void data::setIs_Amazon_Seller(const string& s) { this->Is_Amazon_Seller = s; }
void data::setSize_Quantity_Variant(const string& s) { this->Size_Quantity_Variant = s; }
void data::setProduct_Description(const string& s) { this->Product_Description = s; }
int data::isEmpty()
{
    if(this->id == -1)
    {
        return 1; 
    }
    else{return 0;}
}
void data::setData(data info)
{
    this->Product_Name = info.getProduct_Name(); 
    this->Brand_Name = info.getBrand_Name(); 
    this->Asin = info.getAsin(); 
    this->Category = info.getCategory(); 
    this->Upc_Ean_Code = info.getUpc_Ean_Code(); 
    this->List_Price = info.getList_Price(); 
    this->Selling_Price = info.getSelling_Price(); 
    this->Quantity = info.getQuantity(); 
    this->Model_Number = info.getModel_Number(); 
    this->About_Product = info.getAbout_Product(); 
    this->Product_Specification = info.getAbout_Product(); 
    this->Technical_Details = info.getTechnical_Details(); 
    this->Shipping_Weight = info.getShipping_Weight(); 
    this->Product_Dimensions = info.getProduct_Dimensions(); 
    this->Image = info.getImage(); 
    this->Variants = info.getVariants(); 
    this->Sku = info.getSku(); 
    this->Product_Url = info.getProduct_Url(); 
    this->Stock = info.getStock(); 
    this->Product_Details = info.getProduct_Details(); 
    this->Dimensions = info.getDimensions(); 
    this->Color = info.getColor(); 
    this->Ingredients = info.getIngredients(); 
    this->Direction_To_Use = info.getDirection_To_Use(); 
    this->Is_Amazon_Seller = info.getIs_Amazon_Seller(); 
    this->Size_Quantity_Variant = info.getSize_Quantity_Variant(); 
    this->Product_Description = info.getProduct_Description(); 
}
