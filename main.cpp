#include<bits/stdc++.h>
using namespace std;
#define max 100
struct NhanVien
{
	string ten;//1.Ho va ten
	int msnv;      //2.Ma so nhan vien
	string ngaysinh;     //3.ngay thang nam sinh
	string diachi;  //4.Dia chi
	string sdt;      //5.So dien thoai.
	string chucvu;       //6.Chuc vu
	int songaylamviec;   //7.So ngay lam viec
	double tienluong;     //8. So ngay lam viec trong thang
};
void MENU() 
{
    cout << "+----------------------------+" << endl;
    cout << "|     Quan ly nhan vien      |" << endl;
    cout << "+ ---------------------------+" << endl;
    cout << "|    1. Them nhan vien       |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    2. Sua thong tin        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    3. Xoa nhan vien        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    4. Tim nhan vien        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    5. Sap xep nhan vien    |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    6. Tinh tien luong      |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    7. Hien thi DSNV        |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    8.Luu thong tin vao File|" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    9. Quay lai             |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "|    10. Thoat               |" << endl;
    cout << "+----------------------------+" << endl;
    cout << "   Chon mot chuc nang: ";
}
void Menu3()
{
    cout << "+-------------------------+" << endl;
    cout << "|       Xoa nhan vien     |" << endl;
    cout << "+ ------------------------+" << endl;
    cout << "|    1. Theo MSNV         |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    2. Theo Ten          |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    3. Theo SDT          |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "   Chon mot chuc nang: ";
}
void Menu4()
{
    cout << "+-------------------------+" << endl;
    cout << "|       Tim kiem          |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    1. Theo MSNV         |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    2. Theo Ten          |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    3. Theo dia chi      |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    4. Theo SDT          |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    5. Theo chuc vu      |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "   Chon mot chuc nang: ";
}
//Cac cham sap xep nhan vien:1. Theo MSNV 2.Theo bang chu cai alpha b 3.Theo so ngay lam viec 4.Theo do tuoi
void Menu5()
{
    cout << "+-------------------------+" << endl;
    cout << "|     Sap xep nhan vien   |" << endl;
    cout << "+ ------------------------+" << endl;
    cout << "|    1. Theo MSNV         |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    2. Theo bang chu cai |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    3. Theo so ngay lam  |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "|    4. Theo do tuoi      |" << endl;
    cout << "+-------------------------+" << endl;
    cout << "   Chon mot chuc nang: ";
}
NhanVien dsnv[100];
int dem=0;
//Ham hien thi mot nhan vien(0.1)
void hienthi1(NhanVien a)
{
		system("CLS");
		cout<<"          Thong tin nhan vien"<<endl;
		cout<<"- Ho va ten: "<<a.ten<<endl;
		cout<<"- Ma so nhan vien: "<<a.msnv<<endl;
		cout<<"- Ngay thang nam sinh: "<<a.ngaysinh<<endl;
		cout<<"- Dia chi: "<<a.diachi<<endl;
		cout<<"- So dien thoai: "<<a.sdt<<endl;
		cout<<"- Chuc vu: "<<a.chucvu<<endl;
		cout<<"- So ngay lam viec trong thang: "<<a.songaylamviec<<endl;
}
// Ham hien thi danh sach nhan vien(0.2)
void hienthi2() {
    if (dem == 0) {
        cout << "Chua co nhan vien!" << endl;
        return;
    }
    cout<<"     Danh sach nhan vien     "<<endl;
    for (int i = 0; i < dem; i++)
	{
		cout<<"\n   Nhan vien thu "<<i+1<<"   "<<endl;
		cout<<"\n- Ho va ten: "<<dsnv[i].ten<<endl;
		cout<<"- Ma so nhan vien: "<<dsnv[i].msnv<<endl;
		cout<<"- Ngay thang nam sinh: "<<dsnv[i].ngaysinh<<endl;
		cout<<"- Dia chi: "<<dsnv[i].diachi<<endl;
		cout<<"- So dien thoai: "<<dsnv[i].sdt<<endl;
		cout<<"- Chuc vu: "<<dsnv[i].chucvu<<endl;
		cout<<"- So ngay lam viec trong thang: "<<dsnv[i].songaylamviec<<endl;;
    }
}
//Ham hien thi danh sach luong(0.3)
void hienthi3()
{
	cout<<"          Danh sach luong"<<endl;
	for(int i=0;i<dem;i++)
	{
		cout<<"*Nhan vien thu "<<i+1<<endl;
		cout<<"Ten: "<<dsnv[i].ten<<endl;
		cout<<"MSNV: "<<dsnv[i].msnv<<endl;
		cout<<"Chuc vu: "<<dsnv[i].chucvu<<endl;
		cout<<"So ngay lam viec: "<<dsnv[i].songaylamviec<<endl;
		cout<<"So tien luong: "<<dsnv[i].tienluong<<" K VND"<<endl;
	}
}
// Ham them nhan vien(1)
string chuan_hoa1(string s) 
{
    stringstream a(s);
    string ketqua= "", word;
    while(a >> word)
	{
        ketqua += toupper(word[0]);
        for(int i = 1; i < word.size(); i++)
		{
            ketqua += tolower(word[i]);
        }
        ketqua += " ";
    }
    // Xóa khoảng trắng thừa ở cuối chuỗi kết quả
    ketqua.pop_back();
    return ketqua;
}
string chuan_hoa_date(string &s)
{
	if(s[2]!='/')
	{
		s.insert(0,"0");
	}
	if(s[5]!='/')
	{
		s.insert(3,"0");
	}	
	return s;
}
void ThemNhanVien() {
    while (true) {
        int num;
        cout << "Nhap so luong nhan vien ban tuyen vao: ";
        cin >> num;
        if (dem + num <= max) {
            for (int i = 0; i < num; i++) {
                NhanVien a;
                cout << "          Nhap thong tin nhan vien thu " << (dem + 1)  << endl;
                cout << "Nhap ten nhan vien: ";//1
                cin.ignore();
                getline(cin,a.ten);
                a.ten=chuan_hoa1(a.ten);
                cout << "Nhap ma so nhan vien: ";//2
                cin>>a.msnv;
                cout<<"Nhap dia chi cua nhan vien:";//3
                cin.ignore();
                getline(cin,a.diachi);
                a.diachi=chuan_hoa1(a.diachi);
                cout<<"Nhap ngay/thang/nam sinh: ";//4
                getline(cin,a.ngaysinh);
                a.ngaysinh=chuan_hoa_date(a.ngaysinh);
                cout<<"Nhap so dien thoai:";//5
                getline(cin,a.sdt);
                cout<<"Nhap chuc vu:";//6
                getline(cin,a.chucvu);
                a.chucvu=chuan_hoa1(a.chucvu);
                cout<<"Nhap so ngay lam viec trong thang:";//7
                cin>>a.songaylamviec;
                dsnv[dem] = a;
                dem++;
            }
            break;
        } else {
            cout << "So luong nhan vien vuot qua muc cho phep. Vui long nhap lai" << endl;
        }
    }
}
// Ham sua nhan vien theo msnv(2)
void SuaNhanVien() 
{
    int id;
    bool found = false;
    while (!found) 
    {
        cout << "Nhap ma so nhan vien ban muon sua: ";
        cin >> id;
        for (int i = 0; i < dem; i++)
        {
            if (dsnv[i].msnv == id) 
            {
                hienthi1(dsnv[i]);
                bool tiepTuc = true;
                
                while (tiepTuc) {
                    cout << "Chon thong tin muon sua:\n";
                    cout << "1. Ten\n";
                    cout << "2. Dia chi\n";
                    cout << "3. So dien thoai\n";
                    cout << "4. Chuc vu\n";
                    cout << "5. So ngay lam viec\n";
                    cout << "0. Hoan tat\n";

                    int choice;
                    cout << "Nhap lua chon cua ban: ";
                    cin >> choice;
                    cin.ignore(); // Để bỏ qua ký tự newline còn sót lại

                    switch (choice) {
                        case 1:
                            cout << "Nhap ten nhan vien: ";
                            getline(cin, dsnv[i].ten);
                            dsnv[i].ten=chuan_hoa1(dsnv[i].ten);
                            break;
                        case 2:
                            cout << "Nhap dia chi cua nhan vien: ";
                            getline(cin, dsnv[i].diachi);
                            dsnv[i].diachi=chuan_hoa1(dsnv[i].diachi);
                            break;
                        case 3:
                            cout << "Nhap so dien thoai: ";
                            getline(cin, dsnv[i].sdt);
                            break;
                        case 4:
                            cout << "Nhap chuc vu: ";
                            getline(cin, dsnv[i].chucvu);
                            dsnv[i].chucvu = chuan_hoa1(dsnv[i].chucvu);
                            break;
                        case 5:
                            cout << "Nhap so ngay lam viec trong thang: ";
                            cin >> dsnv[i].songaylamviec;
                            cin.ignore(); // Để bỏ qua ký tự newline còn sót lại
                            break;
                        case 0:
                            tiepTuc = false;
                            break;
                        default:
                            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                    }

                    if (choice != 0) {
                        char suaTiep;
                        cout << "Ban co muon sua thong tin khac khong? (y/n): ";
                        cin >> suaTiep;
                        cin.ignore(); // Để bỏ qua ký tự newline còn sót lại
                        if (suaTiep == 'n' || suaTiep == 'N') {
                            tiepTuc = false;
                        }
                    }
                }
                
                cout << " --> Sua thong tin nhan vien thanh cong! " << endl;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Khong tim thay nhan vien co MSNV vua nhap. Vui long nhap lai! " << endl;
            break;
        }
    }
}

// Ham xoa nhan vien theo msnv(3.1)
void XoaNhanVien1() {
    int id;
    bool found = false;
    while (!found) {
        cout << "Nhap ma so nhan vien ban muon xoa: ";
        cin >> id;
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].msnv == id) {
                for (int j = i; j < dem - 1; j++) {
                    dsnv[j] = dsnv[j + 1];
                }
                dem--;
                cout << "Xoa nhan vien thanh cong." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co MSNV vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
//Ham xoa nhan vien theo ten(3.2)
void XoaNhanVien2() {
    string name;
    bool found = false;
    while (!found) {
        cout << "Nhap ho va ten nhan vien ban muon xoa: ";
        cin.ignore();
        getline(cin,name);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].ten == name) 
			{
                for (int j = i; j < dem - 1; j++) 
				{
                    dsnv[j] = dsnv[j + 1];
                }
                dem--;
                cout << "Xoa nhan vien thanh cong." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co ho va ten vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
//Ham xoa nhan vien theo so dien thoai(3.3)
void XoaNhanVien3() {
    string hotline;
    bool found = false;
    while (!found) {
        cout << "Nhap so dien thoai nhan vien ban muon xoa: ";
        cin.ignore();
        getline(cin,hotline);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].sdt == hotline) {
                for (int j = i; j < dem - 1; j++) {
                    dsnv[j] = dsnv[j + 1];
                }
                dem--;
                cout << "Xoa nhan vien thanh cong." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien so dien thoai vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
//Ham xoa nhan vien theo que quan(3.4)--> Cam sua lai
void XoaNhanVien4() {
    string address;
    bool found = false;
    while (!found) {
        cout << "Nhap dia chi cua nhan vien ban muon xoa: ";
        cin.ignore();
        getline(cin,address);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].diachi == address) {
                for (int j = i; j < dem - 1; j++) {
                    dsnv[j] = dsnv[j + 1];
                }
                dem--;
                cout << "Xoa nhan vien thanh cong." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co dia chi vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
// Ham tim nhan vien theo msnv(4.1)
void TimKiem1() {
    int id;
    bool found = false;
    while (!found) {
        cout << "Nhap ma so nhan vien ban muon tim kiem: ";
        cin >> id;
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].msnv == id) {
                hienthi1(dsnv[i]);
                found = true;
                return;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co MSNV vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
//Ham tim kiem nhan vien theo ten(4.2)
void TimKiem2()
{
	string name;
    bool found = false;
    while (!found) {
        cout << "Nhap ho va ten nhan vien ban muon tim kiem: ";
        cin.ignore();
        getline(cin,name);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].ten == name) {
                hienthi1(dsnv[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co ho va ten vua nhap.Vui long nhap lai!" << endl;
        }
    }
}
//Tim kiem nhan vien theo dia chi(4.3)
void TimKiem3()
{
	string address;
	bool found = false;
    while (!found) {
        cout << "Nhap dia chi nhan vien ban muon tim kiem: ";
        cin.ignore();
        getline(cin,address);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].diachi == address) {
                hienthi1(dsnv[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co dia chi vua nhap. Vui long nhap lai!" << endl;
        }
    }
}
//Tim kiem nhan vien theo so dien thoai(4.4)
void TimKiem4()
{
	string hotline;
	bool found = false;
    while (!found) {
        cout << "Nhap so dien thoai nhan vien ban muon tim kiem: ";
        cin.ignore();
        getline(cin,hotline);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].sdt == hotline) {
                hienthi1(dsnv[i]);
                found = true;
                return;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co so dien thoai vua nhap, vui long nhap lai!" << endl;
        }
    }
}
//Tim kiem nhan vien theo chuc vu(4.5)
void TimKiem5()
{
	string role;
	bool found = false;
    while (!found) {
        cout << "Nhap chuc vu nhan vien ban muon tim kiem: ";
        cin.ignore();
        getline(cin,role);
        for (int i = 0; i < dem; i++) {
            if (dsnv[i].chucvu == role) {
                hienthi1(dsnv[i]);
                found = true;
            }
        }
        if (!found) {
            cout << "Khong tim thay nhan vien co so dien thoai vua nhap, vui long nhap lai!" << endl;
        }
    }
}
//Cac cham sap xep nhan vien:1. Theo MSNV 2.Theo bang chu cai alpha b 3.Theo so ngay lam viec 4.Theo do tuoi
// Ham sap xep nhan vien theo msnv tang dan(5.1)
void Sapxep1() {
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (dsnv[i].msnv > dsnv[j].msnv) {
                NhanVien tmp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = tmp;
            }
        }
    }
    cout << " --> Sap xep xong." << endl;
}
//Ham sap xep nhan vien theo ten theo bang chu cai alpha B(5.2)
void Sapxep2() {
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (dsnv[i].ten < dsnv[j].ten) {
                NhanVien tmp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = tmp;
            }
        }
    }
    cout << " --> Sap xep xong." << endl;
}
//Ham sap xep nhan vien theo so ngay lam viec trong thang tang dan(5.3)
void Sapxep3() {
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (dsnv[i].songaylamviec > dsnv[j].songaylamviec) {
                NhanVien tmp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = tmp;
            }
        }
    }
    cout << " --> Sap xep xong." << endl;
}
//Ham sap xep nhan vien theo tuoi tang dan(5.4)
int tuoi(NhanVien a)
{
	string namsinh;
	for(int i=a.ngaysinh.size()-4;i<a.ngaysinh.size();i++)
	{
		namsinh+=a.ngaysinh[i];
	}
	int age=2024-stoi(namsinh);
	return age;
}
void Sapxep4() {
    for (int i = 0; i < dem - 1; i++) {
        for (int j = i + 1; j < dem; j++) {
            if (tuoi(dsnv[i])>tuoi(dsnv[j])) {
                NhanVien tmp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = tmp;
            }
        }
    }
    cout << " --> Sap xep xong." << endl;
}
/*Ham tinh luong nhan vien theo chuc vu(6)

Nguyen tac: Moi mot chuc vu khac nhau huong tien luong khac nhau.
Nhan Vien: 300k/ngay.
Truong Phong: 500k/ngay.
Giam Doc:1000k/ngay.

*/
void Luong()
{
	for(int i=0;i<dem;i++)
	{
		if(dsnv[i].chucvu=="Giam Doc")
		{
			dsnv[i].tienluong=dsnv[i].songaylamviec*1000;
		}
		else if(dsnv[i].chucvu=="Truong Phong")
		{
			dsnv[i].tienluong=dsnv[i].songaylamviec*500;
		}
		else dsnv[i].tienluong=dsnv[i].songaylamviec*300;
	}
	hienthi3();
}
//Ham luu thong tin nhan vien vao file danhsachnhanvien.txt
void Luu_File() {
    ofstream file("danhsachnhanvien.txt");
    if (file.is_open()) 
	{
		int cnt=0;
        file <<"So luong nhan vien: "<<dem << endl;
        for (int i = 0; i < dem; i++) {
        	++cnt;
        	file<<"- Nhan vien thu "<<cnt<<endl;
            file <<"Ten: "<<dsnv[i].ten << endl;
            file <<"Ma so nhan vien: "<< dsnv[i].msnv << endl;
            file <<"Ngay thang nam sinh: "<< dsnv[i].ngaysinh << endl;
            file <<"Dia chi: "<< dsnv[i].diachi << endl;
            file <<"So dien thoai: "<< dsnv[i].sdt << endl;
            file <<"Chuc vu: "<< dsnv[i].chucvu << endl;
            file <<"So ngay lam viec trong thang: "<< dsnv[i].songaylamviec << endl;
        }
        file.close();
        cout << "--> Luu thong tin vao file thanh cong." << endl;
    } 
	else 
	{
        cout << "Chu y: Khong mo duoc file de ghi." << endl;
    }
}
int main()
{
	int x;
	int m,n,k,p;
	do {
        MENU();
        cin >> x;
        switch (x) 
		{
            case 1:
                ThemNhanVien();
                break;
            case 2:
                SuaNhanVien();
                break;
            case 3:
                Menu3();
                cin>>m;
                switch(m)
                {
                	case 1:
                		XoaNhanVien1();
                		break;
                	case 2:
				XoaNhanVien2();
				break;	
                	case 3:
                		XoaNhanVien3();
                		break;
			default:
                    		cout << "Lua chon khong hop le\n";
                    		break;	
		}
		break;
    
            case 4:
                Menu4();
                cin>>n;
                switch(n)
                {
                	case 1:
                		TimKiem1();
                		break;
                	case 2:
						TimKiem2();
						break;	
                	case 3:
                		TimKiem3();
                		break;
                	case 4:
                		TimKiem4();
                		break;
					case 5:
						TimKiem5();
						break;	
					default:
                    	cout << "Lua chon khong hop le\n";
                    	break;	
				}
				break;
    
            case 5:
            	//Cac cham sap xep nhan vien:1. Theo MSNV 2.Theo bang chu cai alpha b 3.Theo so ngay lam viec 4.Theo do tuoi
                Menu5();
                cin>>k;
                switch(k)
                {
                	case 1:
                		Sapxep1();
                		break;
                	case 2:
						Sapxep2();
						break;
					case 3:
						Sapxep3();
						break;
					case 4:
						Sapxep4();	
						break;	
					default:
                    	cout << "Lua chon khong hop le\n";
                    	break;	
				}
				break;
            case 6:
                Luong();
                break;
            case 7:
            	hienthi2();
            	break;
            case 8:
            	Luu_File();
            	break;
            case 9:
            	system("cls");
            	break;
            case 10:
            	break;
            default:
            	cout<<"Lua chon khong hop le, vui long chon lai!"<<endl;
        }
    } while (x != 10);
}
