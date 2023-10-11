#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Product
{
protected:
    string name;
    double price;

public:
    Product(const string &n, double p) : name(n), price(p) {}

    virtual void display()
    {
        cout << "Name: " << name << ", Price: $" << price << endl;
    }

    virtual double calculateDiscount()
    {
        return price;
    }

    virtual ~Product() {}
};

class SaleProduct : public Product
{
private:
    double discountRate;

public:
    SaleProduct(const string &n, double p, double dr) : Product(n, p), discountRate(dr) {}

    void display() override
    {
        cout << "Sale Product - ";
        Product::display();
        cout << "Discount Rate: " << discountRate << "%" << endl;
    }

    double calculateDiscount() override
    {
        return price - (price * discountRate / 100);
    }

    friend ofstream &operator<<(ofstream &ofs, const SaleProduct &product)
    {
        ofs << "SaleProduct " << product.name << " " << product.price << " " << product.discountRate << endl;
        return ofs;
    }
};

class GiftProduct : public Product
{
private:
    string occasion;

public:
    GiftProduct(const string &n, double p, const string &o) : Product(n, p), occasion(o) {}

    void display() override
    {
        cout << "Gift Product - ";
        Product::display();
        cout << "Occasion: " << occasion << endl;
    }

    friend ofstream &operator<<(ofstream &ofs, const GiftProduct &product)
    {
        ofs << "GiftProduct " << product.name << " " << product.price << " " << product.occasion << endl;
        return ofs;
    }
};

template <class T>
class ProductDatabase
{
private:
    vector<T *> products;

public:
    void addProduct(T *product)
    {
        products.push_back(product);
    }

    void displayAllProducts()
    {
        for (T *product : products)
        {
            product->display();
        }
    }

    typename vector<T *>::iterator begin()
    {
        return products.begin();
    }

    typename vector<T *>::iterator end()
    {
        return products.end();
    }

    double calculateTotalRevenue()
    {
        double total = 0;
        for (T *product : products)
        {
            total += product->calculateDiscount();
        }
        return total;
    }

    ~ProductDatabase()
    {
        for (T *product : products)
        {
            delete product;
        }
    }
};

int main()
{
    ProductDatabase<Product> database;

    // Thêm sản phẩm vào cơ sở dữ liệu
    database.addProduct(new SaleProduct("Laptop", 1000, 10));
    database.addProduct(new GiftProduct("Watch", 200, "Birthday"));

    // Ghi dữ liệu vào file
    ofstream ofs("products.txt");
    if (ofs.is_open())
    {
        for (Product *product : database)
        {
            if (dynamic_cast<SaleProduct *>(product))
            {
                ofs << *(dynamic_cast<SaleProduct *>(product));
            }
            else if (dynamic_cast<GiftProduct *>(product))
            {
                ofs << *(dynamic_cast<GiftProduct *>(product));
            }
        }
        ofs.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    // Hiển thị thông tin sản phẩm
    database.displayAllProducts();

    // Tính tổng doanh thu
    double totalRevenue = database.calculateTotalRevenue();
    cout << "Total Revenue: $" << totalRevenue << endl;

    return 0;
}
