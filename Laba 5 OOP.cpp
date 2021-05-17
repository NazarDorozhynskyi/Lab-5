#include <iostream>
using namespace std;

class Advertisement {
private:
    string adv_name;
    string customer;

public:
    Advertisement() {
        cout << "Викликаємо базовий  конструктор без параметрів..." << endl;
        adv_name = "DEFAULT_NAME";
        customer = "DEFAULT_CUSTOMER";
    }

    Advertisement(const string& adv_name, const string& customer) :
            adv_name(adv_name), customer(customer) {
        cout << "Викликаємо базовий  конструктор з параметрами..." << endl;
    }

    Advertisement(const Advertisement& adv) {
        cout << "Викликаємо базовий  конструктор копіювання..." << endl;
        adv_name = adv.adv_name;
        customer = adv.customer;
    }

    ~Advertisement() {
        cout << "Викликаємо базовий  деструктор..." << endl;
    }

    string GetName() const {
        return adv_name;
    }
    string GetCustomer() const {
        return customer;
    }

    void SetName(string name) {
        adv_name = name;
    }

    void SetCustomer(string cust) {
        customer = cust;
    }

    virtual double TotalCost() const {
        return 1;
    }

    virtual void Info() const {
        cout << "\nAdvertisement name: " << GetName() <<
             "\nCustomer:" << GetCustomer() << "\n\n";
    }
};

class AdvertisementTV : public Advertisement {
private:
    string TVchannel_name;
    double duration_of_1_video;
    double number_of_showings_per_week;
    double cost_show_1_minute;

public:
    AdvertisementTV() : Advertisement() {
        cout << "Викликаємо похідний конструктор TV без параметрів..." << endl;
        TVchannel_name = "DEFAULT_TV_CHANNEL_NAME";
        duration_of_1_video = 1;
        number_of_showings_per_week = 1;
        cost_show_1_minute = 1;
    }

    AdvertisementTV(const string& adv_name, const string& customer,
                    const string& TVchannel_name,
                    const double& duration_of_1_video,
                    const double& number_of_showings_per_week,
                    const double& cost_show_1_minute) :
            Advertisement(adv_name, customer),
            TVchannel_name(TVchannel_name),
            duration_of_1_video(duration_of_1_video),
            number_of_showings_per_week(number_of_showings_per_week),
            cost_show_1_minute(cost_show_1_minute) {
        cout << "Викликаємо похідний конструктор TV з параметрами..." << endl;
    }

    ~AdvertisementTV() {
        cout << "Викликаємо похідний TV деструктор..." << endl;
    }

    string GetTVchannel_name() const {
        return TVchannel_name;
    }

    double GetDuration_of_1_video() const {
        return duration_of_1_video;
    }

    double GetNumber_of_showings_per_week() const {
        return number_of_showings_per_week;
    }

    double GetCost_show_1_minute() const {
        return cost_show_1_minute;
    }

    void SetTVchannel_name(string TVchannel) {
        TVchannel_name = TVchannel;
    }

    void SetDuration_of_1_video(double duration) {
        duration_of_1_video = duration;
    }

    void SetNumber_of_showings_per_week(double showings_week) {
        number_of_showings_per_week = showings_week;
    }

    void SetCost_show_1_minute(double show_1_minute) {
        cost_show_1_minute = show_1_minute;
    }

    double TotalCost() const {
        return number_of_showings_per_week * duration_of_1_video * cost_show_1_minute;
    }

    void Info() const {
        cout << "\nTV Channel name: " << GetTVchannel_name() <<
             "\nDuration of 1 video: " << GetDuration_of_1_video() <<
             "\nNumber of showings per week: " << GetNumber_of_showings_per_week() <<
             "\nCost show 1 minute: " << GetCost_show_1_minute() << "\n\n";
    }
};

class AdvertisementBillboards : public Advertisement {
private:
    string location;
    double width;
    double height;
    double number_of_days;
    double cost_per_1_sq_km_for_1_day;

public:
    AdvertisementBillboards() : Advertisement() {
        cout << "Викликаємо похідний конструктор Billboards без параметрів..." << endl;
        location = "DEFAULT_LOCATION";
        width = 1;
        height = 1;
        number_of_days = 1;
        cost_per_1_sq_km_for_1_day = 1;
    }

    AdvertisementBillboards(const string& adv_name, const string& customer,
                            const string& location,
                            const double& width,
                            const double& height,
                            const double& number_of_days,
                            const double& cost_per_1_sq_km_for_1_day) :
                            Advertisement(adv_name, customer),
                            location(location),
                            width(width),
                            height(height),
                            number_of_days(number_of_days),
                            cost_per_1_sq_km_for_1_day(cost_per_1_sq_km_for_1_day) {
        cout << "Викликаємо похідний конструктор Billboards з параметрами..." << endl;
    }

    ~AdvertisementBillboards() {
        cout << "Викликаємо похідний Billboards деструктор..." << endl;
    }

    string GetLocation() const {
        return location;
    }

    double GetWidth() const {
        return width;
    }

    double GetHeight() const {
        return height;
    }

    double GetNumberOfDays() const {
        return number_of_days;
    }

    double GetCostPer1SqKmFor1Day() const {
        return cost_per_1_sq_km_for_1_day;
    }

    void SetLocation(string set_location) {
        location = set_location;
    }

    void SetWidth(double set_width) {
        width = set_width;
    }

    void SetHeight(double set_height) {
        height = set_height;
    }

    void SetNumberOfDays(double set_number_of_days) {
        number_of_days = set_number_of_days;
    }

    void SetCostPer1SqKmFor1Day(double set_cost_per_1_sq_km_for_1_day) {
        cost_per_1_sq_km_for_1_day = set_cost_per_1_sq_km_for_1_day;
    }

    double TotalCost() const {
        return number_of_days * cost_per_1_sq_km_for_1_day * width * height;
    }

    void Info() const {
        cout << "\nBillboard Location: " << GetLocation() <<
        "\nWidth: " << GetWidth() <<
        "\nHeight: " << GetHeight() <<
        "\nNumber of days: " << GetNumberOfDays() <<
        "\nCost per 1 sq km for 1 day: " << GetCostPer1SqKmFor1Day() << "\n\n";
    }
};

bool operator > (const Advertisement& adv1, const Advertisement& adv2) {
    return adv1.TotalCost() > adv2.TotalCost();
}

bool operator < (const Advertisement& adv1, const Advertisement& adv2) {
    return adv1.TotalCost() < adv2.TotalCost();
}

int main() {
    system("chcp 1251");

    AdvertisementBillboards adv1("NESTLE", "AMAZON", "USA", 12.3, 3.4, 4, 56.2);
    AdvertisementBillboards adv2("COCA-COLA", "TESLA", "China", 23.8, 2.9, 2, 11.7);
    AdvertisementBillboards adv3("PEPSI", "SPACEX", "Ukraine", 3.6, 18.6, 5, 32.1);
    AdvertisementTV adv4("Fanta", "1+1", "France", 720.1, 13, 25.6);
    
    Advertisement *arrAdv[] = {&adv1, &adv2, &adv3, &adv4};
    Advertisement *arrAdvTemp;

    int k1, k2, kst, i;
    double sum;
    kst = sizeof(arrAdv)/sizeof(*arrAdv);

    for (k1 = 1; k1 < kst; k1++) {
        arrAdvTemp = *(arrAdv+k1);
        k2 = k1-1;
        while (k2 >= 0 and (*arrAdvTemp > *arrAdv[k2])) {
            (arrAdv[k2+1]) = arrAdv[k2];
            k2--;
        }
        arrAdv[k2+1] = arrAdvTemp;
    }

    for (i = 0; i < kst; i++) {
        cout << "\nCost of " << i+1 << " Advertisement order: " << arrAdv[i] -> TotalCost() << " \n";
        sum += arrAdv[i] -> TotalCost();
        arrAdv[i] -> Info();
    }
    cout << "Total sum of all orders: " << sum << "\n\n";

    return 0;
}
