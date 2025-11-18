#include <iostream>
#include <string>   
using namespace std;

class NhanVien {
public:
    string maNV;   // Mã nhân viên (duy nhat)
    string hoTen;  
    string chucVu; 
    int namSinh; 

    // --- Hàm nhap thông tin nhân viên ---
    void nhap() {
        cout << "   Nhap ma nhan vien: ";
        getline(cin >> ws, maNV); 

        // Nh?p h? tên nhân viên
        cout << "   Nhap ho ten: ";
        getline(cin, hoTen);

        // Nh?p ch?c v? nhân viên
        cout << "   Nhap chuc vu: ";
        getline(cin, chucVu);

        // Nh?p nam sinh
        cout << "   Nhap nam sinh: ";
        cin >> namSinh;
        cin.ignore(); 
    }

    // --- Hàm xuât thông tin nhân viên ---
    void xuat() {
        cout << "      MaNV: " << maNV
             << " | Ho ten: " << hoTen
             << " | Chuc vu: " << chucVu
             << " | Nam sinh: " << namSinh << endl;
    }
};

// 2. DANH SÁCH NHÂN VIÊN 

typedef struct NodeNV {
    NhanVien data;   
    NodeNV* next;    
} nodeNV;

class listNV {
public:
    nodeNV* head; 
    nodeNV* tail; 
    int size;     


    listNV() {
        head = tail = NULL;
        size = 0;
    }

    // --- Hàm tao node moi ---
    nodeNV* createNode(NhanVien v) {
        nodeNV* p = new nodeNV(); 
        p->data = v;              
        p->next = NULL;           
        return p;
    }

    // --- Thêm nhân viên vào cuoi danh sách ---
    void addLast(NhanVien v) {
        nodeNV* p = createNode(v); 
        if (!head) {               
            head = tail = p;      
        } else {
            tail->next = p;        
            tail = p;              
        }
        size++;                     
    }

    // --- Nhâp danh sách nhân viên ---
    void nhapDSNV() {
        int n; 
        cout << "Nhap so luong nhan vien: "; 
        cin >> n; 
        cin.ignore(); 
        for (int i = 0; i < n; i++) {
            cout << " - Nhap nhan vien thu " << i + 1 << ":\n";
            NhanVien nv; 
            nv.nhap();           
            addLast(nv);          
        }
    }

    // --- Xuât danh sách nhân viên ---
    void xuatDSNV() {
        if (!head) { 
            cout << "   (Khong co nhan vien)" << endl; 
            return; 
        }
        cout << "   --- Danh sach nhan vien ---" << endl;
        for (nodeNV* i = head; i; i = i->next) 
            i->data.xuat(); 
    }

    // --- Tìm kiem nhân viên theo mã ---
    NhanVien* timKiemTheoMa(string ma) {
        for (nodeNV* i = head; i; i = i->next) {
            if (i->data.maNV == ma) return &i->data; 
        }
        return NULL;
    }

    // --- Xóa nhân viên theo mã ---
    void xoaTheoMa(string ma) {
        if (!head) { 
            cout << "Danh sach nhan vien rong!\n"; 
            return; 
        }
        nodeNV* p = head; 
        nodeNV* prev = NULL;
        while (p && p->data.maNV != ma) { prev = p; p = p->next; }
        if (!p) { 
            cout << "? Khong tim thay nhan vien!\n"; 
            return; 
        }
        if (p == head) { 
            head = head->next; 
            if (p == tail) tail = NULL; 
        } else { 
            prev->next = p->next; 
            if (p == tail) tail = prev; 
        }
        delete p; 
        size--;
        cout << "? Da xoa nhan vien!\n";
    }

    // --- S?a thông tin nhân viên theo mã ---
    void suaTheoMa(string ma) {
        nodeNV* p = head;
        while (p) {
            if (p->data.maNV == ma) {
                cout << "\nNhap thong tin moi:\n";
                p->data.nhap(); // Nh?p l?i thông tin
                cout << "? Da cap nhat!\n";
                return;
            }
            p = p->next;
        }
        cout << "? Khong tim thay nhan vien!\n";
    }
};

// 3. CLASS HÀNG HÓA
// Qu?n lý thông tin hàng hóa trong siêu th?

class HangHoa {
public:
    string maHH;            
    string tenHH;          
    string nguonGoc;       
    string phanPhoi;       
    string anToanThucPham;  
    int tonKho;            
    // --- Hàm nhap thông tin hàng hóa ---
    void nhap() {
        cout << "   Nhap ma hang hoa: "; getline(cin >> ws, maHH);
        cout << "   Nhap ten hang hoa: "; getline(cin, tenHH);
        cout << "   Nhap nguon goc: "; getline(cin, nguonGoc);
        cout << "   Nhap ton kho: "; cin >> tonKho; cin.ignore();
        cout << "   Nhap phan phoi: "; getline(cin, phanPhoi);
        cout << "   Nhap an toan thuc pham (Co/Khong): "; getline(cin, anToanThucPham);
    }

    // --- Hàm xuât thông tin hàng hóa ---
    void xuat() {
        cout << "      MaHH: " << maHH
             << " | TenHH: " << tenHH
             << " | Nguon goc: " << nguonGoc
             << " | Ton kho: " << tonKho
             << " | Phan phoi: " << phanPhoi
             << " | An toan: " << anToanThucPham << endl;
    }
};

// 4. DANH SÁCH HÀNG HÓA

typedef struct NodeHH {
    HangHoa data; // Thông tin hàng hóa
    NodeHH* next; // Node ti?p theo
} nodeHH;

class listHH {
public:
    nodeHH* head;
    nodeHH* tail;
    int size;

    listHH() { head = tail = NULL; size = 0; }

    nodeHH* createNode(HangHoa v) {
        nodeHH* p = new nodeHH();
        p->data = v;
        p->next = NULL;
        return p;
    }

    // --- Thêm hàng hóa vào cu?i danh sách ---
    void addLast(HangHoa v) {
        nodeHH* p = createNode(v);
        if (!head) head = tail = p;
        else { tail->next = p; tail = p; }
        size++;
    }

    // --- Nhâp danh sách hàng hóa ---
    void nhapDSHH() {
        int n; cout << "Nhap so luong hang hoa: "; cin >> n; cin.ignore();
        for (int i = 0; i < n; i++) {
            cout << " - Nhap hang hoa thu " << i + 1 << ":\n";
            HangHoa hh; hh.nhap(); addLast(hh);
        }
    }

    // --- Xuât danh sách hàng hóa ---
    void xuatDSHH() {
        if (!head) { cout << "   (Khong co hang hoa)\n"; return; }
        cout << "   --- Danh sach hang hoa ---\n";
        for (nodeHH* i = head; i; i = i->next) i->data.xuat();
    }

    // --- Tìm hàng hóa theo mã ---
    HangHoa* timHangHoaTheoMa(string ma) {
        for (nodeHH* i = head; i; i = i->next)
            if (i->data.maHH == ma) return &i->data;
        return NULL;
    }

    // --- Xóa hàng hóa theo mã ---
    void xoaHangHoaTheoMa(string ma) {
        if (!head) { cout << "Danh sach rong!\n"; return; }
        nodeHH* p = head; nodeHH* prev = NULL;
        while (p && p->data.maHH != ma) { prev = p; p = p->next; }
        if (!p) { cout << "? Khong tim thay hang hoa!\n"; return; }
        if (p == head) { head = head->next; if (p == tail) tail = NULL; }
        else { prev->next = p->next; if (p == tail) tail = prev; }
        delete p; size--;
        cout << "? Da xoa hang hoa!\n";
    }

    // --- Tìm hàng hóa theo ngu?n g?c ---
    void timHangHoaTheoNguonGoc(string nguon) {
        bool found = false;
        for (nodeHH* i = head; i; i = i->next)
            if (i->data.nguonGoc == nguon) { i->data.xuat(); found = true; }
        if (!found) cout << "? Khong tim thay hang hoa co nguon goc: " << nguon << endl;
    }

    // --- Kiem tra ton kho duoi muc ---
    void kiemTraTonKho(int muc) {
        bool found = false;
        for (nodeHH* i = head; i; i = i->next)
            if (i->data.tonKho <= muc) { i->data.xuat(); found = true; }
        if (!found) cout << "? Khong co hang hoa ton kho thap hon " << muc << endl;
    }

    // --- Kiêm tra an toàn thuc pham ---
    void kiemTraAnToan() {
        bool found = false;
        for (nodeHH* i = head; i; i = i->next)
            if (i->data.anToanThucPham != "Co") { i->data.xuat(); found = true; }
        if (!found) cout << "? Tat ca hang hoa an toan\n";
    }

    // --- Tong ton kho ---
    int tongTonKho() {
        int tong = 0;
        for (nodeHH* i = head; i; i = i->next) tong += i->data.tonKho;
        return tong;
    }

    // --- Tong ton kho theo danh muc phân phoi ---
    void tonKhoTheoDanhMuc(string danhMuc) {
        bool found = false;
        int tong = 0;
        for (nodeHH* i = head; i; i = i->next)
            if (i->data.phanPhoi == danhMuc) { tong += i->data.tonKho; found = true; }
        if (found) cout << "? Tong ton kho cua danh muc \"" << danhMuc << "\": " << tong << endl;
        else cout << "? Khong co hang hoa trong danh muc \"" << danhMuc << "\"\n";
    }
};

// 5. CLASS SIÊU TH?
class SieuThi {
public:
    string maSieuThi, tenSieuThi, doanhThu2023, danhMucChinh;
    int namThanhLap;
    listNV nhanSu;   
    listHH hangHoa; 

    // --- Nhap thông tin siêu thi ---
    void nhap() {
        cout << "Nhap Ma Sieu Thi: "; getline(cin >> ws, maSieuThi);
        cout << "Nhap Ten Sieu Thi: "; getline(cin, tenSieuThi);
        cout << "Nhap Nam Thanh Lap: "; cin >> namThanhLap; cin.ignore();
        cout << "Nhap Doanh Thu Nam 2023: "; getline(cin, doanhThu2023);
        cout << "Nhap Danh Muc Chinh: "; getline(cin, danhMucChinh);

        // Nhap danh sách nhân viên
        cout << "\n-- NHAP NHAN VIEN --\n"; 
        nhanSu.nhapDSNV();

        // Nhap danh sách hàng hóa
        cout << "\n-- NHAP HANG HOA --\n"; 
        hangHoa.nhapDSHH();
    }

    // --- Xuat thông tin siêu thi ---
    void xuat() {
        cout << "\n[ MaST: " << maSieuThi
             << " | TenST: " << tenSieuThi
             << " | NamTL: " << namThanhLap
             << " | DoanhThu: " << doanhThu2023
             << " | DanhMuc: " << danhMucChinh << " ]\n";
        nhanSu.xuatDSNV();
        hangHoa.xuatDSHH();
    }
};

// 6. DANH SÁCH SIÊU TH?
typedef struct Node {
    SieuThi data;
    Node* next;
} node;

class list {
public:
    node* head; node* tail; int size;
    list() { head = tail = NULL; size = 0; }

    node* createNode(SieuThi v) { 
        node* p = new node(); 
        p->data = v; 
        p->next = NULL; 
        return p; 
    }

    void addLast(SieuThi v) { 
        node* p = createNode(v); 
        if (!head) head = tail = p; 
        else { tail->next = p; tail = p; } 
        size++; 
    }

    void show() { 
        if(!head){ cout<<"Danh sach rong!\n"; return;}
        for (node* i = head; i; i = i->next) i->data.xuat(); 
    }

    SieuThi* timSieuThiTheoMa(string ma) { 
        for (node* i = head; i; i = i->next) 
            if (i->data.maSieuThi == ma) return &i->data; 
        return NULL; 
    }
    void xoaSieuThiTheoMa(string ma) {
        if (!head) { 
		cout << "? Danh sach sieu thi rong!\n";
		return; }
        node* p = head;
		node* prev = NULL;
        while (p && p->data.maSieuThi != ma) { 
		prev = p; p = p->next; 
		}
        if (!p) { 
		cout << "? Khong tim thay sieu thi!\n"; 
		return; }
        if (p == head) { 
		head = head->next; 
		if (p == tail) tail = NULL; 
		}
        else { 
		prev->next = p->next; 
		if (p == tail) tail = prev; 
		}
        delete p; size--; cout << "? Da xoa sieu thi!\n";
    }
};

// 7. MAIN 
int main() {
    list dsSieuThi; 
    int n; 
    cout << "Nhap so luong sieu thi: "; 
    cin >> n; 
    cin.ignore();

    // Nh?p thông tin các siêu th? ban d?u
    for (int i = 0; i < n; i++) { 
        cout << "\n=== Sieu thi thu " << i + 1 << " ===\n"; 
        SieuThi st; 
        st.nhap(); 
        dsSieuThi.addLast(st); 
    }

    // --- Menu chính ---
    int chon;
    do {
        cout << "\n===== MENU QUAN LY =====\n";
        cout << "1. Hien thi tat ca sieu thi, nhan vien va hang hoa\n";
        cout << "2. Quan ly nhan vien\n"; 
        cout << "3. Them sieu thi moi\n";
        cout << "4. Quan ly hang hoa\n";
        cout << "5. Xoa sieu thi theo ma\n";
        cout << "0. Thoat\nChon: "; 
        cin >> chon; cin.ignore();

        // --- Hien thi tat ca ---
        if (chon == 1) dsSieuThi.show();

        // --- Quan ly nhan vien ---
        else if (chon == 2) {
            string maST; 
            cout << "Nhap ma sieu thi can quan ly nhan vien: "; 
            getline(cin, maST);
            SieuThi* st = dsSieuThi.timSieuThiTheoMa(maST); 
            if (!st) { 
                cout << "? Khong tim thay sieu thi!\n"; 
                continue; 
            }

            // Menu con qu?n lý nhân viên
            int luaChonNV;
            do {
                cout << "\n--- MENU QUAN LY NHAN VIEN ---\n";
                cout << "1. Xem danh sach nhan vien\n";
                cout << "2. Tim nhan vien theo ma\n";
                cout << "3. Xoa nhan vien theo ma\n";
                cout << "4. Sua thong tin nhan vien theo ma\n";
                cout << "5. Them nhan vien moi\n";
                cout << "0. Quay lai menu chinh\n";
                cout << "Chon: "; cin >> luaChonNV; cin.ignore();

                if (luaChonNV == 1) {
                    cout << "\n--- Danh sach nhan vien cua sieu thi " << st->tenSieuThi << " ---\n";
                    st->nhanSu.xuatDSNV();
                }
                else if (luaChonNV == 2) {
                    string maNV;
                    cout << "Nhap ma nhan vien can tim: "; getline(cin, maNV);
                    NhanVien* nv = st->nhanSu.timKiemTheoMa(maNV);
                    if (nv) nv->xuat();
                    else cout << "? Khong tim thay nhan vien!\n";
                }
                else if (luaChonNV == 3) {
                    string maNV;
                    cout << "Nhap ma nhan vien can xoa: "; getline(cin, maNV);
                    st->nhanSu.xoaTheoMa(maNV);
                }
                else if (luaChonNV == 4) {
                    string maNV;
                    cout << "Nhap ma nhan vien can sua: "; getline(cin, maNV);
                    st->nhanSu.suaTheoMa(maNV);
                }
                else if (luaChonNV == 5) {
                    NhanVien nv;
                    cout << "Nhap thong tin nhan vien moi:\n";
                    nv.nhap();
                    st->nhanSu.addLast(nv);
                    cout << "? Da them nhan vien moi!\n";
                }
                else if (luaChonNV != 0) {
                    cout << "? Lua chon khong hop le. Thu lai!\n";
                }
            } while (luaChonNV != 0);
        }

        // --- Them sieu thi moi ---
        else if (chon == 3) { 
            SieuThi st; st.nhap(); 
            dsSieuThi.addLast(st); 
            cout << "? Da them sieu thi moi!\n"; 
        }

        // --- Quan ly hang hoa ---
        else if (chon == 4) {
            string maST;
            cout << "Nhap ma sieu thi: "; getline(cin, maST);
            SieuThi* st = dsSieuThi.timSieuThiTheoMa(maST); 
            if (!st) { cout << "? Khong tim thay\n"; continue; }

            int c;
            do {
                cout << "\n--- QUAN LY HANG HOA ---\n";
                cout << "1. Xem danh sach\n2. Them hang hoa\n3. Xoa hang hoa theo ma\n";
                cout << "4. Tim hang hoa theo ma\n5. Tim hang hoa theo nguon goc\n";
                cout << "6. Kiem tra ton kho\n7. Kiem tra an toan\n";
                cout << "8. Tong ton kho cua sieu thi\n9. Tong ton kho theo danh muc\n";
                cout << "0. Quay lai menu chinh\nChon: ";
                cin >> c; cin.ignore();

                if(c==1) st->hangHoa.xuatDSHH();
            else if(c==2){ 
			   HangHoa hh; 
			   hh.nhap(); 
			   st->hangHoa.addLast(hh); 
			   cout << "? Da them\n"; }
            else if(c==3){ 
		     	string maHH; 
				cout << "Nhap ma: ";
				 getline(cin, maHH); 
				 st->hangHoa.xoaHangHoaTheoMa(maHH); }
            else if(c==4){
			    string maHH; cout << "Nhap ma: ";
				getline(cin, maHH); 
				HangHoa* hh = st->hangHoa.timHangHoaTheoMa(maHH); 
				if(hh) 
				  hh->xuat(); 
				else cout << "? Khong tim thay\n"; }
            else if(c==5){ 
			    string nguon;
				cout << "Nhap nguon goc: "; 
				getline(cin, nguon);
				st->hangHoa.timHangHoaTheoNguonGoc(nguon); }
            else if(c==6){
			     int muc;
				 cout << "Nhap muc ton kho toi da de kiem tra: "; 
				 cin >> muc; cin.ignore(); 
				 st->hangHoa.kiemTraTonKho(muc); }
            else if(c==7){ st->hangHoa.kiemTraAnToan(); }
            else if(c==8){ cout << "? Tong ton kho cua sieu thi: " << st->hangHoa.tongTonKho() << endl; }
            else if(c==9){ 
			    string dm; cout << "Nhap danh muc: "; 
				getline(cin, dm); 
				st->hangHoa.tonKhoTheoDanhMuc(dm); }
            else if(c!=0){ cout << "? Lua chon khong hop le!\n"; }
            else if (chon == 5) { 
			string maST; cout << "Nhap ma sieu thi can xoa: ";
			getline(cin, maST); 
			dsSieuThi.xoaSieuThiTheoMa(maST); 
			}
            } while(c != 0);
        }
          else if (chon == 5) { 
			string maST; cout << "Nhap ma sieu thi can xoa: ";
			getline(cin, maST); 
			dsSieuThi.xoaSieuThiTheoMa(maST); 
			}
    } while(chon != 0);

    cout << "\nKet thuc chuong trinh.\n";
    return 0;
}

