#include <iostream>  
#include <fstream>  
#include <string>  

using namespace std;  
// Struktur untuk menyimpan data pegawai  
struct Staff {  
    int staffNumber;  
    string staffName;  
    float totalSales;  
    float totalCommission;  
};  

// Fungsi untuk menghitung total penjualan dan komisi  
void calculateTotals(Staff &staff, float commissionRate) {  
    staff.totalCommission = staff.totalSales * commissionRate;  
}  

int main() {  
    const int staffCount = 50;  
    Staff staffList[staffCount]; // Array untuk menyimpan pegawai  
    float commissionRate = 0.1; // Misalkan komisi 10%  

    // Input data pegawai  
    for (int i = 0; i < staffCount; i++) {  
        cout << "Enter details for staff " << (i + 1) << endl;  
        staffList[i].staffNumber = i + 1;  
        cout << "Name: ";  
        cin >> staffList[i].staffName;  

        cout << "Enter total sales: ";  
        cin >> staffList[i].totalSales;  

        calculateTotals(staffList[i], commissionRate);  
    }  

    // Menyimpan data ke file  
    ofstream outFile("staff_data.txt");  
    for (int i = 0; i < staffCount; i++) {  
        outFile << staffList[i].staffNumber << " "  
                << staffList[i].staffName << " "  
                << staffList[i].totalSales << " "  
                << staffList[i].totalCommission << endl;  
    }  
    outFile.close();  

    // Menampilkan laporan  
    cout << "\nStaff Report:\n";  
    for (int i = 0; i < staffCount; i++) {  
        cout << "Staff Number: " << staffList[i].staffNumber  
             << ", Name: " << staffList[i].staffName  
             << ", Total Sales: " << staffList[i].totalSales  
             << ", Total Commission: " << staffList[i].totalCommission << endl;  
    }  

    return 0;  
}