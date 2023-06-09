#include <iostream>
#include <ctime>

using namespace std;

class Person {
	private:
	struct tm lahir;

	public:
	Person(int y, int m, int d) {
        lahir.tm_year = y - 1900;
        lahir.tm_mon = m - 1;
        lahir.tm_mday = d;
        lahir.tm_hour = 0;
        lahir.tm_min = 0;
        lahir.tm_sec = 0;
    }

    int hari_inmonth(int tahun, int bulan) {
        if (bulan == 2) {
            if (tahun % 4 == 0 && (tahun % 100 != 0 || tahun % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    bool tahunkabisat(int tahun) {
        if (tahun % 4 == 0 && (tahun % 100 !=0 || tahun % 400 ==0)) {
            return true;
        } else {
            return false;
        }
    }

    void hitungumur () {
        time_t time_now = time (NULL);
        tm* localtm = localtime(&time_now);
        int umur_tahun = localtm->tm_year - lahir.tm_year;
        int umur_bulan = localtm->tm_mon - lahir.tm_mon;
        int umur_hari = localtm->tm_mday - lahir.tm_mday;

        bool tahun_kabisat = tahunkabisat(lahir.tm_year + 1900);

        if (umur_hari < 0) {
            umur_bulan--;
            umur_hari += hari_inmonth(localtm->tm_year, localtm->tm_mon + 1);
        }
        if (umur_bulan < 0) {
            umur_tahun--;
            umur_bulan += 12;
        }

        if (localtm->tm_mon < lahir.tm_mon) {
            umur_tahun--;
        } else if (localtm->tm_mon == lahir.tm_mon && localtm->tm_mday < lahir.tm_mday) {
            umur_tahun--;
        }

        cout << "umur anda adalah " << umur_tahun << " tahun " << umur_bulan << " bulan " << umur_hari << " hari";
        if (tahun_kabisat) {
            cout << ", tahun " << lahir.tm_year + 1900 << " merupakan tahun kabisat";
        } else {
            cout << ", tahun " << lahir.tm_year + 1900 << " bukan tahun kabisat";
        cout << endl;
    }
}
};

int main() {
    int d, m, y;
    cout << "masukkan tanggal, bulan, dan tahun lahir: ";
    cin >> d >> m >> y;

    Person p(y, m, d);
    p.hitungumur();

    return 0; 
	}


