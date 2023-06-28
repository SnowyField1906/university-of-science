#include <iostream>
#include <fstream>
#include "vector.cpp"

using namespace std;

class Phim
{
private:
    string maSo;
    string tenPhim;
    string theLoai;
    string nhaSanXuat;
    int namSanXuat;
    int xepHang;

public:
    Phim(string ma, string ten, string tl, string nsx, int nam, int xh)
    {
        maSo = ma;
        tenPhim = ten;
        theLoai = tl;
        nhaSanXuat = nsx;
        namSanXuat = nam;
        xepHang = xh;
    }

    string getMaSo()
    {
        return maSo;
    }

    string getTenPhim()
    {
        return tenPhim;
    }

    string getTheLoai()
    {
        return theLoai;
    }

    string getNhaSanXuat()
    {
        return nhaSanXuat;
    }

    int getNamSanXuat()
    {
        return namSanXuat;
    }

    int getXepHang()
    {
        return xepHang;
    }
};

class QL_Phim
{
private:
    vector<Phim *> ds_phim;

public:
    void themPhim(Phim *phim)
    {
        int index = 0;
        while (index < ds_phim.size() && ds_phim[index]->getNamSanXuat() < phim->getNamSanXuat())
        {
            index++;
        }
        ds_phim.insert(index, phim);
    }

    void ghiDanhSachPhim()
    {
        ofstream file("ds_phim.dat");
        if (file.is_open())
        {
            for (int i = 0; i < ds_phim.size(); i++)
            {
                file << ds_phim[i]->getMaSo() << "\n";
                file << ds_phim[i]->getTenPhim() << "\n";
                file << ds_phim[i]->getTheLoai() << "\n";
                file << ds_phim[i]->getNhaSanXuat() << "\n";
                file << ds_phim[i]->getNamSanXuat() << "\n";
                file << ds_phim[i]->getXepHang() << "\n";
            }
            file.close();
        }
    }

    void docDanhSachPhim()
    {
        for (int i = 0; i < ds_phim.size(); i++)
        {
            delete ds_phim[i];
        }
        ds_phim.clear();

        ifstream file("ds_phim.dat");
        if (file.is_open())
        {
            string maSo, tenPhim, theLoai, nhaSanXuat;
            int namSanXuat, xepHang;
            while (getline(file, maSo))
            {
                getline(file, tenPhim);
                getline(file, theLoai);
                getline(file, nhaSanXuat);
                file >> namSanXuat;
                file >> xepHang;
                file.ignore(); // ignore the newline character

                Phim *phim = new Phim(maSo, tenPhim, theLoai, nhaSanXuat, namSanXuat, xepHang);
                ds_phim.push(phim);
            }
            file.close();
        }
    }

    void xoaPhimHBO()
    {
        int i = 0;
        while (i < ds_phim.size())
        {
            if (ds_phim[i]->getNhaSanXuat() == "HBO")
            {
                delete ds_phim[i];
                ds_phim.erase(i);
            }
            else
            {
                i++;
            }
        }
    }

    void inDanhSachPhim()
    {
        for (int i = 0; i < ds_phim.size(); i++)
        {
            cout << "Mã số: " << ds_phim[i]->getMaSo() << endl;
            cout << "Tên phim: " << ds_phim[i]->getTenPhim() << endl;
            cout << "Thể loại: " << ds_phim[i]->getTheLoai() << endl;
            cout << "Nhà sản xuất: " << ds_phim[i]->getNhaSanXuat() << endl;
            cout << "Năm sản xuất: " << ds_phim[i]->getNamSanXuat() << endl;
            cout << "Xếp hạng: " << ds_phim[i]->getXepHang() << endl;
            cout << "--------------------------" << endl;
        }
    }
};

int main()
{
    QL_Phim quanLyPhim;

    Phim *phim1 = new Phim("123", "Phim 1", "Hành động", "HBO", 2023, 1);
    Phim *phim2 = new Phim("456", "Phim 2", "Tình cảm", "ABC", 2023, 2);
    Phim *phim3 = new Phim("789", "Phim 3", "Hài", "HBO", 2022, 3);

    quanLyPhim.themPhim(phim1);
    quanLyPhim.themPhim(phim2);
    quanLyPhim.themPhim(phim3);

    cout << "Ghi danh sách phim..." << endl
         << endl;
    quanLyPhim.ghiDanhSachPhim();

    cout << "Đọc danh sách phim..." << endl
         << endl;
    quanLyPhim.docDanhSachPhim();

    cout << "In danh sách phim..." << endl
         << endl;
    quanLyPhim.inDanhSachPhim();

    cout << "Xóa phim HBO..." << endl
         << endl;
    quanLyPhim.xoaPhimHBO();

    cout << "Ghi danh sách phim..." << endl
         << endl;
    quanLyPhim.ghiDanhSachPhim();

    cout << "Đọc danh sách phim..." << endl
         << endl;
    quanLyPhim.docDanhSachPhim();

    cout << "In danh sách phim..." << endl
         << endl;
    quanLyPhim.inDanhSachPhim();

    return 0;
}
