#include "Data_Struct_Wrap.hpp"


dataStruct::dataStruct(){}
dataStruct::~dataStruct(){}
void dataStruct::parseFile()
{
    FILE* infile = fopen("marketing_sample_for_amazon_com-ecommerce__20200101_20200131__10k_data.csv", "r"); 
   char header[100000]; 
    char line[100000]; 
    string arr[28]; 

    fgets(header, sizeof(header), infile);

    while (fgets(line, sizeof(line), infile) != NULL)
    {
        string token;
        int tokenIndex = 0;
        bool marks = false;

        int i = 0;
        while (line[i] != '\0')
        {
            char c = line[i];

            if (c == '"') {
                marks = !marks; // toggle state
            }
            else if (c == ',' && !marks) 
            {
                // end of token
                if (token.empty() || token== "\"\"")
                {
                    token = "N/A";
                }
                arr[tokenIndex++] = token; 
                token.clear(); //empty token for next phase
            }
            else if (c == '\n' && !marks) 
            {
                // end of line
                if (token.empty() || token == "\"\"")
                {
                    token = "N/A";
                }
                arr[tokenIndex++] = token;
                token.clear();
            }
            else 
            {
                token.push_back(c);
            }

            i++; // move to next character
        }

        // pad remaining fields if fewer than 28
        while (tokenIndex < 28) {
            arr[tokenIndex++] = "N/A";
        }

        data info(arr[0], arr[1], arr[2], arr[3],
        arr[4], arr[5], arr[6], arr[7],
        arr[8], arr[9], arr[10], arr[11],
        arr[12], arr[13], arr[14], arr[15],
        arr[16], arr[17], arr[18], arr[19],
        arr[20], arr[21], arr[22], arr[23],
        arr[24], arr[25], arr[26], arr[27]); 
        
        hash<string> convert; 
        int key = convert(arr[0]); 
        struct2.insert(key, info);  
        struct1.insertItem(arr[0], info); 
    }
    fclose(infile); 
}

void dataStruct::find(string target)
{
    data *temp = struct1.find(target); 
    if(temp != NULL)
    {
        cout << "Uniq_id Matches\nUniq_id: " << (*temp).get_id() << "\nDetails\n";
        cout << "Product Name: " << temp->getProduct_Name() << "\n" << "Brand Name: " << temp->getBrand_Name() << "\n" << "Asin: " << temp->getAsin() << "\n" << "Category: " << temp->getCategory() << "\n";
        cout << "UPC/EAN Code: " << temp->getUpc_Ean_Code() << "\n" << "List Price: " << temp->getList_Price() << "\n" << "Selling Price: " << temp->getSelling_Price() << "\n"<< "Quantity: " << temp->getQuantity() << "\n";
        cout << "Model Number: " << temp->getModel_Number() << "\n" << "About Product: " << temp->getAbout_Product() << "\n" << "Product Specification: " << temp->getProduct_Specification() << "\n" << "Technical Details: " << temp->getTechnical_Details() << "\n";
        cout << "Shipping Weight: " << temp->getShipping_Weight() << "\n" << "Product Dimensions: " << temp->getProduct_Dimensions() << "\n" << "Image: " << temp->getImage() << "\n" << "Variants: " << temp->getVariants() << "\n";
        cout << "SKU: " << temp->getSku() << "\n" << "Product URL: " << temp->getProduct_Url() << "\n" << "Stock: " << temp->getStock() << "\n" << "Product Details: " << temp->getProduct_Details() << "\n";
        cout << "Dimensions: " << temp->getDimensions() << "\n" << "Color: " << temp->getColor() << "\n" << "Ingredients: " << temp->getIngredients() << "\n"<< "Directions To Use: " << temp->getDirection_To_Use() << "\n";
        cout << "Is Amazon Seller: " << temp->getIs_Amazon_Seller() << "\n" << "Size/Quantity Variant: " << temp->getSize_Quantity_Variant() << "\n" << "Product Description: " << temp->getProduct_Description() << "\n";
    }
    else{
        cout << "Inventory/Product not found\n"; 
    }
}

void dataStruct::listInventory(string target)
{
    struct2.listInventory(target); 
}

void dataStruct::test()
{
    dataStruct testStruct; 
    //test data, hashTable, AVL, find and ListInventory
    hash<string>convert; 
    data dataTest; 
    dataTest.setUniq_Id("123"); 
    dataTest.setProduct_Name("Test");
    assert(dataTest.getUniq_Id() == "123"); 
//////////////////////////////////////////////////////////////////
    //Hashtable
    testStruct.struct1.insertItem("1234", dataTest); 
    data* temp = testStruct.struct1.find("1234"); 
    assert(temp->getProduct_Name() == "Test"); 

    //hashtable edge case
    data* temp2 = testStruct.struct1.find("5555"); 
    assert(temp2 == nullptr); 
//////////////////////////////////////////////////////////
    //AVL
    data dataTest1; 
    dataTest1.setUniq_Id("1"); 
    dataTest1.setProduct_Name("I1"); 
    dataTest1.setCategory("Cat1");

    data dataTest2;
    dataTest2.setUniq_Id("2"); 
    dataTest2.setProduct_Name("I2"); 
    dataTest2.setCategory("Cat2");

    data dataTest3; 
    dataTest3.setUniq_Id("3"); 
    dataTest3.setProduct_Name("I3"); 
    dataTest3.setCategory("Cat2");

    //Insert into avl tree; 
    testStruct.struct2.insert(convert("1"), dataTest1); 
    testStruct.struct2.insert(convert("2"), dataTest2); 
    testStruct.struct2.insert(convert("3"), dataTest3); 

    testStruct.listInventory("Cat2"); 
    testStruct.listInventory("Cat1"); 
    testStruct.listInventory("Cat0"); 

}